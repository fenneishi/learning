assume cs:code  
code segment  
;安装新的int_7CH
        start:  
        ;持久化中断程序
                ;ds:[si]——————int_7CH代码源地址 
                mov ax,cs
                mov ds,ax                               
                mov si,offset int_7CH                  
                mov ax,0
                ;es:[di]=0:204h——————代码安装地址 
                mov es,ax                             
                mov di,200H
                ;cx = 代码长度 = 循环次数                             
                mov cx,offset int_7CHend - offset int_7CH
                ;正向传送 
                cld
                ;串传送
                rep movsb 
        ;更新中断向量表：9号中断码指向新地址
                cli                                                     ; 置IF=0,此时不响应任何可屏蔽中断信息，防止更新过程被中断，9号中断码指向错误地址
                mov word ptr es:[4*7ch],200H
                mov word ptr es:[4*7ch+2],0
                sti
        ;安装测试                                                               
                mov ah,2                                                ;功能号2，设置背景色  
                mov al,2                                                ;颜色值  
                int 7CH      
        ;结束安装程序
                mov ax,4c00h
                int 21h 
                


               

;int_7CH
        ;名称：int_7CH  
        ;功能：如下功能子程序：0号清屏、1号设置前景色、2号设置背景色、3号向上滚动一行
        ;参数：(ah)为功能号，取值范围：{0、1、2、3} ；(al）1、2号功能颜色值，取值范围{0、1、2、3、4、5、6、7} 
        ;返回：根据功能号调用相应子程序的返回值
        org 200H                                                        ;伪指令，表示下一条地址从偏移地址204H开始，和安装后的偏移地址相同。
                                                                        ;若没有org 204H，中断例程安装后，标号代表的地址改变了，和之前编译器编译的有所区别   
        int_7CH:  
                jmp short int_7CHBegin                                  ;占据两个字节cs:[200H]-cs[201H]
                table dw sub0,sub1,sub2,sub3                            ;占据4个字(8个字节): cs:[202H]-cs[203H]、 cs:[204H]-cs[205H]、cs:[206H]-cs[207H]、cs:[208H]-cs[209H] 
        int_7CHBegin:
                ;保存现场   
                push bx
                ;参数检测  
                cmp ah,3                                                ;判断功能号是否大于3  
                ja int_7CHRet
                ;子程序调用 
                mov bl,ah  
                mov bh,0  
                add bx,bx  
                call word ptr table[bx]                                 ;=      
                                                                        ;        call word ptr cs:[202H+bx]
                                                                        ;=
                                                                        ;       push ip
                                                                        ;       jump word ptr cs:[202H+bx]  
                                                                        ;=（bx等于0时）
                                                                        ;       push ip
                                                                        ;       (ip)低8位=(cs:[202H+bx])=(cs:[202H])=offset sub0的低8位
                                                                        ;       (ip)高8位=(cs:[203H+bx])=(cs:[203H])=offset sub0的高8位
                                                                        ;=（bx等于0时）
                                                                        ;       push ip
                                                                        ;       (ip)=offset sub0=200h+len[(offset sub0)-200h]=200h+len[(offset sub0)-(offset int_7CH)]  其中offset int_7CH = 200h
        int_7CHRet:   
                pop bx  
                iret 




        ;名称：sub0，
        ;功能号:0 
        ;功能：清屏
        ;参数：无
        ;返回：
        ;    寄存器：无
        ;    内存：B800H:0~B800H:[0+4000]偶地址全部改写
        sub0: 
                ;保存现场
                push bx  
                push cx  
                push es 
                ;es:[bx]= B800H:0000
                mov bx,0B800H  
                mov es,bx  
                mov bx,0  
                ;循环次数=2000
                mov cx,2000  
                sub0s:   
                        ;循环内容
                        mov byte ptr es:[bx],' '
                        ;更新循环变量  
                        add bx,2 
                        ;循环跳转 
                        loop sub0s  
                ;恢复现场
                pop es  
                pop cx  
                pop bx
                ;退出子程序，回到中断例程  
                ret  
        
        
        
        ;名称：sub1，
        ;功能号:1 
        ;功能：设置前景色
        ;参数：(al）颜色值，取值范围{0、1、2、3、4、5、6、7} 
        ;返回：
        ;    寄存器：无
        ;    内存：B800H:1~B800H:[1+4000]奇地址全部改写
        sub1:
                ;保存现场
                push bx  
                push cx  
                push es
                ;es:[bx]= B800H:1  
                mov bx,0B800H  
                mov es,bx  
                mov bx,1 
                ;循环次数=2000
                mov cx,2000  
                sub2s:   
                        ;循环内容
                        and byte ptr es:[bx],11111000B                  ;奇地址是保存属性值，后三位决定前景色，先将后三位置0，方便后面修改
                        or es:[bx],al                                   ;al传送颜色值，00000000B~00000111B
                        ;更新循环变量   
                        add bx,2
                        ;循环跳转  
                        loop sub2s
                ;恢复现场  
                pop es  
                pop cx  
                pop bx 
                ;退出子程序，回到中断例程   
                ret  




        ;名称：sub2，
        ;功能号:2 
        ;功能：设置背景色
        ;参数：(al）颜色值，取值范围{0、1、2、3、4、5、6、7} 
        ;返回：
        ;    寄存器：无
        ;    内存：B800H:1~B800H:[1+4000]寄地址全部改写
        sub2:
                ;保存现场 
                push bx  
                push cx  
                push es 
                ;颜色值逻辑左移4位
                mov cl,4  
                shl al,cl 
                ;es:[bx]= B800H:1   
                mov bx,0B800H  
                mov es,bx  
                mov bx,1 
                ;循环次数=2000
                mov cx,2000  
                sub3s: 
                        ;循环内容  
                        and byte ptr es:[bx],10001111B                  ;要改变的位，置0  
                        or es:[bx],al                                   ;al传送颜色值，00000000B~01110000B
                        ;更新循环变量     
                        add bx,2
                        ;循环跳转
                        loop sub3s  
                ;恢复现场  
                pop es  
                pop cx  
                pop bx 
                ;退出子程序，回到中断例程    
                ret  
        


        ;名称：sub3，
        ;功能号:3 
        ;功能：向上滚动一行
        ;参数：无
        ;返回：
        ;    寄存器：无
        ;    内存：B800H:1~B800H:[1+4000]寄地址全部改写
        sub3:   
        ;保存现场
                push cx  
                push si  
                push di  
                push es  
                push ds
        ;es:[di]= B800H:0 指向第n行(一开始指向第0行)
        ;ds:[si]= B800H:160 指向第n+1行(一开始指向第1行)
                mov si,0B800H  
                mov es,si  
                mov ds,si  
                mov si,160
                mov di,0
        ;n+1行内容复制到n行
                ;正向传输
                cld
                ;共循环24次，即复制24行    
                mov cx,24
                sub4s:   
                        push cx  
                        mov cx,160                                      ;cx为传送长度  
                        rep movsb                                       ;每次操作si和di递增，不需要再设置行号和列数
                        ;串操作会同时更改指针，所以不需要再手动更新循环变量  
                        pop cx  
                        loop sub4s  
        ;清空最后一行
                ;循环次数=80
                mov cx,80
                mov si,0  
                sub4s1: 
                        mov byte ptr [160*24+si],' '  
                        add si,2  
                        loop sub4s1  
        ;恢复现场  
                pop ds  
                pop es  
                pop di  
                pop si  
                pop cx 
        ;退出子程序，回到中断例程     
                ret  


;int_7CH结束标号
        int_7CHEnd:  nop  
code ends  
end start 
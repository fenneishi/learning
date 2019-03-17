assume cs:code  



data segment  
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'  
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'  
    db '1993','1994','1995'  
    ;表示21年的21个字符串  
    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514  
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000  
    ;表示21年公司总收入的dword型数据  
    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226  
    dw 11542,14430,15257,17800  
    ;表示21年公司雇员人数的21个word型数据  
data ends  

stack segment  
    db 20 dup (0)                                                ;实际上会占据2个16字节的空间作为栈
stack ends  

string segment  
   ;db 21 dup ('012345678901234567890123456789012345678',0)      ;这里是40个字节一行
    db 21 dup ('1970      0         0         0        ',0) 
string ends




code segment  
start: 
;将data按照格式写入string中   
    ;ss:sp指向stack起始地址
    mov ax,stack  
    mov ss,ax  
    mov sp,32  
    ;ds:[bx+di]指向data起始地址                                                    
    mov ax,data  
    mov ds,ax                                                                     
    mov bx,0  
    mov di,0  
    ;es:[si]指向string起始地址                                                    
    mov ax,string  
    mov es,ax  
    mov si,0  
    ;循环次数为21                                                     
    mov cx,21                                                    
    s0:
    ;有三个数据来源指针，ds:[0+bx]、ds:[54H+bx]、ds:[0A8H+bx]、每次循环都会向右移动（移动步长分别为：4、4、2）
    ;有一个数据去向指针，es:[si]，每写入一个数据，向右移动10个字节
    ;有两个数据转化子程序：dtoc、dtocdw、传入无符号数字，在es:[si]指向的位置写入相应的ASCII码。
    ;有一个数据生成子程序：divdw，输入被除数、除数，输出商和余数。
    ;每次循环过程：从三个数据来源得到三个数据，经过数据转化和生成，生成四个数据，以10为步长，存入数据去向指针位置
    ;注意：es:[si]本身即是数据去向指针，在转移年份的时候使用，又是dtoc和dtocdw的参数和
        ;写入年份,4字节字符串,用mov写两次
        push cx                             ;栈：21、  
        mov ax,[bx+0]                       
        mov es:[si],ax                      ;es:[si]=0、40、80、、、
        add si,2                            ;es:[si]=2、42、82、、、
        mov ax,[bx+2]  
        mov es:[si],ax                       
        add si,8                            ;es:[si]=10、50、90、、、
        ;写入总收入，32位十进制数，用dtocdw写一次
        mov ax,[bx+54H]  
        mov dx,[bx+54H+2]  
        call dtocdw                         
        add si,10                           ;es:[si]=20、60、100、、、
        ;写入雇员数，16位十进制数，用dtoc写一次，注意：因为年份和收入都是4个字节一个单元，而雇员人数是2个字节一个单元，所以ds每次循环加4，di每次循环加2.
        mov ax,[di+0A8H]                                        
        call dtoc                            
        add si,10                           ;es:[si]=30、70、110、、、
        ;计算并写入人均收入，人均收入计算结果为32位十进制数，用dtocdw写一次
        mov ax,[bx+54H+0]                                       
        mov dx,[bx+54H+2]  
        mov cx,[di+0A8H]                            
        call divdw;人均收入，(dx)=高16位，(ax)=低16位，(cx)=余数 
        call dtocdw                           
        add si,10                           ;es:[si]=40、80、120、、、
        ;更新循环变量
        add bx,4  
        add di,2                                         
        pop cx                              ;栈：空
        ;循环  
        loop s0  

;显示string中的数据
    ;设置参数
    ;从第10行开始显示 
    mov dh,10 
    ;ds:bx指向string首地址                               
    mov ax,string  
    mov ds,ax                                                    
    mov bx,0
    ;循环21次                                
    mov cx,21                                                                                  
    s1:
        ;cx入栈保存
        push cx
        ;设置参数                                                 
        mov dl,3  
        mov cl,00000010B 
        ;调用show_str子程序,显示一行数据   
        call show_str
        ;更新循环变量                                          
        inc dh  
        add bx,40
        ;还原cx                                                  
        pop cx
        ;循环  
        loop s1  
    ;mov ah,0  
    ;int 16H                                                    ;按任意键继续，可直接双击运行  
    mov ax,4C00H  
    int 21H  



;名称：dtocdw  
;功能：将dword型十进制数据转化为字符串  
;参数：(ax)是dword型十进制数据低16位，(dx)是dword型十进制数据高16位，es:[si]指向string当前,ss:[sp]指向stack栈底  
;返回：寄存器：无
;     内存空间：es:[si]~es:[si+十进制数据位数] 
;注意：dtocdw程序并不会在末尾写一个0
dtocdw: 
    ;保存现场
    push ax  
    push bx  
    push cx  
    push dx  
    push es  
    mov bx,0  
    numToCharDw:
        ;计算余数   
        mov cx,10                       ;cx = 10 = 除数 
        call divdw                      ;被除数高16位：dx
                                        ;被除数低16位：ax
                                        ;除数       ：cx
                                        ;商高16位    ：dx
                                        ;商低16位    ：ax
                                        ;余数       ：cx
        ;计算ASCII码值
        add cx,30H                      ;cx = 余+30H  ，数字的ASCII码值=数字值+30H
        ;余数入栈
        push cx                         ;栈底：第1个余数、第2个余数、、、、、、  
        ;统计余数个数
        inc bx                          ;bx=1、2、3、4、5、、、代表栈中有几个字符  
        ;计算循环条件
        mov cx,dx                       ;cx=dx=商高16位
        or cx,ax                        ;商为0代表数字处理结束  
        ;if cx==0,跳转到stackToStringDw，结束循环.
        jcxz stackToStringDw  
        ;else,跳转到numToCharDw，继续循环.
        jmp short numToCharDw  
    stackToStringDw:    
        mov cx,bx                       ;cx = 最终栈中字符个数 = 源数据10进制情况下的位数 = 循环次数 
        mov bx,0                        ;bx = 0 
    dtocdwS1: 
        ;循环转移数据 
        pop ax                          ;出栈，一次取一个字 
        mov es:[bx+si],al               ;放到指定内存，一次放一个字节 
        inc bx                          ;es:[bx+si]指向下一字节内存地址 
        loop dtocdwS1  
    dtocdwOk: 
        ;恢复现场
        pop es  
        pop dx  
        pop cx  
        pop bx  
        pop ax
        ;程序返回 
        ret  

;名称：dtoc  
;功能：将十进制数据转化为字符串  
;参数：(ax)是十进制数据，ss:[sp]指向stack栈底，es:[si]指向string起始地址 
;返回：寄存器：无
;     内存空间：es:[si]~es:[si+十进制数据位数]
;注意：dtoc程序并不会在末尾写一个0
dtoc: 
    ;保存现场
    push ax  
    push bx  
    push cx  
    push dx  
    push es  
    mov bx,0  
    numToChar: 
        ;计算余数   
        mov dx,0                        ;dx=0000h,ax=十进制数据 
        mov cx,10                       ;cx=10 
        div cx                          ;=(dx*256*256+ax)/cx = (0+ax)/cx = ax/cx = int(ax/cx).......rem(ax/cx)
                                        ;ax=int(ax/cx)=商
                                        ;dx=rem(ax/cx)=余
        ;计算ASCII码值
        add dx,30H                      ;dx=余+30H，数字的ASCII码值=数字值+30H
        push dx                         ;栈底：第1个余数、第2个余数、、、、、、
        inc bx                          ;bx=栈中字符个数=1、2、3、、、  
        mov cx,ax                       ;cx=ax=商，商为0代表数字处理结束  
        ;if cx==0,跳转到stackToString，结束循环
        jcxz stackToString
        ;else,跳转到numToChar，继续循环              
        jmp short numToChar  
    stackToString:
        ;设置循环参数    
        mov cx,bx                       ;cx = 最终栈中字符个数 = 源数据10进制情况下的位数 = 循环次数
        mov bx,0                        ;bx = 0
    dtocS1:
        ;循环转移数据   
        pop ax                          ;出栈，一次取一个字
        mov es:[bx+si],al               ;放到指定内存，一次放一个字节  
        inc bx                          ;es:[bx+si]指向下一字节内存地址
        loop dtocS1  
    dtocOk: 
        ;恢复现场   
        pop es  
        pop dx  
        pop cx  
        pop bx  
        pop ax
        ;程序返回                           
        ret 

 
;名称：divdw  
;功能：除法，被除数32位，除数16位，商32位，余数16位，不会溢出  
;参数：(dx)=被除数的高16位H，(ax)=被除数的低16位L，(cx)=除数N  
;返回：(dx)=商的高16位，(ax)=商的低16位，(cx)=余数
;原理：X/N= int(H/N)*65536+int{[rem(H/N)*65536+L]/N}   .......................rem{[rem(H/N)*65536+L]/N}  
divdw:  
    ;保存现场
    push bx 
    ;调整参数            
    push ax             ;L入栈暂存
    mov ax,dx           ;(ax)=H
    mov dx,0            ;(dx)=0                   
    ;完成高16位除法
    div cx              ;除数cx，被除数默认为：dx(高16位)ax(低16位)
	                    ;实际过程(0*65536+H)��N = H/N = int(H/N)...........rem(H/N)
	                    ;商默认存放在ax中：(ax)=int(H/N)
	                    ;余数默认存放dx中：(dx)=rem(H/N)
    
    ;完成低16位除法
    mov bx,ax           ;(bx)=int(H/N) 
    pop ax              ;(ax)=L
    div cx              ;除数cx，被除数默认：dx(高16λ)ax(低16λ)
	                    ;实际过程：[rem(H/N)*65536+L]/N =int{[rem(H/N)*65536+L]/N}...........rem{[rem(H/N)*65536+L]/N}     
	                    ;商默认存放ax当中 ：(ax)=int{[rem(H/N)*65536+L]/N} 
	                    ;余数默认存放dx当中： (dx)=rem{[rem(H/N)*65536+L]/N} 

    mov cx,dx           ;用cx存放余数：(cx)=rem{[rem(H/N)*65536+L]/N} 
    mov dx,bx           ;用dx存放商的高16位：(dx) =int(H/N)
    ;恢复现场
    pop bx
    ;程序返回             
    ret  


;名称：show_str  
;功能：在屏幕指定位置，用指定颜色，显示一个用0结尾的字符串  
;参数：参数：(dh)=行号(0~24)，(dl)=列号（0～80），(cl)=颜色，ds:[bx]：该字符串的首地址  
;返回：
;    寄存器改写：无
;    内存改写:   0B800  :  {[行号*160+2列号]~[行号*160+2列号+len(字符串)*2]}
show_str: 
; 数据来源指针：ds:[bx]
; 数据去向指针：es:[si] 
; 寄存器主要用途：ax传递字符(低位、高位分别存放字符和属性)，cx判断是否为0； 
    ;保存现场  
    push cx  
    push ax  
    push dx  
    push es  
    push si    
    push bx                                
    ;得到显存段地址ds
    mov ax,0B800H  
    mov es,ax                                  ;设置段寄存器指向目标段
    ;得到显存偏移地址si
    mov al,160  
    mul dh                                     ;8位乘法，默认与al相乘，结果存ax
    ;sub ax,160                                ;实现公式（行号-1）*160，这种情况下，行号是从1开始数的。最大值为25*160<265*265,没有进位问题。
    add dl,dl                                  ;最多80+80=160=0A0H，没有进位问题  
    mov dh,0  
    add ax,dx                                  ;得到dh行dl列显存的偏移地址
    mov si,ax                                  ;es:[si] 
    ;把颜色值放在ah中                            ;因为cl后面要用到，所以改用ah来保存
    mov ah,cl                                  ;ah存放颜色格式，循环中不再改变  
    change:  
        ;判断是否要进入循环
        mov cl,[bx]  
        mov ch,0  
        jcxz show_strOk                         ;相当于if not 语句：如果是不是0，则正常执行后面指令，否则的话，跳转到show_strOK 
        ;转移数据
        mov al,[bx];得到数据放入al  
        mov es:[si],ax  
        ;数据源指针和数据去向指针均指向下一个目标
        add si,2;下一个字母到下一列  
        inc bx 
        ;进入下一轮操作                                 
        jmp short change  
    show_strOk: 
        ;恢复现场  
        pop bx
        pop si  
        pop es  
        pop dx  
        pop ax  
        pop cx  
        ;退出子程序
        ret  

code ends  
end start 

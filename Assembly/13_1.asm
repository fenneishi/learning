assume cs:code

data segment
        db 'successful install show_str',0
data ends


code segment
;安装程序
    start:
    ;固化代码
        ;ds:[si]——————show_str代码源地址
        mov ax,cs
        mov ds,ax
        mov si,offset show_str
        ;es:[di]=0:200h——————代码安装地址
        mov ax,0
        mov es,ax
        mov di,200h
        ;cx = 代码长度 = 循环次数
        mov cx,offset show_str_end - offset show_str
        ;设置标志寄存器DF=0  
        cld
        ;串传送
        rep movsb
    ;设置0中断码的中断向量 
        mov word ptr es:[7ch*4],200h
        mov word ptr es:[7ch*4+2],0
    ;安装测试：
        mov dh,8                           
        mov dl,3                        
        mov cl,2                               
        mov ax,data
        mov ds,ax
        mov si,0                               
        int 7ch  
    ;结束安装程序
        mov ax,4c00h
        int 21h


;中断程序
    ;名称：show_str  
    ;功能：在屏幕指定位置，用指定颜色，显示一个用0结尾的字符串  
    ;参数：参数：(dh)=行号(0~24)，(dl)=列号（0～80），(cl)=颜色，ds:[bx]：该字符串的首地址  
    ;返回：
    ;    寄存器改写：无
    ;    内存改写:   0B800  :  {[行号*160+2列号]~[行号*160+2列号+len(字符串)*2]}
    show_str: 
        ; 数据来源指针：ds:[bx]
        ; 数据去向指针：es:[si] 
        ; 寄存器主要用途：ax传递字符(低位、高位分别存放字符和属性)；cx判断是否为0； 
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
            ;退出中断程序
            iret   
        show_str_end:
            nop
code ends
end start



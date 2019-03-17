assume cs:code


code segment
;安装程序
    start:
    ;固化代码
        ;ds:[si]——————show_str代码源地址
        mov ax,cs
        mov ds,ax
        mov si,offset lp
        ;es:[di]=0:200h——————代码安装地址
        mov ax,0
        mov es,ax
        mov di,200h
        ;cx = 代码长度 = 循环次数
        mov cx,offset lp_end - offset lp
        ;设置标志寄存器DF=0  
        cld
        ;串传送
        rep movsb
    ;设置0中断码的中断向量 
        mov word ptr es:[7ch*4],200h
        mov word ptr es:[7ch*4+2],0
    ;安装测试：
        ;es:[di]指向显存地址
        mov ax,0b800h
        mov es,ax
        mov di,160*12
        ;bx=标号se到标号s的位移
        mov bx,offset s-offset se
        ;循环次数=80
        mov cx,80
        s:
            ;循环内容
            mov byte ptr es:[di],'!'
            ;更新循环变量
            add di,2
            ;通过中断代码为7ch的中断程序实现循环功能
            int 7ch
        se: nop
    ;结束安装程序
        mov ax,4c00h
        int 21h


;中断程序
    ;名称：lp 
    ;功能：实现指令loop的功能 
    ;参数：bx=跳转偏移地址  cx=循环次数 
    ;返回：
    ;    寄存器改写：cx的值减1；ip值改为循环起始的偏移地址
    ;    内存改写:   无
    lp:  
        ;保存现场    
        push bp                               
        ;ss:[bp]指向栈顶
        mov bp,sp 
        ;递减cx
        dec cx                                  
        ;if cx==0,then jump lpret
        jcxz lpret 
        ;给栈中保存的IP值加上bx
        add [bp+2],bx                                 
        ;lp的返回程序                                
        lpret:                       
            ;恢复现场  
            pop bp 
            ;退出中断程序
            iret 
        ;lp结束位置标号  
        lp_end:nop
code ends
end start



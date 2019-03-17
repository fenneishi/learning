assume cs:code


code segment
start:
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
    mov ax,4c00h
    int 21h
code ends
end start



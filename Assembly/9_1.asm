assume cs:code,ds:data

data segment
        db 'I Love You'
data ends

 
code segment
start:  mov ax,data
        mov ds,ax
        mov bx,0
        mov ax,0b800h
        mov ss,ax
        mov bp,70
        mov ah,10011100b
        mov cx,10
    s:  call show
        inc bx
        add bp,2
        loop s
        mov ax,4c00h
        int 21h

show:  push dx
        push cx
        mov dx,1000h
        mov cx,1000h
   s1: mov al,[bx]
        mov [1920+bp],ax
        sub dx,1
        sbb cx,0
        cmp dx,0
        jne s1
        cmp cx,0
        jne s1
        pop cx
        pop dx
        ret 
 s2:  
        jmp short s2


code ends

end start



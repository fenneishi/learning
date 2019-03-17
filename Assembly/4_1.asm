assume cs:code

code segment
        mov ax,0020h
        mov ds,ax
        mov bx,0
        mov ax,0
        mov cx,0040h

s:      mov [bx],ax
        inc ax
        inc bx
        loop s

        mov ax,4c00h
        int 21h


code ends
end



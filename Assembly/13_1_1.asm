assume cs:code

data segment
        db 'successful install show_str',0
data ends

code segment
    start:
        mov dh,8                           
        mov dl,3                        
        mov cl,2                               
        mov ax,data
        mov ds,ax
        mov si,0                               
        int 7ch  
        mov ax,4c00h
        int 21h
code ends
end start



assume cs:code,ds:data

data segment
       db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
       db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
       db '1993','1994','1995'

       dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
       dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000

       dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
       dw 11542,14430,15257,17800

data ends


table segment
db 22 dup ('year summ ne ?? ')      ；每行是16b占位符，总共22行，最后一行当做栈
table  ends
 
code segment
start:  
        mov ax,data
        mov ds,ax
        mov ax,table
        mov ss,ax

        mov sp,352
        mov bx,0
        mov bp,0
        
        mov cx,21

s:      push cx
        
       
        mov si,0
        mov cx,2
        
s0:    push bx                                ；按理说，si最好也要入栈，但是鉴于si只会出现0和1两种情况，所以可以不用push si
        mov al,[168+bx+si]
        mov [bp+10+si],al
        add bx,bx
        add si,si
        mov ax,[0+bx+si]
        mov [bp+0+si],ax
        mov ax,[84+bx+si]
        mov [bp+5+si],ax
        inc si
        pop bx
        loop s0

        
        pop cx

        mov ax,[bp+5]
        mov dx,[bp+7]
        div word ptr [bp+10]
        mov [bp+13],ax                     ; 32 位 除 以 16 位 型 除法

        add bx,2
        add bp,16
        
        loop s

        mov ax,4c00h
        int 21h
code ends

end start



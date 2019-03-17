assume cs:code

code segment

    s1:  db 'Good,better,best,','$'
    s2:  db 'Never let it rest,','$'
    s3:  db 'Till good is better,','$'
    s4:  db 'And better,best.','$'
    s:   dw offset s1,offset s2,offset s3,offset s4
    row: db 2,4,6,8

    start :
        ;(ds)=（cs）
        mov ax,cs
        mov ds,ax
        ;ds:[bx] 指向：s: dw offset s1,offset s2,offset s3,offset s4
        mov bx,offset s
        ;ds:[si] 指向：row: db 2,4,6,8
        mov si,offset row
        ;循环次数：4
        mov cx,4
    ok:
        ;置光标
        mov bh,0                    ;第0页
        mov dh,[si]                 ;行号
        mov dl,0                    ;列号
        mov ah,2                    ;2号子程序：置光标
        int 10h                     ;调用中断例程
        ;显示字符串
        mov dx,[bx]                 ;ds:[dx]指向字符串首地址
        mov ah,9                    ;9号子程序：显示字符串
        int 21h                     ;调用中断例程
        ;更新循环变量
        inc si
        add bx,2
        ;循环
        loop ok
        ;结束程序
        mov ax,4c00h
        int 21h

code ends
end start
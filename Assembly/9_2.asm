DATAS SEGMENT 
    ;对80*25的屏幕，每行的字节数为80*2=160.
    ;要求显示在屏幕中间，先计算行和列的偏移
    ;行偏移：(25-3)/2=11.所以显示在第11,12,13行。偏移值分别为1760,1920,2080。计算方法为 行数*160(每行的字节数) 。
    ;列偏移：由于要显示的字符数为16个，所以开始显示的列偏移为(80-16)/2*2=64。
    dw 1760,1920,2080,64
       ;要显示的字符 16个
    db 'welcome to masm!'
    ;字符属性：第11行显示绿色字，第12行显示绿底红色，第13行显示白底蓝色
    ;在全屏模式下能看到字符的闪烁效果
    db 82h,0ach,0f9h
DATAS ENDS


CODES SEGMENT 
    ASSUME CS:CODES,DS:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    mov ax,0b800h
    mov es,ax   
    
    mov cx,3
    mov di,0
    
    s1:     
    mov ax,di
    mov bl,2
    div bl
    mov si,ax
    mov ah,[24+si] ;取颜色属性
    
    mov si,ds:[6] ;列
    mov bp,[di] ;行
    
    mov dx,cx
    mov bx,0
    
    mov cx,16   
    s2:
    mov al,[bx+8] ;取字符
    mov es:[bp+si],al  ;写字符
    mov es:[bp+si].1,ah ;设置颜色属性
    inc bx
    add si,2
    loop s2
    
    mov cx,dx
    add di,2
    loop s1
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
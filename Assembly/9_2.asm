DATAS SEGMENT 
    ;��80*25����Ļ��ÿ�е��ֽ���Ϊ80*2=160.
    ;Ҫ����ʾ����Ļ�м䣬�ȼ����к��е�ƫ��
    ;��ƫ�ƣ�(25-3)/2=11.������ʾ�ڵ�11,12,13�С�ƫ��ֵ�ֱ�Ϊ1760,1920,2080�����㷽��Ϊ ����*160(ÿ�е��ֽ���) ��
    ;��ƫ�ƣ�����Ҫ��ʾ���ַ���Ϊ16�������Կ�ʼ��ʾ����ƫ��Ϊ(80-16)/2*2=64��
    dw 1760,1920,2080,64
       ;Ҫ��ʾ���ַ� 16��
    db 'welcome to masm!'
    ;�ַ����ԣ���11����ʾ��ɫ�֣���12����ʾ�̵׺�ɫ����13����ʾ�׵���ɫ
    ;��ȫ��ģʽ���ܿ����ַ�����˸Ч��
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
    mov ah,[24+si] ;ȡ��ɫ����
    
    mov si,ds:[6] ;��
    mov bp,[di] ;��
    
    mov dx,cx
    mov bx,0
    
    mov cx,16   
    s2:
    mov al,[bx+8] ;ȡ�ַ�
    mov es:[bp+si],al  ;д�ַ�
    mov es:[bp+si].1,ah ;������ɫ����
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
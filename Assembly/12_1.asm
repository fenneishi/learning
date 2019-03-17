assume cs:code  
code segment  
start:
;安装
    ;ds:[si]=cs:offset do0——————do0代码源地址
    mov ax,cs     ;要执行的d0段复制到空白内存处作为中断处理程序  
    mov ds,ax  
    mov si,offset do0  
    ;es:[di]=0:200h——————do0代码安装地址
    mov ax,0  
    mov es,ax  
    mov di,200H 
    ;cx = 代码长度 = 循环次数 
    mov cx,offset do0end - offset do0
    ;设置标志寄存器DF=0  
    cld 
    ;串传送 
    rep movsb  
;设置0中断码的中断向量  
    mov word ptr es:[0*4],200H  
    mov word ptr es:[0*4+2],0  
;安装测试：溢出测试  
    mov ax,0000H    
    mov dx,1H       
    mov bx,1H  
    div bx  
;结束程序，但是中断程序已经安装完毕，除非断电重启，否则会一直存在 
    mov ax,4c00h  
    int 21h  
;中断程序
do0:
    jmp short do0start  ;两个字节  
    db 'divide error by qilong!'   
do0start:
    ;ds:[si]=0000:0202字符串起始地址
    mov ax,0  
    mov ds,ax  
    mov si,202h  
    ;es:[di]=B800h:12*160+36*2显存起始址
    mov ax,0B800h  
    mov es,ax  
    mov di,12*160+36*2   ;  
    ;循环次数
    mov cx,22 
    ;循环转移数据 
s:  mov al,[si]  
    mov es:[di],al 
    ;更新循环变量 
    inc si  
    add di,2  
    ;循环
    loop s  
    ;结束程序
    mov ax,4c00h  
    int 21h  
do0end:nop  
code ends  
end start 
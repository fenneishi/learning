assume cs:code,ss:stack  


stack segment  
db 16 dup (0)  
stack ends  



code segment  
start:  
    ;设置参数
    mov ax,4240H    ;被除数的低位——L 
    mov dx,000FH    ;被除数的高位——H
    mov cx,0AH      ;除数—————————N
    ;调用子程序
    call divdw  
    ;主程序结束
    mov ax,4C00H  
    int 21h  


;名称：divdw  
;功能：除法，被除数32位，除数16位，商32位，余数16位，不会溢出  
;参数：(dx)=被除数的高16位H，(ax)=被除数的低16位L，(cx)=除数N  
;返回：(dx)=商的高16位，(ax)=商的低16位，(cx)=余数
;原理：X/N= int(H/N)*65536+int{[rem(H/N)*65536+L]/N}   .......................rem{[rem(H/N)*65536+L]/N}  
divdw:  
    ;保存现场
    push bx 
    ;调整参数            
    push ax             ;L入栈暂存
    mov ax,dx           ;(ax)=H
    mov dx,0            ;(dx)=0                   
    ;完成高16位除法
    div cx              ;除数cx，被除数默认为：dx(高16位)ax(低16位)
	                    ;实际过程(0*65536+H)��N = H/N = int(H/N)...........rem(H/N)
	                    ;商默认存放在ax中：(ax)=int(H/N)
	                    ;余数默认存放dx中：(dx)=rem(H/N)
    
    ;完成低16位除法
    mov bx,ax           ;(bx)=int(H/N) 
    pop ax              ;(ax)=L
    div cx              ;除数cx，被除数默认：dx(高16λ)ax(低16λ)
	                    ;实际过程：[rem(H/N)*65536+L]/N =int{[rem(H/N)*65536+L]/N}...........rem{[rem(H/N)*65536+L]/N}     
	                    ;商默认存放ax当中 ：(ax)=int{[rem(H/N)*65536+L]/N} 
	                    ;余数默认存放dx当中： (dx)=rem{[rem(H/N)*65536+L]/N} 

    mov cx,dx           ;用cx存放余数：(cx)=rem{[rem(H/N)*65536+L]/N} 
    mov dx,bx           ;用dx存放商的高16位：(dx) =int(H/N)
    ;恢复现场
    pop bx
    ;程序返回             
    ret 

code ends  
end start 

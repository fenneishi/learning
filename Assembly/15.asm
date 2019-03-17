assume cs:codesg

codesg segment
;安装新的int9_new
        start:  
        ;持久化中断程序
                ;ds:[si]——————int9_new代码源地址 
                mov ax,cs
                mov ds,ax                               
                mov si,offset int9_new                  
                mov ax,0
                ;es:[di]=0:204h——————代码安装地址 (0:200~0:204存放旧int9代码地址)
                mov es,ax                             
                mov di,204H
                ;cx = 代码长度 = 循环次数                             
                mov cx,offset int9_newend - offset int9_new
                ;正想传送 
                cld
                ;串传送
                rep movsb                               ; 复制新的中断程序于内存单元的0:204处
        ;保存旧版int9程序地址
                mov ax,es:[4*9]
                mov es:[200H],ax
                mov ax,es:[4*9+2]
                mov es:[202H],ax                        ; 保存在0:200~0:204（0:200开头的一段内存地址一般不会被操作系统和其他程序使用）
        ;更新中断向量表：9号中断码指向新地址
                cli                                     ; 置IF=0,此时不响应任何可屏蔽中断信息，防止更新过程被中断，9号中断码指向错误地址
                mov word ptr es:[4*9],204H
                mov word ptr es:[4*9+2],0
                sti                                     ; 置IF=1，恢复正常状态                   
        ;结束安装程序
                mov ax,4c00h
                int 21h
;新的int9_new
        int9_new: 
        ;保存现场  
                push ax
                push es
                push di
                push cx
        ;读取键盘扫描码
                in al,60H                
        ;调用旧int9
                pushf
                call dword ptr cs:[200h]                 ; 当前cs=0，因为程序的存放位置就在0：200处
        ;添加功能：松开A,出现满屏幕的A
                ; if：读取的扫描码 == "释放A"的扫描码
                cmp al,1EH+80H 
                ;不等于：跳转到int9_newret          
                jne int9_newret
                ;等于：出现满屏幕A
                        ;es:[di]指向显存第一个地址
                        mov ax,0B800H
                        mov es,ax
                        mov di,0
                        ;循环次数=80*25（80行，25列）
                        mov cx,80*25
                        s:      
                        mov byte ptr es:[di],'A'        ; 显示"A"
                        mov byte ptr es:[di+1],2        ; 更改颜色
                        add di,2                        ; 指向下一个
                        loop s
        ;退出中断程序
        int9_newret:
                ;恢复现场
                pop cx
                pop di
                pop es
                pop ax
                ;退出
                iret
        ;程序截止标号，用于统计程序长度
        int9_newend: 
                nop
codesg ends
end start
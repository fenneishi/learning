assume cs:code  
  
code segment

start:  
        ;es:[di]指向显存其实地址
        mov ax,0b800h  
        mov es,ax  
        mov di,160*12+30*2  
        ;设置保存必要参数
        mov al,0ah                  ;al = CMOS RAM地址，初始地址=10  
        push di                     ;暂存di=显存其实地址  
      
rdata:  
        ;更新循环条件
        dec al                      ;当al=10、9、8（dec al =9、8、7）执行下面循环
        ;检测循环条件                            
        cmp al,7                    ;7是分界线
        ;生成判断：跳出循环or继续循环                    
        jb rtime                    ;al≥7执行循环中内容，否则跳转到rtime  
        ;循环主体 
        call show 
        ;更新循环变量 
        add di,6                    ;字符本身占用4个字节，还有2个字节是给“/”预留的 
        ;循环
        jmp short rdata               
          
rtime:  
        ;更新循环条件
        sub al,2                    ;当al=6、4、2（al-2=4、2、0）执行下面循环
        ;检测循环条件 
        cmp al,0feh                    ;
        ;生成判断：跳出循环or继续循环   
        je  sign                    ;al≠feH执行循环中内容，否则跳转到sign
                                    ;错误示范：因为00h-2=feh>0
                                    ;cmp al,0
                                    ;jb  sign 
        ;循环主体 
        call show
        ;更新循环变量   
        add di,6                    ;字符本身占用4个字节，还有2个字节是给“/”预留的 
        ;循环  
        jmp short rtime  
              
sign:   
        ;添加符号，例：18/06/06 17:26:10
        ;18/                           
        pop di                      ;取出di=显存起始地址  
        add di,4                    ;‘18’=4个字节  
        mov byte ptr es:[di],'/'  
        ;18/06 
        add di,6                    ;'/06'=6个字节  
        mov byte ptr es:[di],'/'  
        ;18/06/06 17     
        add di,12                   ;'/06 17'=12个字节 
        mov byte ptr es:[di],':'    
        ;18/06/06 17:26      
        add di,6                    ;‘:26’=6个字节  
        mov byte ptr es:[di],':'     
        ;18/06/06 17:26:10      
        mov ax,4c00h  
        int 21h  
  
;名称：show
;功能：在指定位置，按照默认属性，展示CMOS RAM指定位置的2位BCD编码十进制数字。
;参数：al=CMOS RAM内存指定地址 ； es:[di]=显存指定位置
;返回：通用寄存器：无 ；标志寄存器：未知，不重要 ；地址寄存器：无
;     内存地址空间：改写es:[di] ~  es:[di+4] 
;     端口：70h端口,改写成al=CMOS RAM内存指定地址；71h端口,改写成al=CMOS RAM内存指定地址的内容（一个字节）
show:   
        ;保存现场
        push ax  
        push cx  
        ;通过端口从CMOS RAM内，地址为al的存储单元获取一个字节数据，并存到al中 
        out 70h,al  
        in al,71h  
        ;转码：BCD→ASCII
        mov cx,4                    ;cl=移位个数=4
        mov ah,al                   ;用两个寄存器(ah与al)来存储数据，方便后面操作
        shr ah,cl                   ;ah=数据的十位BCD码值
        and al,00001111b            ;al=数据的个位BCD码值  
        add ah,30h                  ;ah=数据的十位ASCII码值  
        add al,30h                  ;al=数据的个位ASCII码值
        ;显示    
        mov es:[di+0],ah            ;es:[di+0]存ah,es:[di+0]存ah的属性
        mov es:[di+2],al            ;es:[di+2]存al,es:[di+3]存al的属性                
        ;恢复现场    
        pop cx  
        pop ax  
        ret  
code ends  
end start  
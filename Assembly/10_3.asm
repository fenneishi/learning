assume cs:code


string segment
     db 16 dup(0)                   ;用0作为填充，保证了字符串的结尾一定是0
string ends

stack segment  
    db 20 dup (0)                   ;实际上会占据2个16字节的空间作为栈,
stack ends  



code segment
start:
    ;设置参数
    mov ax,stack  
    mov ss,ax  
    mov sp,32                       ;ss:sp指向stac栈底
    mov ax,string
    mov es,ax                       
    mov si,0                        ;es:si指向string起始地址
    mov ax,12666                    ;ax=12666<256*256
    ;调用子程序,将十进制数据用ASCII码形式写入string中
    call dtoc
    ;设置参数
    mov dh,8
    mov dl,3
    mov cl,00000010B
    mov ax,string
    mov ds,ax
    mov bx,0
    ;调用子程序，显示string中的数据
    call show_str
    ;结束程序
    mov ax,4c00h
    int 21h
 


;名称：dtoc  
;功能：将十进制数据转化为字符串  
;参数：(ax)是十进制数据，ss:[sp]指向stack栈底，es:[si]指向string起始地址 
;返回：寄存器：无
;     内存空间：es:[si]~es:[si+十进制数据位数]
;注意：dtoc程序并不会在末尾写一个0
dtoc: 
    ;保存现场
    push ax  
    push bx  
    push cx  
    push dx  
    push es  
    mov bx,0  
    numToChar: 
        ;计算余数   
        mov dx,0                        ;dx=0000h,ax=十进制数据 
        mov cx,10                       ;cx=10 
        div cx                          ;=(dx*256*256+ax)/cx = (0+ax)/cx = ax/cx = int(ax/cx).......rem(ax/cx)
                                        ;ax=int(ax/cx)=商
                                        ;dx=rem(ax/cx)=余
        ;计算ASCII码值
        add dx,30H                      ;dx=余+30H；数字的ASCII码值=数字值+30H
        push dx                         ;栈底：第1个余数、第2个余数、、、、、、
        inc bx                          ;bx=栈中字符个数=1、2、3、、、  
        mov cx,ax                       ;cx=ax=商，商为0代表数字处理结束  
        ;if cx==0,跳转到stackToString，结束循环
        jcxz stackToString
        ;else,跳转到numToChar，继续循环              
        jmp short numToChar  
    stackToString:
        ;设置循环参数    
        mov cx,bx                       ;cx = 最终栈中字符个数 = 源数据10进制情况下的位数 = 循环次数
        mov bx,0                        ;bx = 0
    dtocS1:
        ;循环转移数据   
        pop ax                          ;出栈，一次取一个字
        mov es:[bx+si],al               ;放到指定内存，一次放一个字节  
        inc bx                          ;es:[bx+si]指向下一字节内存地址
        loop dtocS1  
    dtocOk: 
        ;恢复现场   
        pop es  
        pop dx  
        pop cx  
        pop bx  
        pop ax
        ;程序返回                           
        ret  
 




;名称：show_str  
;功能：在屏幕指定位置，用指定颜色，显示一个用0结尾的字符串  
;参数：参数：(dh)=行号(0~24)，(dl)=列号（0～80），(cl)=颜色，ds:[bx]：该字符串的首地址  
;返回：
;    寄存器改写:无
;    内存改写:0B800:{[行号*160+2列号]~[行号*160+2列号+len(字符串)*2]}
show_str: 
; 数据来源指针：ds:[bx]
; 数据去向指针：es:[si] 
; 寄存器主要用途：ax的低位、高位分别存放字符和属性；cx存放字符，结合jcxz来判断是否为0 
    ;保存现场  
    push cx  
    push ax  
    push dx  
    push es  
    push si
    push bx                                   
    ;得到显存段地址
    mov ax,0B800H  
    mov es,ax                                  ;设置段寄存器指向目标段
    ;得到显存偏移地址
    mov al,160  
    mul dh                                     ;8位乘法，默认与al相乘，结果存ax
    ;sub ax,160                                ;实现公式（行号-1）*160，这种情况下，行号是从1开始数的。最大值为25*160<265*265,没有进位问题。
    add dl,dl                                  ;最多80+80=160=0A0H，没有进位问题  
    mov dh,0  
    add ax,dx                                  ;得到dh行dl列显存的偏移地址
    mov si,ax                                  ;es:[si] 
    ;把颜色值放在ah中                            ;因为cl后面要用到，所以改用ah来保存
    mov ah,cl                                  ;ah存放颜色格式，循环中不再改变  
    change:  
        ;判断是否要进入循环
        mov cl,[bx]  
        mov ch,0  
        jcxz show_strOk                         ;相当于if not 语句：如果是不是0，则正常执行后面指令，否则的话，跳转到show_strOK 
        ;转移数据
        mov al,[bx];得到数据放入al  
        mov es:[si],ax  
        ;数据源指针和数据去向指针均指向下一个目标
        add si,2;下一个字母到下一列  
        inc bx 
        ;进入下一轮操作                                 
        jmp short change  
    show_strOk: 
        ;恢复现场 
        pop bx 
        pop si  
        pop es  
        pop dx  
        pop ax  
        pop cx  
        ;退出子程序
        ret  
 
 code ends
 end start
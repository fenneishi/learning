assume cs:codesg

datasg segment
    db "Beginner's All-purpose Symbolic Instruction Code.",0
datasg ends

stack segment
    db 16 dup(0)
stack ends

codesg segment
    begin:
        ;ss:sp指向stack起始地址
        mov ax,stack
        mov ss,ax
        mov sp,16
        ;ds:[bx+di]指向data起始地址    
        mov ax,datasg
        mov ds,ax
        mov si,0
        ;调用子程序
        call letterc
        ;结束程序
        mov ax,4c00h
        int 21h

    ;名称：letterc  
    ;功能：任意形式字符串所有英文字母大写  
    ;参数：ds:[si]字符串起始地址,ss:[sp]指向stack栈底  
    ;返回：内存空间：ds:[si]~es:[si+len(字符串)] 
    letterc:
        ;保存现场
        pushf
        push cx
        push si
        next:
            ;遇到0时，结束循环
            mov ch,0
            mov cl,ds:[si]
            jcxz ok
            ;<61h过,≥61h继续
            cmp byte ptr ds:[si],61h
            jb addsi
            ;>7Ah过,≤7Ah继续
            cmp byte ptr ds:[si],7Ah
            ja addsi
            ;61h≤字符ASCII码值≤7Ah：说明是小写英文字母，做大写化处理
            and byte ptr ds:[si],11011111B
        addsi:
            ;更新循环变量
            inc si
            ;循环
            jmp short next
        ok:
            ;恢复现场
            pop si
            pop cx
            popf
            ;返回
            ret
codesg ends
end begin
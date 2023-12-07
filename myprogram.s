.file "myprogram.s"
.data
x: 
.quad 1, 2, 3, 4, 5
.data
y: 
codegen error: array subtype must be integer
.text
.global main
main:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
PUSHQ %rdx
PUSHQ %rcx
PUSHQ %r8
PUSHQ %r9
MOVQ x, %rbx
LEAQ y, %r10
MOVQ $1, %r11
MOVQ $8, %rax
IMULQ %r11
MOVQ %rax, %r11
ADDQ %r11, %r10
MOVQ %rbx, (%r10)
SUBQ $8, %rsp
MOVQ $0, %rbx
MOVQ %rbx, -56(%rbp)
.L1:
MOVQ -56(%rbp), %rbx
MOVQ $5, %r11
CMPQ %r11, %rbx
JL .L3
MOVQ $0, %rbx
JMP .L4
.L3:
MOVQ $1, %rbx
.L4:
CMP $0, %rbx
JE .L2
MOVQ x, %rbx
LEAQ y, %r11
MOVQ -56(%rbp), %r12
MOVQ $8, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r11
MOVQ %rbx, (%r11)
MOVQ -56(%rbp), %rbx
INCQ -56(%rbp)
JMP .L1
.L2:
ADDQ $8, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

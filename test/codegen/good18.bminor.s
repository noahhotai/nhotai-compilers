.file "test/codegen/good18.bminor.s"
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
MOVQ $0, %rbx
PUSHQ %rbx
MOVQ $0, %rbx
PUSHQ %rbx
MOVQ $0, %rbx
MOVQ %rbx, -56(%rbp)
.L1:
MOVQ -56(%rbp), %rbx
MOVQ $9, %r10
CMPQ %r10, %rbx
JL .L3
MOVQ $0, %rbx
JMP .L4
.L3:
MOVQ $1, %rbx
.L4:
CMP $0, %rbx
JE .L2
MOVQ $0, %rbx
MOVQ %rbx, -64(%rbp)
.L5:
MOVQ -64(%rbp), %rbx
MOVQ $9, %r10
CMPQ %r10, %rbx
JL .L7
MOVQ $0, %rbx
JMP .L8
.L7:
MOVQ $1, %rbx
.L8:
CMP $0, %rbx
JE .L6
MOVQ -56(%rbp), %rbx
MOVQ $2, %r10
CMPQ %r10, %rbx
JE .L11
MOVQ $0, %rbx
JMP .L12
.L11:
MOVQ $1, %rbx
.L12:
CMP $0, %rbx
JE .L9
MOVQ -56(%rbp), %r10
MOVQ -64(%rbp), %r11
MOVQ %r11, %rax
IMULQ %r10
MOVQ %rax, %r10
MOVQ %r10, %rdi
CALL print_integer
.data
.L13:
.string "\n"
.text
MOVQ $.L13, %r10
MOVQ %r10, %rdi
CALL print_string
JMP .L10
.L9:
.L10:
MOVQ -64(%rbp), %rbx
INCQ -64(%rbp)
JMP .L5
.L6:
MOVQ -56(%rbp), %rbx
INCQ -56(%rbp)
JMP .L1
.L2:
ADDQ $16, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

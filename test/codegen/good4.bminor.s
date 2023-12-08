.file "test/codegen/good4.bminor.s"
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
MOVQ $1, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
CMPQ %r10, %rbx
JL .L1
MOVQ $0, %rbx
JMP .L2
.L1:
MOVQ $1, %rbx
.L2:
MOVQ %rbx, %rdi
CALL print_boolean
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
CMPQ %r10, %rbx
JLE .L3
MOVQ $0, %rbx
JMP .L4
.L3:
MOVQ $1, %rbx
.L4:
MOVQ %rbx, %rdi
CALL print_boolean
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
CMPQ %r10, %rbx
JE .L5
MOVQ $0, %rbx
JMP .L6
.L5:
MOVQ $1, %rbx
.L6:
MOVQ %rbx, %rdi
CALL print_boolean
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
CMPQ %r10, %rbx
JG .L7
MOVQ $0, %rbx
JMP .L8
.L7:
MOVQ $1, %rbx
.L8:
MOVQ %rbx, %rdi
CALL print_boolean
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
CMPQ %r10, %rbx
JGE .L9
MOVQ $0, %rbx
JMP .L10
.L9:
MOVQ $1, %rbx
.L10:
MOVQ %rbx, %rdi
CALL print_boolean
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
CMPQ %r10, %rbx
JE .L11
MOVQ $0, %rbx
JMP .L12
.L11:
MOVQ $1, %rbx
.L12:
CMPQ $1, %rbx
JE .L13
MOVQ $1, %rbx
JMP .L14
.L13:
MOVQ $0, %rbx
.L14:
MOVQ %rbx, %rdi
CALL print_boolean
ADDQ $16, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

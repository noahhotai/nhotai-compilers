.file "myprogram.s"
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
.data
.L1:
.string "ll"
.text
MOVQ $.L1, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
PUSHQ %rbx
.data
.L2:
.string "hello\n"
.text
MOVQ $.L2, %rbx
MOVQ %rbx, -56(%rbp)
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_string
ADDQ $16, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

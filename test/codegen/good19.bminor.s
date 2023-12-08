.file "test/codegen/good19.bminor.s"
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
MOVQ $1, %rbx
MOVQ $1, %r10
MOVQ $1, %r11
MOVQ $4, %r12
MOVQ $6, %r13
MOVQ %r12, %rax
CQO
IDIVQ %r13
MOVQ %rdx, %r12
MOVQ $5, %r13
MOVQ %r13, %rax
IMULQ %r12
MOVQ %rax, %r12
MOVQ $0, %r13
MOVQ $8, %r14
SUBQ %r14, %r13
ADDQ %r12, %r13
ADDQ %r11, %r13
ADDQ %r10, %r13
ADDQ %rbx, %r13
PUSHQ %r13
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
ADDQ $8, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

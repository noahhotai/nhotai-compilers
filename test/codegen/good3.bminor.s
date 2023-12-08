.file "test/codegen/good3.bminor.s"
.data
the_array: 
.quad 1, 2, 3
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
MOVQ %rbx, -56(%rbp)
.L1:
MOVQ -56(%rbp), %rbx
MOVQ $3, %r10
CMPQ %r10, %rbx
JL .L3
MOVQ $0, %rbx
JMP .L4
.L3:
MOVQ $1, %rbx
.L4:
CMP $0, %rbx
JE .L2
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
MOVQ -56(%rbp), %rbx
MOVQ $1, %r10
ADDQ %rbx, %r10
MOVQ %r10, -56(%rbp)
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

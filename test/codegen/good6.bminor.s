.file "test/codegen/good6.bminor.s"
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
MOVQ $1, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
INCQ -56(%rbp)
MOVQ %rbx, %rdi
CALL print_integer
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

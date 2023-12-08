.file "test/codegen/good5.bminor.s"
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
MOVQ $2, %rbx
PUSHQ %rbx
MOVQ $3, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
MOVQ -64(%rbp), %r10
MOVQ %rbx, %rdi
MOVQ %r10, %rsi
CALL integer_power
MOVQ %rax, %rbx
MOVQ %rbx, %rdi
CALL print_integer
ADDQ $16, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

.file "test/codegen/good0.bminor.s"
.data
denis: 
.string "9"
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
MOVQ $10, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
PUSHQ %rbx
MOVQ -64(%rbp), %rbx
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

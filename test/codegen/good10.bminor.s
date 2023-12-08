.file "test/codegen/good10.bminor.s"
.data
new2: 
.quad 0
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
MOVQ $5, %rbx
MOVQ $10, %r10
MOVQ $3, %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rdx, %r10
MOVQ %r10, %rax
IMULQ %rbx
MOVQ %rax, %rbx
MOVQ %rbx, %rdi
CALL print_integer
ADDQ $0, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

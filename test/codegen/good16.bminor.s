.file "test/codegen/good16.bminor.s"
.data
y: 
.quad 0
.data
x: 
.string ""
.data
a: 
.quad 0, 0, 0
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
.string "hello world\n"
.text
MOVQ $.L1, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
MOVQ %rbx, x
MOVQ x, %rbx
MOVQ %rbx, %rdi
CALL print_string
ADDQ $8, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

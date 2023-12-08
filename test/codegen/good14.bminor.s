.file "test/codegen/good14.bminor.s"
.data
y: 
.quad 0
.data
z: 
.quad 0
.data
x: 
.string ""
.data
a: 
.quad 0, 0, 0, 0, 0, 0
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
MOVQ y, %rbx
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

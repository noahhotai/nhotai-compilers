.file "test/codegen/good16.bminor.s"
.data
x: 
.string "hello world\n"
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
MOVQ $1, %rbx
MOVQ $1, %r10
MOVQ $1, %r11
MOVQ $1, %r12
MOVQ $1, %r13
ADDQ %r12, %r13
ADDQ %r11, %r13
ADDQ %r10, %r13
ADDQ %rbx, %r13
MOVQ %r13, %rdi
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

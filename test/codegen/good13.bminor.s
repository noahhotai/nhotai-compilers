.file "test/codegen/good13.bminor.s"
.data
chelsea: 
.quad 1, 2, 3
.data
the_string: 
.string "hello"
.data
new: 
.quad 15
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
MOVQ $10, %rbx
LEAQ chelsea, %r10
MOVQ $2, %r11
MOVQ $8, %rax
IMULQ %r11
MOVQ %rax, %r11
ADDQ %r11, %r10
MOVQ %rbx, (%r10)
MOVQ $9, %rbx
LEAQ chelsea, %r11
MOVQ $2, %r12
MOVQ $8, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r11
MOVQ %rbx, (%r11)
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

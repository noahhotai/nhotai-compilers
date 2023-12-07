.file "myprogram.s"
.data
denis: 
.string "9"
.text
.global printer
printer:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
PUSHQ %rdx
PUSHQ %rcx
PUSHQ %r8
PUSHQ %r9
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET
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
MOVQ $10, %r10
PUSHQ %r10
MOVQ $11, %r11
PUSHQ %r11
PUSHQ %r10
PUSHQ %r11
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
CALL (null)
POPQ %rbx
POPQ %r12
POPQ %r13
POPQ %r14
POPQ %r15
POPQ %r10
POPQ %r11
MOVQ %rax, %r12
POPQ %rdx
POPQ %rdx
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

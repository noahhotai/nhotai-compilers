.file "test/codegen/good1.bminor.s"
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
MOVQ -8(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L1:
.string " "
.text
MOVQ $.L1, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -16(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
.data
.L2:
.string "\n"
.text
MOVQ $.L2, %rbx
MOVQ %rbx, %rdi
CALL print_string
ADDQ $0, %rsp
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
MOVQ $1, %rbx
PUSHQ %rbx
MOVQ $2, %rbx
PUSHQ %rbx
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
MOVQ -64(%rbp), %rbx
MOVQ %rbx, %rsi
PUSHQ %r10
PUSHQ %r11
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
CALL printer
POPQ %rbx
POPQ %r12
POPQ %r13
POPQ %r14
POPQ %r15
POPQ %r10
POPQ %r11
MOVQ %rax, %rbx
ADDQ $16, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

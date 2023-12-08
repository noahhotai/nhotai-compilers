.file "test/codegen/good7.bminor.s"
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
.string "\n"
.text
MOVQ $.L1, %rbx
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
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
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
ADDQ $8, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

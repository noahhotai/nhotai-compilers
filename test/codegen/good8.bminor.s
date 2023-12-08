.file "test/codegen/good8.bminor.s"
.text
.global add_one1
add_one1:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
PUSHQ %rdx
PUSHQ %rcx
PUSHQ %r8
PUSHQ %r9
MOVQ $1, %rbx
MOVQ -8(%rbp), %r10
ADDQ %rbx, %r10
MOV %r10, %rax
ADDQ $0, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET
RET
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
.global add_one
add_one:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
PUSHQ %rdx
PUSHQ %rcx
PUSHQ %r8
PUSHQ %r9
MOVQ $1, %rbx
MOVQ -8(%rbp), %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
MOVQ -16(%rbp), %r11
MOVQ %r11, %rsi
PUSHQ %r10
PUSHQ %r11
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
CALL add_one1
POPQ %rbx
POPQ %r12
POPQ %r13
POPQ %r14
POPQ %r15
POPQ %r10
POPQ %r11
MOVQ %rax, %r11
ADDQ %r10, %r11
ADDQ %rbx, %r11
MOV %r11, %rax
ADDQ $0, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET
RET
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
MOVQ %rbx, %rdi
.data
.L1:
.string "hello\n"
.text
MOVQ $.L1, %rbx
MOVQ %rbx, %rsi
PUSHQ %r10
PUSHQ %r11
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
CALL add_one
POPQ %rbx
POPQ %r12
POPQ %r13
POPQ %r14
POPQ %r15
POPQ %r10
POPQ %r11
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

.file "test/codegen/good19.bminor.s"
.text
.global return_hello_world
return_hello_world:
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
MOV %rbx, %rax
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
PUSHQ %r10
PUSHQ %r11
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
CALL return_hello_world
POPQ %rbx
POPQ %r12
POPQ %r13
POPQ %r14
POPQ %r15
POPQ %r10
POPQ %r11
MOVQ %rax, %rbx
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

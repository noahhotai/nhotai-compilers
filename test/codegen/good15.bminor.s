.file "test/codegen/good15.bminor.s"
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
MOVQ $0, %rbx
CMP $0, %rbx
JE .L1
MOVQ $0, %r10
MOVQ %r10, %rdi
CALL print_integer
JMP .L2
.L1:
MOVQ $1, %r10
CMP $0, %r10
JE .L3
MOVQ $1, %r11
MOVQ %r11, %rdi
CALL print_integer
JMP .L4
.L3:
MOVQ $0, %r11
MOVQ %r11, %rdi
CALL print_integer
.L4:
.L2:
ADDQ $0, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

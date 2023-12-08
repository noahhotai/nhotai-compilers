.file "test/codegen/good12.bminor.s"
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
MOVQ $1, %rbx
MOVQ $1, %r10
ANDQ %rbx, %r10
MOVQ $0, %rbx
ANDQ %r10, %rbx
MOVQ $1, %r10
ANDQ %rbx, %r10
CMP $0, %r10
JE .L1
.data
.L3:
.string "and doesn't\n"
.text
MOVQ $.L3, %rbx
MOVQ %rbx, %rdi
CALL print_string
JMP .L2
.L1:
MOVQ $1, %rbx
MOVQ $1, %r11
ANDQ %rbx, %r11
MOVQ $1, %rbx
ANDQ %r11, %rbx
MOVQ $1, %r11
ANDQ %rbx, %r11
CMP $0, %r11
JE .L4
.data
.L6:
.string "works\n"
.text
MOVQ $.L6, %rbx
MOVQ %rbx, %rdi
CALL print_string
JMP .L5
.L4:
.L5:
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

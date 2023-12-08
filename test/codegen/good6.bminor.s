.file "test/codegen/good6.bminor.s"
.data
the_array: 
.quad 1, 2, 3
.data
the_string: 
.string "the_string\n"
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
MOVQ the_string, %rbx
PUSHQ %rbx
MOVQ the_string, %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ -56(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_string
MOVQ $1, %rbx
PUSHQ %rbx
MOVQ -64(%rbp), %rbx
INCQ -64(%rbp)
MOVQ %rbx, %rdi
CALL print_integer
MOVQ -64(%rbp), %rbx
MOVQ %rbx, %rdi
CALL print_integer
ADDQ $16, %rsp
POPQ %r9
POPQ %r8
POPQ %rcx
POPQ %rdx
POPQ %rsi
POPQ %rdi
POPQ %rbp
RET

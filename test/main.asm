	.file	"main.c"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	.L.str(%rip), %rax
	leaq	.L__func__.main(%rip), %rcx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, %rdi
	movq	%rcx, %rsi
	movb	$0, %al
	callq	printf@PLT
	movl	$0, %edx
	movl	%eax, -20(%rbp)         # 4-byte Spill
	movl	%edx, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp5:
	.size	main, .Ltmp5-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "%s\n"
	.size	.L.str, 4

	.type	.L__func__.main,@object # @__func__.main
.L__func__.main:
	.asciz	 "main"
	.size	.L__func__.main, 5


	.section	".note.GNU-stack","",@progbits

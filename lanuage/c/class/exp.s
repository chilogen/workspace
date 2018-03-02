	.file	"exp.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN3abcC2Ei,"axG",@progbits,_ZN3abcC5Ei,comdat
	.align 2
	.weak	_ZN3abcC2Ei
	.type	_ZN3abcC2Ei, @function
_ZN3abcC2Ei:
.LFB1459:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1459:
	.size	_ZN3abcC2Ei, .-_ZN3abcC2Ei
	.weak	_ZN3abcC1Ei
	.set	_ZN3abcC1Ei,_ZN3abcC2Ei
	.section	.text._ZN3abcC2ERS_,"axG",@progbits,_ZN3abcC5ERS_,comdat
	.align 2
	.weak	_ZN3abcC2ERS_
	.type	_ZN3abcC2ERS_, @function
_ZN3abcC2ERS_:
.LFB1462:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1462:
	.size	_ZN3abcC2ERS_, .-_ZN3abcC2ERS_
	.weak	_ZN3abcC1ERS_
	.set	_ZN3abcC1ERS_,_ZN3abcC2ERS_
	.section	.text._ZN3abcD2Ev,"axG",@progbits,_ZN3abcD5Ev,comdat
	.align 2
	.weak	_ZN3abcD2Ev
	.type	_ZN3abcD2Ev, @function
_ZN3abcD2Ev:
.LFB1465:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1465
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEPKv@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1465:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN3abcD2Ev,"aG",@progbits,_ZN3abcD5Ev,comdat
.LLSDA1465:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1465-.LLSDACSB1465
.LLSDACSB1465:
.LLSDACSE1465:
	.section	.text._ZN3abcD2Ev,"axG",@progbits,_ZN3abcD5Ev,comdat
	.size	_ZN3abcD2Ev, .-_ZN3abcD2Ev
	.weak	_ZN3abcD1Ev
	.set	_ZN3abcD1Ev,_ZN3abcD2Ev
	.text
	.globl	_Z3fun3abc
	.type	_Z3fun3abc, @function
_Z3fun3abc:
.LFB1467:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN3abcC1ERS_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1467:
	.size	_Z3fun3abc, .-_Z3fun3abc
	.globl	main
	.type	main, @function
main:
.LFB1468:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-36(%rbp), %rax
	movl	$2, %esi
	movq	%rax, %rdi
	call	_ZN3abcC1Ei
	leaq	-36(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN3abcC1ERS_
	leaq	-28(%rbp), %rax
	leaq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z3fun3abc
	leaq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3abcD1Ev
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3abcD1Ev
	movl	$0, %ebx
	leaq	-36(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3abcD1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1468:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1905:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L11
	cmpl	$65535, -8(%rbp)
	jne	.L11
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L11:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1905:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3fun3abc, @function
_GLOBAL__sub_I__Z3fun3abc:
.LFB1906:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1906:
	.size	_GLOBAL__sub_I__Z3fun3abc, .-_GLOBAL__sub_I__Z3fun3abc
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3fun3abc
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits

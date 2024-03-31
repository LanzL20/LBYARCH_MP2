section .data
msg1 db "Float = %lf",10,0
temp dq 0.0

section .text
bits 64

default rel		

extern printf

global Compute
Compute:
	push rbp
	mov rbp, rsp
	add rbp, 16
	mov r10, qword [rbp + 32]

	; X Y Z A i: rcx rdx r8 r9 r10
	; xmm0 is temp sum.
	; r11 is loop counter.
	; xmm1 contains A (deferenced).
	mov r11, 0
	movsd xmm1, [r9]

loopstart:
	movsd xmm0, [rcx + r11 * 8]
	vmulsd xmm0, xmm0, xmm1
	vaddsd xmm0, xmm0, [rdx + r11 * 8]
	movsd [r8 + r11 * 8], xmm0

	inc r11
	cmp r11, r10
	jnz loopstart

	pop rbp
	ret
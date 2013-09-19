.text
.global _start

_start:
	mov r0, #10
	sub sp, sp, #4
	str lr, [sp]
	bl f
	ldr lr, [sp]
	add sp, sp, #4
	b stop

f:
	cmp r0, #0
	moveq r3, #0
	moveq pc, lr
	cmp r0, #1
	moveq r3, #1
	moveq pc, lr
	sub r0, r0, #1
	mov r4, r0
	sub sp, sp, #8
	str lr, [sp]
	str r4, [sp, #4]
	bl f
	ldr lr, [sp]
	ldr r4, [sp, #4]
	add sp, sp, #8
	mov r5, r3
	sub r4, r4, #1
	mov r0, r4
	stmfd sp!, {r4, r5, lr}
	bl f
	ldmfd sp!, {r4, r5, lr}
	add r3, r3, r5
	mov pc, lr

stop:
	mov r0, #0
	mov r7, #1
	svc 0x00000000

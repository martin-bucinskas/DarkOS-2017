[bits 16]

check_a20:
	pushf
	push ds
	push es
	push di
	push si

	cli

	xor ax, ax
	mov es, ax

	not ax
	mov ds, ax

	mov di, 0x0500
	mov si, 0x0510

	mov al, byte [es:di]
	push ax

	mov al, byte [ds:si]
	push ax

	mov byte [es:di], 0x00
	mov byte [ds:si], 0xFF

	cmp byte [es:di], 0xFF
	
	pop ax
	mov byte [ds:si], al

	pop ax
	mov byte [es:di], al

	mox ax, 0
	je check_a20_exit

	mov ax, 1

check_a20_exit:
	pop si
	pop di
	pop es
	pop ds
	popf

	ret

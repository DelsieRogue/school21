				global _ft_strcmp

				section .text
_ft_strcmp:
				xor r10, r10
				xor rax, rax
				xor rcx, rcx
_loop:
				mov al, byte[rdi + r10]
				mov cl, byte[rsi + r10]

				cmp al, 0
				je _ret
				cmp cl, 0
				je _ret
				cmp al, cl

				jne _ret

				inc r10

				jmp _loop
_ret:
				sub rax, rcx
				ret

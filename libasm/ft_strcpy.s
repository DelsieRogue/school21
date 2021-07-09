				global _ft_strcpy

				section .text
_ft_strcpy:
				xor r10, r10
_copy:
				mov bl, byte[rsi + r10]
				mov byte[rdi + r10], bl
				cmp byte[rsi + r10], 0
					je _exit_prog
				inc r10
				jmp _copy
_exit_prog:
				mov rax, rdi
				ret

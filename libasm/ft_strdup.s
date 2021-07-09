				global _ft_strdup
				extern _ft_strlen
				extern _ft_strcpy
				extern _malloc

				section .text
_ft_strdup:
				test rdi, rdi
				jz _error
				push rdi
				call _ft_strlen; в rax я записал длину строки
				mov	rdi, rax; записываю в rdi записываю скока надо выделить
				call _malloc; выделяю в eax записываю указатель
				test rax, rax
				jz _error
				mov rdi, rax
				pop rsi
				call _ft_strcpy
				ret
_error:
				mov eax, 0
				ret

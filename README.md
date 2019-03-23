# ft_printf
project for 42 : recode function printf


## Sources
http://manpagesfr.free.fr/man/man3/printf.3.html  
https://www.supinfo.com/articles/single/5994-dessous-printf  
https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2017  

## librairie stdarg
Cette librairie permet l'utilisation d'un nombre d'arguments inconnus dans une fonction.
Per;ettant ainsi de faire une fonction que l'on appelle variadique.

## librairie stdint.h
Permet l'utilisation de `intmax_t` et `uintmax_t` pour une meilleure portabilitee du projet, car s'adaptera a n'importe quelle machine.


## /!\ Probleme a resoudre!
```
➜  ft_printf git:(master) ✗ ./a.out "|%020.d|"
vrai printf:
|               12345|
faux printf:
|12345|%
ft_printf git:(master) ✗ ./a.out "|%20.d|"
vrai printf:
|               12345|
faux printf:
|               12345|%
ft_printf git:(master) ✗
```


put_f
	ft_is_special
		ft_ldbl_2_str
			meganbr_be_str
				ullong_to_str	|	32
		int_len					|	37 37
		rounding				|	81
			round_check			|||	41 51 59
	print_precision
		ft_putchar_fd
			write				||	

Vive le `valgrind --track-origins=yes ./a.out`!!!
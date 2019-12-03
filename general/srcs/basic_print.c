//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"


void	ft_print_s(t_spec* spec, va_list args)
{
	ft_putstr(va_arg(args, char *));
}

void	ft_print_d(t_spec *spec, va_list args)
{
	char 		buffer[MAX_LL_BUFF_SIZE];

	ft_bzero(buffer, MAX_LL_BUFF_SIZE);
	get_sd(args, spec, buffer);
	ft_put_sd_buf(buffer, spec);
}




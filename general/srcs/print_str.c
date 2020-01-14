//
// Created by dan on 1/14/20.
//

#include "print_str.h"

int fill_str_field(const char *str, t_spec *spec)
{
	int count;
	int i;

	if (spec->precision.value == -1)
		i = ft_strlen(str);
	else
	{
		i = spec->precision.value;
		if (ft_strlen(str) == 0)
			i = 0;
	}
	count = i;
	while (i < spec->width.value)
	{
		ft_putchar(' ');
		i++;
	}
	return (i - count);
}


int		print_str(char *str, t_spec *spec)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (spec->flags['-'] == FALSE)
		i += fill_str_field(str, spec);
	if (spec->precision.value == -1)
	{
		ft_putstr(str);
		i +=ft_strlen(str);
	}
	else
	{
		while (j < spec->precision.value && j < (int)ft_strlen(str))
		{
			ft_putchar(str[j++]);
			i++;
		}
	}
	if (spec->flags['-'] == TRUE)
		i += fill_str_field(str, spec);
	return (i);
}

int		ft_print_s(t_spec* spec, va_list *args) {
	char *tmp;

	if (spec->size.id == -1)
	{
		tmp = va_arg(*args, char *);
		return (print_str(tmp, spec));
	} else if (spec->size.value[0] == 'l')
		return (ft_print_ws(spec, args));
	return (0);
}
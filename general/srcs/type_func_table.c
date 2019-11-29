//
// Created by Aletha Yellin on 20/11/2019.
//

#include "ft_printf.h"
#include <stdlib.h>

#define MAX_TYPE_FUNC_TABLE 255

static int g_was_table_init = 0;

void 	(*g_type_func_table[MAX_TYPE_FUNC_TABLE])(const char *, va_list);

int 	init_func_table()
{
	if (g_was_table_init)
		return (0);
	g_was_table_init = 1;
	g_type_func_table[0] = ft_print_empty;
	g_type_func_table['s'] = ft_print_s;
	g_type_func_table['d'] = ft_print_d;
	g_type_func_table['%'] = ft_print_percent;
	g_type_func_table['x'] = ft_print_x;
	/*
	g_type_func_table['i'] = ft_print_i;
	g_type_func_table['o'] = ft_print_o;
	g_type_func_table['u'] = ft_print_u;

	g_type_func_table['X'] = ft_print_X;
	g_type_func_table['n'] = ft_print_n;
	g_type_func_table['a'] = ft_print_A;
	g_type_func_table['e'] = ft_print_e;
	g_type_func_table['E'] = ft_print_E;
	g_type_func_table['f'] = ft_print_f;
	g_type_func_table['F'] = ft_print_f;
	g_type_func_table['g'] = ft_print_g;
	g_type_func_table['G'] = ft_print_g;
	g_type_func_table['c'] = ft_print_c;
	 */
	return (1);
}

int		get_type_func_id(const char *fmt)
{
	t_pair	*p;
	int		func_id;

	if((p = ft_strfind(fmt, g_type_specs)))
	{
		func_id = fmt[p->x];
		free(p);
		return (func_id);
	}
	return (0);
}
void	call_print_func(const char *format, va_list args, int offset)
{
	int id;

	init_func_table();
	id  = get_type_func_id(format + offset + 1);
	g_type_func_table[id](format + offset + 1, args);
}




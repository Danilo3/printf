//
// Created by Aletha Yellin on 20/11/2019.
//

#include "type_func_table.h"

#define MAX_TYPE_FUNC_TABLE 255

static int g_was_table_init = 0;

int 	(*g_type_func_table[MAX_TYPE_FUNC_TABLE])(t_spec *, va_list*);

int 	init_type_func_table()
{
	if (g_was_table_init)
		return (0);
	g_was_table_init = 1;
	g_type_func_table[0] = ft_print_empty;
	g_type_func_table['s'] = ft_print_s;
	g_type_func_table['d'] = ft_print_d;
	g_type_func_table['%'] = ft_print_percent;
	g_type_func_table['x'] = ft_print_x;
	g_type_func_table['o'] = ft_print_o;
	g_type_func_table['i'] = ft_print_d;
	g_type_func_table['X'] = ft_print_X;
	g_type_func_table['u'] = ft_print_u;
	g_type_func_table['c'] = ft_print_c;
    g_type_func_table['p'] = ft_print_p;
	g_type_func_table['f'] = ft_print_f;
    g_type_func_table['q'] = ft_print_color;
	g_type_func_table['a'] = ft_print_f;
	g_type_func_table['e'] = ft_print_e;
	g_type_func_table['E'] = ft_print_E;
	g_type_func_table['f'] = ft_print_f;
	g_type_func_table['F'] = ft_print_f;
	g_type_func_table['g'] = ft_print_f;
	g_type_func_table['G'] = ft_print_f;
    g_type_func_table['D'] = ft_print_D;
    return (1);

}

int	call_print_func(const char *format, va_list *vargs, int offset)
{
	int		id;
	t_spec	*spec;
	int		count;

	init_type_func_table();
	if (*(format + offset + 1) != '\0')
	{
        spec = parse_spec_format(format + offset + 1);
        fill_spec_from_vargs(spec, vargs);
        id = spec->type == -1 ? 0 : spec->type;
    }
	else
        return (0);
	count = g_type_func_table[id](spec, vargs);
	free(spec);
	return (count);
}




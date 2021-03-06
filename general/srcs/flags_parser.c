//
// Created by Aletha Yellin on 22/11/2019.
//

#include "flags_parse.h"

int is_flag(char c)
{
	return (ft_strchr(FT_PRINTF_FLAGS, c) != NULL);
}

//TODO: if flags are repeated?
int parse_flags(const char *format, t_spec *spec)
{
	size_t i;

	i = 0;
	while (is_flag(format[i]))
		spec->flags[(int)format[i++]] = TRUE;
	return (i);
}
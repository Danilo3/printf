//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_TYPE_FUNC_TABLE_H
#define PRINTF_TYPE_FUNC_TABLE_H

void	call_print_func(const char *format, va_list args, int offset);

int 	init_func_table();

int		get_type_func_id(const char *fmt);

#endif //PRINTF_TYPE_FUNC_TABLE_H

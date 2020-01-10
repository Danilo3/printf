//
// Created by Aletha Yellin on 20/11/2019.
//

#ifndef PRINTF_TYPE_FUNC_TABLE_H
#define PRINTF_TYPE_FUNC_TABLE_H

#include <stdarg.h>
#include "print_oct.h"
#include "print_hex.h"
#include "common_print.h"
#include "additional_print.h"
#include "print_ud.h"
#include "specificator.h"
#include "spec_format_parser.h"
#include "basic_print.h"
#include "float_print.h"

int		call_print_func(const char *format, va_list *args, int offset);

#endif //PRINTF_TYPE_FUNC_TABLE_H

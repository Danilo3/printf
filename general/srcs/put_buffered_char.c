//
// Created by Aletha Yellin on 17/01/2020.
//

#define MAX_OUTPUT_BUFF_SIZE 100

#include "put_bch.h"
#include <unistd.h>

static int g_was_init;

char g_printf_buffer[MAX_OUTPUT_BUFF_SIZE];

static int g_buf_size;

int flush_buffer()
{
    int count;

    count = write(1, g_printf_buffer, g_buf_size);
    g_was_init = 0;
    g_buf_size = 0;
    return (count);
}

void    init()
{
    ft_bzero(g_printf_buffer, MAX_OUTPUT_BUFF_SIZE);
    g_was_init = 1;
}

int     put_bch(char ch)
{
    int count;

    count = 1;
    if (!g_was_init)
        init();
    if (g_buf_size < MAX_OUTPUT_BUFF_SIZE)
        g_printf_buffer[g_buf_size++] = ch;
    else
        count = flush_buffer();
    return (count);
}
//
// Created by dan on 1/14/20.
//

#include "minunit.h"
#include "ft_printf.h"

static char * wp_flag_str_test(void)
{
	mu_assert_printf("precision test", ft_printf, "%-0.5s world", "hello");
	mu_assert_printf("width test", ft_printf, "%-5s world", "hello");
	mu_assert_printf("width and precision test", ft_printf, "%-10.5s world", "hello");
	mu_assert_printf("width and precision test 2", ft_printf, "%-5.10s world", "hello");
	mu_assert_printf("width and precision test", ft_printf, "%-3.2s world", "hello");
	mu_assert_printf("width and precision test 2", ft_printf, "%-2.3s world", "hello");

	return (0);
}

static char *empty_str_test(void)
{
	mu_assert_printf("empty str", ft_printf, "*%10s*", "");
	mu_assert_printf("empty str precision", ft_printf, "*%.5s*", "");
	return (0);
}

static char *empty_wp_str_test(void)
{
	mu_assert_printf("empty precision < width", ft_printf, "%3.2s=(empty)", "");
	return (0);
}

static char *mouli_test(void)
{
    mu_assert_printf("test_precision_s_higher_min_width", ft_printf, "%5.4s", "42");
    mu_assert_printf("test_precision_s_implicit_precision", ft_printf, "%4.s", "42");
    return (0);
}

int main()
{
	test_all("NORMAL STR PRINTF TESTS", 4, empty_wp_str_test, wp_flag_str_test, empty_str_test, mouli_test);
	return (0);
}
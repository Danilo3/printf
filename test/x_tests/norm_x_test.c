//
// Created by dan on 1/13/20.
//

#include "minunit.h"
#include "ft_printf.h"

static char *simple_test()
{
	mu_assert_printf("test1", ft_printf, "%#x", 123);
	mu_assert_printf("test2", ft_printf, "%#llx", 1234);
	return (0);
}

static char *simple_neg_test()
{
	mu_assert_printf("test1", ft_printf, "%#x", -42);
	mu_assert_printf("test2", ft_printf, "%#llx", -42);
	return (0);
}

static char *zero_test()
{
	mu_assert_printf("test1", ft_printf, "%.x", 0);
	mu_assert_printf("test2", ft_printf, "%#.0x", 0);
	return (0);
}

static char *width_test()
{
	mu_assert_printf("test1", ft_printf, "%10x", 123);
	mu_assert_printf("test2", ft_printf, "%010x", 123);
	mu_assert_printf("test3", ft_printf, "%#10x", 123);
	return (0);
}

static char *checker_test()
{
	mu_assert_printf("fill zero", ft_printf, "%010x", 542);
	mu_assert_printf("fill zero after prefix", ft_printf, "%#08x", 42);
	return (0);
}

static char *neg_flag_test()
{
	mu_assert_printf("negative and flag", ft_printf, "%+#x", -42);
	return (0);
}

int main()
{
	test_all("NORM X", 6, simple_test, simple_neg_test, zero_test, width_test, checker_test, neg_flag_test);
	return (0);
}

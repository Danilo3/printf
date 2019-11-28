//
// Created by Aletha Yellin on 28/11/2019.
//

#include "libft.h"
#include <limits.h>

#define LONG_LONG_MAX_DIGITS (sizeof(long long) * 8 + 1)

typedef struct s_lldiv
{
	long long qout;
	long long rem;

}				t_lldiv;

static t_lldiv ll_div(long long value, int base)
{
	t_lldiv r;

	r.qout = (value) / base;
	r.rem  = (value) % base;
	return (r);
}

static char	ft_convert(long long *ll, int base)
{
	t_lldiv r;
	char ch;

	r = ll_div(*ll, base);
	*ll = r.qout;
	ch = (char)(r.rem + ((9L < r.rem) ? ('A' - 10L) : '0'));
	return (ch);
}

static int	ft_is_border(long long *value, int *is_neg, char *str)
{
	if (*value == 0)
	{
		ft_strcpy(str, "0");
		return (1);
	}
	if (*value < 0)
	{
		*is_neg = 1;
		if (*value == LONG_LONG_MIN)
		{
			ft_strcpy(str, FT_LONG_LONG_MIN_STR);
			return (1);
		}
		*value = -(*value);
	}
	return (0);
}

char	*ft_lltoa(long long ll, char *str, int base)
{
	int is_neg;
	int i;

	is_neg = 0;
	i = 0;
	if (!str)
		str = ft_strnew(LONG_LONG_MAX_DIGITS);
	if (36 < base || 2 > base)
		base = 10;
	if (ft_is_border(&ll, &is_neg, str))
		return (str);
	while (ll)
		str[i++] = ft_convert(&ll, base);
	if (is_neg)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
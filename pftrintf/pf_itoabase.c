#include "ft_printf.h"

static long double	pf_powun(int nbr, int pow)
{
	long double	res;

	res = 1;
	while (pow-- >= 1)
		res *= nbr;
	return (res);
}

char						*pf_itoabase(signed long long int i, int base)
{
	char	*str;
	int		j;
	int 	minus;

	j = 1;
	minus = 0;
	if (i == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	if (i < 0)
	{
		minus = 1;
		i *= -1;
	}
	while (pf_powun(base, j) - 1 < i)
		j++;
	str = (char*)malloc(sizeof(char) * j + minus + 1);
	*(str + j + minus) = '\0';
	while (j-- > 0)
	{
		*(str + j + minus) = (i % base) + (i % base > 9 ? 'a' - 10 : '0');
		i /= base;
	}
	minus == 1 ? *str = '-' : 0;
	return (str);
}

char						*pf_itoabaseun(unsigned long long int i, int base)
{
	char	*str;
	int		j;

	j = 1;
	while (pf_powun(base, j) - 1 < i)
		j++;
	str = (char*)malloc(sizeof(char) * j + 1);
	*(str + j) = '\0';
	while (j-- > 0)
	{
		*(str + j) = (i % base) + (i % base > 9 ? 'a' - 10 : '0');
		i /= base;
	}
	return (str);
}
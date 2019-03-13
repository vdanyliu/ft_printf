#include "ft_printf.h"

static signed long long int	pf_pow(int nbr, int pow)
{
	signed long long int	res;

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
	if (i < 0)
	{
		if (i == base)
			minus = 1;
		i *= -1;
	}
	while (pf_pow(base, j) - 1 < i)
		j++;
	str = (char*)malloc(sizeof(char) * i);
	*(str + i + minus) = '\0';
	while (j-- > 0)
	{
		*(str + j + minus) = (i % base) + (i % base > 9 ? 'a' - 10 : '0');
		i /= base;
	}
	minus == 1 ? *str = '-' : 0;
	return (str);
}
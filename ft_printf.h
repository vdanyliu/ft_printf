//
// Created by Volodymyr DANYLIUK on 2019-02-06.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct			s_flag
{
	char 				minus;
	char				plus;
	char				space;
	char 				hesh;
	char				zero;
}						t_flag;

typedef struct			s_width
{
	int 				width;
	char 				star;
}						t_width;

typedef struct			s_accuracy
{
	int 				number;
	char 				star;
}						t_accuracy;

typedef struct			s_specifier
{
	int 				specifier;
}						t_specifier;

typedef struct			s_type
{
	int 				type;
	struct s_specifier	*spec;
	struct s_accuracy	*accur;
	struct s_width		*width;
	struct s_flag		*flag;
	struct s_type		*next;
}						t_type;

#endif

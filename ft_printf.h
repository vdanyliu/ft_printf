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
	int					spec;
	struct s_accuracy	*accur;
	struct s_width		*width;
	struct s_flag		*flag;
	struct s_type		*next;
}						t_type;

int						g_len;
int						pf_any_procent(char *str);
void					pf_type_initiation(t_type **head, char *format);
t_type					*pf_create_type_lst();
void					pf_type_deafult_flags(t_type *buff, char *str);
void					pf_type_cs_flags(t_type *curr, char *str);
void					pf_type_diouxX_flags(t_type *curr, char *str);
int 					pf_is_type(char c);
void 					pf_write_and_remalloc(char **str);
void 					pf_skip_flag_remalloc(char **str);
void					pf_write_flag(va_list ptr, t_type **lst);
void					ft_free_t_type(t_type *head);
int						pf_type_group(int c);
void					pf_print_procent(t_type *buff);
char 					*pf_spaces(t_type *buff, int i);
char 					*pf_union(t_type *buff, char *str1, char *str2);

#endif

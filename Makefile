# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 13:26:03 by vdanyliu          #+#    #+#              #
#    Updated: 2018/08/20 13:46:01 by vdanyliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SOURCE = pf_flag_lst_create.c\
	pf_writer.c\
	pf_validator_part_1.c\
	pf_main.c\
	pf_initiation_part_1.c\
	pf_flags_parcer.c\
	free.c\
	pf_itoabase.c\
	pf_print_part_one.c\
			 

HEADER = ft_printf.h

LIB = pf_flag_lst_create.a\
	pf_writer.a\
	pf_validator_part_1.a\
	pf_main.a\
	pf_initiation_part_1.a\
	pf_flags_parcer.a\
	free.a\
	pf_itoabase.a\
	pf_print_part_one.a\
	  

all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c -lft -L /libft $(SOURCE)
	@ar rc $(NAME) $(LIB)

clean:
	@/bin/rm -f $(LIB)
	@make -C libft/ clean


fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean


re: fclean all


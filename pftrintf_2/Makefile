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

NAME = libftprintf.a

SRC =	src/pf_flag_lst_create.c\
	src/pf_writer.c\
	src/pf_validator_part_1.c\
	src/pf_main.c\
	src/pf_initiation_part_1.c\
	src/pf_flags_parcer.c\
	src/pf_print_csp%.c\
	src/pf_print_csp%.c\
	src/pf_fix.c\
	src/pf_print_part_two.c\
	src/ft_atoi.c\
	src/ft_lstdelone.c\
	src/ft_putchar_fd.c\
	src/ft_strdup.c\
	src/ft_strnew.c\
	src/ft_bzero.c\
	src/ft_lstiter.c\
	src/ft_putendl.c\
	src/ft_strequ.c\
	src/ft_strnstr.c\
	src/ft_charcount.c\
	src/ft_lstmap.c\
	src/ft_putendl_fd.c\
	src/ft_striter.c\
	src/ft_strrchr.c\
	src/ft_isalnum.c\
	src/ft_lstnew.c\
	src/ft_putnbr.c\
	src/ft_striteri.c\
	src/ft_strrev.c\
	src/ft_isalpha.c\
	src/ft_memalloc.c\
	src/ft_putnbr_fd.c\
	src/ft_strjoin.c\
	src/ft_strsplit.c\
	src/ft_isascii.c\
	src/ft_memccpy.c\
	src/ft_putstr.c\
	src/ft_strlcat.c\
	src/ft_strstr.c\
	src/ft_isdigit.c\
	src/ft_memchr.c\
	src/ft_putstr_fd.c\
	src/ft_strlen.c\
	src/ft_strsub.c\
	src/ft_islower.c\
	src/ft_memcmp.c\
	src/ft_strcat.c\
	src/ft_strmap.c\
	src/ft_strtrim.c\
	src/ft_isprint.c\
	src/ft_memcpy.c\
	src/ft_strchr.c\
	src/ft_strmapi.c\
	src/ft_tolower.c\
	src/ft_isupper.c\
	src/ft_memdel.c\
	src/ft_strclr.c\
	src/ft_strncat.c\
	src/ft_toupper.c\
	src/ft_itoa.c\
	src/ft_memmove.c\
	src/ft_strcmp.c\
	src/ft_strncmp.c\
	src/ft_lstadd.c\
	src/ft_memset.c\
	src/ft_strcpy.c\
	src/ft_strncpy.c\
	src/ft_lstdel.c\
	src/ft_putchar.c\
	src/ft_strdel.c\
	src/ft_strnequ.c\
	src/ft_isspace.c\
	src/get_next_line.c\
	src/pf_itoabase.c\
	src/free.c\
	src/pf_fix_part_two.c
	  
OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc -c $< -o $@
	@printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	@/bin/rm -rf obj/
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:34:14 by jbashiri          #+#    #+#              #
#    Updated: 2019/06/05 13:03:02 by sbruen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIBFT =		ft_atoi.c\
				ft_atoi_error.c\
				ft_bzero.c\
				ft_copyuntil.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_power.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strjoinch.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_swap.c\
				get_next_line.c
SRC_PRINTF =	analise.c\
				analise_char.c\
				analise_float_and_l.c\
				analise_float_upl.c\
				analise_h_hh_unsigned_integer.c\
				analise_h_hh_upx.c\
				analise_h_hh_x.c\
				analise_h_o.c\
				analise_hh_o.c\
				analise_j.c\
				analise_l_ll_u.c\
				analise_l_ll_upx.c\
				analise_l_ll_x.c\
				analise_l_o.c\
				analise_ll_o.c\
				analise_pointer.c\
				analise_procent.c\
				analise_str.c\
				analise_three.c\
				analise_two.c\
				analise_u.c\
				analise_upx.c\
				analise_x.c\
				analyse_integer.c\
				analyse_o.c\
				check_flags_di.c\
				check_flags_upxxuo.c\
				check_flags_upxxuo2.c\
				create_struct.c\
				float_help.c\
				float_help_part_two.c\
				float_help_part_two_upl.c\
				float_help_upl.c\
				ft_litoa.c\
				ft_llitoa.c\
				ft_printf.c\
				ft_printf_three.c\
				ft_printf_two.c\
				ft_width_for_int.c\
				new.c\
				print_null_i.c\
				print_pointer.c\
				print_string.c
SRC = 			algoritm.c\
                algoritm_two.c\
                functions_add.c\
                functions_addlink.c\
                functions_ants.c\
                functions_ants_two.c\
                functions_check.c\
                functions_check_three.c\
                functions_check_two.c\
                functions_help.c\
                functions_help_two.c\
                functions_malloc.c\
                functions_malloc_three.c\
                functions_malloc_two.c\
                functions_path.c\
                functions_restart.c\
                functions_sort.c\
				functions_help_three.c\
				main.c
INCLUDE = 		-Ilibftprintf\
			   	-Ilibftprintf/libft
HEAD =			lemin.h
DIR_LIBFT = 	libftprintf/libft/
DIR_PRINTF =	libftprintf/
LIBFT_PRINTF =	libftprintf.a
LEM-IN =        lem-in
FLAGS =			-Wall -Wextra -Werror
CC =			gcc
PSRC_LIBFT = $(addprefix $(DIR_LIBFT), $(SRC_LIBFT))
PSRC_PRINTF = $(addprefix $(DIR_PRINTF), $(SRC_PRINTF))
OBJ_PRINTF = $(PSRC_PRINTF:.c=.o) $(PSRC_LIBFT:.c=.o)
OBJ_SRC = $(SRC:.c=.o)

all: $(LEM-IN)

$(LEM-IN): $(LIBFT_PRINTF) $(OBJ_SRC)
	@$(CC) $(FLAGS) $(OBJ_SRC) $(LIBFT_PRINTF) $(INCLUDE) -o $(LEM-IN)
	echo "lem-in compiled"

$(LIBFT_PRINTF): $(OBJ_PRINTF)
	@ar rc $(LIBFT_PRINTF) $(OBJ_PRINTF)
	@ranlib $(LIBFT_PRINTF)
	echo "libftprintf.a compiled"

.c.o:
	@$(CC) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ_PRINTF)
	@/bin/rm -f $(LIBFT_PRINTF)
	@/bin/rm -f $(OBJ_SRC)

fclean: clean
	@/bin/rm -f $(LIBFT_PRINTF)
	@/bin/rm -f $(LEM-IN)

re: fclean all

.PHONY: clean fclean all re LEM-IN

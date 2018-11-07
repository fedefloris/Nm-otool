# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 18:51:44 by jwong             #+#    #+#              #
#    Updated: 2018/03/22 11:54:47 by jwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SOURCES 	= ft_memset.c		\
			  ft_bzero.c 		\
			  ft_memcpy.c 		\
			  ft_memccpy.c 		\
			  ft_memmove.c 		\
			  ft_memchr.c 		\
			  ft_memcmp.c		\
			  ft_strlen.c		\
			  ft_strdup.c		\
			  ft_strcpy.c		\
			  ft_strncpy.c		\
			  ft_strcat.c		\
			  ft_strncat.c		\
			  ft_strlcat.c		\
			  ft_strchr.c		\
			  ft_strrchr.c		\
			  ft_strstr.c		\
			  ft_strnstr.c		\
			  ft_strcmp.c		\
			  ft_strncmp.c		\
			  ft_atoi.c			\
			  ft_isalpha.c		\
			  ft_isdigit.c		\
			  ft_isalnum.c		\
			  ft_isascii.c		\
			  ft_isprint.c		\
			  ft_toupper.c		\
			  ft_tolower.c		\
			  ft_memalloc.c		\
			  ft_memdel.c		\
			  ft_strnew.c		\
			  ft_strdel.c		\
			  ft_strclr.c		\
			  ft_striter.c		\
			  ft_striteri.c		\
			  ft_strmap.c		\
			  ft_strmapi.c		\
			  ft_strequ.c		\
			  ft_strnequ.c		\
			  ft_strsub.c		\
			  ft_strjoin.c		\
			  ft_strtrim.c		\
			  ft_strsplit.c		\
			  ft_itoa.c			\
			  ft_putchar.c		\
			  ft_putstr.c		\
			  ft_putendl.c		\
			  ft_putnbr.c		\
			  ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c	\
			  ft_lstnew.c		\
			  ft_lstdelone.c	\
			  ft_lstdel.c		\
			  ft_lstadd.c		\
			  ft_lstiter.c		\
			  ft_lstmap.c		\
			  ft_lstsize.c		\
			  ft_lst_search.c	\
			  ft_strrev.c		\
			  ft_isprime.c		\
			  ft_btree_create.c	\
			  ft_btree_prefix.c	\
			  ft_atoi_base.c	\
			  ft_itoa_base.c	\
			  ft_printf/ft_add_sign.c			\
			  ft_printf/ft_alignment1.c			\
			  ft_printf/ft_alignment2.c			\
			  ft_printf/ft_cleanup.c			\
			  ft_printf/ft_fill_buffer.c		\
			  ft_printf/ft_format1.c			\
			  ft_printf/ft_format2.c			\
			  ft_printf/ft_format_processing.c	\
			  ft_printf/ft_fprintf.c			\
			  ft_printf/ft_isvalid_lmod.c		\
			  ft_printf/ft_justified.c			\
			  ft_printf/ft_precision_handling.c	\
			  ft_printf/ft_preformatting.c		\
			  ft_printf/ft_printf.c				\
			  ft_printf/ft_remalloc.c			\
			  ft_printf/ft_snprintf.c			\
			  ft_printf/ft_specifiers1.c		\
			  ft_printf/ft_specifiers2.c		\
			  ft_printf/ft_sprintf.c			\
			  ft_printf/ft_store_options.c		\
			  ft_printf/ft_vfprintf.c			\
			  ft_printf/ft_vprintf.c			\
			  ft_printf/ft_vsnprintf.c			\
			  ft_printf/ft_vsprintf.c			\
			  ft_printf/ft_wchar_processing.c	\
			  ft_printf/ft_wstring_processing.c	\
			  get_next_line.c 					\



CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
INCLUDES_DIR = includes
HEADERS = $(INCLUDES_DIR)/ft_printf.h $(INCLUDES_DIR)/libft.h
INCLUDES	= -I$(INCLUDES_DIR)
DIR			= srcs/
SRC			= $(addprefix $(DIR), $(SOURCES))
OBJ 		= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		ar rc libft.a $(OBJ)
		ranlib libft.a

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) $(INCLUDES)  $< -c -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2018/10/06 15:27:33 by ffloris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCC_FLAGS = -Werror -Wextra -Wall

LIBFT_IN_OBJS = ft_get_next_line.o ft_get_next.o

LIBFT_LIST_OBJS = ft_lstnew.o ft_lstcpy.o ft_lstappend.o ft_lstremove.o \
	ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstfind.o \
	ft_lstmap.o ft_lstsize.o ft_lstlast.o ft_lstat.o \
	ft_lstreverse.o ft_lstmerge.o ft_lstsort.o ft_lstsorted.o \
	ft_lstmiddle.o

LIBFT_MATH_OBJS = ft_abs.o ft_clamp.o ft_sqrt.o ft_pow.o

LIBFT_MEMORY_OBJS = ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	ft_memalloc.o ft_memdel.o ft_is_sorted.o \
	ft_strdel_table.o ft_quicksort.o ft_swap.o \
	ft_struct_del.o ft_strtable.o

LIBFT_OUT_OBJS = ft_putchar.o ft_putwchar.o \
	ft_putstr.o ft_putwstr.o ft_putendl.o ft_putnbr.o \
	ft_putwchar_fd.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putwstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_putnstr.o ft_putnstr_fd.o ft_putnwstr.o ft_putnwstr_fd.o \

LIBFT_OUT_FT_PRINTF_OBJS = ft_printf.o ft_printf_parse.o \
	ft_printf_put.o ft_printf_putid.o \
	ft_printf_set_flags.o ft_printf_set_width.o \
	ft_printf_set_precision.o ft_printf_set_length.o \
	ft_printf_putstr.o ft_printf_putwstr.o \
	ft_printf_putchar.o ft_printf_putwchar.o \
	ft_printf_putnbr.o ft_printf_putonbr.o ft_printf_puthexanbr.o \
	ft_printf_nbrs.o ft_printf_putaddr.o ft_printf_padding.o \
	ft_printf_colors.o ft_printf_chars_written.o \
	ft_printf_fd.o ft_printf_putbinary.o ft_printf_setup_ops.o \
	ft_printf_types.o

LIBFT_STRING_OBJS = ft_strlen.o ft_strdup.o ft_strcpy.o \
	ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o \
	ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
	ft_strcmp.o ft_strncmp.o ft_atoi.o ft_atoi_n.o \
	ft_atol.o ft_atoll.o ft_isalpha.o \
	ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	ft_toupper.o ft_tolower.o ft_islower.o ft_isspace.o \
	ft_isupper.o ft_strnew.o ft_strdel.o ft_strclr.o \
	ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o \
	ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
	ft_strtrim.o ft_strsplit.o ft_itoa.o ft_itoa_base.o \
	ft_wcharlen.o ft_wstrlen.o ft_wstrblen.o ft_nwstrblen.o \
	ft_isnumber.o ft_isinteger.o ft_strrev.o ft_split.o ft_strjoinfree.o

LIBFT_OBJS_DIR = objs
LIBFT_IN_OBJS_DIR = $(LIBFT_OBJS_DIR)/in
LIBFT_LIST_OBJS_DIR = $(LIBFT_OBJS_DIR)/list
LIBFT_MATH_OBJS_DIR = $(LIBFT_OBJS_DIR)/math
LIBFT_MEMORY_OBJS_DIR = $(LIBFT_OBJS_DIR)/memory
LIBFT_OUT_OBJS_DIR = $(LIBFT_OBJS_DIR)/out
LIBFT_OUT_FT_PRINTF_OBJS_DIR = $(LIBFT_OUT_OBJS_DIR)/ft_printf
LIBFT_STRING_OBJS_DIR = $(LIBFT_OBJS_DIR)/string
LIBFT_OBJS_DIRS = $(LIBFT_IN_OBJS_DIR) $(LIBFT_LIST_OBJS_DIR) \
	$(LIBFT_MATH_OBJS_DIR) $(LIBFT_MEMORY_OBJS_DIR) \
	$(LIBFT_OUT_OBJS_DIR) $(LIBFT_OUT_FT_PRINTF_OBJS_DIR) \
	$(LIBFT_STRING_OBJS_DIR)

LIBFT_SRCS_DIR = srcs

LIBFT_INCLUDES_DIR = includes
LIBFT_INCLUDES_FILES = ft_printf ft_printf_colors libft
LIBFT_HEADERS = $(addsuffix .h, $(patsubst %, $(LIBFT_INCLUDES_DIR)/%, $(LIBFT_INCLUDES_FILES)))

OBJS = $(addprefix $(LIBFT_IN_OBJS_DIR)/, $(LIBFT_IN_OBJS))
OBJS += $(addprefix $(LIBFT_LIST_OBJS_DIR)/, $(LIBFT_LIST_OBJS))
OBJS += $(addprefix $(LIBFT_MATH_OBJS_DIR)/, $(LIBFT_MATH_OBJS))
OBJS += $(addprefix $(LIBFT_MEMORY_OBJS_DIR)/, $(LIBFT_MEMORY_OBJS))
OBJS += $(addprefix $(LIBFT_OUT_OBJS_DIR)/, $(LIBFT_OUT_OBJS))
OBJS += $(addprefix $(LIBFT_OUT_FT_PRINTF_OBJS_DIR)/, $(LIBFT_OUT_FT_PRINTF_OBJS))
OBJS += $(addprefix $(LIBFT_STRING_OBJS_DIR)/, $(LIBFT_STRING_OBJS))

SRCS = $(patsubst $(LIBFT_OBJS_DIR)/%.o, $(LIBFT_SRCS_DIR)/%.c, $(OBJS))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"
CREATED_TEXT = $(NAME) "created!"

all: $(NAME)

$(NAME): $(LIBFT_OBJS_DIRS) $(OBJS) $(LIBFT_HEADERS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(CREATED_TEXT)

$(LIBFT_OBJS_DIRS):
	@mkdir -p $(LIBFT_OBJS_DIRS)

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_SRCS_DIR)/%.c $(LIBFT_HEADERS)
	@echo Libft: $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@cc $(GCC_FLAGS) -c $< -o $@ -I $(LIBFT_INCLUDES_DIR)/

clean:
	@rm -rf $(OBJS) $(LIBFT_OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all init_print end_print clean fclean re

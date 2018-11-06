.PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRC =		ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstreturn.c \
			ft_lststrsplit.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putnbrmax_fd.c \
			ft_putnbrumax_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_removeselect.c \
			ft_str_is_alpha.c \
			ft_str_is_alphanumeric.c \
			ft_str_is_lowercase.c \
			ft_str_is_numeric.c \
			ft_str_is_printable.c \
			ft_str_is_uppercase.c \
			ft_strcapitalize.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strlowcase.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strsplitfirst.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_strtrimselect.c \
			ft_strupcase.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi_max.c \
			get_next_line.c \
			options.c \
			ft_printf/ft_printf.c \
			ft_printf/treatment.c \
			ft_printf/initialize.c \
			ft_printf/reinitialize.c \
			ft_printf/parser.c \
			ft_printf/parse_convert.c \
			ft_printf/parse_field_width.c \
			ft_printf/parse_precision.c \
			ft_printf/parse_arguments.c \
			ft_printf/parse_specifier.c \
			ft_printf/switch_display.c \
			ft_printf/display_d.c \
			ft_printf/display_c.c \
			ft_printf/display_s.c \
			ft_printf/display_u.c \
			ft_printf/display_x.c \
			ft_printf/display_o.c \
			ft_printf/display_p.c \
			ft_printf/display_ws.c \
			ft_printf/display_gap.c \
			ft_printf/display_wchar.c \
			ft_printf/display_other.c

OBJ_DIR = ./obj/
OBJ_DIR_PRINTF = $(OBJ_DIR)ft_printf/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = libft.h get_next_line.h ft_printf.h

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR_PRINTF)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

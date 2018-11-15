NAME = ft_nm

GCC_FLAGS = -Werror -Wextra -Wall

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS_INCLUDES_DIR = includes

LIBFT_DIR = ../libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR = $(LIBFT_DIR)/includes

SHARED_DIR = ../shared
SHARED_INCLUDES_DIR = $(SHARED_DIR)/includes

INCLUDE_DIRS = -I $(SRCS_INCLUDES_DIR) -I $(LIBFT_INCLUDES_DIR) \
	-I $(SHARED_INCLUDES_DIR)

INCLUDES_FILES = nm
HEADERS = $(addsuffix .h, $(patsubst %, $(SRCS_INCLUDES_DIR)/%, $(INCLUDES_FILES)))
HEADERS += $(SHARED_INCLUDES_DIR)/nm_otool.h

MAIN_FILES = nm \
	list_object_files_symbols list_object_file_symbols \
	set_mapped_file unset_mapped_file
SHARED_FILES =

MAIN_OBJS = $(addsuffix .o, $(MAIN_FILES))
SHARED_OBJS = $(addsuffix .o, $(SHARED_FILES))

MAIN_OBJS_DIR = $(OBJS_DIR)/main
SHARED_OBJS_DIR = $(OBJS_DIR)/shared
OBJS_DIRS = $(MAIN_OBJS_DIR) $(SHARED_OBJS_DIR)

OBJS = $(patsubst %, $(MAIN_OBJS_DIR)/%, $(MAIN_OBJS))
OBJS += $(patsubst %, $(SHARED_OBJS_DIR)/%, $(SHARED_OBJS))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"

all: comp_libft $(NAME)

comp_libft:
	@make -C $(LIBFT_DIR)/

$(NAME): $(LIBFT_FILE) $(OBJS_DIRS) $(OBJS)
	@echo "Nm:" $(GREEN_COLOR) $(NAME) $(DEFAULT_COLOR)
	@cc $(GCC_FLAGS) $(OBJS) -o $(NAME) $(LIBFT_FILE) $(INCLUDE_DIRS)

$(OBJS_DIRS):
	@mkdir -p $(OBJS_DIRS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  $(HEADERS)
	@echo "Nm:" $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@cc $(GCC_FLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all comp_libft clean fclean re

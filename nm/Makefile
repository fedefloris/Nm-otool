NAME = ft_nm

OS_TYPE = $(shell uname)

GCC_FLAGS = -Werror -Wextra -Wall -g

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
HEADERS += $(SHARED_INCLUDES_DIR)/nm_otool.h \
	$(SHARED_INCLUDES_DIR)/elf.h

MAIN_FILES = nm obj_handler
SYMBOLS_FILES = display_symbols \
	add_symbol \
	sort_symbols merge_sort_symbols \
	free_symbols
MACH_O_FILES =
ELF_FILES = elf_obj_handler \
	elf_32_obj_handler \
	elf_64_obj_handler \
	elf_64_parse_section_headers elf_64_parse_section_header \
	elf_64_set_symbols elf_get_symbol_type

SHARED_FILES = error_log warning_log config_nm_otool \
	list_objs_symbols list_obj_symbols \
	set_file set_file_info \
	set_file_info_on_linux has_good_ELF_magic_number \
	unset_file find_binary get_safe_address string_is_safe \
	options option_check op

ifeq ($(OS_TYPE), Darwin)
	MACH_O_FILES +=	free_sections \
					get_type \
					mach_o_archive \
					mach_o_obj_handler \
					mach_fat_32_obj_handler \
					mach_fat_64_obj_handler \
					mach_o_create_section \
					mach_o_32_get_sections \
					mach_o_32_obj_handler \
					mach_o_64_get_sections \
					mach_o_64_obj_handler \
					mach_o_read_load_commands
	SHARED_FILES += set_file_info_on_macos
endif

MAIN_OBJS = $(addsuffix .o, $(MAIN_FILES))
SYMBOLS_OBJS = $(addsuffix .o, $(SYMBOLS_FILES))
MACH_O_OBJS = $(addsuffix .o, $(MACH_O_FILES))
ELF_OBJS = $(addsuffix .o, $(ELF_FILES))
SHARED_OBJS = $(addsuffix .o, $(SHARED_FILES))

MAIN_OBJS_DIR = $(OBJS_DIR)/main
SYMBOLS_OBJS_DIR = $(OBJS_DIR)/symbols
MACH_O_OBJS_DIR = $(OBJS_DIR)/mach_o
ELF_OBJS_DIR = $(OBJS_DIR)/elf
SHARED_OBJS_DIR = $(OBJS_DIR)/shared
OBJS_DIRS = $(MAIN_OBJS_DIR) \
	$(SHARED_OBJS_DIR) $(SYMBOLS_OBJS_DIR) \
	$(MACH_O_OBJS_DIR) $(ELF_OBJS_DIR)

OBJS = $(patsubst %, $(MAIN_OBJS_DIR)/%, $(MAIN_OBJS))
OBJS += $(patsubst %, $(SYMBOLS_OBJS_DIR)/%, $(SYMBOLS_OBJS))
OBJS += $(patsubst %, $(MACH_O_OBJS_DIR)/%, $(MACH_O_OBJS))
OBJS += $(patsubst %, $(ELF_OBJS_DIR)/%, $(ELF_OBJS))
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

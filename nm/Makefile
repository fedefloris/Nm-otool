NAME = ft_nm

OS_TYPE = $(shell uname)

CC_FLAGS = -Werror -Wextra -Wall -g

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

MAIN_FILES = display_usage \
	nm \
	obj_handler

SYMBOLS_FILES = add_symbol \
	display_symbol \
	display_symbols \
	free_symbols \
	get_middle_symbol \
	merge_sort_symbols \
	sort_symbols

MACH_O_FILES =

ELF_FILES = elf_obj_handler_32 \
	elf_parse_section_header_32 \
	elf_parse_section_headers_32 \
	elf_set_symbols_32 \
	elf_obj_handler_64 \
	elf_parse_section_header_64 \
	elf_parse_section_headers_64 \
	elf_set_symbols_64 \
	elf_get_type \
	elf_get_type_from_section \
	elf_get_type_from_flags \
	elf_obj_handler

SHARED_FILES = archive_handler \
	config_buffer \
	config_nm_otool \
	empty_the_buffer \
	endian_swap \
	error_log \
	find_binary \
	list_obj_symbols \
	list_objs_symbols \
	get_value_32 \
	get_value_64 \
	get_safe_address \
	has_good_elf_magic_number \
	op \
	option_check \
	options \
	set_endianness \
	set_file \
	set_archive_format \
	set_file_info \
	set_file_info_on_linux \
	send_to_buffer \
	string_is_safe \
	unset_file \
	warning_log

ifeq ($(OS_TYPE), Darwin)
	MACH_O_FILES +=	mach_o_free_sections \
		mach_o_get_type \
		mach_o_obj_handler \
		mach_o_get_sections_32 \
		mach_o_obj_handler_32 \
		mach_o_get_sections_64 \
		mach_o_obj_handler_64 \
		mach_o_read_load_commands
	SHARED_FILES += set_file_info_on_macos \
		mach_o_fat_32 \
		mach_o_fat_64
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
	@$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) $(LIBFT_FILE) $(INCLUDE_DIRS)

$(OBJS_DIRS):
	@mkdir -p $(OBJS_DIRS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  $(HEADERS)
	@echo "Nm:" $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@$(CC) $(CC_FLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(OBJS_DIR) $(NAME)

re: fclean all

.PHONY: all comp_libft clean fclean re

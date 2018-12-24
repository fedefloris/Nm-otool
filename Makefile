NM = ft_nm
OTOOL = ft_otool
NAME = $(NM) $(OTOOL)

LIBFT_DIR = libft

NM_DIR = nm
OTOOL_DIR = otool

all: $(NAME)

test: $(NAME)
	@OPTIONS=-p PRINT_REPORT=1 ./scripts/test.sh /bin
	@OPTIONS=-p PRINT_REPORT=1 ./scripts/test.sh /usr/bin

comp_libft:
	@make -C $(LIBFT_DIR)/

comp_nm: comp_libft
	@make -C $(NM_DIR)/

comp_otool: comp_libft
	@make -C $(OTOOL_DIR)/

$(NM): comp_nm $(NM_DIR)/$(NM)
	@cp $(NM_DIR)/$(NM) $(NM)

$(OTOOL): comp_otool $(OTOOL_DIR)/$(OTOOL)
	@cp $(OTOOL_DIR)/$(OTOOL) $(OTOOL)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@make -C $(NM_DIR)/ clean
	@make -C $(OTOOL_DIR)/ clean

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@make -C $(NM_DIR)/ fclean
	@make -C $(OTOOL_DIR)/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all test comp_libft comp_nm comp_otool clean fclean re

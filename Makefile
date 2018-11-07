NM = ft_nm
OTOOL = ft_otool
NAME = $(NM) $(OTOOL)

LIBFT_DIR = libft

NM_DIR = nm
OTOOL_DIR = otool

all: comp_libft comp_nm comp_otool $(NAME)

comp_libft:
	@make -C $(LIBFT_DIR)/

comp_nm:
	@make -C $(NM_DIR)/

comp_otool:
	@make -C $(OTOOL_DIR)/

$(NAME): $(NM_DIR)/$(NM) $(OTOOL_DIR)/$(OTOOL)
	@cp $(NM_DIR)/$(NM) $(NM)
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

.PHONY: all comp_libft comp_nm comp_otool clean fclean re

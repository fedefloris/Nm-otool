#include "nm_otool.h"
#include "nm.h"

static bool	is_initialized_data_section(char *sh_name)
{
	return (!ft_strcmp(sh_name, ".data")
		|| !ft_strcmp(sh_name, ".data1"));
}

static bool	is_text_section(char *sh_name)
{
	return (!ft_strcmp(sh_name, ".code")
		|| !ft_strcmp(sh_name, ".fini")
		|| !ft_strcmp(sh_name, ".init")
		|| !ft_strcmp(sh_name, ".text")
		|| !ft_strcmp(sh_name, ".fini_array")
		|| !ft_strcmp(sh_name, ".init_array"));
}

char	elf_get_type_from_section(t_elf_symbols_info *info)
{
	if (!ft_strcmp(info->sh_name, ".bss"))
		return ('b');
	if (!ft_strcmp(info->sh_name, ".sbss"))
		return ('s');
	if (!ft_strcmp(info->sh_name, ".debug"))
		return ('N');
	if (is_initialized_data_section(info->sh_name))
		return ('d');
	if (!ft_strcmp(info->sh_name, ".drectve") || !ft_strcmp(info->sh_name, ".idata"))
		return ('i');
	if (!ft_strcmp(info->sh_name, ".edata"))
		return ('e');
	if (!ft_strcmp(info->sh_name, ".pdata"))
		return ('p');
	if (!ft_strcmp(info->sh_name, ".rodata") || !ft_strcmp(info->sh_name, ".rodata1"))
		return ('r');
	if (!ft_strcmp(info->sh_name, ".scommon"))
		return ('c');
	if (!ft_strcmp(info->sh_name, ".sdata"))
		return ('g');
	if (is_text_section(info->sh_name))
		return ('t');
	return ('?');
}

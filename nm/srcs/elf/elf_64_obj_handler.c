#include "nm_otool.h"
#include "nm.h"

// Check if e_shnum is larger than or equal to SHN_LORESERVE (man elf)
// should I use e_shentsize?
// Check if e_shstrndx is larger than or equal to SHN_LORESERVE (man elf)
// Some  section header table indices are reserved: the initial entry and the indices between
// SHN_LORESERVE and SHN_HIRESERVE.  The initial entry is used  in  ELF  exten‐
// sions  for  e_phnum, e_shnum and e_strndx; in other cases, each field in the
// initial entry is set to zero.  An object file does  not  have  sections  for
// these special indices

bool				elf_64_obj_handler(t_nm_otool *nm_otool)
{
	Elf64_Ehdr	*header;

	if (!SET(header, nm_otool->file.memory)
		|| !STRUCT_IS_SAFE(header))
			return (ERROR_LOG("not enough space for the ELF header"));
	if (header->e_shoff == 0)
		return (true);
	return (elf_64_parse_section_headers(nm_otool, header));
}

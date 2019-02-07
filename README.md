[![Build Status](https://travis-ci.com/davhojt/Nm-otool.svg?token=dH8C3CpkpNBzxeKzZ8gb&branch=master)](https://travis-ci.com/davhojt/Nm-otool)
# Nm-otool
***
### Score TBA
##### Mandatory
TBA/TBA
##### Bonus
TBA/TBA
##### Outstanding Project
TBA/TBA
***
### Challenge  
To recode the `unix` commands `nm` (with no options) and `otool` (the same as `-t`) The executeables must be named `ft_nm` and `ft_otool`  
  
The function must conform to 42's norm.  
  
The programs cannot leak. All errors must be handled carefully. In no way can the programs quit in an unexpected manner (Segmentation fault, bus error, double free, etc).  
  
Allowed functions for the mandatory part are:
- `open(2)`
- `close(2)`
- `mmap(2)`
- `munmap(2)`
- `write(2)`
- `fstat(2)`
- `malloc(3)`
- `free(3)`

Everything else is forbidden. Other functions can be used for bonus, but their use must be justified.
***
### Using the project

### Bonus
- `ft_nm` works on `macOS` and `Linux`
- `ft_nm` works on `ELF` binaries. `ELF` binaries are a completely different architecture to `mach-o`. This functionality is an entire `ft_nm` in its own right.
- `ft_otool` is 4.8x faster than `otool`. One benchmark measured:  
`ft_otool`: 73 seconds  
`otool`: 551 seconds
- `-j` Just display the symbol names (no value or type).
- `-r` Sort in reverse order.
- `-p` Don't sort; display in symbol-table order.
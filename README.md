# Nm-otool - 42born2code
[![Build Status](https://travis-ci.com/fedefloris/Nm_otool.svg?token=dH8C3CpkpNBzxeKzZ8gb&branch=master)](https://travis-ci.com/fedefloris/Nm_otool)
***
## Challenge  
To recode the `UNIX` commands `nm` (with no options) and `otool` (the same as `-t`) The executables must be named `ft_nm` and `ft_otool`  

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
## Using the project
#### Compile
To compile the project, run `make`. This will compile `ft_nm` and `ft_otool`
```console
make
```
#### Execute
To execute (see the below options) execute like a normal non-`$PATH` binary.
```console
$> ./ft_nm ls
                 U __DefaultRuneLocale
                 U ___assert_rtn
                 U ___bzero
                 U ___error
                 U ___maskrune
                 U ___snprintf_chk
                 U ___stack_chk_fail
                 U ___stack_chk_guard
                 U ___stderrp
                 U ___stdoutp
                 U ___tolower
0000000100000000 T __mh_execute_header
                 U _acl_free
                 U _acl_get_entry
                 U _acl_get_flag_np
                 U _acl_get_flagset_np
                 U _acl_get_link_np
                 U _acl_get_perm_np
                 U _acl_get_permset
                 U _acl_get_qualifier
                 U _acl_get_tag_type
                 U _atoi
                 U _calloc
                 U _compat_mode
                 U _err
                 U _exit
                 U _fflagstostr
                 U _fprintf
                 U _fputs
                 U _free
                 U _fts_children$INODE64
                 U _fts_close$INODE64
                 U _fts_open$INODE64
                 U _fts_read$INODE64
                 U _fts_set$INODE64
                 U _fwrite
                 U _getbsize
                 U _getenv
                 U _getopt
                 U _getpid
                 U _getuid
                 U _getxattr
                 U _group_from_gid
                 U _humanize_number
                 U _ioctl
                 U _isatty
                 U _kill
                 U _listxattr
                 U _localtime
                 U _malloc
                 U _mbr_identifier_translate
                 U _mbrtowc
                 U _memchr
                 U _nl_langinfo
                 U _optind
                 U _printf
                 U _putchar
                 U _readlink
                 U _realloc
                 U _reallocf
                 U _setenv
                 U _setlocale
                 U _signal
                 U _sscanf
                 U _strcoll
                 U _strcpy
                 U _strdup
                 U _strerror
                 U _strftime
                 U _strlen
                 U _strmode
                 U _tgetent
                 U _tgetstr
                 U _tgoto
                 U _time
                 U _tputs
                 U _user_from_uid
                 U _uuid_unparse_upper
                 U _warn
                 U _warnx
                 U _wcwidth
                 U _write
                 U dyld_stub_binder
```
```console
$> ./ft_otool -t ls
ls:
Contents of (__TEXT,__text) section
0000000100000f0c        55 48 89 e5 48 83 c7 68 48 83 c6 68 5d e9 5e 36
0000000100000f1c        00 00 55 48 89 e5 48 8d 46 68 48 8d 77 68 48 89
0000000100000f2c        c7 5d e9 49 36 00 00 55 48 89 e5 4c 8b 46 60 48
0000000100000f3c        8b 57 60 48 8b 4a 30 b8 01 00 00 00 49 39 48 30
0000000100000f4c        7f 1a 7d 07 b8 ff ff ff ff eb 11 48 8b 4a 38 49
0000000100000f5c        39 48 38 7f 07 b8 ff ff ff ff 7d 02 5d c3 48 83

00000001000043ac        48 ff c3 49 ff cf 75 f0 8b bd 4c ff ff ff 44 89
00000001000043bc        e3 e8 1a 02 00 00 01 c3 e9 64 ff ff ff 48 8b 05
00000001000043cc        48 0c 00 00 48 8b 00 48 3b 45 d0 75 14 89 d8 48
00000001000043dc        81 c4 98 00 00 00 5b 41 5c 41 5d 41 5e 41 5f 5d
00000001000043ec        c3 e8 4c 00 00 00 55 48 89 e5 48 8b 05 23 0c 00
00000001000043fc        00 48 8b 08 48 8d 3d 21 0b 00 00 be 3e 00 00 00
000000010000440c        ba 01 00 00 00 e8 be 00 00 00 bf 01 00 00 00 e8
000000010000441c        78 00 00 00
```
***
## Bonus
- `ft_nm` works on `macOS` and `Linux`

- `ft_nm` works on `ELF` binaries. `ELF` binaries are a completely different architecture to `mach-o`. This functionality is an entire `ft_nm` in its own right.

-  Binary finder: `./ft_nm ls` is equivalent to `./ft_nm /bin/ls`.

- `ft_otool` is 4.8x faster than `otool`. One benchmark measured:  
`ft_otool`: 73 seconds  
`otool`: 551 seconds

- Unit testing

- Every error has an individual message.

- `-j` Just display the symbol names (no value or type).

- `-r` Sort in reverse order.

- `-p` Don't sort; display in symbol-table order.

- `-h` Help; for usage.

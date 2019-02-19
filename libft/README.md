# Libft - 42Born2Code
My personal C library used at 42Born2Code.

## What is libft?
Libft is a 42 project where we have to re-implement some standard C library functions + some additional ones.

For more details look at the [subject](subject.pdf).

## How do I use the library?
```console
git clone https://github.com/fedefloris/Libft.git && cd Libft && make
```
Now you should see a **libft.a** file in the root folder.
```console
gcc your_file.c libft.a -I includes
```
Example of **your_file.c**:
```c
#include "libft.h"

int main(void)
{
  ft_printf("Hello %d\n", 42);
  return (0);
}
```

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.

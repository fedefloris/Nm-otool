/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:56:18 by jwong             #+#    #+#             */
/*   Updated: 2015/12/09 18:45:59 by jwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

/*
void    test_memset(void)
{
    char    str[50];
    
   	strcpy(str, "This is string.h library function");

    ft_memset(str, '$', 7);
    printf("%s\n", str);
}
*/

/*
void    test_bzero(void)
{
    char    str[50];

    strcpy(str, "This is string.h library function");

    ft_bzero(str, 7);
    printf("%s\n", str);
    printf("%c\n", str[8]);
}
*/

/*
void    test_memcpy(void)
{
	const char	*src = "Hello World is the first progam";
	char		dest[30];
	char		dest1[3];

    ft_memcpy(dest, src, strlen(src)+1);
    printf("%s\n", dest);
    ft_memcpy(dest1, src, strlen(src)+1);
    printf("%s\n", dest1);
}
*/

/*
void	test_memccpy(void)
{
	const char	*src = "Hello World is the first progam";
	char		dest[4];
	char		dest1[3];
	char		dest2[13];

	memccpy(dest, src, 'l', 3);
	printf("case 1: %s\n", dest);
	memccpy(dest1, src, 'o', 6); -----------------------------------> check this 
	printf("case 1: %s\n", dest1);
	memccpy(dest2, src, 'z', 13);
	printf("case 2: %s\n", dest2);
}
*/

/*
void	test_memmove(void)  
{
	const char	*src = "Hello World";
	char		dest[14];

	memmove(dest, src, 12);
	printf("%s\n", dest);
}
*/

/*
void	test_memchr(void)
{
    char        *ret;
	const char	*s1 = "Hello World";
	const char	*s2 = "";

	ret = ft_memchr((char *)s1, 108, 4);
    if (ret != NULL)
		printf("%s\n", ret);
    ret = ft_memchr((char *)s1, 'H', 2);
    if (ret != NULL)
        printf("passed\n");
	ret = ft_memchr((char *)s2, 108, 4);
    if (ret == NULL)
		printf("%s\n", ret);
}
*/

/*
void    test_memcmp(void)
{
    char *s1 = "Hello World";
    char *s2 = "Hello World";
    char *s3 = "Hello";
    char *s4 = "hi";
    
    printf("case 1: %d\n", ft_memcmp((char *)s1, (char *)s2, strlen(s1)));
    printf("case 2: %d\n", ft_memcmp((char *)s1, (char *)s3, 5));
    printf("case 3: %d\n", ft_memcmp((char *)s1, (char *)s4, 5));
}
*/

/*
void	test_strlen(void)
{
	char a[] = "hello";
	char b[] = "";

	printf("%zu\n", ft_strlen(a));
	printf("%zu\n", ft_strlen(b));
}
*/

/*
void	test_strdup(void)
{
	char 	a[] = "hello";
	char	b[] = "";
	char	c[] = " Hello World ";
	char	*str; 

	str = ft_strdup(a);
	printf("%s\n", str);
	str = ft_strdup(b);
	printf("%s\n", str);
	str = ft_strdup(c);
	printf("%s\n", str);
}
*/

/*
void    test_strcpy(void)
{
    char    a[] = "hello";
    char    b[6];
    char    *res;

    res = ft_strcpy(b, a);
    printf("%s\n", res);
}
*/

/*
void    test_strncpy(void)
{
    char    a[] = "hello";
    char    b[3];
    size_t  n = 3;
    char    *res;

    res = ft_strncpy(b, a, n);
    printf("%s\n", res);
}
*/

/*
void    test_strcat(void)
{
    char    a[] = "World";
    char    b[15] = "Hello ";
    char    *res;

    res = ft_strcat(b, a);
    printf("%s\n", res);
}
*/

/*
void    test_strncat(void)
{
    char    a[] = "World";
    char    b[15] = "Hello ";
    char    *res;

    res = ft_strncat(b, a, 3);
    printf("%s\n", res);
}
*/

/*
void    test_strlcat(void) 
{
    const char  *src = "World";
    char        dst[16] = "Hello ";
    char        dst1[7] = "Hello ";
	char		dst2[8];

    printf("case 1: %zu   %s\n", ft_strlcat(dst, src, sizeof(dst)), dst);
    printf("case 2: %zu   %s\n", ft_strlcat(dst1, src, sizeof(dst1)), dst1);
    printf("case 3: %zu   %s\n", ft_strlcat(dst2, "abcd", 2), dst2);
}
*/

/*
void    test_strchr(void)
{
    const char  *s = "Hello World";
    int         i = 101;
    char        *ret;

    ret = ft_strchr(s, i);
    printf("%s\n", ret);
}
*/
/*
void    test_strrchr(void)
{
    const char  *s = "Hello World";
    int         i = 108;
    char        *ret;

    ret = ft_strrchr(s, i);
    printf("%s\n", ret);
}
*/

/*
void    test_strcmp(void)
{
    const char *s1 = "Hello World";
    const char *s2 = "Hello World";
    const char *s3 = "Hello";
    const char *s4 = "hi";
    
    printf("case 1: %d\n", ft_strcmp(s1, s2));
    printf("case 2: %d\n", ft_strcmp(s1, s3));
    printf("case 3: %d\n", ft_strcmp(s1, s4));
    printf("case 4: %d\n", ft_strcmp("\200", "\0"));
}
*/

/*
void    test_strncmp(void)
{
    const char  *s1 = "Hello World";
    const char  *s2 = "Hello";
    const char  *s3 = "hi";

    printf("case 1: %d\n", ft_strncmp(s1, s2, 2));
    printf("case 2: %d\n", ft_strncmp(s1, s3, 2));
    printf("case 3: %d\n", ft_strncmp("\200", "\0", 1));
    printf("case 4: %d\n", ft_strncmp("abc", "abcde", 3));
    printf("case 5: %d\n", ft_strncmp("\200", "\0", 1));
}
*/

/*
void    test_strstr(void)
{
    const char  *s1 = "Hello World hello";
    const char  *s2 = "World";
    const char  *s3 = "hello";
    const char  *s4 = "hi";
    char        *ret;

    ret = ft_strstr(s1, s2);
    printf("case 1: %s\n", ret);
    ret = ft_strstr(s1, s3);
    printf("case 2: %s\n", ret);
    ret = ft_strstr(s1, s4);
    printf("case 3: %s\n", ret);
    ret = ft_strstr("", "");
    printf("case 4: %s\n", ret);
}
*/

/*
void    test_strnstr(void)
{
    const char  *s1 = "Hello World hello";
    const char  *s2 = "World";
    const char  *s3 = "Hello";
    const char  *s4 = "hi";
    const char  *s5 = "";
	char		s6[10] = "un deux 9";
    char        *ret;

    ret = ft_strnstr(s1, s2, 11);
    printf("case 1: %s\n", ret);
    ret = ft_strnstr(s1, s3, 5);
    printf("case 2: %s\n", ret);
    ret = ft_strnstr(s1, s4, 2);
    printf("case 3: %s\n", ret);
    ret = ft_strnstr(s1, s5, 5);
    printf("case 4: %s\n", ret);
    ret = ft_strnstr(s6, "deux", 5);
    printf("case 5: %s\n", ret);
}
*/

/*
void	test_atoi(void)
{
	const char	*str = "str42";
	const char	*str1 = "42";
	const char	*str2 = "-42";
	const char	*str3 = "424242424";
	const char	*str4 = "-2147483648";
	const char	*str5 = "42school21";

	printf("case 1: %d\n", ft_atoi(str));
	printf("case 2: %d\n", ft_atoi(str1));
	printf("case 3: %d\n", ft_atoi(str2));
	printf("case 4: %d\n", ft_atoi(str3));
	printf("case 5: %d\n", ft_atoi(str4));
	printf("case 6: %d\n", ft_atoi(str5));
	printf("case 7: %d\n", ft_atoi("+876"));
}
*/

/*
void    test_num_alpha(void)
{
    char c;
	int n;

    c = 'c';
    if (ft_isalpha(c) == 'c')
        printf("ft_isalpha case 1 of 3: pass\n");
    c = 'C';
    if (ft_isalpha(c) == 'C')
        printf("ft_isalpha case 2 of 3: pass\n");
    if (ft_isalpha('1') == 0)
        printf("ft_isalpha case 3 of 3: pass\n");

    c = '1';
    if (ft_isdigit(c) == '1')
        printf("ft_isdigit case 1 of 2: pass\n");
    if (ft_isdigit('a') == 0)
        printf("ft_isdigit case 2 of 2: pass\n");

    c = '1';
    if (ft_isalnum(c) == '1')
        printf("ft_isalnum case 1 of 4: pass\n");
    c = 'a';
    if (ft_isalnum(c) == 'a')
        printf("ft_isalnum case 2 of 4: pass\n");
    c = 'A';
    if (ft_isalnum(c) == 'A')
        printf("ft_isalnum case 3 of 4: pass\n");
    if (ft_isalpha('&') == 0)
        printf("ft_isalnum case 4 of 4: pass\n");

    if (ft_isascii(7) != 0)
        printf("ft_isascii case 1 of 3: pass\n");
    if (ft_isascii(129) == 0)
        printf("ft_isascii case 2 of 3: pass\n");

    c = ' ';
    if (ft_isprint(c) == ' ')
        printf("ft_isprint case 1 of 2: pass\n");
    c = '~' + 1;
    if (ft_isprint(c) == 0)
        printf("ft_isprint case 2 of 2: pass\n");

    c = 'a';
    if (ft_toupper(c) == 'A')
        printf("ft_toupper case 1 of 2: pass\n");
    c = '1';
    if (ft_toupper(c) == '1')
        printf("ft_toupper case 2 of 2: pass\n");
    
    c = 'A';
    if (ft_tolower(c) == 'a')
        printf("ft_tolower case 1 of 2: pass\n");
    c = 's';
    if (ft_tolower(c) == 's')
        printf("ft_tolower case 2 of 2: pass\n");
}
*/


void	test_memalloc(void)
{
    size_t  size = 42;
    char    *cmp = malloc(size);
    int     diff;
    char    *ret;
    char    *iret;
    int     i;

    printf("test_memalloc\n");
	free(ft_memalloc(4));
    printf("case 1 of 3: pass\n");

    ret = ft_memalloc(size);
    memset(cmp, '\0', size);
    memset(ret, '\0', size);
    bzero(cmp, size);
    diff = memcmp(cmp, ret, size);
    if (diff != 0)
        printf("case 2 of 3: failed\n");
    free(ret);
    printf("case 2 of 3: pass\n");

    printf("if 41 blanks --> case 3 of 3: pass\n");
    iret = ft_memalloc(size);
    i = 0;
	while (i++ < 41)
	{
		printf("%c\n", (char)iret[i]);
	}
    free(iret);
}



void	test_memdel(void)
{
	char	*str;

    printf("test_memdel\n");
	str = (char *)malloc(sizeof(*str) * 4);
	if (str != NULL)
	{
		ft_memdel((void **)&str);
		if (str == NULL)
			printf("case 1 of 1: pass\n");
		else
			printf("case 1 of 1: fail\n");
	}
}



void	test_strnew(void)
{
	char	*str;
	size_t	i;
    size_t  n;

    printf("test_strnew\n");
    n = 5;
	str = ft_strnew(n);
	i = 0;
	while (i < n && str[i] == '\0')
	{
		i++;
	}
	if (i == n)
		printf("case 1 of 1: pass\n");
	else
		printf("case 1 of 1: fail\n");
}


void	test_strdel(void)
{
	char	*str;

    printf("test_strdel\n");
	str = (char *)malloc(sizeof(*str) * 4);
	if (str != NULL)
	{
		ft_strdel(&str);
		if (str == NULL)
			printf("case 1 of 1: pass\n");
		else
			printf("case 1 of 1: fail\n");
	}
}



void	test_strclr(void)
{

	char	str[] = "hello";
	int		i;

    printf("test_strclr\n");
	ft_strclr(str);
	i = 0;
	while (i < 6 && str[i] == '\0')
	{
		i++;
	}
	if (i == 6)
		printf("case 1 of 1: pass\n");
	else
		printf("case 1 of 1: fail\n");
}



void    ft_test(unsigned int i, char *s)
{
    printf("%u\n", i);
    *s = 'a';
}

void    test_striteri(void)
{
    void (*f) (unsigned int, char *);
    f = &ft_test;
    char    s[6] = "Hello";

    printf("test_striteri\n");
    ft_striteri(s, f);
    printf("case 1 of 1: %s\n   if aaaaa -> pass", s);
}



char	ft_testfn(char c)
{
	return (c + 1);
}

void	test_strmap(void)
{
	char (*f) (char);
	f = &ft_testfn;
	char const	*s = "Hello";
	char		*ret;

    printf ("test_strmap\n");
	ret = ft_strmap(s, f);
	printf("%s\n", ret);
}



void    test_strsub(void)
{
    char const  s[] = "Hello World";
    char        *ret;

    printf("test_strsub\n");
    ret = ft_strsub(s, 6, 5);
    printf("%s\n", ret);
}



void    test_strjoin(void)
{
    char const  *s1 = "Hello ";
    char const  *s2 = "World!";
    char        *ret;

    ret = ft_strjoin(s1, s2);
    printf("%s\n", ret);
}



void    test_strtrim(void)
{
    char const  *s = "      Hello World     !    ";
    char const  *s1 = "Hello World!";
    char const  *s2 = "Hello    World!    ";
    char const  *s3 = " \nHello World!\n";
    char const  *s4 = " ";
    char        *ret;

    ret = ft_strtrim(s);
    printf("case 1: %s\n", ret);
    ret = ft_strtrim(s1);
    printf("case 2: %s\n", ret);
    ret = ft_strtrim(s2);
    printf("case 3: %s\n", ret);
    ret = ft_strtrim(s3);
    printf("case 4: %s\n", ret);
    ret = ft_strtrim(s4);
    printf("case 5: %s\n", ret);
}



void  tableprint(char **table, int test_num)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = 0;
    if (table != NULL)
    {
        while (table[i])
        {
            len++;
            i++;
        }
        i = 0;
        while (i < len)
        {
            printf("test %d: %s\n", test_num, table[i]);
            i++;
        }   
        printf("test %d: %s\n", test_num, table[i]);
    }
}

void    test_strsplit(void)
{
    char    **table;
    char    **table2;
    char    **table3;
    char    **table4;
    char    **table5;
    char    **table6;

    table = ft_strsplit("Hello World!", ' ');
    tableprint(table, 1);
    printf("Expected: 3 indices\n");
    free(table);
    table2 = ft_strsplit("   split   this for   me !     ", ' ');
    tableprint(table2, 2);
    printf("Expected: 6 indices\n");
    free(table2);
    table3 = ft_strsplit("               ", ' ');
    tableprint(table3, 3);
    printf("Expected: 1 indices\n");
    free(table3);
    table4 = ft_strsplit("               lollll", ' ');
    tableprint(table4, 4);
    printf("Expected: 2 indices\n");
    free(table4);
    table5 = ft_strsplit("loll          ", ' ');
    tableprint(table5, 5);
    printf("Expected: 2 indices\n");
    free(table5);
    table6 = ft_strsplit(NULL, ' ');
    tableprint(table6, 6);
    printf("Expected: NULL");
    free(table6);
}



void	test_itoa(void)
{
	char	*ret;

	ret = ft_itoa(42);
	printf("case 1: %s\n", ret);
	ret = ft_itoa(-42);
	printf("case 2: %s\n", ret);
	ret = ft_itoa(2147483647);
	printf("case 3: %s\n", ret);
	ret = ft_itoa(-2147483648);
	printf("case 4: %s\n", ret);
}



void    test_putchar(void)
{
    ft_putchar('c');
    printf("    if output is 'c' -> pass\n");
}



void    test_putstr(void)
{
    ft_putstr("hello world");
    printf("    if 'hello world' -> pass\n");
}



void    test_putendl(void)
{
    ft_putendl("hello world");
    printf("    if 'hello world w/ newline -> pass\n");
}



void    test_putnbr(void)
{
    ft_putnbr(42);
    printf("\n");
    ft_putnbr(-42);
    printf("\n");
    ft_putnbr(0);
    printf("\n");
    ft_putnbr(5667788);
    printf("\n");
    ft_putnbr(-5667788);
    printf("\n");
    ft_putnbr(-2147483648);
    printf("\n");
}


/*
void    test_lstnew(void)
{
    t_list      *temp;
    char const  *s = "hello";

    temp = ft_lstnew((char const *)s, ft_strlen(s));
    ft_putstr((*temp).content);
    s = NULL;
    temp = ft_lstnew((char const *)s, 5);
    if ((*temp).content == NULL && (*temp).content_size == 0)
        printf("\npass\n");
    else
        printf("\nfail\n");
}
*/

/*
void    ft_print(t_list *n)
{
    while (n != NULL)
    {
        printf("%s\n", (char *)(*n).content);
        printf("%zu \n", (*n).content_size);
        n = (*n).next;
    }
}
*/

/*
void    test_lstadd(void)
{
    t_list  **table;
    t_list  *first;
    t_list  *new;

    table = &first;
    first = (t_list *)malloc(sizeof(*first));
    if (first != NULL)
    {
        (*first).content_size = 4;
        (*first).next = NULL;
    }
    new = (t_list *)malloc(sizeof(*new));
    if (new != NULL)
    {
        (*new).content_size = 9;
        ft_lstadd(table, new);
    }
    ft_print(new);
}
*/
/*
void    ft_del(void *s, size_t n)
{
    ft_memset(s, '\0', n);
}

void    test_lstdelone (void)
{
    void (*del) (void *, size_t);
    del = &ft_del;
    t_list      **temp;
    t_list      *start;
    t_list      *second;
    char const  *s = "hello";
    char const  *s1 = "World";

    start = ft_lstnew((char const *)s, ft_strlen(s));
    second = ft_lstnew((char const *)s1, ft_strlen(s1));
    (*start).next = second;
    temp = &start; 
    ft_lstdelone(temp, del);
    ft_print(temp);
}
*/


void    test_lstsize(void)
{
    t_list  *head;
    t_list  *new;

    printf("test lstsize\n");
    head = (t_list *)malloc(sizeof(*head));
    if (head != NULL)
    {
        (*head).content = NULL;
        (*head).content_size = 2;
        new = (t_list *)malloc(sizeof(*new));
        if (new != NULL)
        {
            (*head).next = new;
            (*new).content = NULL;
            (*new).content_size = 4;
            (*new).next = NULL;
        }
    }
    printf("case 1 of 2: %zu\n", ft_lstsize(head));
    printf("case 2 of 2: %zu\n", ft_lstsize(NULL));
    free(head);

}

void    test_lst_search(void)
{
    t_list  head;
    t_list  next1;
    t_list  next2;
    t_list  *ret;
    char    *s = "World";

    printf("test_lst_search\n");
    head.content = "hello";
    head.content_size = 1;
    head.next = &next1;
    next1.content = "World";
    next1.content_size = 2;
    next1.next = &next2;
    next2.content = "!";
    next2.content_size = 3;
    next2.next = NULL;
    ret = ft_lst_search(&head, s, 5);
    printf("case 1 of 1: %zu\n", (*ret).content_size);

}


void    test_strrev(void )
{
    char *s = strdup("hello");
    char *s1 = NULL;
    char *s2 = strdup("");
    char *ret;

    printf("test_strrev\n");
    ret = ft_strrev(s);
    printf("case 1 of 3: %s\n", ret);
    ret = ft_strrev(s1);
    printf("case 2 of 3: %s\n", ret);
    ret = ft_strrev(s2);
    printf("case 3 of 3: %s\n", ret);

}


void    test_isprime(void)
{
    printf("test isprime\n");
    printf("%zu\n", ft_isprime(0));
    printf("%zu\n", ft_isprime(1));
    printf("%zu\n", ft_isprime(2));
    printf("%zu\n", ft_isprime(3));
    printf("%zu\n", ft_isprime(4));
}

int main(void)
{
    test_memalloc();
    test_memdel();
    test_strnew();
    test_strdel();
    test_strclr();
    test_striteri();
    test_strmap();
    test_strsub();
    test_strjoin();
    test_strtrim();
    test_strsplit();
    test_itoa();
    test_putchar();
    test_putstr();
    test_putendl();
    test_putnbr();
    test_lstsize();
    test_lst_search();
    test_strrev();
    test_isprime();
    return (0);
}

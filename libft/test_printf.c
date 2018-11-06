#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>
#include "../../includes/libft.h"
#include "../../includes/ft_printf.h"
/*
void    test_check_flags(void)
{
    t_specs spec;
    char    str[] = "%#0- +l";
    int     len;

    ft_bzero(&spec, sizeof(spec));
    if (spec.flag_sharp == 0)
        printf("good\n");
    len = check_flags(&spec, str, 1);
    printf("%d\n", len);
    if (spec.flag_sharp != 0)
        printf("success\n");
}

void    test_check_min_width(void)
{
    t_specs  spec;
    char    str[] = "093.";
    int     len;

    ft_bzero(&spec, sizeof(spec));
    len = check_min_width(&spec, str, 0);
    printf("len = %d\n", len);
    printf("min_width = %d\n", spec.min_width);
}
*/

void	test_str_ptr(void)
{
	int	ret;

	printf("\n\n-------------> s tests <----------------\n\n");
    printf("");
    ft_printf("");
    
	printf("hello\n");
    ft_printf("hello\n");
	
	ret = printf("NULL test: {%s}", 0);
	printf("%d\n", ret);
	ret = ft_printf("NULL test: {%s}", 0);
	printf("%d\n", ret);
	
    ret = printf("Empty Str Test: {%s}", "");
	printf("%d\n", ret);
	ret = ft_printf("Empty Str Test: {%s}", "");
	printf("%d\n", ret);
	
    ret = printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("%d\n", ret);
	ret = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("%d\n", ret);
    
    ret = printf("%-5.2s is a string", "this");
	printf("%d\n", ret);
    ret = ft_printf("%-5.2s is a string", "this");
   	printf("%d\n", ret);
    
    ret = printf("%-10s is a string", "this");
	printf("%d\n", ret);
    ret = ft_printf("%-10s is a string", "this");
   	printf("%d\n", ret);	
    
    ret = printf("string test: %.3s", "hello");
	printf("%d\n", ret);
    ret = ft_printf("string test: %.3s", "hello");
	printf("%d\n", ret);
	
	ret = ft_printf("mine:05.s, 0:%05.s", 0);
	printf("%d\n", ret);
    ret = printf("real:05.s, 0:%05.s", 0);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:05.s, 0:%s", NULL);
	printf("%d\n", ret);
    ret = printf("real:05.s, 0:%s", NULL);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:4.s, 42:%4.s", "42");
	printf("%d\n", ret);
    ret = printf("real:4.s, 42:%4.s", "42");
	printf("%d\n", ret);
}

void    test_printf_basic(void)
{
    int     		i = INT_MAX;
	int     		j = INT_MIN;
	unsigned int	m = UINT_MAX;
	long long		k = -9223372038647758071;
    char    		c = 'c';
    int     		*add;
	char			*I = setlocale(LC_ALL, "");
	int				ret;

    add = NULL;


    printf("\n\n------------> INT_MAX test <-------------\n\n");
	ret = ft_printf("mine:d, {%d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%#d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%0d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%-d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%+d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {% d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%#100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%0100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%-100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%+100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% 100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {% 100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%.100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .100d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {% .100d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%.d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.d}", i);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .d}", i);
	printf("%d\n", ret);
    ret = printf("real:d, {% .d}", i);
	printf("%d\n", ret);


    printf("\n\n------------> INT_MIN test <-------------\n\n");
	ret = ft_printf("mine:d, {%d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%#d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%0d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%-d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%+d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {% d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%#100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%0100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%-100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%+100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% 100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {% 100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%.100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .100d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {% .100d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%.d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.d}", j);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .d}", j);
	printf("%d\n", ret);
    ret = printf("real:d, {% .d}", j);
	printf("%d\n", ret);
    

	printf("\n\n-----------> Flags/Precision/width Test <-------------\n\n"); 
	ret = printf(" d Test: % d", 9999);
	printf("%d\n", ret);
	ret = ft_printf(" d Test: % d", 9999);
	printf("%d\n", ret);
	ret = printf("%03.2d", 0);
	printf("%d\n", ret);
	ret = ft_printf("%03.2d", 0);
	printf("%d\n", ret);
   	ret = printf(".0 test: %.0d\n", 0);
	printf("%d\n", ret);
   	ret = ft_printf(".0 test: %.0d\n", 0);
	printf("%d\n", ret);
    ret = printf("hh test: %-6.6hhd", i);
	printf("%d\n", ret);
    ret = ft_printf("hh test: %-6.6hhd", i);
	printf("%d\n", ret);
   	ret = printf("ll test: %lld", k);
	printf("%d\n", ret);
    ret = ft_printf("ll test: %lld", k);
	printf("%d\n", ret);
    ret = printf("03.2d, 0: {%03.2d}", 0);
	printf("%d\n", ret);
    ret = ft_printf("03.2d, 0: {%03.2d}", 0);
   	printf("%d\n", ret);
	ret = printf("03.2d, 1: {%03.2d}", 1);
	printf("%d\n", ret);
    ret = ft_printf("03.2d, 1: {%03.2d}", 1);
   	printf("%d\n", ret);
    ret = printf("0+5d, 42: {%0+5d}", 42);
	printf("%d\n", ret);
    ret = ft_printf("0+5d, 42: {%0+5d}", 42);
   	printf("%d\n", ret);
   	ret = printf("5d, -42: {%5d}", -42);
	printf("%d\n", ret);
    ret = ft_printf("5d, -42: {%5d}", -42);
   	printf("%d\n\n", ret);
	ret = printf("10d, -42: {%10d}", -42);
	printf("%d\n", ret);
    ret = ft_printf("10d, -42: {%10d}", -42);
   	printf("%d\n\n", ret);
    ret = printf("#+10d, 4242: {%+10d}", 4242);
	printf("%d\n", ret);
    ret = ft_printf("#+10d, 4242: {%+10d}", 4242);
   	printf("%d\n\n", ret);
	ret = ft_printf("mine: 10.5d, 4242:% 10.5d", 4242);
	printf("%d\n", ret);
    ret = printf("real: 10.5d, 4242:% 10.5d", 4242);
	printf("%d\n", ret);
	ret = ft_printf("mine:+d, 0:%+d", 0);
	printf("%d\n", ret);
    ret = printf("real:+d, 0:%+d", 0);
	printf("%d\n", ret);
	ret = ft_printf("mine:5.d, 0:%5.d", 0);
	printf("%d\n", ret);
    ret = printf("real:5.d, 0:%#5.d", 0);
	printf("%d\n", ret);
	ret = ft_printf("mine:0-3d, 0:{%0-3d}", 0);
	printf("%d\n", ret);
    ret = printf("real:0-3d, 0:{%0-3d}", 0);
	printf("%d\n", ret);
	ret = ft_printf("mine:rd:, 123:%4dd", 123);
	printf("%d\n", ret);
    ret = printf("real:rd:, 123:%4dd", 123);
	printf("%d\n", ret);
    
    printf("\n\n--------------> p test <------------------\n\n");
	ret = ft_printf("mine:d, {%p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%#p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%0p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%-p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%+p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {% p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%#100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%0100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%-100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%+100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% 100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {% 100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%.100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .100p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {% .100p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%.p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.p}", add);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .p}", add);
	printf("%d\n", ret);
    ret = printf("real:d, {% .p}", add);
	printf("%d\n", ret);
	
	ret = printf("ignore p test: %lp", 42);
	printf("-->%d<--\n", ret);
	ret = ft_printf("ignore p test: %lp", 42);
	printf("-->%d<--\n\n", ret);
    
	ret = ft_printf("mine:.p, 0:{%.p}", 0);
	printf("%d\n", ret);
    ret = printf("real:.p, 0:{%.p}", 0);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:3.p, 0:{%3.p}", 0);
	printf("%d\n", ret);
    ret = printf("real:3.p, 0:{%3.p}", 0);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:05.p, 0:{%05.p}", 0);
	printf("%d\n", ret);
    ret = printf("real:05.p, 0:{%05.p}", 0);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:05p, 0:%05p", 0);
	printf("%d\n", ret);
    ret = printf("real:05p, 0:%05p", 0);
	printf("%d\n", ret);
	
    ret = printf("pointer test: %p", add);
	printf("%d\n", ret);
    ret = ft_printf("pointer test: %p", add);
	printf("%d\n", ret);
	
	
	printf("\n\n--------------> Mixed Test <------------------\n\n");
    ret = printf("hello this is a test: %#3.4x and %#-5X", i, j);
	printf("%d\n", ret);
    ret = ft_printf("hello this is a test: %#3.4x and %#-5X", i, j);
	printf("%d\n", ret);
    ret = printf("character test: %#5.8cblablabla", c);
	printf("%d\n", ret);
    ret = ft_printf("character test: %#5.8cblablabla", c);
	printf("%d\n", ret);
    ret = printf("percent test: %%");
	printf("%d\n", ret);
    ret = ft_printf("percent test: %%");
	printf("%d\n", ret);
    ret = printf("h test: %#hx", j);
	printf("%d\n", ret);
    ret = ft_printf("h test: %#hx", j);
	printf("%d\n", ret);
    ret = printf("modulo test: %");
	printf("%d\n", ret);
    ret = ft_printf("modulo test: %");
	printf("%d\n\n", ret);
	ret = ft_printf("mine:5:%5%");
	printf("%d\n", ret);
    ret = printf("real:5:%5%");
	printf("%d\n", ret);
    
    
	printf("\n\n--------------> o test <------------------\n\n");
	ret = ft_printf("mine:d, {%o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%#o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%0o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%-o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%+o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {% o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%#100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%0100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%-100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%+100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% 100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {% 100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%.100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%-.100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%+.100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%+.100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {% .100o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {% .100o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%.o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%.o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%#.o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%#.o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%0.o}", m);
	printf("%d\n", ret);
    ret = printf("real:d, {%0.o}", m);
	printf("%d\n", ret);
	ret = ft_printf("mine:d, {%-.o}", m);
	printf("%d\n", ret);
    ret = printf("%o", 0);
	printf("%d\n", ret);
	ret = ft_printf("%o", 0);
	printf("%d\n", ret);
	
	ret = printf("%#o", 0);
	printf("%d\n", ret);
	ret = ft_printf("%#o", 0);
	printf("%d\n", ret);
	
	ret = printf("%#.o", 0);
	printf("%d\n", ret);
	ret = ft_printf("%#.o", 0);
	printf("%d\n", ret);
	
	ret = printf("%.o", 0);
	printf(" ret = %d\n", ret);
	ret = ft_printf("%.o", 0);
	printf(" ret = %d\n", ret);
	
    ret = printf("%.o", 3);
	printf(" ret = %d\n", ret);
	ret = ft_printf("%.o", 3);
	printf(" ret = %d\n", ret);
	
	ret = ft_printf("mine:5.0o, 0:%5.0o", 0);
	printf("%d\n", ret);
    ret = printf("real:5.0o, 0:%5.0o", 0);
	printf("%d\n", ret);
	
    ret = printf("-+6o, 2500: {%-+6o}", 2500);
	printf("%d\n", ret);
    ret = ft_printf("-+60, 2500: {%-+6o}", 2500);
   	printf("%d\n", ret);
    
	ret = printf("precision o test: %.o, %#.0o\n", 0, 0);
	printf("%d\n", ret);
   	ret = ft_printf("precision o test: %.o, %#.0o\n", 0, 0);
	printf("%d\n", ret);
   	
	printf("\n\n--------------> x test <------------------\n\n");
	ret = printf("sharp-precision x test: %#.x, %#.0x\n", 0, 0);
	printf("%d\n", ret);
   	ret = ft_printf("sharp-precision x test: %#.x, %#.0x\n", 0, 0);
	printf("%d\n", ret);
	ret = printf("#8x, 42: {%#8x}", 42);
	printf("%d\n", ret);
    ret = ft_printf("#8x, 42: {%#8x}", 42);
   	printf("%d\n", ret);
    ret = printf("llx limit:%llx", 4294967296);
	printf("%d\n", ret);
	ret = ft_printf("llx limit:%llx", 4294967296);
	printf("%d\n\n", ret);
	ret = printf("#08x, 42: {%#08x}", 42);
	printf("%d\n", ret);
    ret = ft_printf("#08x, 42: {%#08x}", 42);
   	printf("%d\n\n", ret);
	ret = printf("#-08x, 42: {%#-08x}", 42);
	printf("%d\n", ret);
    ret = ft_printf("#-08x, 42: {%#-08x}", 42);
   	printf("%d\n\n", ret);
	ret = ft_printf("mine:x, 0:%x", 0);
	printf("%d\n", ret);
    ret = printf("real:x, 0:%x", 0);
	printf("%d\n", ret);
	ret = ft_printf("mine:#3x, 0:%#3.6x", 0);
	printf("%d\n", ret);
    ret = printf("real:#3x, 0:%#3.6x", 0);
	printf("%d\n", ret);
    
    
	printf("\n\n--------------> u test <------------------\n\n");
	ret = ft_printf("mine:u, 0:{%u}", 0);
	printf("%d\n", ret);
    ret = printf("real:u, 0:{%u}", 0);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:.u, 0:{%.u}", 0);
	printf("%d\n", ret);
    ret = printf("real:.u, 0:{%.u}", 0);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:5u, 0:{%5u}", 0);
	printf("%d\n", ret);
    ret = printf("real:5u, 0:{%5u}", 0);
	printf("%d\n", ret);
	
	printf("\n\n--------------> c test <------------------\n\n");
	ret = ft_printf("mine:2c,0:%2c", 0);
	printf("%d\n", ret);
    ret = printf("real:2c,0:%2c", 0);
	printf("%d\n", ret);
	ret = ft_printf("mine:03c, 0:{%03c}", 0);
	printf("%d\n", ret);
    ret = printf("real:03c, 0:{%03c}", 0);
	printf("%d\n", ret);
	ret = printf("char 0: %c", 0);
	printf("%d\n", ret);
	ret = ft_printf("char 0: %c", 0);
	printf("%d\n", ret);
	
	
	printf("\n\n--------------> wchar test <------------------\n\n");
	ret = printf("C test: %C", 30000);
	printf("%d\n", ret);
    ret = ft_printf("C test: %C", 30000);
	printf("%d\n", ret);
	ret = printf("C 0: %.C", 0);
	printf("%d\n", ret);
	ret = ft_printf("C 0: %.C", 0);
	printf("%d\n", ret);
  	ret = printf("S test: %S\n", L"我是一只猫");
	printf("%d\n", ret);
   	ret = ft_printf("S test: %S\n", L"我是一只猫");
	printf("%d\n", ret);
    test_str_ptr();
}

void    test_snprintf(void)
{
	printf("\n\n----> sprintf <------\n\n");
    char *str;

    str = (char *)malloc(sizeof(*str) * 20);
    if (str)
        write(1, str, ft_sprintf(str, "hello world!"));
}

void	test_unresolved(void)
{
	int	ret;

	printf("\n\n-------> UNRESOLVED <---------\n\n");
	
    
	
	ret = ft_printf("mine:.4S: %.4S", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d\n", ret);
	ret = printf("real:.4S: %.4S", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("%d\n", ret);
	
	ret = ft_printf("mine:-15Z, 123:%-15Z", 123);
	printf("%d\n", ret);
    ret = printf("real:-15Z, 123:%-15Z", 123);
	printf("%d\n", ret);
	
	ret = ft_printf("mine:05.Z, 0:%05.Z", 0);
	printf("%d\n", ret);
    ret = printf("real:05.Z, 0:%05.Z", 0);
	printf("%d\n", ret);
	
    
	ret = ft_printf("mine:#.3o:, 1:%#.3o", 1);
	printf("%d\n", ret);
    ret = printf("real:#.3o:, 1:%#.3o", 1);
	printf("%d\n", ret);

	ret = ft_printf("mine:hhC, 0, hhC:%hhC, %hhC", 0, L'Á±≥');
	printf("%d\n", ret);
	ret = printf("real:hhC, 0, hhC:%hhC, %hhC", 0, L'Á±≥');
	printf("%d\n", ret);
	
	ret = ft_printf("mine:lc:%lc", L'Á±≥');
	printf("%d\n", ret);
	ret = printf("real:lc:%lc", L'Á±≥');
	printf("%d\n", ret);
	
	ret = ft_printf("mine:C:%C", L'ÁM-^L´');
	printf("%d\n", ret);
	ret = printf("real:C:%C", L'ÁM-^L´');
	printf("%d\n", ret);
	
}

void	test_sysdiff(void)
{
	int ret;

	printf("\n\n----------------------> system diff <--------------------------\n\n");

    ret = printf("kaslaj%");
	printf("%d\n", ret);
    ret = ft_printf("kaslaj%"); 
	printf("%d\n", ret);
    
    ret = printf("test D: %D", 0L);
	printf("-->%d<--\n", ret);
	ret = ft_printf("test D: %D", 0L);
	printf("-->%d<--\n", ret);
	
    ret = printf("0 precision: %.0p, %.p", 0, 0);
	printf("-->%d<--\n", ret);
	ret = ft_printf("0 precision: %.0p, %.p", 0, 0);
	printf("-->%d<--\n", ret);
	
    ret = printf("5 precision: %.5p", 0);
	printf("-->%d<--\n", ret);
	ret = ft_printf("5 precision: %.5p", 0);
	printf("-->%d<--\n", ret);
	
    ret = printf("p = 0 test: %p", 0);
	printf("-->%d<--\n", ret);
	ret = ft_printf("p = 0 test: %p", 0);
	printf("-->%d<--\n", ret);
	
    
    ret = printf("Test U: %U", "42");
	printf("-->%d<--\n", ret);
	ret = ft_printf("Test U: %U", "42");
	printf("-->%d<--\n", ret);
	
    ret = printf("Test O: %#O", 1);
	printf("-->%d<--\n", ret);
	ret = ft_printf("Test O: %#O", 1);
	printf("-->%d<--\n", ret);
	
    ret = printf("{%hU}", "4294967296");
	printf("-->%d<--\n", ret);
    ret = ft_printf("{%hU}", "4294967296");
   	printf("-->%d<--\n", ret);
	
}

int     main(void)
{
    //test_check_flags();
    //test_check_min_width();
    test_printf_basic();
    test_unresolved();
    test_sysdiff();
    //test_snprintf();
    return (0);
}

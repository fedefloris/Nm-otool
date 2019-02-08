/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:16 by ffloris           #+#    #+#             */
/*   Updated: 2018/11/14 17:56:44 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "ft_printf.h"
# define BUFF_SIZE 4096

typedef unsigned char	t_uchar;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_buff
{
	int					fd;
	char				*content;
	struct s_buff		*next;
}						t_buff;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
																size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);

void					ft_swap(int *a, int *b);
void					ft_quicksort(int *a, int a_size);
int						ft_is_sorted(int *a, int a_size);
char					**ft_strtable(size_t row_size, size_t col_size);
void					ft_strdel_table(char **arr);
void					ft_struct_del(void *el, size_t el_size);

size_t					ft_strlen(const char *s);
size_t					ft_wcharlen(const wchar_t c);
size_t					ft_wstrlen(const wchar_t *s);
size_t					ft_wstrblen(const wchar_t *s);
size_t					ft_nwstrblen(const wchar_t *s, size_t n);
char					*ft_strdup(const char *src);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *dst, const char *src);
char					*ft_strncat(char *dst, const char *src, size_t nb);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					ft_strrev(char **str);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack,
														const char *needle);
char					*ft_strnstr(const char *haystack,
											const char *needle, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(char const *s1, char const *s2, size_t n);
int						ft_atoi(const char *s);
int						ft_atoi_n(const char *s, size_t n);
long					ft_atol(const char *s);
long long				ft_atoll(const char *s);
int						ft_isspace(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isnumber(char *str);
int						ft_isinteger(char *str);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s,
											void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
											char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
											unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoinfree(char *ret, char *s1, char *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					**ft_split(char const *s);
char					*ft_itoa(int n);
char					*ft_itoa_base(int n, int base);

void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putwchar(wchar_t c);
void					ft_putwchar_fd(wchar_t c, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putwstr(const wchar_t *s);
void					ft_putwstr_fd(const wchar_t *s, int fd);
void					ft_putendl(const char *s);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnstr(const char *s, size_t n);
void					ft_putnstr_fd(const char *s, int fd, size_t n);
void					ft_putnwstr(const wchar_t *s, size_t n);
void					ft_putnwstr_fd(const wchar_t *s, int fd, size_t n);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);

t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstcpy(void *content, size_t content_size);
void					ft_lstremove(t_list **alst, void *content,
																int (*cmp)());
void					ft_lstdelone(t_list **alst,
												void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstappend(t_list **lst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstfind(t_list *lst, void *content, int (*cmp)());
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t					ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstat(t_list *lst, size_t nbr);
void					ft_lstreverse(t_list **lst);
void					ft_lstmerge(t_list **lst1, t_list *lst2);
void					ft_lstsort(t_list **lst, int (*cmp)());
int						ft_lstsorted(t_list *a, int (*cmp)());
t_list					*ft_lstmiddle(t_list *head);

int						ft_abs(int a);
int						ft_clamp(int a, int min, int max);
double					ft_sqrt(double a);
int						ft_pow(int b, int e);
int						ft_get_next_line(const int fd, char **line);
int						ft_get_next(const int fd, char **line, char c);
int						ft_printf(const char *s, ...);
#endif

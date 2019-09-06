/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:34:30 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/22 03:27:14 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libftprintf.h"

# define CHCST		char const
# define CSTCH		const char
# define S_T		size_t
# define CSTIN		const int
# define UINT		unsigned int

# define SUCCESS	0
# define ERROR		1

# define INTMIN		-2147483648
# define INTMAX		2147483647

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_list
{
	void			*content;
	S_T				content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(CSTCH *str);
int					ft_abs(int number);
void				ft_bzero(void *s, S_T len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(S_T size);
void				*ft_memccpy(void *dst, const void *src, int c, S_T n);
void				*ft_memchr(const void *s, int c, S_T n);
void				*ft_memcpy(void *dst, const void *src, S_T n);
int					ft_memcmp(const void *s1, const void *s2, S_T n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, S_T len);
void				*ft_memset(void *b, int c, S_T len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(CHCST *s);
void				ft_putendl_fd(CHCST *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(CHCST *s);
void				ft_putstr_fd(CHCST *s, int fd);
char				*ft_strcat(char *s1, CSTCH *s2);
char				*ft_strchr(CSTCH *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(CSTCH *s1, CSTCH *s2);
char				*ft_strcpy(char *dst, CSTCH *src);
void				ft_strdel(char **as);
char				*ft_strdup(CSTCH *s1);
int					ft_strequ(CHCST *s1, CHCST *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(CHCST *s1, CHCST *s2);
char				*ft_strjoin_free(CHCST **s1, CHCST **s2, S_T nb);
S_T					ft_strlcat(char *dst, CSTCH *src, S_T size);
S_T					ft_strlen(CSTCH *s);
char				*ft_strmap(CHCST *s, char (*f)(char));
char				*ft_strmapi(CHCST *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, S_T n);
int					ft_strncmp(CSTCH *s1, CSTCH *s2, S_T n);
char				*ft_strndup(CSTCH *s1, S_T n);
int					ft_strnequ(CHCST *s1, CHCST *s2, S_T n);
char				*ft_strnjoin_free(CHCST **s1, CHCST **s2, S_T len, S_T nb);
char				*ft_strnstr(CSTCH *h, CSTCH *n, S_T len);
char				*ft_strncpy(char *dst, CSTCH *src, S_T len);
char				*ft_strnew(S_T size);
char				*ft_strrchr(CSTCH *s, int c);
char				**ft_strsplit(CHCST *s, char c);
char				*ft_strsub(CHCST *s, unsigned int start, S_T len);
char				*ft_strstr(CSTCH *haystack, CSTCH *needle);
char				*ft_strtrim(CHCST *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

t_list				*ft_lstnew(void const *content, S_T content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, S_T));
void				ft_lstdel(t_list **alst, void (*del)(void*, S_T));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_colchr(char **map, int height, char val, int column);
int					ft_count_digit_base(long n, int base);
int					ft_ucount_digit_base(unsigned long n, int base);
char				*ft_strrev(char *s);
void				ft_swap(char *a, char *b);
int					ft_factorial(int nb);
int					ft_sqrt(int nb);
long				ft_pow(int number, int pow);
void				ft_print_bits(unsigned char octet);
unsigned char		ft_swap_bits(unsigned char octet);
unsigned char		ft_reverse_bits(unsigned char octet);
char				*ft_itoa_base(int n, int base);
char				*ft_ultoa_base(unsigned long n, int base);
char				*ft_ltoa_base(long n, int base);
void				ft_strtoupper(char *s);
void				ft_ltoa_base_buff(long n, int base, char *value);
void				ft_ultoa_base_buff(unsigned long n, int base, char *val);
long				ft_atol(CSTCH *str);

#endif

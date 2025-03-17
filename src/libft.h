/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:08:24 by juportie          #+#    #+#             */
/*   Updated: 2025/03/14 12:02:04 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define UINT_MAX 4294967295
// Macros for error handling
# define WRONG_INPUT 1
# define OVERFLOW 2
# define UNDERFLOW 4

# include <stdlib.h>
# include <unistd.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

//LISTS
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(
					t_list *lst, void *(*f)(void *), void (*del)(void *));

//ADDED FUNCTIONS
//	CHECKS
int				ft_isdigitstr(char *str);
int				ft_issdigitstr(char *str);
int				ft_ismuloverflow(int a, int b);
//	CONVERSIONS
typedef struct s_iflag
{
	int				i;
	int				flag;
}	t_iflag;
int				ft_atoi_sat(const char *nptr);
t_iflag			ft_atoi_flag(const char *nptr);
unsigned int	ft_atoui_base(const char *nptr, char *base);
unsigned int	ft_uhextoui(const char *nptr);
//	DOUBLY LINKED LISTS
typedef struct s_dlst
{
	void				*content;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}	t_dlst;
t_dlst			*ft_dlstnew(void *);
void			ft_cdlstadd_back(t_dlst **lst, t_dlst *new_node);
void			ft_cdlstadd_front(t_dlst **lst, t_dlst *new_node);
void			ft_cdlstclear(t_dlst **lst);
int			ft_cdlstsize(t_dlst *lst);

typedef struct s_dlstip
{
	int				*content;
	struct s_dlstip	*next;
	struct s_dlstip	*prev;
}	t_dlstip;
t_dlstip		*ft_dlstip_new(int *content);
void			ft_cdlstip_add_back(t_dlstip **lst, t_dlstip *new_node);
void			ft_cdlstip_add_front(t_dlstip **lst, t_dlstip *new_node);
void			ft_dlstip_clear(t_dlstip **lst);

typedef struct s_dlsti
{
	int				content;
	struct s_dlsti	*next;
	struct s_dlsti	*prev;
}	t_dlsti;

t_dlsti			*ft_dlsti_new(int i);
void			ft_cdlsti_add_back(t_dlsti **lst, t_dlsti *new_node);
void			ft_cdlsti_add_front(t_dlsti **lst, t_dlsti *new_node);
void			ft_cdlsti_clear(t_dlsti **lst);
void			ft_print_dlsti(t_dlsti *lst);
int				ft_cdlsti_size(t_dlsti *lst);

#endif

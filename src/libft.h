/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:08:24 by juportie          #+#    #+#             */
/*   Updated: 2025/06/03 16:10:51 by juportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif
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
//	MODIFED LIB FUNCTIONS
char			*ft_strdup_s(const char *s);
//	CHECKS
int				ft_isdigitstr(char *str);
int				ft_issdigitstr(char *str);
int				ft_isequalstr(char *str_a, char *str_b);
int				ft_ismuloverflow(int a, int b);
//	MATHS
int				ft_sqrt_floor(int nbr);
//	CONVERSIONS
typedef struct s_iflag
{
	int				nbr;
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
	struct s_dlst		*next;
	struct s_dlst		*prev;
}	t_dlst;
t_dlst			*ft_dlstnew(void *content);
t_dlst			*ft_dlstlast(t_dlst *lst);
t_dlst			*ft_dlsthead(t_dlst *lst);
void			ft_dlstadd_back(t_dlst **lst, t_dlst *new_node);
void			ft_dlstadd_front(t_dlst **lst, t_dlst *new_node);
void			ft_dlstinsert_next(t_dlst **lst, t_dlst *new_node);
void			ft_dlstinsert_sublist_next(t_dlst *lst, t_dlst *sublist);
int				ft_dlstsize(t_dlst *lst);
void			ft_dlstclear(t_dlst *lst, void del(void *));
void			ft_dlstremove(
					t_dlst *node,
					void del_content(void *),
					void del_node(void *));
void			ft_dlstsplit(t_dlst *lst_b_head);
void			ft_cdlstadd_back(t_dlst **lst, t_dlst *new_node);
void			ft_cdlstadd_front(t_dlst **lst, t_dlst *new_node);
void			ft_cdlstclear(t_dlst **lst);
int				ft_cdlstsize(t_dlst *lst);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:04:38 by polenyc           #+#    #+#             */
/*   Updated: 2024/09/28 19:14:02 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

# define HEX_BASE_L		"0123456789ABCDEF"
# define HEX_BASE_S		"0123456789abcdef"
# define OCTA_BASE		"012345678"
# define BIN_BASE		"01"
# define P_C_BLACK		"\033[30m"
# define P_C_RED		"\033[31m"
# define P_C_GREEN		"\033[32m"
# define P_C_YELLOW		"\033[33m"
# define P_C_BLUE		"\033[34m"
# define P_C_MAGENT		"\033[35m"
# define P_C_CYAN		"\033[36m"
# define P_C_WHITE		"\033[37m"
# define FT_BIT_MAX		8
# define FT_UCHARMAXVAL	255

enum	e_bits
{
	FT_BITERROR,
};

typedef const char		t_cchar;
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef void			(*t_del)(void *);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlist
{
	int				number;
	void			*content;
	struct s_dlist	*next;
}				t_dlist;

typedef struct s_dllist
{
	int				pid;
	void			*data;
	struct s_dllist	*next;
	struct s_dllist	*previous;
}					t_dllist;

typedef struct s_llist
{
	void			*data;
	struct s_llist	*next;
	struct s_llist	*previous;
}					t_llist;

long		ft_atoi_base(const char *nptr, const char *base);
long		ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int arg);
int			ft_isalpha(int arg);
int			ft_isascii(int arg);
int			ft_isdigit(int arg);
int			ft_isprint(int arg);
int			ft_isspace(int c);
char		*ft_itoa(int n);
int			ft_matsize(const char **matrix);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putstr(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_straddchr(char *dest, char ch);
char		*ft_straddchrfree(char *dest, char ch);
char		*ft_strcpy(char *dest, char const *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinfree(char *s1, char *s2, int pos);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		**ft_strsdup(const char **src);
char		*ft_strndup(const char *src, int n);
char		*ft_strldup(const char *src, int n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strncpy(char *dest, const char *src, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_filesize(char *filename);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
const char	*ft_strlcmp(const char *str, const char *cmp);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *str, int ch);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
void		ft_lstclear(t_list **lst, t_del del);
void		ft_lstdelone(t_list *lst, t_del del);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), t_del);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
/////////////////////////////////////////////T_DLIST\\\\\\\\\\\\\\\\\\\\\\\\\\/
void		ft_dlstadd_back(t_dlist **lst, t_dlist *newnode);
void		ft_dlstadd_front(t_dlist **lst, t_dlist *newnode);
void		ft_dlstclear(t_dlist **lst, t_del del);
void		ft_dlstdelone(t_dlist *lst, t_del del);
void		ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist		*ft_dlstlast(t_dlist *lst);
t_dlist		*ft_dlstmap(t_dlist *l, void *(*f)(void *), t_del del, int n);
t_dlist		*ft_dlstnew(int number, void *content);
int			ft_dlstsize(t_dlist *lst);
/////////////////////////////////////////////T_DLIST\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_dllist	*dllistadd_back(t_dllist **dllst, t_dllist *newnode);
t_dllist	*dllistadd_front(t_dllist **dllst, t_dllist *newnode);
void		*dllistclear(t_dllist **dllst, t_del del);
t_dllist	*dllistdelnode(t_dllist **dllst, t_del del);
t_dllist	*dllistnewnode(int pid, void *data);
int			dllistsize(t_dllist *dllst);
/////////////////////////////////////////////T_LLIST\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_llist		*llistadd_back(t_llist **llst, t_llist *newnode);
t_llist		*llistadd_front(t_llist **llst, t_llist *newnode);
void		*llistclear(t_llist **llst, t_del del);
t_llist		*llistdelnode(t_llist **llst, t_del del);
void		llistiter(t_llist *lst, void (*f)(void *));
t_llist		*llistnewnode(void *data);
t_llist		*llistmap(t_llist *lst, void *(*f)(void *), void (*del)(void *));
int			llistsize(t_llist *llst);
t_llist		*llistinsert(t_llist *pos, t_llist *newnode);
/////////////////////////////////////////////FT_FREE\\\\\\\\\\\\\\\\\\\\\\\\\\/
void		ft_freenode(void *data);
void		*ft_free(void *ptr);
void		*ft_free_d(void **ptr);
void		*ft_free_t(void ***ptr);
/////////////////////////////////////////////FT_FILE\\\\\\\\\\\\\\\\\\\\\\\\\\/
long		filesize(const char *filename);
/////////////////////////////////////////////FT_FILE\\\\\\\\\\\\\\\\\\\\\\\\\\/
void		*ft_perror(const char *msg);
/////////////////////////////////////////////FT_GETPRIMES\\\\\\\\\\\\\\\\\\\\\/
t_uchar		*ft_getmarkprimes(unsigned long num);
t_llist		*ft_getprimes(unsigned long num);
////////////////////////////////////FT_BIT_OPER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_uchar		getbit(t_uchar *data, t_uint bit);
t_uchar		resetbit(t_uchar *data, t_uint bit);
t_uchar		setbit(t_uchar *data, t_uint bit);
#endif
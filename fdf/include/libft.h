/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:44:27 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/17 11:55:43 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_char_list
{
	char			*str_buffer;
	struct s_char_list	*next;
}				t_char_list;

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int dig);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(const char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_atoi_base(const char *str, int base);
int			ft_lstsize(t_list *lst);
int			ft_printf(const char *format, ...);
int			print_char(int c);
int			find_format(char specifier, va_list ap);
int			print_string(const char *str);
int			print_digit(long n, int base, int upper);
int			print_address(unsigned long address);
int			found_newline(t_char_list *list);
int			ft_count_words(char	*str, char c);
int 		ft_count_file_rows(int fd, char c);
int 		ft_count_file_lines(int fd);
void		*ft_memset(void *ptr, int value, size_t len);
void		ft_bzero(void *ptr, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		create_list(int fd, t_char_list **list);
void		create_node(t_char_list **list, char *buffer, int bytes_read);
void		extract_line(t_char_list *list, char **line);
void		clean_list(t_char_list **list);
void		create_line(char **line, t_char_list *list);
void		delete_list(t_char_list **list);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char*src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*get_next_line(int fd);
char		**ft_split(const char *s, char c);
t_list		*ft_lstnew(void *nbr);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_char_list	*get_last_node(t_char_list *list);


#endif
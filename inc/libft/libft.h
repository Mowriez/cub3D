/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:59:24 by mtrautne          #+#    #+#             */
/*   Updated: 2022/12/15 20:11:59 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ToDo: Check, if all prototypes are the same in functions as in libft.h!!!*/

/*ifndefine/define are include guards: Checks whether an unique value (in this 
case LIBFT_H is already defined - meaning the header file beeing already 
included somewhere else)
if not -> it defines LIBFT_H and continues through the rest of the file. If 
LIBFT_H is already defined, it jumps to the endif and omits the second 
inclusion of the header file.*/

#ifndef LIBFT_H
# define LIBFT_H

/* Function Prototypes tell the compiler that there exists a function of the
declared name with the declared input and return values in one of the compiled
files, so one doesnt have to forward declare every fct. Because compiling works 
in two stages (The first is the compilation of "source" text files into binary 
"object" files: The file is compiled without any knowledge about the other files 
(or even libraries), unless fed to it through raw declaration or header 
inclusion. 
The  file is usually compiled into a .OBJ or a .O "object" file.
Only second is the linking together of all the "object" files, and thus, the 
creation of the final binary file (either a library or an executable). So gcc
needs you to not be an idiot in the first step and use proper input vars and so
on. */

/*needed for all functions that use a variable of type size_t*/
# include <stddef.h>
/*needed for all functions that use malloc*/
# include <stdlib.h>
/*needed for all functions that use write*/
# include <unistd.h>
/*needed for compilation on linux*/
# include <stdint.h>

//Functions Part 1:
/*checks if c is an alphabetical character.*/
int		ft_isalpha(int c);
/*checks if c is a digit (0 through 9)*/
int		ft_isdigit(int c);
/*checks if c is alphanumerical*/
int		ft_isalnum(int c);
/*checks if c is in the ascii character set.*/
int		ft_isascii(int c);
/*checks if c is a printable char.*/
int		ft_isprint(int c);
/*converts a lower-case letter to the corresponding upper-case letter.*/
int		ft_toupper(int c);
/*converts an upper-case letter to the corresponding lower-case letter.*/
int		ft_tolower(int c);
/*converts the initial portion of the string pointed to by str to int 
representation.*/
int		ft_atoi(const char *str);

/*copies up to dstsize - 1 characters from the string src to dst, 
NULL-terminating the result if dstsize is not 0.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*appends src to the end of dst, but at most dstsize-1 characters. NUL-
Terminates if there is room.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/*returns a pointer to the last occurrence of the character c in the 
string s.*/
char	*ft_strrchr(const char *s, int c);
/*locates the first occurrence of the null-terminated string needle in the 
string haystack, where not more than len characters are searched. Characters 
that appear after a ‘\0’ character are not searched.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*compares the first (at most) n bytes of s1 and s2.*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*writes n zeroed bytes to the string s. If n is zero, does nothing.*/
void	ft_bzero(void *s, size_t n);
/*writes len bytes of value c (converted to an unsigned char) to 
the string b.*/
void	*ft_memset(void *b, int c, size_t len);
/*copies n bytes from memory area src to memory area dst. If dst and 
src overlap, behavior is undefined.*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
/*copies len bytes from string src to string dst. The two strings may overlap; 
the copy is always done in a non-destructive manner.*/
void	*ft_memmove(void *dst, const void *src, size_t len);
/*locates the first occurrence of c (converted to an unsigned char) in 
string s.*/
void	*ft_memchr(const void *s, int c, size_t n);
/*compares byte string s1 against byte string s2.  Both strings are assumed
to be n bytes long.*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*allocates sufficient memory for a copy of the string s1, does the copy, and 
returns a pointer to it.*/
char	*ft_strdup(const char *s1);
/*contiguously allocates enough space for count objects that are size bytes of 
memory each and returns a pointer to the allocated memory. The allocated memory 
is filled with bytes of value zero.*/
void	*ft_calloc(size_t count, size_t size);

//Functions Part 2:
/*See functions for description*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//Header get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *static_str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_next_line(char *static_str);
char	*ft_resize_static_str(char *static_str);

#endif
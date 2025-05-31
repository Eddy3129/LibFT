/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:12:54 by marvin            #+#    #+#             */
/*   Updated: 2025/05/31 13:12:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// Windows doesn't have these functions, so we'll implement simple versions for testing
#ifdef _WIN32
void bzero(void *s, size_t n) {
    memset(s, 0, n);
}

size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t src_len = strlen(src);
    if (size > 0) {
        size_t copy_len = (src_len < size - 1) ? src_len : size - 1;
        memcpy(dst, src, copy_len);
        dst[copy_len] = '\0';
    }
    return src_len;
}

size_t strlcat(char *dst, const char *src, size_t size) {
    size_t dst_len = strlen(dst);
    size_t src_len = strlen(src);
    if (dst_len >= size) return dst_len + src_len;
    return strlcpy(dst + dst_len, src, size - dst_len) + dst_len;
}

char *strnstr(const char *haystack, const char *needle, size_t len) {
    size_t needle_len = strlen(needle);
    if (needle_len == 0) return (char *)haystack;
    for (size_t i = 0; i <= len - needle_len && haystack[i]; i++) {
        if (strncmp(haystack + i, needle, needle_len) == 0)
            return (char *)(haystack + i);
    }
    return NULL;
}
#endif

void print_test_result(const char *function_name, int test_num, int passed) {
    printf("%s Test %d: %s\n", function_name, test_num, passed ? "PASS" : "FAIL");
}

// Character classification tests
void test_ft_isalpha() {
    printf("\n=== Testing ft_isalpha ===\n");
    print_test_result("ft_isalpha", 1, !!ft_isalpha('a') == !!isalpha('a'));
    print_test_result("ft_isalpha", 2, !!ft_isalpha('Z') == !!isalpha('Z'));
    print_test_result("ft_isalpha", 3, !!ft_isalpha('5') == !!isalpha('5'));
}

void test_ft_isdigit() {
    printf("\n=== Testing ft_isdigit ===\n");
    print_test_result("ft_isdigit", 1, !!ft_isdigit('5') == !!isdigit('5'));
    print_test_result("ft_isdigit", 2, !!ft_isdigit('a') == !!isdigit('a'));
    print_test_result("ft_isdigit", 3, !!ft_isdigit('0') == !!isdigit('0'));
}

void test_ft_isalnum() {
    printf("\n=== Testing ft_isalnum ===\n");
    print_test_result("ft_isalnum", 1, !!ft_isalnum('a') == !!isalnum('a'));
    print_test_result("ft_isalnum", 2, !!ft_isalnum('5') == !!isalnum('5'));
    print_test_result("ft_isalnum", 3, !!ft_isalnum('@') == !!isalnum('@'));
}

void test_ft_isascii() {
    printf("\n=== Testing ft_isascii ===\n");
    print_test_result("ft_isascii", 1, ft_isascii(65) == 1);
    print_test_result("ft_isascii", 2, ft_isascii(128) == 0);
    print_test_result("ft_isascii", 3, ft_isascii(0) == 1);
}

void test_ft_isprint() {
    printf("\n=== Testing ft_isprint ===\n");
    print_test_result("ft_isprint", 1, !!ft_isprint('A') == !!isprint('A'));
    print_test_result("ft_isprint", 2, !!ft_isprint('\t') == !!isprint('\t'));
    print_test_result("ft_isprint", 3, !!ft_isprint(' ') == !!isprint(' '));
}

void test_ft_toupper() {
    printf("\n=== Testing ft_toupper ===\n");
    print_test_result("ft_toupper", 1, ft_toupper('a') == toupper('a'));
    print_test_result("ft_toupper", 2, ft_toupper('Z') == toupper('Z'));
    print_test_result("ft_toupper", 3, ft_toupper('5') == toupper('5'));
}

void test_ft_tolower() {
    printf("\n=== Testing ft_tolower ===\n");
    print_test_result("ft_tolower", 1, ft_tolower('A') == tolower('A'));
    print_test_result("ft_tolower", 2, ft_tolower('z') == tolower('z'));
    print_test_result("ft_tolower", 3, ft_tolower('5') == tolower('5'));
}

// String functions
void test_ft_strlen() {
    printf("\n=== Testing ft_strlen ===\n");
    print_test_result("ft_strlen", 1, ft_strlen("Hello") == strlen("Hello"));
    print_test_result("ft_strlen", 2, ft_strlen("") == strlen(""));
    print_test_result("ft_strlen", 3, ft_strlen("42") == strlen("42"));
}

void test_ft_strchr() {
    printf("\n=== Testing ft_strchr ===\n");
    char *str = "Hello World";
    print_test_result("ft_strchr", 1, ft_strchr(str, 'W') == strchr(str, 'W'));
    print_test_result("ft_strchr", 2, ft_strchr(str, 'x') == strchr(str, 'x'));
    print_test_result("ft_strchr", 3, ft_strchr(str, '\0') == strchr(str, '\0'));
}

void test_ft_strrchr() {
    printf("\n=== Testing ft_strrchr ===\n");
    char *str = "Hello World";
    print_test_result("ft_strrchr", 1, ft_strrchr(str, 'l') == strrchr(str, 'l'));
    print_test_result("ft_strrchr", 2, ft_strrchr(str, 'x') == strrchr(str, 'x'));
    print_test_result("ft_strrchr", 3, ft_strrchr(str, 'H') == strrchr(str, 'H'));
}

void test_ft_strncmp() {
    printf("\n=== Testing ft_strncmp ===\n");
    print_test_result("ft_strncmp", 1, ft_strncmp("abc", "abc", 3) == strncmp("abc", "abc", 3));
    print_test_result("ft_strncmp", 2, (ft_strncmp("abc", "abd", 3) < 0) == (strncmp("abc", "abd", 3) < 0));
    print_test_result("ft_strncmp", 3, ft_strncmp("abc", "ab", 2) == strncmp("abc", "ab", 2));
}

void test_ft_strlcpy() {
    printf("\n=== Testing ft_strlcpy ===\n");
    char dst1[20], dst2[20];
    char *src = "Hello World";
    size_t ret1 = ft_strlcpy(dst1, src, 10);
    size_t ret2 = strlcpy(dst2, src, 10);
    print_test_result("ft_strlcpy", 1, ret1 == ret2 && strcmp(dst1, dst2) == 0);
    
    ret1 = ft_strlcpy(dst1, src, 0);
    ret2 = strlcpy(dst2, src, 0);
    print_test_result("ft_strlcpy", 2, ret1 == ret2);
    
    ret1 = ft_strlcpy(dst1, "", 5);
    ret2 = strlcpy(dst2, "", 5);
    print_test_result("ft_strlcpy", 3, ret1 == ret2 && strcmp(dst1, dst2) == 0);
}

void test_ft_strlcat() {
    printf("\n=== Testing ft_strlcat ===\n");
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";
    char *src = " World";
    size_t ret1 = ft_strlcat(dst1, src, 20);
    size_t ret2 = strlcat(dst2, src, 20);
    print_test_result("ft_strlcat", 1, ret1 == ret2 && strcmp(dst1, dst2) == 0);
    
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    ret1 = ft_strlcat(dst1, src, 8);
    ret2 = strlcat(dst2, src, 8);
    print_test_result("ft_strlcat", 2, ret1 == ret2 && strcmp(dst1, dst2) == 0);
    
    strcpy(dst1, "");
    strcpy(dst2, "");
    ret1 = ft_strlcat(dst1, "test", 10);
    ret2 = strlcat(dst2, "test", 10);
    print_test_result("ft_strlcat", 3, ret1 == ret2 && strcmp(dst1, dst2) == 0);
}

void test_ft_strnstr() {
    printf("\n=== Testing ft_strnstr ===\n");
    char *haystack = "Hello World";
    print_test_result("ft_strnstr", 1, ft_strnstr(haystack, "World", 11) == strnstr(haystack, "World", 11));
    print_test_result("ft_strnstr", 2, ft_strnstr(haystack, "World", 5) == strnstr(haystack, "World", 5));
    print_test_result("ft_strnstr", 3, ft_strnstr(haystack, "", 11) == strnstr(haystack, "", 11));
}

void test_ft_atoi() {
    printf("\n=== Testing ft_atoi ===\n");
    print_test_result("ft_atoi", 1, ft_atoi("123") == atoi("123"));
    print_test_result("ft_atoi", 2, ft_atoi("-456") == atoi("-456"));
    print_test_result("ft_atoi", 3, ft_atoi("  +789") == atoi("  +789"));
}

// Memory functions
void test_ft_memset() {
    printf("\n=== Testing ft_memset ===\n");
    char buf1[10], buf2[10];
    print_test_result("ft_memset", 1, memcmp(ft_memset(buf1, 'A', 5), memset(buf2, 'A', 5), 5) == 0);
    print_test_result("ft_memset", 2, memcmp(ft_memset(buf1, 0, 10), memset(buf2, 0, 10), 10) == 0);
    print_test_result("ft_memset", 3, memcmp(ft_memset(buf1, 255, 3), memset(buf2, 255, 3), 3) == 0);
}

void test_ft_bzero() {
    printf("\n=== Testing ft_bzero ===\n");
    char buf1[10], buf2[10];
    memset(buf1, 'A', 10);
    memset(buf2, 'A', 10);
    ft_bzero(buf1, 5);
    bzero(buf2, 5);
    print_test_result("ft_bzero", 1, memcmp(buf1, buf2, 10) == 0);
    
    memset(buf1, 'B', 10);
    memset(buf2, 'B', 10);
    ft_bzero(buf1, 0);
    bzero(buf2, 0);
    print_test_result("ft_bzero", 2, memcmp(buf1, buf2, 10) == 0);
    
    memset(buf1, 'C', 10);
    memset(buf2, 'C', 10);
    ft_bzero(buf1, 10);
    bzero(buf2, 10);
    print_test_result("ft_bzero", 3, memcmp(buf1, buf2, 10) == 0);
}

void test_ft_memcpy() {
    printf("\n=== Testing ft_memcpy ===\n");
    char src[] = "Hello World";
    char dst1[20], dst2[20];
    print_test_result("ft_memcpy", 1, memcmp(ft_memcpy(dst1, src, 5), memcpy(dst2, src, 5), 5) == 0);
    print_test_result("ft_memcpy", 2, memcmp(ft_memcpy(dst1, src, 0), memcpy(dst2, src, 0), 0) == 0);
    print_test_result("ft_memcpy", 3, memcmp(ft_memcpy(dst1, src, 11), memcpy(dst2, src, 11), 11) == 0);
}

void test_ft_memmove() {
    printf("\n=== Testing ft_memmove ===\n");
    char str1[] = "Hello World";
    char str2[] = "Hello World";
    print_test_result("ft_memmove", 1, memcmp(ft_memmove(str1 + 2, str1, 5), memmove(str2 + 2, str2, 5), 11) == 0);
    
    strcpy(str1, "Hello World");
    strcpy(str2, "Hello World");
    print_test_result("ft_memmove", 2, memcmp(ft_memmove(str1, str1 + 2, 5), memmove(str2, str2 + 2, 5), 11) == 0);
    
    strcpy(str1, "Hello World");
    strcpy(str2, "Hello World");
    print_test_result("ft_memmove", 3, memcmp(ft_memmove(str1, str1, 5), memmove(str2, str2, 5), 11) == 0);
}

void test_ft_memchr() {
    printf("\n=== Testing ft_memchr ===\n");
    char *str = "Hello World";
    print_test_result("ft_memchr", 1, ft_memchr(str, 'W', 11) == memchr(str, 'W', 11));
    print_test_result("ft_memchr", 2, ft_memchr(str, 'x', 11) == memchr(str, 'x', 11));
    print_test_result("ft_memchr", 3, ft_memchr(str, '\0', 12) == memchr(str, '\0', 12));
}

void test_ft_memcmp() {
    printf("\n=== Testing ft_memcmp ===\n");
    print_test_result("ft_memcmp", 1, ft_memcmp("abc", "abc", 3) == memcmp("abc", "abc", 3));
    print_test_result("ft_memcmp", 2, (ft_memcmp("abc", "abd", 3) < 0) == (memcmp("abc", "abd", 3) < 0));
    print_test_result("ft_memcmp", 3, ft_memcmp("abc", "ab", 2) == memcmp("abc", "ab", 2));
}

// String manipulation functions
void test_ft_strdup() {
    printf("\n=== Testing ft_strdup ===\n");
    char *dup1 = ft_strdup("Hello");
    char *dup2 = strdup("Hello");
    print_test_result("ft_strdup", 1, strcmp(dup1, dup2) == 0);
    free(dup1); free(dup2);
    
    dup1 = ft_strdup("");
    dup2 = strdup("");
    print_test_result("ft_strdup", 2, strcmp(dup1, dup2) == 0);
    free(dup1); free(dup2);
    
    dup1 = ft_strdup("42");
    dup2 = strdup("42");
    print_test_result("ft_strdup", 3, strcmp(dup1, dup2) == 0);
    free(dup1); free(dup2);
}

void test_ft_calloc() {
    printf("\n=== Testing ft_calloc ===\n");
    int *ptr1 = ft_calloc(5, sizeof(int));
    int *ptr2 = calloc(5, sizeof(int));
    print_test_result("ft_calloc", 1, memcmp(ptr1, ptr2, 5 * sizeof(int)) == 0);
    free(ptr1); free(ptr2);
    
    ptr1 = ft_calloc(0, sizeof(int));
    ptr2 = calloc(0, sizeof(int));
    print_test_result("ft_calloc", 2, (ptr1 == NULL) == (ptr2 == NULL));
    if (ptr1) free(ptr1); if (ptr2) free(ptr2);
    
    char *cptr1 = ft_calloc(10, sizeof(char));
    char *cptr2 = calloc(10, sizeof(char));
    print_test_result("ft_calloc", 3, memcmp(cptr1, cptr2, 10) == 0);
    free(cptr1); free(cptr2);
}

// Additional functions
void test_ft_substr() {
    printf("\n=== Testing ft_substr ===\n");
    char *sub = ft_substr("Hello World", 6, 5);
    print_test_result("ft_substr", 1, strcmp(sub, "World") == 0);
    free(sub);
    
    sub = ft_substr("Hello", 10, 5);
    print_test_result("ft_substr", 2, strcmp(sub, "") == 0);
    free(sub);
    
    sub = ft_substr("Hello", 0, 3);
    print_test_result("ft_substr", 3, strcmp(sub, "Hel") == 0);
    free(sub);
}

void test_ft_strjoin() {
    printf("\n=== Testing ft_strjoin ===\n");
    char *joined = ft_strjoin("Hello", " World");
    print_test_result("ft_strjoin", 1, strcmp(joined, "Hello World") == 0);
    free(joined);
    
    joined = ft_strjoin("", "test");
    print_test_result("ft_strjoin", 2, strcmp(joined, "test") == 0);
    free(joined);
    
    joined = ft_strjoin("test", "");
    print_test_result("ft_strjoin", 3, strcmp(joined, "test") == 0);
    free(joined);
}

void test_ft_strtrim() {
    printf("\n=== Testing ft_strtrim ===\n");
    char *trimmed = ft_strtrim("  Hello World  ", " ");
    print_test_result("ft_strtrim", 1, strcmp(trimmed, "Hello World") == 0);
    free(trimmed);
    
    trimmed = ft_strtrim("abcHello Worldcba", "abc");
    print_test_result("ft_strtrim", 2, strcmp(trimmed, "Hello World") == 0);
    free(trimmed);
    
    trimmed = ft_strtrim("   ", " ");
    print_test_result("ft_strtrim", 3, strcmp(trimmed, "") == 0);
    free(trimmed);
}

void test_ft_split() {
    printf("\n=== Testing ft_split ===\n");
    char **split = ft_split("Hello,World,42", ',');
    print_test_result("ft_split", 1, strcmp(split[0], "Hello") == 0 && strcmp(split[1], "World") == 0 && strcmp(split[2], "42") == 0);
    for (int i = 0; split[i]; i++) free(split[i]);
    free(split);
    
    split = ft_split("", ',');
    print_test_result("ft_split", 2, split[0] == NULL);
    free(split);
    
    split = ft_split("Hello", ',');
    print_test_result("ft_split", 3, strcmp(split[0], "Hello") == 0 && split[1] == NULL);
    for (int i = 0; split[i]; i++) free(split[i]);
    free(split);
}

void test_ft_itoa() {
    printf("\n=== Testing ft_itoa ===\n");
    char *str = ft_itoa(123);
    print_test_result("ft_itoa", 1, strcmp(str, "123") == 0);
    free(str);
    
    str = ft_itoa(-456);
    print_test_result("ft_itoa", 2, strcmp(str, "-456") == 0);
    free(str);
    
    str = ft_itoa(0);
    print_test_result("ft_itoa", 3, strcmp(str, "0") == 0);
    free(str);
}

char test_toupper_func(unsigned int i, char c) {
    (void)i;
    return ft_toupper(c);
}

void test_striteri_func(unsigned int i, char *c) {
    (void)i;
    *c = ft_toupper(*c);
}

void test_ft_strmapi() {
    printf("\n=== Testing ft_strmapi ===\n");
    char *result = ft_strmapi("hello", test_toupper_func);
    print_test_result("ft_strmapi", 1, strcmp(result, "HELLO") == 0);
    free(result);
    
    result = ft_strmapi("", test_toupper_func);
    print_test_result("ft_strmapi", 2, strcmp(result, "") == 0);
    free(result);
    
    result = ft_strmapi("42", test_toupper_func);
    print_test_result("ft_strmapi", 3, strcmp(result, "42") == 0);
    free(result);
}

void test_ft_striteri() {
    printf("\n=== Testing ft_striteri ===\n");
    char str1[] = "hello";
    ft_striteri(str1, test_striteri_func);
    print_test_result("ft_striteri", 1, strcmp(str1, "HELLO") == 0);
    
    char str2[] = "";
    ft_striteri(str2, test_striteri_func);
    print_test_result("ft_striteri", 2, strcmp(str2, "") == 0);
    
    char str3[] = "42";
    ft_striteri(str3, test_striteri_func);
    print_test_result("ft_striteri", 3, strcmp(str3, "42") == 0);
}

void test_ft_putchar_fd() {
    printf("\n=== Testing ft_putchar_fd ===\n");
    printf("ft_putchar_fd Test 1: ");
    ft_putchar_fd('A', 1);
    printf(" (should show A)\n");
    
    printf("ft_putchar_fd Test 2: ");
    ft_putchar_fd('\n', 1);
    printf("(should show newline above)\n");
    
    printf("ft_putchar_fd Test 3: ");
    ft_putchar_fd('5', 1);
    printf(" (should show 5)\n");
}

void test_ft_putstr_fd() {
    printf("\n=== Testing ft_putstr_fd ===\n");
    printf("ft_putstr_fd Test 1: ");
    ft_putstr_fd("Hello", 1);
    printf(" (should show Hello)\n");
    
    printf("ft_putstr_fd Test 2: ");
    ft_putstr_fd("", 1);
    printf("(should show nothing)\n");
    
    printf("ft_putstr_fd Test 3: ");
    ft_putstr_fd("42", 1);
    printf(" (should show 42)\n");
}

void test_ft_putendl_fd() {
    printf("\n=== Testing ft_putendl_fd ===\n");
    printf("ft_putendl_fd Test 1: ");
    ft_putendl_fd("Hello", 1);
    printf("(should show Hello with newline above)\n");
    
    printf("ft_putendl_fd Test 2: ");
    ft_putendl_fd("", 1);
    printf("(should show empty line above)\n");
    
    printf("ft_putendl_fd Test 3: ");
    ft_putendl_fd("42", 1);
    printf("(should show 42 with newline above)\n");
}

void test_ft_putnbr_fd() {
    printf("\n=== Testing ft_putnbr_fd ===\n");
    printf("ft_putnbr_fd Test 1: ");
    ft_putnbr_fd(123, 1);
    printf(" (should show 123)\n");
    
    printf("ft_putnbr_fd Test 2: ");
    ft_putnbr_fd(-456, 1);
    printf(" (should show -456)\n");
    
    printf("ft_putnbr_fd Test 3: ");
    ft_putnbr_fd(0, 1);
    printf(" (should show 0)\n");
}

// Bonus functions tests
void test_ft_lstnew() {
    printf("\n=== Testing ft_lstnew (Bonus) ===\n");
    char *content = "Hello";
    t_list *node = ft_lstnew(content);
    print_test_result("ft_lstnew", 1, node != NULL && node->content == content && node->next == NULL);
    free(node);
    
    node = ft_lstnew(NULL);
    print_test_result("ft_lstnew", 2, node != NULL && node->content == NULL && node->next == NULL);
    free(node);
    
    int *num = malloc(sizeof(int));
    *num = 42;
    node = ft_lstnew(num);
    print_test_result("ft_lstnew", 3, node != NULL && node->content == num && *(int*)node->content == 42);
    free(num);
    free(node);
}

void test_ft_lstadd_front() {
    printf("\n=== Testing ft_lstadd_front (Bonus) ===\n");
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("First");
    ft_lstadd_front(&list, node1);
    print_test_result("ft_lstadd_front", 1, list == node1 && strcmp((char*)list->content, "First") == 0);
    
    t_list *node2 = ft_lstnew("Second");
    ft_lstadd_front(&list, node2);
    print_test_result("ft_lstadd_front", 2, list == node2 && strcmp((char*)list->content, "Second") == 0 && list->next == node1);
    
    t_list *node3 = ft_lstnew("Third");
    ft_lstadd_front(&list, node3);
    print_test_result("ft_lstadd_front", 3, list == node3 && strcmp((char*)list->content, "Third") == 0);
    
    // Cleanup
    free(node1); free(node2); free(node3);
}

void test_ft_lstsize() {
    printf("\n=== Testing ft_lstsize (Bonus) ===\n");
    t_list *list = NULL;
    print_test_result("ft_lstsize", 1, ft_lstsize(list) == 0);
    
    t_list *node1 = ft_lstnew("First");
    list = node1;
    print_test_result("ft_lstsize", 2, ft_lstsize(list) == 1);
    
    t_list *node2 = ft_lstnew("Second");
    node1->next = node2;
    t_list *node3 = ft_lstnew("Third");
    node2->next = node3;
    print_test_result("ft_lstsize", 3, ft_lstsize(list) == 3);
    
    // Cleanup
    free(node1); free(node2); free(node3);
}

void test_ft_lstlast() {
    printf("\n=== Testing ft_lstlast (Bonus) ===\n");
    t_list *list = NULL;
    print_test_result("ft_lstlast", 1, ft_lstlast(list) == NULL);
    
    t_list *node1 = ft_lstnew("First");
    list = node1;
    print_test_result("ft_lstlast", 2, ft_lstlast(list) == node1);
    
    t_list *node2 = ft_lstnew("Second");
    node1->next = node2;
    t_list *node3 = ft_lstnew("Third");
    node2->next = node3;
    print_test_result("ft_lstlast", 3, ft_lstlast(list) == node3);
    
    // Cleanup
    free(node1); free(node2); free(node3);
}

void test_ft_lstadd_back() {
    printf("\n=== Testing ft_lstadd_back (Bonus) ===\n");
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("First");
    ft_lstadd_back(&list, node1);
    print_test_result("ft_lstadd_back", 1, list == node1 && ft_lstlast(list) == node1);
    
    t_list *node2 = ft_lstnew("Second");
    ft_lstadd_back(&list, node2);
    print_test_result("ft_lstadd_back", 2, ft_lstlast(list) == node2 && node1->next == node2);
    
    t_list *node3 = ft_lstnew("Third");
    ft_lstadd_back(&list, node3);
    print_test_result("ft_lstadd_back", 3, ft_lstlast(list) == node3 && ft_lstsize(list) == 3);
    
    // Cleanup
    free(node1); free(node2); free(node3);
}

void del_content(void *content) {
    free(content);
}

void test_ft_lstdelone() {
    printf("\n=== Testing ft_lstdelone (Bonus) ===\n");
    char *content = malloc(10);
    strcpy(content, "Hello");
    t_list *node = ft_lstnew(content);
    print_test_result("ft_lstdelone", 1, node != NULL);
    
    ft_lstdelone(node, del_content);
    print_test_result("ft_lstdelone", 2, 1); // If we reach here, no crash occurred
    
    // Test with NULL
    ft_lstdelone(NULL, del_content);
    print_test_result("ft_lstdelone", 3, 1); // Should handle NULL gracefully
}

void test_ft_lstclear() {
    printf("\n=== Testing ft_lstclear (Bonus) ===\n");
    t_list *list = NULL;
    
    // Create a list with malloc'd content
    for (int i = 0; i < 3; i++) {
        char *content = malloc(10);
        sprintf(content, "Node%d", i);
        t_list *node = ft_lstnew(content);
        ft_lstadd_back(&list, node);
    }
    
    print_test_result("ft_lstclear", 1, ft_lstsize(list) == 3);
    
    ft_lstclear(&list, del_content);
    print_test_result("ft_lstclear", 2, list == NULL);
    
    // Test with NULL list
    ft_lstclear(&list, del_content);
    print_test_result("ft_lstclear", 3, list == NULL);
}

void print_content(void *content) {
    printf("%s ", (char*)content);
}

void test_ft_lstiter() {
    printf("\n=== Testing ft_lstiter (Bonus) ===\n");
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");
    
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);
    
    printf("ft_lstiter Test 1: ");
    ft_lstiter(list, print_content);
    printf("(should show: First Second Third)\n");
    
    ft_lstiter(NULL, print_content);
    print_test_result("ft_lstiter", 2, 1); // Should handle NULL gracefully
    
    print_test_result("ft_lstiter", 3, ft_lstsize(list) == 3); // List should remain unchanged
    
    // Cleanup
    free(node1); free(node2); free(node3);
}

void *duplicate_content(void *content) {
    char *str = (char*)content;
    char *dup = malloc(strlen(str) + 1);
    strcpy(dup, str);
    return dup;
}

void test_ft_lstmap() {
    printf("\n=== Testing ft_lstmap (Bonus) ===\n");
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");
    
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);
    
    t_list *new_list = ft_lstmap(list, duplicate_content, del_content);
    print_test_result("ft_lstmap", 1, new_list != NULL && ft_lstsize(new_list) == 3);
    
    print_test_result("ft_lstmap", 2, strcmp((char*)new_list->content, "First") == 0);
    
    t_list *empty_list = ft_lstmap(NULL, duplicate_content, del_content);
    print_test_result("ft_lstmap", 3, empty_list == NULL);
    
    // Cleanup
    ft_lstclear(&new_list, del_content);
    free(node1); free(node2); free(node3);
}

int main() {
    printf("=== LIBFT COMPREHENSIVE TEST SUITE ===\n");
    
    // Character classification tests
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_toupper();
    test_ft_tolower();
    
    // String functions
    test_ft_strlen();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_strnstr();
    test_ft_atoi();
    
    // Memory functions
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_memchr();
    test_ft_memcmp();
    
    // String manipulation functions
    test_ft_strdup();
    test_ft_calloc();
    
    // Additional functions
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_itoa();
    test_ft_strmapi();
    test_ft_striteri();
    
    // Output functions
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    
    // Bonus functions
    test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstsize();
    test_ft_lstlast();
    test_ft_lstadd_back();
    test_ft_lstdelone();
    test_ft_lstclear();
    test_ft_lstiter();
    test_ft_lstmap();
    
    printf("\n=== TEST SUITE COMPLETED ===\n");
    return 0;
}
# Source files for your libft library
SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_substr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
ARFLAGS = rcs

# Library name
NAME = libft.a

# Default target
all: $(NAME)

# Rule to build the library
$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

# Rule to build the test executable (if you have one, otherwise remove this section)
# TEST_NAME = test_libft
# TEST_SRCS = test_main.c # Example test source file
# TEST_OBJS = $(TEST_SRCS:.c=.o)
# $(TEST_NAME): $(TEST_OBJS) $(NAME)
# 	$(CC) $(CFLAGS) $(TEST_OBJS) -L. -lft -o $(TEST_NAME)

# Clean object files
clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

# Rebuild everything
re: fclean all

# Phony targets (targets that are not files)
.PHONY: all clean fclean re test


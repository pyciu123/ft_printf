# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 15:16:35 by jpyciarz          #+#    #+#              #
#    Updated: 2024/03/27 11:18:49 by jpyciarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_DIR) -I$(INCLUDES)
AR = ar rcs
RM = rm -f
NAME = libftprintf.a

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = includes

LIBFT_FILES = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit \
              ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset \
              ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr \
              ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi \
              ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper

PRINTF_FILES = ft_print_decimal ft_print_hexadecimal ft_print_percent ft_print_pointer \
               ft_print_str ft_print_unsigned ft_printchar ft_printf ft_unsigned_itoa

LIBFT_SRC = $(addprefix $(LIBFT_DIR)/, $(addsuffix .c, $(LIBFT_FILES)))
PRINTF_SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(PRINTF_FILES)))
LIBFT_OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIBFT_FILES)))
PRINTF_OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(PRINTF_FILES)))

OBJ = $(LIBFT_OBJ) $(PRINTF_OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
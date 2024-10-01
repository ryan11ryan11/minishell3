# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 21:03:51 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/08/18 21:30:18 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_pow
LIBNAME = lib$(NAME).a
TESTNAME = test
TESTFILE = app.c

SRCDIR = src
OBJDIR = objs

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -Wall -Wextra -Werror
LFLAGS = -L. -l$(NAME)

.PHONY: all, lib, run, clean, fclean, re

all: lib

lib: $(LIBNAME)

run: lib
	$(CC) $(CFLAGSO) $(TESTFILE) $(LFLAGS) -o $(TESTNAME)
	./$(TESTNAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TESTNAME) $(LIBNAME)

re: fclean all

$(LIBNAME): $(OBJ)
	ar -rc $(LIBNAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@
	

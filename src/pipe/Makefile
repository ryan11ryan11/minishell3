# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 13:19:55 by junhhong          #+#    #+#              #
#    Updated: 2024/09/03 14:47:26 by junhhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipe
LIBNAME = pipe.a
LIBNAMEFULL = pipe.a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
GNLDIR = ../../get_next_line
PRINTFDIR = ../../ft_printf
STRHANDLERDIR = ../strhandler
SRCDIR = src
OBJDIR = objs

LIBFT = ft
GNL = gnlfull
PRINTF = ftprintffull
STRHANDLER = strhandler
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -L$(LIBFTDIR) -l$(LIBFT) -L$(GNLDIR) -l$(GNL) -L$(PRINTFDIR) -l$(PRINTF) -L$(STRHANDLERDIR) -l$(STRHANDLER)full -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libf: $(LIBNAMEFULL)

cobj: $(OBJ)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(PRINTFDIR) clean
	$(MAKE) -C $(STRHANDLERDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean
	$(MAKE) -C $(STRHANDLERDIR) fclean
	rm -f $(NAME) $(LIBNAME) $(LIBNAMEFULL) $(TEST)

re: fclean all

run: $(LIBNAME)
	$(CC) $(TESTFILE) -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	$(MAKE) -C $(STRHANDLERDIR)
	$(CC) $(OBJ) $(LIBRS) -o $@

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	$(MAKE) -C $(STRHANDLERDIR) libfull
	ar -rc $(LIBNAME) $(OBJ)
	ranlib	$@

$(LIBNAMEFULL): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	$(MAKE) -C $(STRHANDLERDIR)
	ar -rc $(LIBNAMEFULL) $(OBJ) $(STRHANDLERDIR)/$(OBJDIR)/*.o $(LIBFTDIR)/$(OBJDIR)/*.o
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -g $(CFLAGSO) $< -o $@

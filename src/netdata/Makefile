# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 18:22:27 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/10/01 10:29:34 by junhhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = netdata
FULLLIB = full
LIBNAME = lib$(NAME).a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
GNLDIR = ../../get_next_line
PRINTFDIR = ../../ft_printf
STRHANDLERDIR = ../strhandler
SPLITERDIR = ../splitter
SRCDIR = src
OBJDIR = objs
PIPEDIR = ../pipe

LIBFT = ft
GNL = gnlfull
PRINTF = ftprintffull
STRHANDLER = strhandler
SPLITER = splitter
PIPE = pipe

LIBLIBFT = -L$(LIBFTDIR) -l$(LIBFT)
LIBGNL = -L$(GNLDIR) -l$(GNL)
LIBPRINTF = -L$(PRINTFDIR) -l$(PRINTF)
LIBSTRHNDLR = -L$(STRHANDLERDIR) -l$(STRHANDLER)
LIBSPLITER = -L$(SPLITERDIR) -l$(SPLITER)
LIBRLINE = -l$(READLINE)
LIBPIPE = -L$(PIPEDIR) -l$(PIPE)

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJLIBFT = $(LIBFTDIR)/$(OBJDIR)/*.o
OBJSTRHNLR = $(STRHANDLERDIR)/$(OBJDIR)/*.o
OBJSPLITER = $(SPLITERDIR)/$(OBJDIR)/*.o
OBJPIPE = $(PIPEDIR)/$(OBJDIR)/*.o

CC = gcc
CFLAGSO = -c -Wall -Wextra

LIBRS = -lreadline

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
	$(MAKE) -C $(SPLITERDIR) clean
	$(MAKE) -C $(PIPEDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean
	$(MAKE) -C $(STRHANDLERDIR) fclean
	$(MAKE) -C $(SPLITERDIR) fclean
	$(MAKE) -C $(PIPEDIR) fclean
	rm -f $(NAME) $(LIBNAME) $(LIBNAMEFULL) $(TEST)

re: fclean all

run: $(LIBNAME)
	$(CC) $(TESTFILE) -g -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(STRHANDLERDIR)
	$(MAKE) -C $(SPLITERDIR)
	$(MAKE) -C $(PIPEDIR)
	ar -x $(LIBFTDIR)/lib$(LIBFT).a
	ar -x $(STRHANDLERDIR)/lib$(STRHANDLER).a
	ar -x $(SPLITERDIR)/lib$(SPLITER).a
	ar -x $(PIPEDIR)/$(PIPE).a
	mv *.o $(OBJDIR)
	ar -rc $(LIBNAME) $(OBJDIR)/*.o
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -g $(CFLAGSO) $< -o $@
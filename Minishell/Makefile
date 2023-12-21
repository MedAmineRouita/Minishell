##
## EPITECH PROJECT, 2022
## B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
## File description:
## Makefile
##

CC				=		gcc

SRC				=		$(wildcard src/*.c)	\
						$(wildcard lib/*.c)

OBJ				=		$(SRC:.c=.o)

TARGET			=		libmy.a

all:	$(TARGET)

$(TARGET):	$(OBJ)
	ar src $(TARGET) $(OBJ)
	$(CC) main.c -Iinclude/ -L./ -lmy -g3 -o mysh

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(TARGET)
	rm mysh

re : fclean all

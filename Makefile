NAME = libhash.a

SRC = hash.c elem.c

OBJ = $(subst .c,.o,$(SRC))

INC = -I./includes/ -I../libft/
FLAG = -Wall $(INC)

.SILENT:

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c  $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm  -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all clean

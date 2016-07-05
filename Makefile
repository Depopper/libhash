NAME = libhash.a

SRC = hash.c elem.c memory.c h_print.c

OBJ = $(subst .c,.o,$(SRC))

INC = -I./includes/ -I../libft/includes
FLAG = -Wall $(INC)

.SILENT:

all: $(NAME)

$(NAME):
	gcc -O2 $(FLAG) -c  $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	rm *.o

clean :
	rm  -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all

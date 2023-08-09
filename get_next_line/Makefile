CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c get_next_line_utils.c
OBJ =get_next_line.o get_next_line_utils.o
NAME = get_next_line.a
HEADER = get_next_line.h

.PHONY: claen fclaen re all
all :  $(NAME)
$(NAME) : $(OBJ)
	ar rc $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $^ -o $@
clean :
	rm -f $(OBJ)
	rm -f $(BOBJ)
fclean : clean
	rm -f $(NAME)
re :
	make fclean
	make all
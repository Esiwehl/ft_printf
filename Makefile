SRCS			= main.c
MAN_OBJS		=	$(SRCS:.c=.o)


NAME			= libftprintf.a
HEADERF			= libft.h

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c $(HEADERF)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re all

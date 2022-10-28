NAME			= libftprintf.a

LIBFT			= libft
HEADERF			= headers

SRCS			= ft_printf.c ft_puthex.c ft_putuint.c
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR			= obj/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a
	@mv libft.a $(NAME)
	@$(AR) $@ $^
	@echo "Compiling ft_printf..."

$(OBJ_DIR)%.o : %.c $(HEADERF)
	@echo "HELLUP"
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean :
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "I just-a cleaning lady... :shrug:"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a

re : fclean all

norm:
	@norminette $(SRCS) $(HEADERF) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

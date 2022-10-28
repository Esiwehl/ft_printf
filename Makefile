NAME			= libftprintf.a

LIBFT			= libft
HEADERF			= headers

SRC_DIR			= src/
OBJ_DIR			= obj/

SRCSF			= main.c
SRCS			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $@ $^
	@echo "Compiling ft_printf..."

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@echo "HELLUP"
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

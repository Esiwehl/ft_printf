# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2022/10/28 17:15:18 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

LIBFT			= libft
HEADERF			= headers

SRCS			= ft_printf.c ft_putstr.c ft_putuint.c ft_puthex.c
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR			= obj/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@echo "Compiling libft..."
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $@ $^
	@echo "Compiling ft_printf..."

$(OBJ_DIR)%.o : %.c $(HEADERF)
	@echo "HELLUP $@"
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean :
	@$(RM) -R $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "I just-a cleaning lady... :shrug:"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@$(RM) $(LIBFT)/libft.a

re : fclean all

norm:
	@norminette $(SRCS) $(HEADERF)

.PHONY:		all clean fclean re norm

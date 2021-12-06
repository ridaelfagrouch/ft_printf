CBONUS = ft_printf_bonus.c ft_printf_bonus_utils1.c
OBONUS = ${CBONUS:.c=.o}

CC = gcc
W = -Wall -Werror -Wextra
INC = ft_printf.h
NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OBONUS} ${INC}
	@ar -rcs ${NAME} ${OBONUS}
	@echo "libftprintf.a is created"

%.o:%.c
	@${CC} ${W} -o $@ -c $<
	@echo "$@ created"

clean:
	@rm -f ${OBONUS}

fclean : clean
	@rm -f ${NAME}

re : fclean all

bonus : all
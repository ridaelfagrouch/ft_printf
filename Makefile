CFILES = ft_printf.c ft_printf_utils1.c
OFILES = ${CFILES:.c=.o}

CBONUS = ft_printf_bonus.c ft_printf_bonus_utils1.c
OBONUS = ${CBONUS:.c=.o}

CC = gcc
W = -Wall -Werror -Wextra
INC = ft_printf.h
NAME = libftprintf.a

all : ${NAME}

${NAME} : ${OFILES} ${INC}
	@ar -rcs ${NAME} ${OFILES}
	@echo "libftprintf.a is created"

%.o:%.c
	@${CC} ${W} -o $@ -c $<
	@echo "$@ created"

clean:
	@rm -f ${OFILES} ${OBONUS}

fclean : clean
	@rm -f ${NAME}

re : fclean all

bonus: all ${OBONUS}
	@ar -rcs ${NAME} ${OBONUS} $(OFILES)
	@echo "libft.a bonus created"
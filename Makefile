NAME = dot

SRC = dot.cpp
SRC += dot.class.cpp
SRC += display.class.cpp
SRC += ft_ExitWithError.cpp

SRCS = ${addprefix ./src/, ${SRC}}

INCLUDE = -I ./include

CC = g++

.PHONY: all fclean re

all:
	${CC} ${INCLUDE} ${SRCS} -lSDL2 -lSDL2main -lSDL2_image -o ${NAME}

fclean:
	${RM} ${NAME}

re:
	${MAKE} --no-print-directory fclean
	${MAKE} --no-print-directory

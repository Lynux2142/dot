NAME	= dot

SRC		= dot.cpp
SRC		+= dot.class.cpp
SRC		+= display.class.cpp
SRC		+= ft_ExitWithError.cpp

SRCS	= ${addprefix ./src/, ${SRC}}

INCLUDE	= -I ./include
LIB		=
LINK	= -lSDL2main -lSDL2_image -lSDL2 -std=c++17 -lstdc++fs

ifeq (${OS}, Windows_NT)
	INCLUDE	+= -I ./sdl/include
	LIB		+= -L ./sdl/lib
	LINK	:= -lmingw32 ${LINK}
endif

CC = g++

.PHONY: all fclean re

all:
	${CC} -g ${SRCS} ${INCLUDE} ${LIB} ${LINK} -o ${NAME}

fclean:
	${RM} ${NAME}

re:
	${MAKE} --no-print-directory fclean
	${MAKE} --no-print-directory

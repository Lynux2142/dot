NAME = dot

SRC = dot.cpp
SRC += dot.class.cpp
SRC += display.class.cpp
SRC += ft_ExitWithError.cpp

SRCS = ${addprefix ./src/, ${SRC}}

ifeq (${OS}, Windows_NT)
	INCLUDE = -I ./include -I ./sdl/include
	LIB = -L ./sdl/lib
	LINK = -lmingw32 -lSDL2main -lSDL2_image -lSDL2
else
	INCLUDE = -I ./include
	LIB =
	LINK = -lSDL2main -lSDL2_image -lSDL2
endif


CC = g++

.PHONY: all fclean re

all:
	${CC} ${SRCS} ${INCLUDE} ${LIB} ${LINK} -o ${NAME} -std=c++17

fclean:
	${RM} ${NAME}

re:
	${MAKE} --no-print-directory fclean
	${MAKE} --no-print-directory

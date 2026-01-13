CC=g++
CPPFLAGS= -I. -g -std=c++11      #opciones de compilación
RM=rm -f

all: main
#-----------------------------------------------------------
# Compilacion
main.o: main.cpp 
	${CC} -c main.cpp ${CPPFLAGS}
#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. OjO: se borrarán sin preguntar
# RM es una de las variables predefinidas en make: invoca borrado de fichero del SO
clean:
	${RM} main.o main
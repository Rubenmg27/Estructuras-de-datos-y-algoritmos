CC=g++
CPPFLAGS= -I. -g -std=c++11      #opciones de compilación
RM=rm -f

all: main
#-----------------------------------------------------------
# Compilacion
main.o: main.cc 
	${CC} -c main.cc ${CPPFLAGS}

agenda.o: agenda.cc agenda.h
	${CC} -c agenda.cc ${CPPFLAGS}
# Compilacion
contacto.o: contacto.cc contacto.h
	${CC} -c contacto.cc ${CPPFLAGS}
#linkado
main: main.o contacto.o agenda.o 
	${CC} main.o contacto.o agenda.o  -o main ${LDFLAGS}

#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. OjO: se borrarán sin preguntar
# RM es una de las variables predefinidas en make: invoca borrado de fichero del SO
clean:
	${RM} contacto.o agenda.o main.o main
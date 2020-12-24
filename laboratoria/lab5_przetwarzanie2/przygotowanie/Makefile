CC = gcc
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -lm *c

__start__: ${TRGDIR}/przetwarzanie
	${TRGDIR}/przetwarzanie

${TRGDIR}/przetwarzanie: ${OBJ} ${OBJ}/main.o ${OBJ}/PrzygotowanieProgramu.o\
		${OBJ}/OperacjeLokalne.o ${OBJ}/OperacjePunktowe.o
	${CC} -o ${TRGDIR}/przetwarzanie ${OBJ}/main.o ${OBJ}/PrzygotowanieProgramu.o\
		${OBJ}/OperacjeLokalne.o ${OBJ}/OperacjePunktowe.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.c inc/PrzygotowanieProgramu.h inc/OperacjeLokalne.h inc/OperacjePunktowe.h
	${CC} ${FLAGS} -o ${OBJ}/main.o src/main.c

${OBJ}/PrzygotowanieProgramu.o: src/PrzygotowanieProgramu.c inc/PrzygotowanieProgramu.h\
		inc/ZmiennePomocnicze.h
	${CC} ${FLAGS} -o ${OBJ}/PrzygotowanieProgramu.o src/PrzygotowanieProgramu.c

${OBJ}/OperacjeLokalne.o: src/OperacjeLokalne.c inc/OperacjeLokalne.h inc/ZmiennePomocnicze.h
	${CC} ${FLAGS} -o ${OBJ}/OperacjeLokalne.o src/OperacjeLokalne.c

${OBJ}/OperacjePunktowe.o: src/OperacjePunktowe.c inc/OperacjePunktowe.h\
		inc/ZmiennePomocnicze.h
	${CC} ${FLAGS} -o ${OBJ}/WyrazenieZesp.o src/WyrazenieZesp.c


clear:
	rm -f ${TRGDIR}/przetwarzanie ${OBJ}/*

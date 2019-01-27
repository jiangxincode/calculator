CC := gcc
RM := rm -f
LIBS =
CFLAGS += `pkg-config --cflags gtk+-3.0` -Wall
LDFLAGS += `pkg-config --libs gtk+-3.0` -lm -Wall
TARGET = main
OBJS = main.o signal_process.o conversion.o test_calculator.o

all: $(TARGET)

clean:
		$(RM)  *.exe *.o ${TARGET}

main: ${OBJS}
		$(CC) -o main ${OBJS} ${LDFLAGS}

main.o: include/calculator.h
		$(CC) -c src/main.c ${CFLAGS}

signal_process.o: include/calculator.h
		$(CC) -c src/signal_process.c ${CFLAGS}

conversion.o: include/calculator.h
		$(CC) -c src/conversion.c ${CFLAGS}
	
test_calculator.o:
	$(CC) -c test/test_calculator.c ${CFLAGS}

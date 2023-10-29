CC := gcc
RM := rm -f
LIBS =
CFLAGS += `pkg-config --cflags gtk4` -Wall -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -g
LDFLAGS += `pkg-config --libs gtk4` -lm -Wall
TARGET = main main_test
OBJS = main.o signal_process.o conversion.o
TEST_OBJES = test_calculator.o

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

main_test: ${TEST_OBJES}
	$(CC) -o main_test ${TEST_OBJES} ${LDFLAGS}
	
test_calculator.o:
	$(CC) -c test/test_calculator.c ${CFLAGS}

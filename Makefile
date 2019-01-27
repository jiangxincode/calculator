CC := gcc
RM := rm -f
LIBS =
CFLAGS += `pkg-config --cflags gtk+-2.0` -Wall -DGTK_DISABLE_SINGLE_INCLUDES -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DGSEAL_ENABLE
LDFLAGS += `pkg-config --libs gtk+-2.0` -lm -Wall
TARGET = main
OBJS = main.o signal_process.o conversion.o

all: $(TARGET)

clean:
		$(RM)  *.exe *.o

main: ${OBJS}
		$(CC) -o main ${OBJS} ${LDFLAGS} 

main.o: calculator.h
		$(CC) -c main.c ${CFLAGS}

signal_process.o: calculator.h
		$(CC) -c signal_process.c ${CFLAGS}

conversion.o: calculator.h
		$(CC) -c conversion.c ${CFLAGS}

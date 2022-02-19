
TARGET = calculator

SRCS = calculator.c
OBJS = ${SRCS:.c=.o}

LDFLAGS += -lmymath -lmylog


all: $(TARGET)


$(TARGET):
	$(CC) -Wall -Wextra -fPIC -c $(SRCS)
	#$(CC) -o $@ $(OBJS) -lmymath -lmylog
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.so*
	rm -rf $(TARGET)

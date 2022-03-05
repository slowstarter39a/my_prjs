
LIB_TARGET_SO = libmypow.so

SRCS_SO = mypow.c
OBJS_SO = ${SRCS_SO:.c=.o}

all: $(LIB_TARGET_SO)

$(LIB_TARGET_SO):
	$(CC) -Wall -Wextra -fPIC -c $(SRCS_SO)
	$(CC) -shared -Wl,-soname,libmypow.so.1 -o libmypow.so.1.0 $(OBJS_SO)

clean:
	rm -rf *.o
	rm -rf *.so*

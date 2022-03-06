
LIB_TARGET_SO = libmypow.so
MAJOR = 0
MINOR = 1

SRCS_SO = mypow.c
OBJS_SO = ${SRCS_SO:.c=.o}

all: $(LIB_TARGET_SO)

$(LIB_TARGET_SO):
	$(CC) -Wall -Wextra -fPIC -c $(SRCS_SO)
	$(CC) -shared -Wl,-soname,$(LIB_TARGET_SO).$(MAJOR) \
		-o $(LIB_TARGET_SO).$(MAJOR).$(MINOR) $(OBJS_SO)

clean:
	rm -rf *.o
	rm -rf *.so*

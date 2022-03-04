
LIB_TARGET_SO = libmymath.so
LIB_TARGET_A = libmylog.a

SRCS_SO = mymath.c
OBJS_SO = ${SRCS_SO:.c=.o}

SRCS_A = mylog.c
OBJS_A = ${SRCS_A:.c=.o}

all: $(LIB_TARGET_SO) $(LIB_TARGET_A)

$(LIB_TARGET_SO):
	$(CC) -Wall -Wextra -fPIC -c $(SRCS_SO)
	$(CC) -shared -Wl,-soname,libmymath.so.1 -o libmymath.so.1.0 $(OBJS_SO)

$(LIB_TARGET_A):
	$(CC) -Wall -Wextra -c $(SRCS_A)
	$(AR) rvcs $(LIB_TARGET_A) $(OBJS_A)

clean:
	rm -rf *.o
	rm -rf $(LIB_TARGET_SO)*
	rm -rf $(LIB_TARGET_A)*

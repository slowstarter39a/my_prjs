#include "mylog.h"
#include <stdarg.h>
#include <stdio.h>

int msg(char *fmt, ...)
{
	int done;
	va_list arg;

	va_start(arg, fmt);
	done = vfprintf(stdout, fmt, arg);
	va_end(arg);

	return done;
}


#include "mypow.h"
#include <stdio.h>

int my_pow(int a, int b)
{
	int i = 0;
	int result = 1;

	for (i = 0; i < b; i++) {
		result *= a;

		printf("%s result = %d\n", __func__, result);
	}

	return result;
}

#include <stdio.h>
#include "mymath.h"
#include "mylog.h"

int main(void)
{
	int input1 = 0, input2 = 0;
	int result_add, result_sub, result_mul, result_div, result_rem, result_pow;

	printf("This is a calculator application!\n");
	printf("Input two numbers\n");

	(void)scanf("%d%d", &input1, &input2);

	result_add = addition(input1, input2);
	result_sub = subtraction(input1, input2);
	result_mul = multiplication(input1, input2);
	result_div = division(input1, input2);
	result_rem = remainder(input1, input2);
	result_pow = power(input1, input2);

	msg("result_add = %d\n", result_add);
	msg("result_sub = %d\n", result_sub);
	msg("result_mul = %d\n", result_mul);
	msg("result_div = %d\n", result_div);
	msg("result_rem = %d\n", result_rem);
	msg("result_pow = %d\n", result_pow);

	return 0;
}

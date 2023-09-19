#include  "main.h"

/**
 * check_flags - obtaions flags that are active
 * @format: formatted string to print arguments
 * @i: parameter
 * Return: flags
 */
int check_flags(const char *format, int *i)
{
	int j, pres_i;
	int flags = 0;
	const char FLAGS_C[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_A[] = {F_NEG, F_POS, F_ZERO, F_HASH, F_SPACE, 0};

	for (pres_i = *i + 1; format[pres_i] != '\0'; pres_i++)
	{
		for (j = 0; FLAGS_C[j] != '\0'; j++)
			if (format[pres_i] == FLAGS_C[j])
			{
				flags |= FLAGS_A[j];
				break;
			}
		if (FLAGS_C[j] == 0)
			break;
	}
	*i = pres_i - 1;
	return (flags);
}

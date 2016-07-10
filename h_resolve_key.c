#include "libhash.h"

int h_get_key(int size, char *key)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (key[i])
	{
		ret += key[i];
		i++;
	}
	return (ret % size);
}

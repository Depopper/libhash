#include "libhash.h"

t_hash *create_hash(char *name, int size)
{
	t_hash *new_hash;

	if (name == NULL)
		return (NULL);
	if (!(new_hash = (t_hash *)malloc(1 * sizeof(t_hash))))
		return (NULL);
	if (!(new_hash->hash_tab = (t_elem **)malloc(sizeof(t_elem *) * size)))
		return (NULL);
	new_hash->name = name;
	new_hash->size = size;
	return (new_hash);
}
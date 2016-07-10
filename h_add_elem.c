#include "libhash.h"

void	h_add_elem(t_hash *hash, char *key, char *value)
{
	int index;

	hash->nb_elem++;
	index = h_get_key(hash->size, key);
	lst_push_elem(&(hash->hash_tab[index]), ft_strdup(key), ft_strdup(value));
}

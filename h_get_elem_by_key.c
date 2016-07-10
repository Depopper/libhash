#include "libhash.h"

t_elem *get_elem_by_name(t_hash *hash, char *key)
{
	t_elem *curr_elem;
	int index;

	index = h_get_key(hash->size, key);
	curr_elem = hash->hash_tab[index];
	if (!curr_elem)
		return (NULL);
	while (curr_elem && ft_strncmp(curr_elem->key, key, ft_strlen(key)))
		curr_elem = curr_elem->next;
	if (!curr_elem)
		return (NULL);
	return (curr_elem);
}

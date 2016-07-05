#include "libhash.h"

int h_get_key(int size, char *key)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (key[i])
	{
		ret += key[i] + i;
		i++;
	}
	return (ret % size);
}

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

static t_elem *lst_new_elem(char *key, char *value)
{
	t_elem *new_elem;

	if (!(new_elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	new_elem->key = key;
	new_elem->value = value;
	new_elem->next  = NULL;
	return (new_elem);
}

static void lst_push_elem(t_elem **entry, char *key, char *value)
{
	t_elem *curr_elem;

	if (!*entry)
	{
		*entry = lst_new_elem(key, value);
		return ;
	}
	curr_elem = *entry;
	while (curr_elem->next)
		curr_elem = curr_elem->next;
	curr_elem->next = lst_new_elem(key, value);
}

void	h_add_elem(t_hash *hash, char *key, char *value)
{
	int index;

	hash->nb_elem++;
	index = h_get_key(hash->size, key);
	lst_push_elem(&(hash->hash_tab[index]), ft_strdup(key), ft_strdup(value));
}

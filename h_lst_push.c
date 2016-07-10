#include "libhash.h"

void lst_push_elem(t_elem **entry, char *key, char *value)
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

#include "libhash.h"

int main(int ac, char **av, char **env_P)
{
	t_hash *new_hash;
	char **tab;

	new_hash = create_hash("env", 133);
	for(int i = 0; env_P[i]; i++)
	{
		tab = ft_strsplit(env_P[i], '=');
		h_add_elem(new_hash, tab[0], tab[1]);
		printf("key: %s\n", tab[0]);
		//printf("entrèe 1: %s\n\n", tab[1]);
	}
	if (get_elem_by_name(new_hash, "LOGNAME") == NULL)
		ft_putstr("nope");
}

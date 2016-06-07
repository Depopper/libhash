#include "libhash.h"

int main(int ac, char **av, char **env_P)
{
	t_hash *new_hash;
	t_elem *mon_elem;
	char **tab;

	new_hash = create_hash("env", 1000);
	for(int i = 0; env_P[i]; i++)
	{
		tab = ft_strsplit(env_P[i], '=');
		h_add_elem(new_hash, tab[0], tab[1]);
		//printf("key: %s\n", tab[0]);
		//printf("entrèe 1: %s\n\n", tab[1]);
	}
	h_delete_elem(new_hash, "TERM");
	h_print(new_hash);
}

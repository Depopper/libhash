#include "libhash.h"

int main(int ac, char **av, char **env_P)
{
	t_hash *new_hash;
	t_elem *mon_elem;
	char **tab;

	new_hash = create_hash("env", 300);
	for(int i = 0; env_P[i]; i++)
	{
		tab = ft_strsplit(env_P[i], '=');
		h_add_elem(new_hash, tab[0], tab[1]);
		ft_free_tab(&tab);
	}
	h_print(new_hash, VAL_OK|NUM_OK|LEN_OK);
	tab = hash_to_tab(new_hash);
	h_free(&new_hash);
//	ft_puttab(tab);
	ft_free_tab(&tab);
}

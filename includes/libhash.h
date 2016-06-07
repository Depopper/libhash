#ifndef LIBHASH_H
# define LIBHASH_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_elem	t_elem;
struct					s_elem
{
	char *key;
	char *value;
	t_elem *next;
};

typedef struct s_hash	t_hash;
struct					s_hash
{
	char *name;
	int size;
	int nb_elem;
	t_elem **hash_tab;
};

t_hash					*create_hash(char *name, int size);
void					h_add_elem(t_hash *hash, char *key, char *value);
t_elem					*get_elem_by_name(t_hash *hash, char *key);

#endif

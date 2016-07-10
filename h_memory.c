/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 20:18:58 by aschafer          #+#    #+#             */
/*   Updated: 2016/06/07 21:39:14 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

static void h_free_elem(t_elem **elem)
{
	if ((*elem)->key)
		free((*elem)->key);
	if ((*elem)->value)
		free((*elem)->value);
	ft_memdel((void **)elem);
}
static void h_free_elems(t_elem **first)
{
	t_elem *next;

	while ((next = (*first)->next))
	{
		h_free_elem(first);
		*first = next;
	}
	h_free_elem(first);
}

void h_free(t_hash **hash)
{
	int i;

	i = 0;
	while(i < (*hash)->size)
	{
		if ((*hash)->hash_tab[i])
			h_free_elems(&((*hash)->hash_tab[i]));
		i++;
	}
	ft_memdel((void **)&(*hash)->hash_tab);
	ft_memdel((void **)hash);
}

static void h_safe_delete(t_elem *prev, char *key)
{
	t_elem *curr_elem;

	curr_elem = prev->next;
	while (curr_elem && ft_strcmp(key, curr_elem->key) != 0)
	{
		prev = curr_elem;
		curr_elem = curr_elem->next;
	}
	if (curr_elem && ft_strcmp(key, curr_elem->key) == 0)
	{
		prev->next = curr_elem->next;
		h_free_elem(&curr_elem);
	}
}

void	h_delete_elem(t_hash *hash, char *key)
{
	int index;
	t_elem *curr_elem;

	index = h_get_key(hash->size, key);
	curr_elem = hash->hash_tab[index];
	if (!curr_elem)
		return ;
	hash->nb_elem--;
	if (!curr_elem->next && ft_strcmp(key, curr_elem->key) == 0)
		h_free_elem(&curr_elem);
	else if (!ft_strncmp((curr_elem)->key, key, ft_strlen(key)))
	{
		hash->hash_tab[index] = (curr_elem)->next;
		h_free_elem(&curr_elem);
	}
	else
		h_safe_delete(curr_elem, key);
}

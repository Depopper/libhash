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

static void h_safe_delete(t_elem *curr_elem)
{
	ft_putendl("XXXXXXXXXX");
}

void	h_delete_elem(t_hash *hash, char *key)
{
	int index;
	t_elem **curr_elem;

	index = h_get_key(hash->size, key);
	curr_elem = &(hash->hash_tab[index]);
	if (!*curr_elem)
		return ;
	hash->nb_elem--;
	if (!(*curr_elem)->next)
	{
		free((*curr_elem)->key);
		free((*curr_elem)->value);
		ft_memdel((void **)curr_elem);
	}

	else if (!ft_strncmp((*curr_elem)->key, key, ft_strlen(key)))
	{
		hash->hash_tab[index] = (*curr_elem)->next;
		free(*curr_elem);
	}
	else
		h_safe_delete(*curr_elem);
}

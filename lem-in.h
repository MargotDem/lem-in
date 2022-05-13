/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:46:12 by mde-maul          #+#    #+#             */
/*   Updated: 2022/05/13 10:46:14 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_links_list_el {
	char	*name;
}	t_links_list_el;

typedef struct s_links_list {
	t_links_list_el		*content;
	struct s_links_list	*next;
}	t_links_list;

typedef struct s_rooms_list_el {
	int				x;
	int				y;
	char			*name;
	t_links_list	*links_list;
}	t_rooms_list_el;

typedef struct s_rooms_list {
	t_rooms_list_el			*content;
	struct s_rooms_list		*next;
}	t_rooms_list;

typedef struct s_map {
	char			*start;
	char			*end;
	size_t			nb_ants;
	t_rooms_list	*rooms;
}	t_map;

void	handle_error(void);

#endif

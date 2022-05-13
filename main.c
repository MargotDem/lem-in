/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:45:58 by mde-maul          #+#    #+#             */
/*   Updated: 2022/05/13 10:46:00 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

size_t	get_str_ar_size(char **str_ar)
{
	size_t	size;

	size = 0;
	while (str_ar[size])
		size++;
	return (size);
}

int	main(void)
{
	char	*line;
	t_rooms_list	*rooms;
	char	**str_ar;
	size_t	ar_size;
	size_t	start;
	size_t	end;
	t_map	*map;

	get_next_line(0, &line);
	printf("heyyy the line now: %s\n", line);
	start = 0;
	end = 0;
	map = (t_map *)malloc(sizeof(t_map *));
	if (!map)
		handle_error();
	map->nb_ants = ft_atoi(line);
	free(line);
	while (get_next_line(0, &line))
	{
		if (*line == '#')
		{
			if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			{
				if (ft_strcmp(line, "##start") == 0)
					start = 1;
				else
					end = 1;
				printf("hey start or end\n");
			}
		}
		else
		{
			str_ar = ft_strsplit(line, ' ');
			ar_size = get_str_ar_size(str_ar);
			if (ar_size == 3)
			{
				printf("room: %s\n", line);
				if (start)
				{
					start = 0;
					map->start = ft_strdup(str_ar[0]);
				}
				if (end)
				{
					end = 0;
					map->end = ft_strdup(str_ar[0]);
				}
			}
			else
			{
				printf("links: %s\n", line);
			}
			ft_free_str_array(str_ar, ar_size);
				free(str_ar);
		}
		free(line);
	}
	rooms = (t_rooms_list *)malloc(sizeof(t_rooms_list *));
	if (!rooms)
		handle_error();
	map->rooms = rooms;
	//at the end free everythinggg
	free(map->start);
	free(map->end);
	free(map);
	free(rooms);
	//system("leaks lem-in");
}

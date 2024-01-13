/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 07:57:36 by ottouti           #+#    #+#             */
/*   Updated: 2024/01/10 15:11:18 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Parses list and looks for newline*/
int	found_newline(t_char_list *list)
{
	int			i;
	t_char_list	*current;

	if (list == NULL)
		return (0);
	current = get_last_node(list);
	i = 0;
	while (current->str_buffer[i])
	{
		if (current->str_buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*Returns the last node of the list*/
t_char_list	*get_last_node(t_char_list *list)
{
	t_char_list	*current;

	if (!list || list -> str_buffer == NULL)
		return (NULL);
	current = list;
	while (current && current->next)
		current = current->next;
	return (current);
}

/*Finds num of bytes before nl and allocates memory for line*/
void	create_line(char **line, t_char_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*line = (char *) malloc(sizeof(char) * (len + 1));
}

/*Clears the list*/
void	delete_list(t_char_list **list)
{
	t_char_list	*current;
	t_char_list	*next;

	current = *list;
	while (current)
	{
		free(current->str_buffer);
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}


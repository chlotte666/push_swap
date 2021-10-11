/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: challeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:33:28 by challeau          #+#    #+#             */
/*   Updated: 2021/09/20 16:33:28 by challeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	max(t_node *head)
{
	int	max;
	t_node	*ptr;

	max = INT_MIN;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->next;
	}
	return (max);
}

void	partition(t_node **a, t_node **b, int pivot)
{
	char	*ins = ft_strdup("");
	t_node *ptr = (*a);

	while (ptr != NULL && max(ptr) > pivot)
	{
		if (ptr->data > pivot)
			ins = ft_add_char(ins, 'p');
		else
			ins = ft_add_char(ins, 'r');
		ptr = ptr->next;
	}
	for (int i = 0 ; ins[i] ; i++)
	{
		if (ins[i] == 'p')
			push(a, b, "pb\n");
		else if (ins[i] == 'r')
			rotate(a, "ra\n");
	}
	ft_memdel(ins);
}

/* /\* */
/* ** Sorts stack of 6+. */
/* *\/ */
/* void	sort_big_stack(t_node **a, t_node **b) */
/* { */
/* 	while (*b != NULL) */
/* 	{ */
/* 		find_data_limits(*a, &min_data, &max_data); */
/* 		if ((*b)->data < max_data) */
/* 		{ */
/* 			int i = stack_len(*a) - get_index(*a, (*b)->data); */
/* 			while (i > 0) */
/* 			{ */
/* 			     rev_rotate(a, "rra\n"); */
/* 			     i--; */
/* 			} */
/* 			push(b, a, "pa\n"); */
/* 			while (min_data < (*a)->data) */
/* 				rotate(a, "ra\n"); */
/* 		} */
/* 		else */
/* 		{ */
/* 			push(b, a, "pa\n"); */
/* 			rotate(a, "ra\n"); */
/* 		} */
/* 	} */
/* } */


void	sort_big_stack(t_node **a, t_node **b)
{
	int	min_data, max_data, med_data;
	int	min;

	min = INT_MIN;
	while (stack_len(*a) > 5)
	{
		find_data_limits(*a, &min_data, &max_data);
		med_data = (min_data + max_data) / 2;
		partition(a, b, med_data);
	}
//	print_stacks(*a, *b);
	if (stack_is_sorted(*a) == false)
		sort_small_stack(a, b, stack_len(*a));
//	print_stacks(*a, *b);
	while (*b)
	{
		min = get_next_min(*b, min);
		while ((*b)->data != min)
		{
			if (node_id(*b, min) <= stack_len(*b) / 2)
				rotate(b, "rb\n");
			else
				rev_rotate(b, "rrb\n");
		}
		push(b, a, "pa\n");
		rotate(a, "ra\n");
	}
//	print_stacks(*a, *b);
}

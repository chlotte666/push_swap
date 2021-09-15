#include "../inc/push_swap.h"

static void	rev_rotate_stack(t_node **head)
{
	t_node	*ptr;
	t_node	*new_node = NULL;

	if (!head || (*head)->next == NULL)
		return ;
	ptr = (*head);
	while (ptr->next != NULL)
		add_node_back(&new_node, pop(&ptr));
	add_node_front(&new_node, pop(&ptr));
	(*head) = new_node;
}

void		rev_rotate(t_node **a, t_node **b, enum e_ins_info ins_info)
{
	static char	*instructions[3] = {"rra\n", "rrb\n", "rrr\n"};

	if (ins_info == e_INS_A || ins_info == e_INS_AB)
		rev_rotate_stack(a);
	if (ins_info == e_INS_B || ins_info == e_INS_AB)
		rev_rotate_stack(b);
	ft_putstr_fd(instructions[ins_info], 1);
}
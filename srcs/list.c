# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	print_list_content(t_file *node)
{
	while (node->next != NULL)
	{
		if (node->sub_dir != NULL)
			print_list_content(node->sub_dir);
		ft_printf("name : %-20s\ttype : %d\n", node->name, node->type);
		node = node->next;
	}
}

void	fill_list_content(t_file **node, struct dirent *content)
{
	// faire comparaison, add front et add back
	(*node)->name = content->d_name;
	(*node)->type = content->d_type;
	(*node)->next = NULL;
	(*node)->sub_dir = NULL;
}

t_file	*init_list_head(struct dirent *entry)
{
	t_file	*head;
	head = (t_file *)malloc(sizeof(t_file));
	if (head == NULL)
		return NULL;
	fill_list_content(&head, entry);
	return head;
}

t_file	*add_node_to_list(t_file **prev, struct dirent *content)
{
	t_file	*node;
	node = (t_file *)malloc(sizeof(t_file));
	if (node == NULL)
		return NULL;
	fill_list_content(&node, content);
	//if (prev)
	(*prev)->next = node;
	return node;
}


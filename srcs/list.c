# include "../includes/header.h"

void	fill_list_content(t_file **node, struct dirent *content)
{
	(*node)->name = content->d_name;
	(*node)->type = content->d_type;
	(*node)->next = NULL;
}

t_file	*init_list_head(struct dirent *entry)
{
	t_file	*head;
	head = (t_file *)malloc(sizeof(t_file));
	if (head == NULL)
		return NULL;
	fill_list_content(&head, entry);
	//head->name = entry->d_name;
	//head->type = entry->d_type;
	//head->next = NULL; 
	return head;
}

t_file	*add_node_to_list(t_file **prev, struct dirent *content)
{
	t_file	*node;
	node = (t_file *)malloc(sizeof(t_file));
	if (node == NULL)
		return NULL;
	(*prev)->next = node;
	fill_list_content(&node, content);
	//node->name = entry->d_name;
	//node->type = entry->d_type;
	//node->next = NULL;
	return node;
}

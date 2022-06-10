# include "../includes/header.h"

t_file	*init_list_head(struct dirent *entry)
{
	t_file	*head;
	head = (t_file *)malloc(sizeof(t_file));
	if (head == NULL)
		return NULL;
	head->name = entry->d_name;
	head->type = entry->d_type;
	head->next = NULL; 
	return head;
}

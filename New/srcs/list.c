# include "../includes/header.h"

void	print_paths_list(t_path *paths)
{
	if (paths)
	{
		do
		{
			ft_printf("path : %s\tsingle_file : %5d\n", \
				paths->c_path, paths->single_file);
			if (paths->next)
				paths = paths->next;
			else
				break;
		} while (paths);
	}
}

t_path	*add_node_to_paths(t_path **prev, t_path *new_path)
{
	(*prev)->next = new_path;
	new_path->next = NULL;
	return new_path;
}

void	init_path_node(t_path **path_node, char *path, char *add_to_path)
{
	(*path_node) = (t_path *)malloc(sizeof(t_path));
	if (!(*path_node))
		return ;
	if (add_to_path)
	{
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, add_to_path);
	}
	(*path_node)->c_path = path;
	(*path_node)->next = NULL;
}

void	init_new_node(t_path **path, struct stat *buf, struct dirent *content)
{
	ft_printf("in path : %s\n", (*path)->c_path);
	ft_printf("init new node for %s\n", content->d_name);
	//(void)(*path);
	//(void)buf;
	//(void)content;
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	// TODO need to finish filling new linked_list sub node
	node->name = content->d_name;
	node->mode = buf->st_mode;
	ft_printf("node->mode : %hu\n", node->mode);
	node->next = NULL;
	(*path)->node = node;
}



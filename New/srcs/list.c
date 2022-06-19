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
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, add_to_path);
	(*path_node)->c_path = path;
	(*path_node)->next = NULL;
}

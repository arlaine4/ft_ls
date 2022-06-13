# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	select_print_color(char *path, char *name, int type)
{
	// Joining directory path with file name in order to check the right to run
	// the executable if type == 8
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, name);
	if (type == 4)
		ft_printf("\033[1;34m");
	else if (type == 8)
	{
		if (!(access(path, X_OK)))
			ft_printf("\033[1;32m");
	}
	else if (type == 10)
		ft_printf("\033[1;36m");
}

DIR		*get_directory(char *path)
{
	DIR *dir;
	dir = opendir(path);
	if (dir == NULL)
		return NULL;
	return dir;
}

void	print_directory_content(char *dir_path, DIR *dir)
{
	// maybe delete dir_path param ?
	(void)dir_path;

	struct dirent *content;

	t_file *head;
	// loop until we don't have a fd starting with a dot before setting up head
	if ((content = readdir(dir)) != NULL)
		head = init_list_head(content);
	t_file	*prev = NULL;
	while ((content = readdir(dir)) != NULL)
	{
		t_file	*node;
		if (prev == NULL)
			node = add_node_to_list(&head, content);
		else
			node = add_node_to_list(&prev, content);
		prev = node;
		/*
		if ((content->d_name[0] != '.' && ft_strcmp(content->d_name, "..") != 0) \
				&& content->d_type == 4)
		{
			ft_printf("\n\nOpening folder %s\n\n", content->d_name);
			dir = get_directory(ft_strjoin("./", content->d_name));
			return print_directory_content("", dir);
		}*/
	}
	while (head->next != NULL)
	{
		ft_printf("node->name : %-20s\tnode->type : %d\n", head->name, head->type);
		head = head->next;
	}
}

char	*get_current_directory_path(char *buff, char *path)
{
	if (ft_strcmp(path, ".") == 0)
		buff = getcwd(buff, 256);
	else
	{
		buff = getcwd(buff, 256);
		buff = ft_strjoin(buff, "/");
		buff = ft_strjoin(buff, path);
		//tmp = ft_strjoin(path, "/");
	}
		
	// add condition if we do have path as a parameter so we don't use getcwd
	// but opendir or something like that instead
	if (buff == NULL)
	{
		ft_printf("Error opening directory %s\n", ".");
		return NULL;
	}
	return buff;
}

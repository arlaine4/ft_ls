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

void	print_directory_content(t_file *head, char *dir_path, DIR *dir)
{
	//(void)dir_path;

	struct	dirent *content;
	t_file	*node;

	//if (dir && (content = readdir(dir)) != NULL && head == NULL)
	if (dir)
	{
		ft_printf("dir ok\n");
		content = readdir(dir);
		if (content)
		{
			ft_printf("content ok\n");
			if (head == NULL)
			{
				ft_printf("head ok\n");
				while (1)
				{
					if (!(content->d_name[0] == '.'))
					{
						head = init_list_head(content);
						break;
					}
					else
					{
						if (!(content = readdir(dir)))
							return ;
					}
				}
			}
			else
			{
				ft_printf("return at head : %s\n", dir_path);
				return ;
			}
		}
		else
		{
			ft_printf("return at content : %s\n", dir_path);
			return ;
		}
	}
	else
	{
		ft_printf("return at dir : %s\n", dir_path);
		return ;
	}
	t_file	*prev;

	prev = head;
	while (1)
	{
		if (!(content->d_name[0] == '.' || ft_strcmp(content->d_name, "..") == 0))
		{
			if (prev == head)
				node = add_node_to_list(&head, content);
			else
				node = add_node_to_list(&prev, content);

			ft_printf("path : %s | ", dir_path);
			ft_printf("adding %s\t%d\n", content->d_name, content->d_type);
			prev = prev->next;

			if (content->d_type == 4)
			{
				ft_printf("recurs path : %s | ", dir_path);
				ft_printf("recurs call with %s\n", content->d_name);
				print_directory_content(head->sub_dir, content->d_name, opendir(content->d_name));
			}
		}
		content = readdir(dir);
		if (!content)
			break ;
	}
	(void)node;
	//print_list_content(head);
}

/*void	print_directory_content(char *dir_path, DIR *dir)
  {
// maybe delete dir_path param ?
(void)dir_path;

struct dirent *content = NULL;

t_file *head;
t_file *tmp;
// loop until we don't have a fd starting with a dot before setting up head
//ft_printf("name : %s\n", readdir(dir)->d_name);
if ((content = readdir(dir)) != NULL)
head = init_list_head(content);
//ft_printf("head name : %s\n", head->name);
t_file	*prev = NULL;
tmp = head;
while ((content = readdir(dir)) != NULL)
{
while (tmp->next != NULL)
{
ft_printf("name : %-20s\ttype : %d\n", tmp->name, tmp->type);
tmp = tmp->next;
}
t_file	*node;
if (prev == NULL)
node = add_node_to_list(&head, content);
else
node = add_node_to_list(&prev, content);
prev = node;
ft_printf("fd : %s\tstrcmp : %d\n", content->d_name, ft_strcmp(content->d_name, ".."));
if (content->d_name[0] == '.' || ft_strcmp(content->d_name, "..") == 0)
continue;
if (content->d_name[0] != '.' && ft_strcmp(content->d_name, "..") != 0 && \
content->d_type == 4)
{
dir = opendir(content->d_name);
if (!dir)
return;
//dir = opendir(ft_strjoin("./", content->d_name));
//		ft_printf("Opening dir : %s\n", content->d_name);
print_directory_content("", dir);
}
}
while (head->next != NULL)
{
ft_printf("node->name : %-20s\tnode->type : %d\n", head->name, head->type);
head = head->next;
}
}*/

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

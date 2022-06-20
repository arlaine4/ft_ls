# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	parse_paths(t_path *paths, t_options *options)
{
	do
	{
		parse_path_content(&paths, options);
	} while((paths = paths->next) != NULL);
}

void	parse_path_content(t_path **path, t_options *options)
{
	DIR 			*dir;
	struct	dirent 	*content;
	struct	stat	buf;

	dir = opendir((*path)->c_path);
	ft_printf("Entering path %s\n", (*path)->c_path);
	while ((content = readdir(dir)) != NULL)
	{
		if (options && content->d_name[0] == '.' && !options->a)
			continue;
		if (stat(content->d_name, &buf) != -1)
			init_new_node(path, &buf, content);
		else
			ft_printf("Error in parse_path_content for %s\n", content->d_name);
		//ft_printf("%s\n", buf->st_mode);

		//ft_printf("%s\t%d\n", content->d_name, content->d_type);
	}
	closedir(dir);
}

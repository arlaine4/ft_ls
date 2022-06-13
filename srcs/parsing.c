# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	look_for_file_in_directory(char *path)
{
	DIR 	*dir = get_directory(path);
	struct 	dirent *content;
	char	buff[256];
	char	*absolute_path = get_current_directory_path(buff, ".");
	while ((content = readdir(dir)) != NULL)
	{
		if (ft_strcmp(content->d_name, path) == 0)
		{
			//select_print_color(get_current_directory_path(buff, "."), content->d_name, content->d_type);
			select_print_color(absolute_path, content->d_name, content->d_type);
			ft_printf("%s\033[0m\n", content->d_name);
			return ;
		}
		// Need to make some kind of recursive search here if we run into folders while looking
		//  for a potential file, need to change the path and call this function with a new path and
		//  take a look inside this folder

		/*else if (content->d_type == 4)
		{
			path = ft_strjoin(absolute_path, "/");
			path = ft_strjoin(path, content->d_name);
			return look_for_file_in_directory(path);
		}*/
	}
	ft_printf("ft_ls: cannot access '%s': No such file or directory\n", path);
}

void	handle_no_args(char *path)
{
	char 	*dir_path;
	DIR 	*dir;
	char	buff[256];
	t_file	*head = NULL;

	// Using current directory as reference is path is NULL
	if (path == NULL)
		dir_path = get_current_directory_path(buff, ".");
	else
	{
		// Trying to get the current directory path
		dir_path = get_current_directory_path(buff, path);
		// If path isn't a directory or we can't open it, checking if it's just a file inside current directory
		if (dir_path == NULL)
			look_for_file_in_directory(path);
	}
	if (dir_path != NULL)
	{
		// If we did manage to get a valid folder_path from path argument,
		// we get the DIR pointer to this repository
		dir = get_directory(dir_path);
		// If we can't open the directory, we try to check if it's a file
		if (dir == NULL)
			look_for_file_in_directory(path);
		// If we do have this folder we print it's content
		else
		{
			print_directory_content(head, dir_path, dir);
		}
	}
	else
		ft_printf("ft_ls: cannot access '%s': No such file or directory", path);
}

void	handle_double_args(char *av)
{
	// If argument is a folder or file
	if (av[0] != '-')
		handle_no_args(av);
	else
		ft_printf("Need to handle handle_double_args with - arguments as av[1]\n");
}

void	handle_triple_args(char *av1, char *av2)
{
	// select and save path for av1 or av2 depending on the order and content of
	// those string
	//  after getting the options, we get the directory path and call the right
	//   function to print its content with the options as parameters
	t_options *options = NULL;
	if (av1[0] == '-' && av2[0] != '-')
	{
		ft_printf("Selected %s as options to parse\n", av1);
		options = get_prog_options(av1, options);
	}
	else if (av2[0] == '-' && av1[0] != '-')
	{
		ft_printf("Selected %s as options to parse\n", av2);
		options = get_prog_options(av2, options);
	}
	else
		ft_printf("ft_ls: arguments error.\n");
	if (options->invalid == 1)
		ft_printf("ft_ls: invalid options.\n");
	else
	{
		ft_printf("Options after parsing of :\n");
		ft_printf("options->l : %d\n", options->l);
		ft_printf("options->a : %d\n", options->a);
		ft_printf("options->R : %d\n", options->R);
		ft_printf("options->r : %d\n", options->r);
		ft_printf("options->t : %d\n", options->t);
		ft_printf("options->invalid : %d\n", options->invalid);
	}
}

t_options	*get_prog_options(char *s, t_options *options)
{
	options = (t_options *)malloc(sizeof(t_options));
	if (options == NULL)
		return NULL;
	if (ft_strlen(s) == 1)
		options->invalid = 1;
	else
	{
		int	i = 1;
		while (s[i])
		{
			switch (s[i])
			{
				case 'l':
					options->l = 1;
					break;
				case 'a':
					options->a = 1;
					break;
				case 'r':
					options->r = 1;
					break;
				case 'R':
					options->R = 1;
					break;
				case 't':
					options->t = 1;
					break;
				default:
					options->invalid = 1;
					return options;
			};
			i++;
		}
	}
	return options;
}

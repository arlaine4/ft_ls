# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

void	handle_no_args()
{
	//t_file	*head = NULL;
	char	*dir_path;
	DIR		*dir;
	char	buff[256];
	struct	dirent *entry;

	dir_path = get_directory_path(buff, ".");
	dir = opendir(dir_path);
	//entry = readdir(dir);
	//head = init_list_head(entry);
	//ft_printf("head_name : %s\thead_type : %d\n", head->name, head->type);

	if (dir == NULL)
		ft_printf("Can't open current folder for some reason.\n");
	else
	{
		while ((entry = readdir(dir)) != NULL)
		{
			select_print_color(dir_path, entry->d_name, entry->d_type);
			if (entry->d_name[0] != '.')
				ft_printf("%s  \033[0m", entry->d_name);
		}
		ft_printf("\n");
	}
}

void	handle_double_args(char *av)
{
	(void)av;	
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

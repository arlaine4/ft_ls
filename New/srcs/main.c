# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	char		buff[256];
	char		*dir_path;
	char		*new_path;
	t_options	*options;

	dir_path = getcwd(buff, 256);
	if (!dir_path)
	{
		ft_printf("ft_ls: invalid current working directory.\n");
		return 1;
	}
	options	= NULL;

	(void)new_path;
	if (ac == 2)
	{
		new_path = parse_single_arg(&options, dir_path, av[1]);
		if (!new_path && !options)
			ft_printf("ft_ls: cannot access '%s': no such file or directory\n", av[1]);
		else
			print_args_debug(dir_path, options);
	}
	//else if (ac > 2)
	//	new_path = parse_multiple_args(&options, dir_path, av);
	//if ((!options && ft_strcmp(dir_path, new_path) == 0) || options->invalid)
	//	ft_printf("ft_ls: error while parsing arguments.\n");
	//else
	//print_args_debug(dir_path, options);
	return 0;
}

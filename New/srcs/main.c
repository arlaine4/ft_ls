# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	char		buff[256];
	char		*dir_path;
	t_path		*paths;
	t_options	*options;

	options	= NULL;
	paths = NULL;
	dir_path = getcwd(buff, 256);
	if (!dir_path)
	{
		ft_printf("ft_ls: invalid current working directory\n");
		return 1;
	}

	if (ac == 2)
	{
		paths = parse_single_arg(&options, dir_path, av[1]);
		if (!paths && !options)
		{
			ft_printf("ft_ls: cannot access '%s': no such file or directory\n", av[1]);
			exit(0);
		}
	}
	else if (ac > 2)
	{
		paths = parse_multiple_args(&options, dir_path, av);
		if (!options && !paths)
			ft_printf("ft_ls: error while parsing arguments\n");
	}

	if (!paths && (ac == 1 || ac == 2))
		init_path_node(&paths, dir_path, NULL);
	//print_args_debug(options);
	print_paths_list(paths);
	parse_paths(paths, options);
	//ls_loop(paths, options);

	return 0;
}

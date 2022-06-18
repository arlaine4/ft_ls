# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	char		buff[256];
	char		*dir_path;
	t_path		*paths;
	t_options	*options;

	options	= NULL;
	dir_path = getcwd(buff, 256);
	if (!dir_path)
	{
		ft_printf("ft_ls: invalid current working directory\n");
		return 1;
	}

	if (ac == 2)
	{
		paths = parse_single_arg(&options, dir_path, av[1]);
		dir_path = NULL; // Setting base path to NULL since we found ano
		if (!paths && !options)
			ft_printf("ft_ls: cannot access '%s': no such file or directory\n", av[1]);
	}
	else if (ac > 2)
	{
		paths = parse_multiple_args(&options, dir_path, av);
		dir_path = NULL;
		if (!options && !paths)
			ft_printf("ft_ls: error while parsing arguments\n");
	}
	print_args_debug(dir_path, options);
	print_paths_list(paths);
	return 0;
}

# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int		check_if_file_is_dir(const char *file_name)
{
	struct stat path;

	stat(file_name, &path);
	return S_ISREG(path.st_mode);
}

long unsigned int		str_double_len(char **args)
{
	long unsigned int i;

	i = 0;
	while (args[i])
		i++;
	return i;
}

void	print_args_debug(t_options *options)
{
	if (options)
	{
		ft_printf("options->a : %d\n", options->a);
		ft_printf("options->l : %d\n", options->l);
		ft_printf("options->R : %d\n", options->R);
		ft_printf("options->r : %d\n", options->r);
		ft_printf("options->t : %d\n", options->t);
	}
}

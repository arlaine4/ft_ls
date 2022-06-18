# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int		str_double_len(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return i;
}

void	print_args_debug(char *path, t_options *options)
{
	if (path)
		ft_printf("Path found : %s\n", path);
	if (options)
	{
		ft_printf("options->a : %d\n", options->a);
		ft_printf("options->l : %d\n", options->l);
		ft_printf("options->R : %d\n", options->R);
		ft_printf("options->r : %d\n", options->r);
		ft_printf("options->t : %d\n", options->t);
	}
}

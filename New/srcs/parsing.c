# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

char	*parse_single_arg(t_options **options, char *path, char *arg)
{
	if (arg[0] != '-')
	{
		if (!opendir(arg))
			return NULL;
		else
		{
			//path = ft_memset(path, 0, ft_strlen(path));
			ft_strcat(path, "/");
			ft_strcat(path, arg);
			return path;
		}
	}
	else
	{
		(*options) = (t_options *)malloc(sizeof(t_options));
		if (!(*options))
			return NULL;
		loop_over_argv(options, arg);
		return NULL;
	}
	
}

void	loop_over_argv(t_options **options, char *arg)
{
	if (ft_strlen(arg) == 1)
		(*options) = NULL;
	else
	{
		for (size_t i = 1; i < ft_strlen(arg); i++)
		{
			switch (arg[i])
			{
				case 'l':
					(*options)->l = 1;
					break ;
				case 'a':
					(*options)->a = 1;
					break ;
				case 'r':
					(*options)->r = 1;
					break ;
				case 'R':
					(*options)->R = 1;
					break ;
				case 't':
					(*options)->t = 1;
					break ;
				default:
					break ;
			}
		}
	}
}

# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

t_path	*parse_single_arg(t_options **options, char *path, char *arg)
{
	t_path	*c_path;

	c_path = NULL;
	if (arg[0] != '-')
	{
		if (!opendir(arg))
			return NULL;
		else
		{
			init_path_node(&c_path, path, arg);
			return c_path;
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

t_path	*parse_multiple_args(t_options **options, char *path, char **args)
{
	t_path	*curr_path;
	t_path	*head;
	t_path	*prev;

	curr_path = NULL;
	head = NULL;
	prev = NULL;
	for (int i = 1; i < str_double_len(args); i++)
	{
		if (!head)
		{
			head = parse_single_arg(options, path, args[i]);
			prev = head;
		}
		else
		{
			curr_path = parse_single_arg(options, path, args[i]);
			if (curr_path)
			{
				curr_path = add_node_to_paths(&prev, curr_path);
				prev = curr_path;
			}
			else
			{
				ft_printf("ft_ls: cannot access '%s': No such file or directory\n", args[i]);
				continue ;
			}
		}
		
	}
	return head;
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

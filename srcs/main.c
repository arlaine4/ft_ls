# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	if (ac > 2)
		ft_printf("Invalid number of arguments.\n");
	
	char *ptr_base_directory = get_current_directory_path();

	if (ac == 1)
		list_base_directory(ptr_base_directory, NULL);
	/*
		Move all of the code below into another function which decides what call to do in regard
		 to ac and av[1]
	*/
	else if (ac == 2 || ac == 3)
	{
		/*
			Handle arguments here
		*/
		//if (ac == 3)
			
		if (ft_strlen(av[1]) >= 2 && av[1][0] == '-')
		{
			t_options	*args;
			args = check_and_re_order_args(av[1]);
			if (args->invalid == 1)
				ft_printf("Invalid argument(s)\n");
			else
			{
				ft_printf("Valid args\n");
			}
			//else
			//	decide_calls_for_base_args(args
		}
		else
		{
			//if (av[1][0] == '-')
			//	ft_printf("Invalid argument(s)\n");
			/*
				Handle ls redirection with a directory and not current directory
			*/
			if (get_directory_path(av[1]) == NULL)
				ft_printf("ft_ls: cannot access '%s': No such file or directory\n", av[1]);
				//ft_printf("Invalid directory argument.\n");
			else
				list_base_directory(av[1], NULL);
		}
	}
	return 0;
}

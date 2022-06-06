#include "../includes/header.h"
#include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	if (ac == 1 || ac > 3)
	{
		ft_printf("Invalid number of arguments.\n");
	}
	else
	{
		ft_printf("%s\n", av[1]);
	}
	return 0;
}

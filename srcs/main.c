#include "../includes/header.h"
#include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 2)
		ft_printf("Invalid number of arguments.\n");

	char *ptr_base_directory = get_current_directory_path();

	if (ac == 1)
		list_base_directory(ptr_base_directory);
	return 0;
}

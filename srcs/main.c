# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av) {
    if (ac > 2)
        ft_printf("Invalid number of arguments.\n");

    char *ptr_base_directory = get_current_directory_path();

    if (ac == 1)
        list_base_directory(ptr_base_directory, NULL);
    else if (ac == 2)
        handle_ac_two(av[1]);
    /*
        Move all of the code below into another function which decides what call to do in regard
         to ac and av[1]
    */
    return 0;
}

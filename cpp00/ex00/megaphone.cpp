#include "iostream"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (av[++i])
		while (av[i][++j] && av[i][j] >= 'a' && av[i][j] <= 'z')
			av[i][j] -= 32;
	i = 0;
	while (av[++i])
		std::cout << av[i];
}
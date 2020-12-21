#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define ft_print(s) ft_putstr_fd(s, 1)
#define ft_println(s) ft_putendl_fd(s, 1)

/*
ft_print("Words: ");
ft_putnbr_fd(n_words, 1);
ft_print(", chars: ");
ft_putnbr_fd(n_chars, 1);
ft_print("\n");
*/

void ft_wmtest(char **tabstr, char *test, char *s1, char c)
{
	int		i;

	i = 0;
	tabstr = NULL;
	ft_print("\n\x1b[33m");
	ft_print(test);
	ft_print("\x1b[0m\n");
	ft_print("Test string: [\x1b[31m");
	ft_print(s1);
	ft_print("\x1b[0m], test char: [\x1b[31m");
	ft_putchar_fd(c, 1);
	ft_print("\x1b[0m]\nTest result: [\n");
		if (!(tabstr = ft_split(s1, c)))
			ft_println("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print("- ");
				ft_print(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	ft_print("]\n");
}

int main()
{
	char **t;

	t = NULL;
	ft_wmtest(t, "War machine, ft_split, test 1",
		"          ",
		' ');
	free(t);
	t = NULL;
	ft_wmtest(t, "War machine, ft_split, test 2",
		"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse",
		' ');
	free(t);
	t = NULL;
	ft_wmtest(t, "War machine, ft_split, test 3",
		"   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ",
		' ');
	free(t);
	t = NULL;
	ft_wmtest(t, "War machine, ft_split, test 4",
		"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.",
		'i');
	free(t);
	t = NULL;
	ft_wmtest(t, "War machine, ft_split, test 5",
		"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.",
		'z');
	free(t);
	t = NULL;
	ft_wmtest(t, "War machine, ft_split, test 6", "", 'z');
	free(t);
	t = NULL;

	ft_wmtest(t, "ft_split, 7", "qwer\0asdf", 'm');
	free(t);
	t = NULL;

	ft_wmtest(t, "ft_split, 8", "qwer\0asdf", '\0');
	free(t);
	t = NULL;

	ft_wmtest(t, "ft_split, 9", "", '\0');
	free(t);
	t = NULL;

	ft_wmtest(t, "ft_split, 10", "Hello, !", '\0');
	free(t);
	t = NULL;

	ft_wmtest(t, "ft_split, 10", "Hello, beautiful world!", '\0');
	free(t);
	t = NULL;

	return (0);
}

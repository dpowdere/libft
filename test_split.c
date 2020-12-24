#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

#ifdef SPLIT_CONST
# define ft_split	ft_split_const
#endif

#define ft_print(s) ft_putstr_fd(s, 1)
#define ft_println(s) ft_putendl_fd(s, 1)

void ft_test(char *test, char *s1, char c)
{
	int			i;
#	ifdef SPLIT_CONST
	char *const	*tabstr;
#	else
	char		**tabstr;
#	endif

	tabstr = NULL;
	ft_print("\n\x1b[33m");
	ft_print(test);
	ft_print("\x1b[0m\n");
	ft_print("Test string: [\x1b[31m");
	ft_print(s1);
	ft_print("\x1b[0m], test char: [\x1b[31m");
	ft_putchar_fd(c, 1);
	ft_print("\x1b[0m]\nTest result: [\n");
	tabstr = ft_split(s1, c);
	if (!tabstr)
		ft_println("NULL");
	else
	{
		i = 0;
		while (tabstr[i] != NULL)
		{
			ft_print("- ");
			ft_print(tabstr[i]);
#			ifndef SPLIT_CONST
			free(tabstr[i]);
#			endif
			write(1, "\n", 1);
			i++;
		}
	}
	ft_print("]\n");
	free((void *)tabstr);
}

int main()
{
	ft_test("War machine, ft_split, test 1",
		"          ",
		' ');
	ft_test("War machine, ft_split, test 2",
		"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse",
		' ');
	ft_test("War machine, ft_split, test 3",
		"   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ",
		' ');
	ft_test("War machine, ft_split, test 4",
		"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.",
		'i');
	ft_test("War machine, ft_split, test 5",
		"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.",
		'z');
	ft_test("War machine, ft_split, test 6", "", 'z');
	ft_test("ft_split, 7", "qwer\0asdf", 'm');
	ft_test("ft_split, 8", "qwer\0asdf", '\0');
	ft_test("ft_split, 9", "", '\0');
	ft_test("ft_split, 10", "Hello, !", '\0');
	ft_test("ft_split, 11", "Hello, beautiful world!", '\0');

	return (0);
}

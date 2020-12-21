#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	char t[100];

	strcpy(s, "qwer");
	strcpy(t, "0123456789");
	printf("%lu\n", strlcat(s, t, 20));
	printf("%s\n\n", s);

	strcpy(s, "qwer");
	strcpy(t, "0123456789");
	printf("%lu\n", strlcat(s, t, 8));
	printf("%s\n\n", s);

	strcpy(s, "qwer");
	strcpy(t, "0123456789");
	printf("%lu\n", strlcat(s, t, 3));
	printf("%s\n\n", s);

	return 0;
}

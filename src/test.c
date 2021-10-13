
#include "../include/pipex.h"

int test(char *s)
{
	printf("in test %p\n", &s);
	s[3] = '4';
	printf("in test %s\n", s);
	return (0);
}

int main()
{
	char *s;

	s = malloc(sizeof(char) * 10);
	s[0] = 'j';
	s[1] = 'e';
	s[2] = 's';
	s[3] = 'u';
	s[4] = 'i';
	s[5] = 't';
	s[6] = 'l';
	s[7] = 'a';
	s[8] = 'w';
	s[9] = '\0';
	printf("dans main %p\n", &s);
	test(s);
	printf("dans main %p\n", &s);
	return (0);
}
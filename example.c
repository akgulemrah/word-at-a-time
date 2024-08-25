#include "word_at_a_time.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *str = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, "
		"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
		"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
		"nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
		"reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
		"pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa "
		"qui officia deserunt mollit anim id est laborum.";
	char buf[50];

	// 
	if (!word_at_a_time(str, buf))
		printf("%s | ", buf);
	else
		return EXIT_FAILURE;
	
	while (!word_at_a_time(0, buf))
		printf("%s | ", buf);
	return EXIT_SUCCESS;
}

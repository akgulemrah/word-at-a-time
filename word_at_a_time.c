#include "word_at_a_time.h"
#include <stddef.h>

int word_at_a_time(char *src, char *buf)
{
	static char *src_ptr = NULL;
	if (src != NULL) {
		src_ptr = src;
	}

	if (src_ptr == NULL || *src_ptr == '\0') {
		return -1; 
	}

	while (*src_ptr == ' ' && *src_ptr != '\0') {
		src_ptr++;
	}

	if (*src_ptr == '\0') {
		return -1; 
	}

	while (*src_ptr != ' ' && *src_ptr != '\0') {
		*buf++ = *src_ptr++;
	}

	*buf = '\0';

	return 0;
}

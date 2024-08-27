#if !defined(WORD_AT_A_TIME_H)
#define WORD_AT_A_TIME_H 1

#include <stddef.h>
#include <ctype.h>

int word_at_a_time(const char *src, char *buf)
{
        static const char *src_ptr = NULL;

        if (src != NULL)
                src_ptr = src;
        
        if (src_ptr == NULL)
                return -1;
        else if (*src_ptr == '\0')
                return -1; 

        while (isspace(*src_ptr))
                src_ptr++;

        if (*src_ptr == '\0')
                return -1;

        while (!isspace(*src_ptr) && *src_ptr != '\0')
                *buf++ = *src_ptr++;

        *buf = '\0';
        return 0;
}

#endif /* WORD_AT_A_TIME */

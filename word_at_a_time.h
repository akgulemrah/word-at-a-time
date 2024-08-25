#if !defined(WORD_AT_A_TIME_H)
#define WORD_AT_A_TIME_H 1

#include <stddef.h>

int word_at_a_time(char *src, char *buf)
{
        static char *src_ptr = NULL;
        char *buf_ptr = buf;
        if (src != NULL)
                src_ptr = src;
        
        if (src_ptr == NULL)
                return -1;
        else if (*src_ptr == '\0')
                return -1; 

        while (*src_ptr == ' ' && *src_ptr != '\0')
                src_ptr++;

        if (*src_ptr == '\0')
                return -1; 

        while (*src_ptr != ' ' && *src_ptr != '\0')
                *buf_ptr++ = *src_ptr++;

        *buf_ptr = '\0';
        return 0;
}

#endif /* WORD_AT_A_TIME */

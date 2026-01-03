#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    /* Maximum input line length. */
#define LENGTH_LIMIT 80 /* We print lines longer than this limit. */

int my_getline(char s[], int lim);

/* Purpose: Prints back input lines longer than 80 characters. */
int main(void)
{
    int len;            /* Current line text length. */
    char line[MAXLINE]; /* Current input line (text only) */

    /* my_getline returns -1 only on EOF before any data; 0 is a valid
     * empty line. */
    while ((len = my_getline(line, MAXLINE)) >= 0)
    {
        if (len > LENGTH_LIMIT)
        {
            printf("%s\n", line);
        }
    }

    return EXIT_SUCCESS;
}

/*
 * my_getline: Read one line of text into s, return the line length.
 *
 * Contract:
 * - Stores up to (lim - 1) characters of text in s, always '\0'
 * terminated.
 * - Does not store '\n'.
 * - Returns the full text length (excluding '\n'), even if longer than
 * the buffer.
 * - Returns 0 for an empty line.
 * - Returns -1 if EOF occurs before any characters are read (no more
 * lines).
 */
int my_getline(char s[], int lim)
{
    int c;
    int len = 0;     /* Total text length (excluding '\n'). */
    int idx = 0;     /* Number of characters stored into s. */
    int reading = 1; /* Loop-control flag. */

    if (lim <= 0)
    {
        return -1;
    }

    while (reading)
    {
        c = getchar();

        if (c == EOF)
        {
            reading = 0;
        }
        else if (c == '\n')
        {
            reading = 0;
        }
        else
        {
            ++len;

            if (idx < (lim - 1))
            {
                s[idx] = c;
                ++idx;
            }
        }
    }

    s[idx] = '\0';

    /* EOF before any text and before any newline => no more lines. */
    if ((c == EOF) && (len == 0))
    {
        return -1;
    }

    return len;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10 /* Maximum input line length. */

int my_getline(char s[], int lim);
void copy(char to[], char from[]);

/* Purpose: Prints the longest input line (truncated to fit the buffer).
 */
int main(void)
{
    int len;               /* current line text length */
    int max;               /* maximum text length seen so far */
    int have_any_line;     /* did we read at least one line? */
    char line[MAXLINE];    /* current input line (text only) */
    char longest[MAXLINE]; /* longest line prefix saved here */

    max = 0;
    have_any_line = 0;
    longest[0] = '\0';

    /* my_getline returns -1 only on EOF before any data; 0 is a valid
     * empty line. */
    while ((len = my_getline(line, MAXLINE)) >= 0)
    {
        have_any_line = 1;

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (have_any_line)
    {
        if (max > 0)
        {
            printf("%s\n", longest);
        }
        printf("Actual length of longest line: %d\n", max);
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

/* copy: Copy 'from' into 'to'; assume to is big enough. */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

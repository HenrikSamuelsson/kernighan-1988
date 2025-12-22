#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("\\a (alert) Produces an audible or visible alert without "
           "changing the active position.\n");
    printf("\a");
    printf("\n");

    printf("\\b (backspace)  Moves the active position to the previous "
           "position on the current line. If the active position is at "
           "the initial position of a line, the behavior of the "
           "display device is unspecified.\n");
    printf("123\b4\n");
    printf("\n");

    printf("\\z Isn't a defined escape sequence in the the C11 "
           "standard lets see what happens.\n");
    printf("\z");
    printf("\n");

    // TODO test \e

    return EXIT_SUCCESS;
}

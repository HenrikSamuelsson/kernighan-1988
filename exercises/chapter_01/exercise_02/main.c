#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("1. Alert\n");
    printf("<\a>\n");
    printf("2. Vertical Tab\n");
    printf("<\v>\n");
    printf("3. Undefined Escape Sequence\n");
    printf("<\z>\n");
    printf("4. GCC Extension (\\e) Escape Sequence\n");
    printf("<\e>\n");
    return EXIT_SUCCESS;
}

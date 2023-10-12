#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'b';
    
    if (islower(c)) {
        printf("%c é uma letra minúscula.\n", c);
    } else {
        printf("%c não é uma letra minúscula.\n", c);
    }
    
    return 0;
}

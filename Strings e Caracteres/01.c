#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'A';
    
    if (isalpha(c)) {
        printf("%c é uma letra.\n", c);
    } else {
        printf("%c não é uma letra.\n", c);
    }
    
    return 0;
}

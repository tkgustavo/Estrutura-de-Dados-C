#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'B';
    
    if (isupper(c)) {
        printf("%c é uma letra maiúscula.\n", c);
    } else {
        printf("%c não é uma letra maiúscula.\n", c);
    }
    
    return 0;
}

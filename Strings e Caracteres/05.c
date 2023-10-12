#include <stdio.h>
#include <ctype.h>

int main() {
    char c = '7';
    
    if (isalnum(c)) {
        printf("%c é uma letra ou um dígito.\n", c);
    } else {
        printf("%c não é uma letra ou um dígito.\n", c);
    }
    
    return 0;
}

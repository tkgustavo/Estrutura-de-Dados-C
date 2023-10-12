#include <stdio.h>
#include <ctype.h>

int main() {
    char c = '5';
    
    if (isdigit(c)) {
        printf("%c é um dígito.\n", c);
    } else {
        printf("%c não é um dígito.\n", c);
    }
    
    return 0;
}

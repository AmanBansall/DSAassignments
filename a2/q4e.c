#include <stdio.h>
#include <ctype.h>
int main() {
    char s[100];
    gets(s);
    for(int i=0;s[i];i++) s[i]=tolower(s[i]);
    puts(s);
    return 0;
}

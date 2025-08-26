#include <stdio.h>
#include <string.h>
int main() {
    char s[100], t;
    gets(s);
    int i=0, j=strlen(s)-1;
    while(i<j) {
        t=s[i]; s[i]=s[j]; s[j]=t;
        i++; j--;
    }
    puts(s);
    return 0;
}

#include <stdio.h>
#include <ctype.h>
int main() {
    char s[100], r[100];
    gets(s);
    int j=0;
    for(int i=0;s[i];i++) {
        char c=tolower(s[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') continue;
        r[j++]=s[i];
    }
    r[j]='\0';
    puts(r);
    return 0;
}

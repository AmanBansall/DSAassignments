#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    char s[50][100], t[100];
    for(int i=0;i<n;i++) gets(s[i]);
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(strcmp(s[i],s[j])>0) {
                strcpy(t,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],t);
            }
        }
    }
    for(int i=0;i<n;i++) puts(s[i]);
    return 0;
}

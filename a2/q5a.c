#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n][n], d[n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++) d[i]=a[i][i];
    for(int i=0;i<n;i++) printf("%d ",d[i]);
    return 0;
}



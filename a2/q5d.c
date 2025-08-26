#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n][n], u[n*(n+1)/2], k=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++) for(int j=i;j<n;j++) u[k++]=a[i][j];
    for(int i=0;i<k;i++) printf("%d ",u[i]);
    return 0;
}

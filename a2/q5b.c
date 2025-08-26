#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n][n], t[3*n-2], k=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i-j<=1 && j-i<=1) t[k++]=a[i][j];
    for(int i=0;i<k;i++) printf("%d ",t[i]);
    return 0;
}

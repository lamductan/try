#include <stdio.h>
#define maxn 100005
#define oo 100000000

int min(int a, int b) {
    if (a==0) return b;
    if (b==0) return a;
    if (a<b) return a; return b;
}
int dp[maxn][111], a[maxn], l[111];
int n, m;
int main() {
   // freopen("test.txt","r",stdin);

    scanf("%d %d",&n, &m);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    for (int i=1; i<=m; i++) scanf("%d",&l[i]);

    a[0] = 0;
    for (int i=1; i<=n; i++) a[i]+=a[i-1];

    int st = 0;
    for (int i=0; i<=n; i++) dp[i][0] = 0;
    for (int i=0; i<=m; i++) dp[0][i] = 0;

    for (int j=1; j<=m; j++) {
        st+=l[j];
        for (int i=n; i>=st; i--)
            if (i>=l[j]) dp[i][j] = dp[i-l[j]][j-1] + a[i] - a[i-l[j]];
        for (int i=st; i<=n; i++) dp[i][j] = min(dp[i][j], dp[i-1][j]);
        //for (int i=1; i<=n; i++) printf("%d ",dp[i][j]);
       // printf("\n");
    }
    int res = oo;
    for (int i=st; i<=n; i++) res=min(res,dp[i][m]);
    if (res==oo) printf("-1"); else printf("%d",res);
}

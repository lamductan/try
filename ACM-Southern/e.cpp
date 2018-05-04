#include <stdio.h>
#include <map>
using namespace std;
map <int, int> M;
int n, m, a[1010][1010];

int max(int a, int b) {return (a>b)?a:b;}

int calc(int x, int y) {
    M.clear();
    M[a[x][y]]++;
    M[a[x][m-y+1]]++;
    M[a[n-x+1][y]]++;
    M[a[n-x+1][m-y+1]]++;
    int sl = 0;
    sl = max(sl, M[a[x][y]]);
    sl = max(sl, M[a[x][m-y+1]]);
    sl = max(sl, M[a[n-x+1][y]]);
    sl = max(sl, M[a[n-x+1][m-y+1]]);
    return sl;
}

int main() {
    //freopen("test.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++)
        for (int j = 1; j <= m; j++) scanf("%d",&a[i][j]);
    int res = m*n;
    for (int i = 1; i<=n/2; i++)
        for (int j = 1; j<=m/2; j++)
            res -= calc(i,j);
    //printf("%d\n",res);
    if (m % 2 == 1) {
        for (int i=1; i<=n/2; i++)
            if (a[i][m/2+1]!=a[n-i+1][m/2+1]) res-=1; else res-=2;
    }
    //printf("%d\n",res);
    if (n % 2 == 1) {
        for (int j = 1; j <= m/2; j++)
            if (a[n/2+1][j]!=a[n/2+1][m-j+1]) res -= 1; else res-=2;
    }
    //printf("%d\n",res);
    if (n%2==1&&m%2==1) res--;


    printf("%d",res);
}

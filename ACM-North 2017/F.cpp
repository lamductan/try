#include <stdio.h>
#define maxn 39811


int n, m, cnt, u, v, tr[maxn], link[maxn], ke[maxn], dinh[maxn], res;
bool chuaxet[maxn];

void dfs(int i) {
    dinh[cnt]++;
    chuaxet[i] = false;
    int k = link[i];
    while (k>0) {
        int v = ke[k];
        if (chuaxet[v]) dfs(v);
        k=tr[k];
    }
}

int calc(int cnt, int z) {
    if (cnt%2==1) return 1-(z%2);
    return 0;
}

void addc(int u, int v, int i) {
    ke[i] = v;
    tr[i] = link[u];
    link[u] = i;
}

int main() {
    freopen("test.txt","r",stdin);
    int t;
    scanf("%d",&t);

    while (t) {
        t--;
        scanf("%d %d",&n,&m);
        for (int i=1; i<=39811; i++) {
            tr[i] = 0;
            link[i] = 0;
            chuaxet[i] = true;
            dinh[i] = 0;
        }
        for (int i=1; i<=m; i++) {
            scanf("%d %d",&u,&v);
            addc(u,v,i);
            addc(v,u,i+m);
        }

        cnt = 0;
        res=0;
        for (int i=1; i<=n; i++) if (chuaxet[i]) {
            cnt++; dfs(i);
        }

        for (int i=1; i<=cnt; i++) {
            if (dinh[i]==1) res++;
            res += (dinh[i]*(dinh[i]-1)/2);
        }
        res-=m;

        printf("%d\n",calc(cnt, res));

    }
}

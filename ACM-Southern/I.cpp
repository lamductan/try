#include <bits/stdc++.h>

using namespace std;

long long a[20000], b[20000], cx[20000], cy[20000], ans = 0;
int M, N;

int main() {
    scanf("%d", &N);
    for (int x, i = 1; i <= N; ++i) {
        scanf("%d", &x);
        a[x] += i;
        ++cx[x];
    }
    scanf("%d", &M);
    for (int x, i = 1; i <= M; ++i) {
        scanf("%d", &x);
        b[x] += i;
        ++cy[x];
    }



    for (int i = 1; i <= 10000; ++i) if (a[i] > 0)
        for (int j = 1; j <= 10000; ++j) if (b[j] > 0)
            ans += (a[i] * cy[j] - b[j] * cx[i]) *((i >= j) ? (i - j) : (j - i));


    printf("%lld", ans);
}

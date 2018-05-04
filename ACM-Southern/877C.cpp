#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 5;
int main() {
    int n, ans;
    int k[MAX];
    scanf("%d", &n);
    for(int i = 1; i <= n/2; i++) {
        k[i] = k[i + n] = 2*i;
        k[i + n/2] = 2*i-1;
    }
    if (n&1) {
        k[n] = n;
        ans = (3*n - 1)/2;
    }
    else ans = 3*n/2;

    printf("%d\n", ans);
    for(int i = 1; i <= ans; i++)
        printf("%d ", k[i]);
    return 0;
}

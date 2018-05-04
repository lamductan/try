#include <bits/stdc++.h>

using namespace std;

int N, a[1000];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", a + i);

    for(int i = 0; i < N; ++i) {
        int x = (1LL * a[i] * (i + 1)) % N;
        printf("%d ", x ? x : N);
    }
}

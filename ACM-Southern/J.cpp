#include <bits/stdc++.h>

using namespace std;
char a[2000000];
char b[2000000];

int main() {
    scanf("%s", a);
    scanf("%s", b);
    int M = strlen(a);
    int N = strlen(b);
    if (M != N)
        printf("%d", max(M, N));
    else {
        int k = 0;
        while (k < M && a[k] == b[k]) ++k;
        printf("%d", M - k);
    }
}

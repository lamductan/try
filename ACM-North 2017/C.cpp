#include <stdio.h>
#include <iostream>

using namespace std;

int calc(long long n) {
    int cnt = 0;
    while (n) {cnt++; n/=2;};
    return cnt;
}

void solve() {
    long long a, n;
    scanf("%lld %lld",&a,&n);
    long long c = 0^a;
    if (c>a^n) c = a^n;
    if (c>a) c = a;

    for (long long K=1; K<=1000; K++){
                    if (c>((K*n)^a)) c = (K*n)^a;
                }

    printf("%lld\n", c);
}

int main() {

    int t;
    scanf("%d",&t);
    while (t) {
        t--;
        solve();
    }

}

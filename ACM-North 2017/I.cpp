#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int key = 0;
int mark[20000];

int main() {
    //freopen("test.txt","r",stdin); submit di
    int T, x;
    scanf("%d",&T);

    while (T--){
        ++key;
        scanf("%d", &N);
        int cnta = 0, cntb = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &x);
            if (x == 1) {
                ++cnta;
                mark[i] = key;
            }
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d", &x);
            if (x == 1) {
                ++cntb;
                mark[i] = key;
            }
        }

        if (cnta == 0 || cntb == 0) printf("%d\n", N);
        else {
            int cnt = 0;
            for (int i = 0; i < N; ++i)
                cnt += (mark[i] == key);
            printf("%d\n", N - cnt + 1);
        }
    }
}


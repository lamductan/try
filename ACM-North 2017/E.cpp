#include <stdio.h>
#include <iostream>>
using namespace std;
int a[1010][1010];

int main() {
    int t;
    scanf("%d",&t);
    while (t) {
        t--;
        int n, k,aa,b,c,d;
        scanf("%d %d",&n,&k);
        if (k%2==1) {
            b = c = 1;
            aa = (k+1)/2;
            d = 2;
        } else {
            b = 1;
            c = d = 2;
            aa = k/2 + 1;
        }
        a[0][0] = aa;
        a[0][1] = b;
        a[1][0] = c;
        a[1][1] = d;
        for (int i=1; i<n-1;  i++) {
            for (int j = 0; j<=i; j++) {
                a[j][i+1] = a[j][1];
                a[i+1][j] = a[i][j];
                a[i+1][i] = b;
                a[i+1][i+1] = d;
            }
        }
       // freopen("out.txt", "w", stdout);
        if (k == 2) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        //printf("%d %d\n", n, k);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) printf("%d ",a[i][j]);
            printf("\n");
        }

        // print matlab
       // printf("%d %d\n", n, k);
        //cout << "[";
        //for (int i=0; i<n; i++) {
          //  for (int j=0; j<n; j++) printf("%d ",a[i][j]);
            //if (i < n - 1) printf("; ");
        //}
        //cout << "]" << endl;
    }
}

#include <stdio.h>
#include <algorithm>

using namespace std;
int res(int a, int b, int c, int d) {
    if (b==d) return (2*(a&1));
    if (b<d) {
        swap(a,c);
        swap(b,d);
    }
    if (b-d==1) return 1;
    if (b-d>1) return (b-d);

}

int main() {
    int a, b, c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d",res(a,b,c,d));
}

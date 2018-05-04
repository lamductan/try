#include <iostream>

using namespace std;

int main() {
    int a, n;
    cin >> a >> n;

    printf("%d ",1998^5);
    for (int i=0; i<=100000; i++) if ((a^i) % n == 0) {
        cout <<i << endl;
        return 0;
    }
}

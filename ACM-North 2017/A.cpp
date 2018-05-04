#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
int m, p, q, a[111] = {0}, b[111] = {0}, c[111];

int pow(int a, int x, int m) {
    if (a==0&&x==0) return 1;
    int b = 1;
    int n = x;
    while (n) {
        if (n&1) b*=a, b%=m;
        a*=a, a%=m;
        n = n >> 1;
    }
    return b;
}


int f(int k) {
    int res = 0;
    for (int i=1; i<=p; i++) res = res + (c[p-i+1]*pow(k,i-1,m) % m);
    return res % m;
}

int main() {
    freopen("test.txt","r",stdin);
    scanf("%d",&m);

    string st;
    getline(cin, st);

    p = q = 1;

    bool flag = false;
    getline(cin, st);
    for (int i=0; i<st.length(); i++)
        if (st[i]>='0' && st[i]<='9') {
            a[p] = a[p]*10 + st[i]-'0';
            flag = true;
        }
        else {
            p++;
            flag = false;
        }
    if (!flag) p--;

    flag = false;
    getline(cin, st);
    for (int i=0; i<st.length(); i++)
        if (st[i]>='0' && st[i]<='9') {
            b[q] = b[q]*10 + st[i]-'0';
            flag = true;
        }
        else {
            q++;
            flag = false;
        }
    if (!flag) q--;


    //for (int i=1; i<=q; i++) cout << b[i] << " ";

    if (p<q) {
        swap(p,q);
        for (int i=1; i<=p; i++) swap(a[i],b[i]);
    }



    int j = q;
    b[0] = 0;
    for (int i = p; i>=1; i--) {
        c[i] = (a[i] - b[j]) % m;
        if (c[i]<0) c[i]+=m;
        j--;
        if (j<=0) j = 0;
    }

 //   for (int i=1; i<=p; i++) cout << c[i] << " "; cout << endl;

    int res = 0;
    for (int i=0; i<=m-1; i++) {
        if (f(i)==0) res++;//, cout << i << " ";
    }

    long long R[5] = {0LL};
    R[0] = 1;
    R[1] = 1;
    long long p = 1E17;
    long long remind = 0;
    for (int i=1; i<=res; i++) {
        remind = remind + R[1]*2;
        R[1] = remind % p;
        remind /= p;
        remind = remind + R[2]*2;
        R[2] = remind % p;
        remind /= p;
    }
    for (int i=3; i>=1; i--) if (R[i]>0) cout << R[i];
}

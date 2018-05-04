#include <bits/stdc++.h>
using namespace std;

int mark[1000], p[20];

int str2int(string a) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
        ans = ans * 10 + a[i] - 48;
    return ans;
}

string int2str(int a) {
    string ans = "";
    do {
        ans = char(a%10 + 48) + ans;
        a /= 10;
    } while (a);
    return ans;
}

int minPer(int N) {
    string strN = int2str(N);
    sort(strN.begin(), strN.end());
    for (int i = 0; i < strN.size(); ++i)
    if (strN[i] != '0') {
        swap(strN[i], strN[0]);
        break;
    }
    return str2int(strN);
}

int valid(int N) {
    string M = int2str(N);
    int k = 0;
    for (int i = 0; i < M.size(); ++i)
        k += (M[i] != '0');
    return k;
}

int solve(int N) {
    //cout << N << endl;
    if (N < 100) return 0;
    int nOtherZero = valid(N);
    string str = int2str(N);
    if (nOtherZero == 1)  return 1 + solve(N - 1);
    if (nOtherZero == 2) {
        if (N % 10 != 0 && str[0] == '1') {
            //cout << endl << N << " " << N%10 + 1 << endl;
            return (N % 10 + 1 + solve(N - N%10 -1));
        }
    }
    int ans = 0;
//    int idx = 0, ans = 0;
//    for (int i = 1; i < str.size(); ++i)
//        if (str[i] <= str[idx] && str[i] != '0') idx = i;
//
//    if (str[idx] == '1') ans = (idx != 0);
//    else ans = (str[idx] - 49) + 1 + (idx != (str.size() - 1));
//
//    for (int i = 0; i < str.size(); ++i)
//        if (idx == i) continue;
//        else if (str[i] != '0') ans += (str[i] - 48) + 1;
    //cout << "str = " << str << endl;
    if (str[0] != '1') {
        for(int i = 0; i < str.size(); i++)
            {
                ans += str[i] - '0';
                ans += str[i] != '0';
            }
        ans--;
    }
    else {
        for(int i = 1; i < str.size(); i++)
            {
                ans += str[i] - '0';
                ans += str[i] != '0';
            }
        ans++;
    }
    //cout << endl << N << " " << ans << endl;
    return ans + solve(p[str.size() - 1] - 1);
}



void per(queue <int> &q, int u) {
    int a[] = {u/100, (u/10)%10, u%10};
    int b[] = {0, 1, 2};
    do {
        int v = 0;
        for (int i = 0; i < 3; ++i)  v = v * 10 + a[b[i]];
        if (mark[v] == 0) {
            mark[v] = mark[u] + 1;
            q.push(v);
           // cout << v << " " << u << endl;
        }
    } while (next_permutation(b, b + 3));
}

void bfs() {
    queue <int> q;
    q.push(1);
    mark[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = u + 1;
        if (v <= 999) {
            if (mark[v] == 0) {
                q.push(v);
                mark[v] = mark[u] + 1;
              //  cout << u << " " << v << endl;
            }
        }
        if (u > 9 && u < 100) {
            v = (u % 10) * 10 + (u / 10);
            if (mark[v] == 0) {
                q.push(v);
                mark[v] = mark[u] + 1;
            }
        }
        if (99 < u && u <100)
        per(q,u);
    }
    for (int i = 1; i < 1000; ++i) --mark[i];
}


int main() {
    int m, n;
    scanf("%d", &m);
    bfs();
    p[0] = 1;
    for (int i = 1; i < 10; ++i)
        p[i] = p[i - 1] * 10;
    while(m--) {
        int ans = 0;
        scanf("%d", &n);
        if (n < 100) printf("%d\n", mark[n]);
        else printf("%d\n", mark[99] + solve(n));
    }

//    for(int i = 100; i < 1000; ++i)
//        printf("i = %d, mark = %d, solve = %d\n",i, mark[i], solve(i) + mark[99]);
    //cout << solve(962) + mark[99];
}

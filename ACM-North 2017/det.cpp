/*
 * C++ Program to Find the Determinant of a Given Matrix
 */
#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
double d = 0;
double det(int n, double mat[10][10])
{
    int c, subi, i, j, subj;
    double submat[10][10];
    if (n == 2)
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for(c = 0; c < n; c++)
        {
            subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            double x = det(n - 1, submat);
            cout << x << endl;
        d = d + (pow(-1 ,c) * mat[0][c] * x);
        }
    }
    return d;
}
int main()
{
    int n, k;
    freopen("out.txt", "r", stdin);
    cin >> n >> k;
    double mat[10][10];
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout << n << " " << k << endl;
    cout<<"determinant = "<<det(n,mat) << endl;
}

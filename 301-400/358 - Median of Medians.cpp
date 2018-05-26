#include <bits/stdc++.h>
#define INF (1e9)+5

using namespace std;

typedef long long ll;

int V[5], A[5], B[5], C[5];

int main()
{
    cin>>V[1]>>V[2]>>V[3];
    sort(V+1, V+4);
    cin>>A[1]>>A[2]>>A[3];
    sort(A+1, A+4);
    cin>>B[1]>>B[2]>>B[3];
    sort(B+1, B+4);
    C[1]=V[2];
    C[2]=A[2];
    C[3]=B[2];
    sort(C+1, C+4);
    cout<<C[2];
    return 0;
}
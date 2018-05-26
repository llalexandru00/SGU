#include <bits/stdc++.h>

using namespace std;

long long n, nr, V[20];
bool B[100];
int A[1000005], Rez[1000005], R[1000005];

void bkt(long long* V, long long x, long long t)
{
    long long tot=t;
    if (x==10)
    {
        for (long long i=9; i>=1; i--)
            cout<<V[i];
        cout<<'\n';
        return;
    }
    for (long long i=2, j=x-1; i<=x-1; i++, j--)
    {
        tot+=V[i]*V[j];
    }
    for (long long i=0; i<=9; i++)
    {
        if ((tot+i*V[1]*2)%10==x)
        {
            V[x]=i;
            bkt(V, x+1, (tot+i*V[1]*2)/10);
            V[x]=0;
        }
    }
}

void put(char*A, long long a, long long b)
{
    for (long long i=1; i<=b; i++)
    {
        long long t=0;
        for (long long j=1; j<=A[0]; j++)
        {
            A[j]=A[j]*a+t;
            t=A[j]/10;
            A[j]=A[j]%10;
        }
        while(t)
        {
            A[0]++;
            A[A[0]]=t%10;
            t/=10;
        }
    }
}

void prod(int* A, int* B)
{
    int last=0, idx;
    memset(Rez, 0, sizeof(Rez));
    for (int i=1; i<=A[0]; i++)
    {
        int t=0;
        for (int j=1; j<=B[0]; j++)
        {
            Rez[i+j-1]+=A[i]*B[j]+t;
            t=Rez[i+j-1]/10;
            Rez[i+j-1]%=10;
            last=max(i+j-1, last);
        }
        idx=i+B[0]-1;
        while(t)
        {
            idx++;
            Rez[idx]+=t%10;
            last=max(idx, last);
            t/=10;
        }
    }
    for (int i=1; i<=idx; i++)
        A[i]=Rez[i];
    A[0]=idx;
}

int main()
{
    cin>>n;
    //V[1]=1;
    //bkt(V, 2, 0);
    //V[1]=9;
    //bkt(V, 2, 8);
    if (n<9)
        cout<<0;
    else
    {
        if (n==9)
        {
            cout<<8;
            return 0;
        }

        cout<<72;
        n-=10;
        for (int i=1; i<=n; i++)
            cout<<0;
    }
    return 0;
}
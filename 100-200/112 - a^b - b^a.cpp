#include <iostream>

using namespace std;

long long a, b, A[1000], B[1000];

void put(long long a, long long b, long long* A)
{
    A[0]=A[1]=1;
    for(long long i=1; i<=b; i++)
    {
        long long t=0, j;
        for (j=1; j<=A[0]; j++)
        {
            A[j]=A[j]*a+t;
            t=A[j]/10;
            A[j]%=10;
        }
        while (t)
        {
            A[0]++;
            A[A[0]]=t%10;
            t/=10;
        }
    }
}

bool comp(long long* A, long long* B)
{
    if (A[0]>B[0])
        return 1;
    if (B[0]>A[0])
        return 0;
    for (long long i=A[0]; i>=1; i--)
    {
        if (A[i]>B[i])
            return 1;
        if (B[i]>A[i])
            return 0;
    }
    return 1;
}

void dif(long long* A, long long* B)
{
    for (long long i=1; i<=A[0]; i++)
    {
        A[i]=A[i]-B[i];
        if (A[i]<0)
        {
            A[i+1]--;
            A[i]+=10;
        }
    }
    while (A[A[0]]==0 && A[0]>0)
        A[0]--;
}

void write(long long* A)
{
    if (A[0]==0)
        cout<<0;
    for (long long i=A[0]; i>=1; i--)
        cout<<A[i];
}

int main()
{
    cin>>a>>b;
    put(a, b, A);
    put(b, a, B);
    if (comp(A, B))
    {
        dif(A, B);
        write(A);
    }
    else
    {
        dif(B, A);
        cout<<"-";
        write(B);
    }

    return 0;
}
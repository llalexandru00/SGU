#include <iostream>
#include <algorithm>

using namespace std;

struct nod{nod*st, *dr; long long val;};
struct elem{long long val, idx;} V[65540];

long long n, tot;

void arbBuild(nod* act, long long st, long long dr)
{
    if (st==dr)
    {
        act->val=1;
        return;
    }
    act->st=new nod();
    act->dr=new nod();
    arbBuild(act->st, st, (st+dr)/2);
    arbBuild(act->dr, (st+dr)/2+1, dr);
    act->val=act->st->val+act->dr->val;
}

long long arbFind(nod* act, long long x, long long st, long long dr, long long tot)
{
    if (st==dr)
    {
        return tot;
    }
    if (x<=(st+dr)/2)
        return arbFind(act->st, x, st, (st+dr)/2, tot);
    else
        return arbFind(act->dr, x, (st+dr)/2+1, dr, tot+act->st->val);
}
void arbDelete(nod* act, long long x, long long st, long long dr)
{
    if (st==dr)
    {
        act->val=0;
        return;
    }
    if (x<=(st+dr)/2)
        arbDelete(act->st, x, st, (st+dr)/2);
    else
        arbDelete(act->dr, x, (st+dr)/2+1, dr);
    act->val=act->st->val+act->dr->val;
}

bool comp(elem a, elem b)
{
    if (a.val==b.val)
        return a.idx<b.idx;
    return a.val<b.val;
}

int main()
{
    cin>>n;
    nod* tata = new nod();
    arbBuild(tata, 1, n);
    for (long long i=1; i<=n; i++)
    {
        cin>>V[i].val;
        V[i].idx=i;
    }
    sort(V+1, V+n+1, comp);
    for (long long i=1; i<=n; i++)
    {
        tot+= arbFind(tata, V[i].idx, 1, n, 0);
        arbDelete(tata, V[i].idx, 1, n);
    }
    cout<<tot;
    return 0;
}
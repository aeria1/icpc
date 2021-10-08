#include <bits/stdc++.h>
#define inf 1e9+7
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

//Префиксная сумма

vector<int> sum(vector<int> & a)
{
    int n=a.size();
    vector<int >ans(n+1,0);
    for(int i=0;i<n;i++)
    {
        ans[i+1]=ans[i]+a[i];
    }
    return ans;
}

//Разностный массив

vector<int> razn(vector<int> & a)
{
    int n=a.size();
    vector<int >ans(n-1,0);
    for(int i=0;i<n-1;i++)
    {
        ans[i]=a[i+1]-a[i];
    }
    return ans;
}

//z-функция

vector <int> zfunc(string& s)
{
    int l,r=0;
    vector<int> z(s.size(),0);
    for(int i=1;i<s.size();i++)
    {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(z[i]+i<s.size()&&(s[i+z[i]]==s[z[i]]))
        {
            z[i]++;
        }
        if(i+z[i]-1>r)
        {
            l=i;r=i+z[i]-1;
        }
    }
    return z;
}

//Манакер
//d1 - палиндромы нечетной длины(m("сABAd") = 0 0 2 0 0)
//d2 - палиндромы четной длины(m("сABBAd") = 0 0 0 2 0 0)

vector<int> d1 (n);
int l=0, r=-1;
for (int i=0; i<n; ++i) {
  int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
  while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
  d1[i] = k;
  if (i+k-1 > r)
    l = i-k+1,  r = i+k-1;
}
vector<int> d2 (n);
l=0, r=-1;
for (int i=0; i<n; ++i) {
  int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
  while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
  d2[i] = k;
  if (i+k-1 > r)
    l = i-k,  r = i+k-1;
}

//Кун. Паросочетания.

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<bool> used;

bool kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (auto i:g[v]) {
        int to = i;
        if (mt[to] == -1 || kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

//БОР

vector<vector<int>> trie(10000,vector<int>(26,0));
bool terminal[10000];
int m=1;
void insert(string s)
{
    int v=0;
    for(char c:s)
    {
        int edge=c-'a';
        if(trie[v][edge]==0)
        {
            trie[v][edge]=m++;
        }
        v=trie[v][edge];
    }
    terminal[v]=true;
}
bool check(string s)
{
    int v=0;
    for(char c:s)
    {
        int edge=c-'a';
        if(trie[v][edge]==0)
        {
            return false;
        }
        v=trie[v][edge];
    }
    if(terminal[v])return true;
    return false;
}

// СНМ

vector<int> p;
vector<int> r;

void make_set(int v)
{
    p[v]=v;
    r[v]=0;
}

int get(int v)
{
    return p[v]=(p[v]==v?v:get(p[v]));
}

void union_set(int a,int b)
{
    a=get(a);
    b=get(b);
    if(a!=b)
    {
        if (r[a]<r[b])
        {
            swap(a,b);
        }
        if (r[a]==r[b])
        {
            r[a]++;
        }
        p[b]=a;
    }
}

//Крускал
//Функции из СНМ

 multiset<pair<int,pair<int,int>>> s;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        make_set(a);
        make_set(b);
        s.insert({c,{a,b}});
    }
    for(auto i:s)
    {
        if(get(i.second.first)!=get(i.second.second))
        {
            union_set(i.second.first,i.second.second);
            ans+=i.first;
        }
    }
    cout<<ans;


//Дерево отрезков на сумму

struct segtree
{
    vector<long long> tree;
    int size=1;
    void init(int n)
    {
        while(size<n) size*=2;
        tree.assign(2*size-1,0);
    }
    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            tree[x]=v;
            return;
        }
        int m=(rx+lx)/2;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else
        {
            set(i,v,2*x+2,m,rx);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void set(int i,int v)
    {
        set(i,v,0ll,0ll,size);
    }
    int sum(int l,int r,int x,int lx,int rx)
    {
        if(lx>=r||l>=rx)
        {
            return 0;
        }
        if(lx>=l&&rx<=r)
        {
            return tree[x];
        }
        int m=(rx+lx)/2;
        int s1=sum(l,r,2*x+1,lx,m);
        int s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    int sum(int l,int r)
    {
        return sum(l,r,0,0,size);
    }
};

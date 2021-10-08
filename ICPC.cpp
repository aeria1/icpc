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


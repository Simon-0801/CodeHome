#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 10 + 5;

string zh,ho;

void dfs(int l,int r,int zl,int zr){
    if(l>r)  return;
    cout<<ho[r];
    int pos=zh.find(ho[r]);
    dfs(l,l+pos-zl-1,zl,pos-1);
    dfs(l+pos-zl,r-1,pos+1,zr);
}

int main() {
    cin>>zh>>ho;
    dfs(0,ho.length()-1,0,zh.length()-1);
    return 0;
}
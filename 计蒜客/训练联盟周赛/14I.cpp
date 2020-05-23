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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

VI sta;
char tab[100]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main() {
    int p,q;
    ll n;
    scanf("%d%d%lld",&p,&q,&n);
    while(n){
        int lef=n%p;
        sta.push_back(lef);
        n=1ll*(n-lef)*q/p;
    }
    while(sta.size()){
        int tmp=sta.back();
        sta.pop_back();
        cout<<tab[tmp];
    }
    return 0;
}
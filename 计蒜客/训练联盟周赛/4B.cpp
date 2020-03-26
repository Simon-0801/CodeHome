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
const int maxn = 100000 + 5;

map<string,int> mp;
char str[50];
int cnt[maxn];
vector<int> v[30];
int sum[maxn];

int main() {
    int n;
    scanf("%d",&n);
    string tmp;
    int index=0;
    rep(i,1,n){
        scanf("%s",str);
        tmp=str;
        if(!mp[tmp]){
            mp[tmp]=++index;
            cnt[index]++;
            int c=tmp[0]-'A'+1;
            v[c].push_back(index);
        }
        else{
            cnt[mp[tmp]]++;
        }
    }
    ll ans=0;
    rep(i,1,26){
        int len=v[i].size();
        sum[0]=0;
        rep(j,1,len){
            sum[j]=sum[j-1]+cnt[v[i][j-1]];
        }
        repd(j,len,2){
            ans+=2ll*sum[j-1]*cnt[v[i][j-1]];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
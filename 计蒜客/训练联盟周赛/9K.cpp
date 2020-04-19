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

char str[maxn];
VI v;
ll co[maxn];

int main() {
    scanf("%s",str);
    int len=strlen(str);
    rep(i,1,len-1){
        if(str[i]!=str[i-1]){
            v.push_back(2*i+1);
        }
    }
    if(v.size()==0){
        printf("0\n");
        if(str[0]=='H')  printf("1\n");
        else  printf("-1\n");
        return 0;
    }
    int sz=v.size();
    co[0]=1;
    rep(i,0,sz-1){
        repd(j,i+1,1){
            co[j]=co[j-1];
        }
        co[0]=0;
        rep(j,0,i){
            co[j]+=co[j+1]*(-v[i]);
        }
    }
    int f=1;
    if(str[0]=='H'&&sz%2==1)  f=-1;
    if(str[0]=='A'&&sz%2==0)  f=-1;
    printf("%d\n",sz);
    repd(i,sz,0){
        printf("%lld%c",co[i]*f,i==0?'\n':' ');
    }
    return 0;
}
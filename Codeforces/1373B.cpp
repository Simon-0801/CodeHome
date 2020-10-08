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
const int maxn = 100 + 5;

char str[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str+1);
        int len=strlen(str+1);
        int cnt0=0,cnt1=0;
        rep(i,1,len){
            if(str[i]=='0')  cnt0++;
            else  cnt1++;
        }
        int cnt=min(cnt0,cnt1);
        if(cnt&1)  printf("DA\n");
        else  printf("NET\n");
    }
    return 0;
}
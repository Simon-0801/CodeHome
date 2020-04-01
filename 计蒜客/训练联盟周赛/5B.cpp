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

map<char,char> mp;
char str[100];

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        int p;
        scanf("%d",&p);
        mp.clear();
        char a[10],b[10];
        rep(i,1,p){
            scanf("%s%s",a,b);
            mp[a[0]]=b[0];
            mp[b[0]]=a[0];
        }
        int q;
        scanf("%d",&q);
        printf("Test case #%d:\n",cas);
        rep(i,1,q){
            scanf("%s",str+1);
            int l=1,r=strlen(str+1);
            while(l<=r&&(str[l]==str[r]||str[l]==mp[str[r]])){
                l++,r--;
            }
            if(l<=r){
                printf("%s NO\n",str+1);
            }
            else{
                printf("%s YES\n",str+1);
            }
        }
        printf("\n");
    }
    return 0;
}
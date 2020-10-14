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



int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d %d %d\n",a,b,c);
        int g=__gcd(b,c);
        int l=b/g*c;
        int ans;
        if(a%l==0){
            int tmp=a/l;
            ans=tmp*(l/b+l/c-1)-1;
        }
        else{
            int tmp=a/l;
            ans=tmp*(l/b+l/c-1);
            int lft=a-l*tmp;
            if(lft%b==0){
                ans+=lft/b-1+lft/c;
            }
            else if(lft%c==0){
                ans+=lft/c-1+lft/b;
            }
            else{
                ans+=lft/c+lft/b;
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
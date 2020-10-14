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
    int n;
    int tot=0,cas=0;
    while(scanf("%d",&n)&&n){
        ++cas;
        tot+=n;
        int tmp=tot/50;
        if(tmp>0){
            if(tmp==1){
                printf("Input #%d: Sweet!\n",cas);
            }
            else{
                printf("Input #%d: Totally Sweet!\n",cas);
            }
            tot-=tmp*50;
        }
    }
    return 0;
}
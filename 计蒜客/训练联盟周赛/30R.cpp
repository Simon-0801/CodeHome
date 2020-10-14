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
    int s;
    scanf("%d",&s);
    printf("%d:\n",s);
    rep(i,2,s-1){
        int tmp=i+i-1;
        if(s%tmp==0){
            printf("%d,%d\n",i,i-1);
        }
        else if(s%tmp==i){
            printf("%d,%d\n",i,i-1);
        }
        tmp=i*2;
        if(s%tmp==0){
            printf("%d,%d\n",i,i);
        }
        else if(s%tmp==i){
            printf("%d,%d\n",i,i);
        }
    }
    return 0;
}
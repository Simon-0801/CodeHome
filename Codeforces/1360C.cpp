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

int a[maxn];
int cnt[maxn];
VI ji,ou;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        mst(cnt,0);
        ji.clear();
        ou.clear();
        rep(i,1,n){
            scanf("%d",a+i);
            cnt[a[i]]++;
            if(a[i]&1)  ji.push_back(a[i]);
            // else  ou.push_back(a[i]);
        }
        int sz=ji.size();
        if(sz==0||sz==n){
            printf("YES\n");
            continue;
        }
        if(sz%2==0){
            printf("YES\n");
            continue;
        }
        int flag=0;
        sort(ji.begin(),ji.end());
        for(auto &x:ji){
            if(cnt[x-1]){
                flag=1;
                break;
            }
            else if(cnt[x+1]){
                flag=1;
                break;
            }
        }
        if(flag)  printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}
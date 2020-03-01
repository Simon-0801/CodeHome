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
const int maxn = 400000 + 5;

int vis[maxn];
vector<int> v;

void primes(int n){
    mst(vis,0);
    rep(i,2,n){
        if(vis[i])  continue;
        v.push_back(i);
        rep(j,i,n/i)  v[i*j]=1;
    }
}

int main() {
    int n,cnt1=0,cnt2=0,tmp,sum=0;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&tmp);
        if(tmp==1)  cnt1++;
        if(tmp==2)  cnt2++;
        sum+=tmp;
    }
    if(cnt1==0){
        rep(i,1,n){
            printf("2 ");
        }
        return 0;
    }
    if(cnt2==0){
        rep(i,1,n){
            printf("1 ");
        }
        return 0;
    }
    printf("2 1 ");
    cnt2--;
    cnt1--;
    rep(i,3,n){
        if(cnt2){
            printf("2 ");
            cnt2--;
        }
        else if(cnt1){
            printf("1 ");
            cnt1--;
        }
    }
    // primes(sum);
    // int tsum=0;
    // rep(i,0,v.size()-1){
    //     int num=v[i],num1,num2;
    //     int cha=num-tsum;
    //     if(cha&1){
    //         if(cnt1==0)  continue;
    //         num2=min(cnt2,cha/2);
    //         cnt2-=num2;
    //         rep(j,1,num2)  printf("2 ");
    //         printf("1 ");
    //         cnt1--;
    //     }
    //     else{

    //     }
    // }
    return 0;
}
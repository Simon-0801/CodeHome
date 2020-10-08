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

char str[105];
char ans[105];
ll a[105];
map<ll,int> mp;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        // mst(num,0);
        mp.clear();
        rep(i,1,n){
            scanf("%s",str+1);
            ll num=0;
            rep(j,1,m){
                num=2ll*num;
                num=0ll+num+str[j]-'0';
            }
            mp[num]=1;
            a[i]=num;
        }
        ll mx=(1LL<<m)-1;
        ll mid=(mx/2);
        // ll mid=((1LL<<m)-n-1)/2;
        sort(a+1,a+n+1);
        ll l=0;
        rep(i,1,n){
            if(a[i]>mid)  break;
            l++;
        }
        // rep(i,1,n){
        //     mid+=(a[i]<=mid);
        // }
        // repd(i,m-1,0){
        //     printf("%d",((mid&(1ll<<i))>>i));
        // }
        // printf("\n");
        // // printf("%s\n",ans);
        // mst(ans,0);
        if(n&1){
            ll lnum=(1ll<<(m-1))-l;
            ll rnum=(1ll<<(m-1))-(n-l);
            if(lnum>rnum+1){
                ll tmp=mid;
                while(lnum>rnum+1){
                    while(mp.count(tmp)){
                        tmp--;
                    }
                    tmp--;
                    lnum--;
                    rnum++;
                }
                while(mp.count(tmp))  tmp--;
                ltoa(tmp,ans,2);
                // rep(i,1,m-strlen(ans)){
                //     printf("0");
                // }
                // printf("%s\n",ans);
                repd(i,m-1,0){
                    printf("%d",((tmp&(1ll<<i))>>i));
                }
                printf("\n");
            }
            else{
                ll tmp=mid;
                while(lnum<rnum+1){
                    int f=0;
                    while(mp.count(tmp)){
                        tmp++;
                        f=1;
                    }
                    if(f){
                        lnum++;
                        rnum--;
                    }
                    else{
                        tmp++;
                        while(mp.count(tmp))  tmp++;
                        lnum++;
                        rnum--;
                    }
                }
                while(mp.count(tmp))  tmp--;
                ltoa(tmp,ans,2);
                // rep(i,1,m-strlen(ans)){
                //     printf("0");
                // }
                // printf("%s\n",ans);
                repd(i,m-1,0){
                    printf("%d",((tmp&(1ll<<i))>>i));
                }
                printf("\n");
            }
        }
        else{
            ll lnum=(1ll<<(m-1))-l;
            ll rnum=(1ll<<(m-1))-(n-l);
            if(lnum>rnum){
                ll tmp=mid;
                while(lnum>rnum){
                    while(mp.count(tmp)){
                        tmp--;
                    }
                    tmp--;
                    lnum--;
                    rnum++;
                }
                while(mp.count(tmp))  tmp--;
                ltoa(tmp,ans,2);
                // rep(i,1,m-strlen(ans)){
                //     printf("0");
                // }
                // printf("%s\n",ans);
                repd(i,m-1,0){
                    printf("%d",((tmp&(1ll<<i))>>i));
                }
                printf("\n");
            }
            else{
                ll tmp=mid;
                while(lnum<rnum){
                    int f=0;
                    while(mp.count(tmp)){
                        tmp++;
                        f=1;
                    }
                    if(f){
                        lnum++;
                        rnum--;
                    }
                    else{
                        tmp++;
                        while(mp.count(tmp))  tmp++;
                        lnum++;
                        rnum--;
                    }
                }
                while(mp.count(tmp))  tmp--;
                ltoa(tmp,ans,2);
                // rep(i,1,m-strlen(ans)){
                //     printf("0");
                // }
                // printf("%s\n",ans);
                repd(i,m-1,0){
                    printf("%d",((tmp&(1ll<<i))>>i));
                }
                printf("\n");
            }
        }
    }
    return 0;
}
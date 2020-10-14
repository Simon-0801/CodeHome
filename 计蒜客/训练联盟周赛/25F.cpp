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

vector<vector<ll>> mat;
ll num[maxn];
int r,c;
ll s;
vector<ll> sta;     //单调栈

int solve(){
    int res=INF;
    sta.clear();
    sta.push_back(0);
    rep(i,1,c){
        int l=0,r=sta.size()-1;
        ll tmp=num[i]-s;
        int ans=-1;
        while(l<=r){        //二分查找
            int mid=(l+r)/2;
            if(num[sta[mid]]<=tmp){
                l=mid+1;
                ans=sta[mid];
            }
            else{
                r=mid-1;
            }
        }
        if(ans!=-1){
            res=min(res,i-ans);
        }
        while(!sta.empty()&&num[sta[sta.size()-1]]>=num[i]){        //单调栈操作
            sta.pop_back();
        }
        sta.push_back(i);
    }
    return res;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lld",&r,&c,&s);
        //选择r和c中较小的作为行进行存储
        if(r < c){
            mat.resize(r+1);
            rep(i,0,r){
                mat[i].resize(c+1);
            }
            rep(i,1,r){
                rep(j,1,c){
                    scanf("%lld",&mat[i][j]);
                }
            }
        }
        else{
            mat.resize(c+1);
            rep(i,0,c){
                mat[i].resize(r+1);
            }
            rep(i,1,r){
                rep(j,1,c){
                    scanf("%lld",&mat[j][i]);
                }
            }
            swap(r,c);
        }
        rep(i,1,c){
            mat[0][i]=0;
        }
        //预处理二维前缀和
        rep(i,1,r){
            rep(j,1,c){
                mat[i][j]=mat[i-1][j]+mat[i][j];
            }
        }
        int ans=INF;
        rep(l,1,r){
            rep(rr,l,r){
                num[0]=0;
                rep(i,1,c){
                    num[i]=mat[rr][i]-mat[l-1][i];
                }
                rep(i,1,c){
                    num[i]+=num[i-1];
                }
                int ret=solve();
                if(ret==INF)  continue;
                ans=min(ans,(rr-l+1)*ret);
            }
        }
        printf("%d\n",ans==INF?-1:ans);
    }
    return 0;
}
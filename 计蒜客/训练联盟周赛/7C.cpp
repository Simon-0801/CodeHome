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
const int maxn = 20 + 5;

int cnt[maxn];
int cp[maxn];
vector<int> same;

bool hasSeq(){
    rep(i,1,13){
        int tot=0,en=-1;
        rep(j,i,13){
            if(cp[j]==0){
                if(tot>=3)  en=j-1;
                break;
            }
            tot++;
        }
        if(tot>=3){
            while(cp[en]>0){
                cp[en]--;
                en--;
            }
            return true;
        }
    }
    return false;
}

int getScore(){
    rep(i,1,13)  cp[i]=cnt[i];
    while(hasSeq());
    int res=0;
    rep(i,1,13){
        res+=i*cp[i];
    }
    return res;
}

int main() {
    int tmp;
    rep(i,1,7){
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    rep(i,1,13){
        if(cnt[i]>=3){
            same.push_back(i);
        }
    }
    if(same.size()==2){
        int ans=0;
        rep(i,1,13){
            if(cnt[i]<3){
                ans+=i*cnt[i];
            }
        }
        printf("%d\n",ans);
        return 0;
    }
    int ans=INF;
    if(same.size()==1){
        int num=same[0];
        int t=cnt[num];
        int lef=t-3;
        while(lef>=0){
            cnt[num]=lef;
            tmp=getScore();
            ans=min(ans,tmp);
            lef--;
        }
        cnt[num]=t;
    }
    tmp=getScore();
    ans=min(tmp,ans);
    printf("%d\n",ans);
    return 0;
}
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

char str[maxn],out[maxn];
int cnt[30];
int num[30];

int main() {
    int k;
    scanf("%s",str+1);
    scanf("%d",&k);
    scanf("%s",out+1);
    int len=strlen(str+1);
    int i=1;
    while(i<=len){
        if(str[i]>='A'&&str[i]<='Z'){
            int j=i+1;
            int tmp=0;
            while(j<=len&&str[j]>='0'&&str[j]<='9'){
                tmp*=10;
                tmp+=str[j]-'0';
                j++;
            }
            if(j==i+1)  cnt[str[i]-'A'+1]+=1*k;
            else  cnt[str[i]-'A'+1]+=tmp*k;
            i=j;
        }
    }
    i=1;
    len=strlen(out+1);
    while(i<=len){
        if(out[i]>='A'&&out[i]<='Z'){
            int j=i+1;
            int tmp=0;
            while(j<=len&&out[j]>='0'&&out[j]<='9'){
                tmp*=10;
                tmp+=out[j]-'0';
                j++;
            }
            if(j==i+1)  num[out[i]-'A'+1]+=1;
            else  num[out[i]-'A'+1]+=tmp;
            i=j;
        }
    }
    int ans=INF;
    rep(i,1,26){
        if(cnt[i]==0&&num[i]){
            ans=min(0,ans);
        }
        else if(cnt[i]==0&&num[i]==0){

        }
        else if(cnt[i]&&num[i]==0){

        }
        else{
            ans=min(ans,cnt[i]/num[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
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

char str[maxn];
// vector<int> v[40];
char ans[maxn];
int vis[maxn];
vector<char> sta;
int cnt[40];

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    rep(i,1,len){
        int tmp=str[i]-'a'+1;
        cnt[tmp]++;
        // v[tmp].push_back(i);
    }
    // int cnt=0;
    int pos=1;
    rep(i,1,26){
        char c='a'+i-1;
        while(!sta.empty()&&sta.back()<=c){
            printf("%c",sta.back());
            sta.pop_back();
        }
        while(cnt[i]){
            while(pos<=len&&str[pos]>c){
                sta.push_back(str[pos]);
                cnt[str[pos]-'a'+1]--;
                pos++;
            }
            while(pos<=len&&str[pos]==c){
                printf("%c",c);
                cnt[i]--;
                pos++;
            }
        }
    }
    while(!sta.empty()){
        printf("%c",sta.back());
        sta.pop_back();
    }
    // rep(i,1,cnt)  printf("%c",ans[i]);
    // repd(i,len,1){
    //     if(vis[i])   continue;
    //     printf("%c",str[i]);
    // }

    return 0;
}
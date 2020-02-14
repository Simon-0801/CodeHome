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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

char str[maxn];
map<char,int> mp;
set<int> st[30];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str+1);
        int len=strlen(str+1);
        int flag=1;
        string ans="";
        mp.clear();
        for(int i=0;i<30;i++)  st[i].clear();
        ans+=str[1];
        mp[str[1]]=1;
        for(int i=2;i<=len;i++){
            mp[str[i]]=1;
            int tmp1=str[i]-'a'+1,tmp2=str[i-1]-'a'+1;
            if(st[tmp1].count(tmp2)){
                continue;
            }
            int pos=ans.find(str[i-1]);
            int tlen=ans.length();
            if(pos==0){
                if(ans.find(str[i])==ans.npos)  ans=str[i]+ans;
                else{
                    flag=0;
                    break;
                }
            }
            else if(pos==tlen-1){
                if(ans.find(str[i])==ans.npos)  ans=ans+str[i];
                else{
                    flag=0;
                    break;
                }
            }
            else{
                flag=0;
                break;
            }
            st[tmp1].insert(tmp2);
            st[tmp2].insert(tmp1);
            // else if(i==len){
            //     st[tmp].insert(str[i-1]);
            // }
            // else{
            //     st[tmp].insert(str[i+1]);
            //     st[tmp].insert(str[i-1]);
            // }
        }
        if(flag){
            printf("YES\n");
            if(ans.length()<26){
                for(int i=1;i<=26;i++){
                    char c='a'+i-1;
                    if(!mp[c])  ans+=c;
                }
            }
            cout<<ans<<endl;
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int num[30][maxn];
char s[maxn],t[maxn];
// map<char,int> mp;
set<int> st[30];

int main() {
    int T,cnt;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<30;i++)  st[i].clear();
        cnt=1;
        scanf("%s",s+1);
        scanf("%s",t+1);
        int slen=strlen(s+1),tlen=strlen(t+1);
        for(int i=1;i<=slen;i++){
            st[s[i]-'a'+1].insert(i);
        }
        int pos=0;
        for(int i=1;i<=tlen;i++){
            if(st[t[i]-'a'+1].empty()){
                cnt=-1;
                break;
            }
            auto nxt=st[t[i]-'a'+1].upper_bound(pos);
            if(nxt==st[t[i]-'a'+1].end()){
                cnt++;
                pos=0;
                i--;
            }
            else{
                pos=*nxt;
            }
        }
        // memset(num,0,sizeof num);
        // mp[s[1]]=1;
        // for(int i=2;i<=slen;i++){
        //     if(!mp[s[i]])  mp[s[i]]=i;
        //     for(int j=1;j<i;j++){
        //         if(!num[s[i]-'a'+1][j])  num[s[i]-'a'+1][j]=i;
        //     }
        // }
        // int nxt=mp[t[1]];
        // if(nxt==0){
        //     printf("-1\n");
        //     continue;
        // }
        // cnt++;
        // for(int i=2;i<=tlen;i++){
        //     nxt=num[t[i]-'a'+1][nxt];
        //     if(!nxt){
        //         nxt=mp[t[i]];
        //         if(nxt==0){
        //             cnt=-1;
        //             break;
        //         }
        //         cnt++;
        //     }
        // }
        printf("%d\n",cnt);
    }

    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

char p[maxn];
map<pair<int,int>,int> mp;

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d",&n);
        scanf("%s",p+1);
        int ansl=-1,ansr=-1,tmpx=0,tmpy=0,ans=0x3f3f3f3f;
        mp[make_pair(0,0)]=0;
        for(int i=1;i<=n;i++){
            if(p[i]=='L'){
                tmpx--;
            }
            else if(p[i]=='R'){
                tmpx++;
            }
            else if(p[i]=='U'){
                tmpy++;
            }
            else{
                tmpy--;
            }
            if(tmpx==0&&tmpy==0&&!mp[make_pair(0,0)]){
                mp[make_pair(0,0)]=i;
                if(ans>i){
                    ansl=1;
                    ansr=i;
                    ans=i;
                }
            }
            else{
                if(!mp[make_pair(tmpx,tmpy)]){
                    mp[make_pair(tmpx,tmpy)]=i;
                }
                else{
                    if(ans>i-mp[make_pair(tmpx,tmpy)]){
                        ans=i-mp[make_pair(tmpx,tmpy)];
                        ansl=mp[make_pair(tmpx,tmpy)]+1;
                        ansr=i;
                    }
                    mp[make_pair(tmpx,tmpy)]=i;
                }
            }
        }
        if(ans==0x3f3f3f3f)  printf("-1\n");
        else  printf("%d %d\n",ansl,ansr);
    }
    return 0;
}
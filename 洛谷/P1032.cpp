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

string A,B;
pair<string,string> mp[10];
map<string,int> mmp;
int cnt=15;
int indx=0;
queue<pair<string,int>> pq;

int bfs(string tmp){
    pq.push(make_pair(tmp,0));
    while(!pq.empty()){
        pair<string,int> tp=pq.front();
        pq.pop();
        string now=tp.first,nxt;
        if(mmp[now])  continue;
        mmp[now]=1;
        if(now==B)  return tp.second;
        rep(i,1,indx){
            int tpos=0,pos;
            while((pos=now.find(mp[i].first,tpos))!=now.npos){
                nxt=now;
                nxt.replace(pos,mp[i].first.length(),mp[i].second);
                tpos=pos+1;
                if(tp.second+1>10)  continue;
                pq.push(make_pair(nxt,tp.second+1));
            }
        }
    }
    return -1;
}

int main() {
    string a,b;
    cin>>A>>B;
    while(cin>>a>>b){
        mp[++indx]=make_pair(a,b);
    }
    cnt=bfs(A);
    if(cnt==-1)  printf("NO ANSWER!\n");
    else  printf("%d\n",cnt);
    return 0;
}
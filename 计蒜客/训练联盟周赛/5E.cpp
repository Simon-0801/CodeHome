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

char mp[55][55];
char str[105];
int r,c;

struct node
{
    char ss[25];
    int x,y;
    char dir;
}p[10005];
int cnt=0;

vector<int> v[30];

void add(int x,int y){
    //上
    ++cnt;
    p[cnt].ss[0]=mp[x][y];
    int pos=0;
    repd(i,x-1,1){
        p[cnt].ss[++pos]=mp[i][y];
    }
    repd(i,r,x+1){
        p[cnt].ss[++pos]=mp[i][y];
    }
    p[cnt].ss[++pos]='\0';
    v[mp[x][y]-'A'+1].push_back(cnt);
    p[cnt].x=x;
    p[cnt].y=y;
    p[cnt].dir='U';

    //下
    ++cnt;
    p[cnt].ss[0]=mp[x][y];
    pos=0;
    rep(i,x+1,r){
        p[cnt].ss[++pos]=mp[i][y];
    }
    rep(i,1,x-1){
        p[cnt].ss[++pos]=mp[i][y];
    }
    p[cnt].ss[++pos]='\0';
    v[mp[x][y]-'A'+1].push_back(cnt);
    p[cnt].x=x;
    p[cnt].y=y;
    p[cnt].dir='D';

    //左
    ++cnt;
    p[cnt].ss[0]=mp[x][y];
    pos=0;
    repd(i,y-1,1){
        p[cnt].ss[++pos]=mp[x][i];
    }
    repd(i,c,y+1){
        p[cnt].ss[++pos]=mp[x][i];
    }
    p[cnt].ss[++pos]='\0';
    v[mp[x][y]-'A'+1].push_back(cnt);
    p[cnt].x=x;
    p[cnt].y=y;
    p[cnt].dir='L';

    //右
    ++cnt;
    p[cnt].ss[0]=mp[x][y];
    pos=0;
    rep(i,y+1,c){
        p[cnt].ss[++pos]=mp[x][i];
    }
    rep(i,1,y-1){
        p[cnt].ss[++pos]=mp[x][i];
    }
    p[cnt].ss[++pos]='\0';
    v[mp[x][y]-'A'+1].push_back(cnt);
    p[cnt].x=x;
    p[cnt].y=y;
    p[cnt].dir='R';
}

node solve(int tmp,char *str){
    int len=strlen(str);
    node res;
    for(auto &nod:v[tmp]){
        node nn=p[nod];
        int plen=strlen(nn.ss);
        int f=1,pos=0;
        rep(i,0,len-1){
            if(str[i]!=nn.ss[pos]){
                f=0;
                break;
            }
            pos=(pos+1)%plen;
        }
        if(f)  return nn;
    }
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        printf("Word search puzzle #%d:\n",cas);
        rep(i,1,26)  v[i].clear();
        // mst(mp,0);
        scanf("%d%d",&r,&c);
        rep(i,1,r){
            scanf("%s",mp[i]+1);
        }
        cnt=0;
        rep(i,1,r){
            rep(j,1,c){
                add(i,j);
            }
        }
        int s;
        scanf("%d",&s);
        rep(l,1,s){
            scanf("%s",str+1);
            int tmp=str[1]-'A'+1;
            node ans=solve(tmp,str+1);
            printf("%c %d %d %s\n",ans.dir,ans.x,ans.y,str+1);
        }
        printf("\n");
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int n;

int fa[maxn],sum[maxn];
char str[maxn];
vector<int> v[maxn];//记录与黑色点相连的白色点
vector<int> black;//记录黑色点
map<int,int> mp;

int find(int x){
	if(fa[x]==x)  return x;
	int root=find(fa[x]);
	sum[x]+=sum[fa[x]];	//路径压缩过程中，组内白点个数的更新 
	return fa[x]=root;
}

void merge(int a,int b){//两组合并
	int ffa=find(a),ffb=find(b);
    if(ffa==ffb)  return;
	fa[ffb]=ffa;
	sum[ffa]+=sum[ffb];
} 

void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
        sum[i]=1;//初始化每个白点自己成为一组
	}
}


int main() {
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++){
        if(str[i]=='B'){
            mp[i]=1;
            black.push_back(i);
        }
    }
    init();
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        if(mp[x]&&!mp[y]){
            v[x].push_back(y);
        }
        else if(!mp[x]&&mp[y]){
            v[y].push_back(x);
        }
        else if(!mp[x]&&!mp[y]){//两个白点相连，合并两组
            merge(x,y);
        }
    }
    ll ans=0;
    for(int i=0;i<black.size();i++){//对每个黑点进行计算
        ll cnt=0;//记录所有与该黑点相连组的白点总数，简化第二种情况下的内层循环
        for(int j=0;j<v[black[i]].size();j++){
            int ff1=find(v[black[i]][j]);
            ans=ans+sum[ff1];
            cnt+=sum[ff1];
        }
        for(int j=0;j<v[black[i]].size();j++){
            int ff1=find(v[black[i]][j]);
            cnt-=sum[ff1];
            ans=ans+cnt*sum[ff1];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
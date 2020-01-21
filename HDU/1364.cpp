#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct node{
	int l,r;
	char dir;
};

vector<node> v;
int vlen;

int mp[105][105];
int sum1[105][105],sum2[105][105];
int m,n;
int tans;

bool check(int i,int j,int steps,char dir){
	if(dir=='R'){
		if(j+steps>n)  return false;
		else  return true;
	}
	if(dir=='L'){
		if(j-steps<1)  return false;
		else  return true;
	}
	if(dir=='U'){
		if(i-steps<1)  return false;
		else  return true;
	}
	if(dir=='D'){
		if(i+steps>n)  return false;
		else  return true;
	}
}

bool judge(int i,int j,int steps,char dir){
	if(dir=='R'){
		if(sum1[i][j+steps]-sum1[i][j]==0)  return true;
		else  return false;
	}
	if(dir=='L'){
		if(sum1[i][j-1]-sum1[i][j-steps]+mp[i][j-steps]==0)  return true;
		else  return false;
	}
	if(dir=='U'){
		if(sum2[i-1][j]-sum2[i-steps][j]+mp[i-steps][j]==0)  return true;
		else  return false;
	}
	if(dir=='D'){
		if(sum2[i+steps][j]-sum2[i][j]==0)  return true;
		else  return false;
	}
}

void dfs(int i,int j,int step){
	int l=v[step].l,r=v[step].r;
	char dir=v[step].dir;
	if(step>=vlen){
		tans=1;
		return;
	}
	for(int k=l;k<=r;k++){
		if(check(i,j,k,dir)&&judge(i,j,k,dir)){
			if(dir=='R'){
				dfs(i,j+k,step+1);
			}
			if(dir=='L'){
				dfs(i,j-k,step+1);
			}
			if(dir=='U'){
				dfs(i-k,j,step+1);
			}
			if(dir=='D'){
				dfs(i+k,j,step+1);
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		v.clear();
		scanf("%d%d",&m,&n);
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&mp[i][j]);
				sum1[i][j]=sum1[i][j-1]+mp[i][j];
				sum2[i][j]=sum2[i-1][j]+mp[i][j];
			}
		}
		int tl,tr;
		while(scanf("%d%d",&tl,&tr)!=EOF&&tl&&tr){
			node tmp;
			tmp.l=tl;
			tmp.r=tr;
			scanf(" %c",&tmp.dir);
//			cout<<tmp.dir<<endl;
			v.push_back(tmp);
		}
		vlen=v.size();
		int ans=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]==1)  continue;
				tans=0;
				dfs(i,j,0);
				if(tans)  ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

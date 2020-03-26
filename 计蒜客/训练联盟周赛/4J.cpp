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
#define eps 1e-8
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;



int main() {
    double x,y,r,tx,ty,s;
	cin>>x>>y>>r>>tx>>ty>>s;
	double ax=s/2,ay=s/2;
	tx+=s/2,ty+=s/2;
	x-=tx,y-=ty;
	if(x<-eps)x=-x;
	if(y<-eps)y=-y;
	double bx=x,by=y;
	double cx=bx-ax,cy=by-ay;
	if(cx<-eps)cx=0;
	if(cy<-eps)cy=0;
	double k=cx*cx+cy*cy;
	double R=r*r;
	int ans=_sign(k-R);
	if(ans==1){
		printf("0\n");
	}
	if(ans==2){
		printf("2\n");
	}
	if(ans==0){
		printf("1\n");
	}
    return 0;
}
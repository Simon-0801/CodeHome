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
#define eps 1e-6
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 50 + 5;

// struct node
// {
//     double x,y;
// }po[maxn];

// bool check(double a,double b){
//     if(abs(a-b)<=eps)  return true;
//     return false;
// }

// int cmpy(node a,node b){
//     if(check(a.y,b.y))  return a.x<b.x;
//     return a.y<b.y;  
// }

// int cmpx(node a,node b){
//     if(check(a.x,b.x))  return a.y<b.y;
//     return a.x<b.x;  
// }

// int main(){
//     int n,p;
//     scanf("%d",&n);
//     rep(cas,1,n){
//         scanf("%d",&p);
//         rep(i,1,p){
//             scanf("%lf%lf",&po[i].x,&po[i].y);
//         }
//         sort(po+1,po+p+1,cmpy);
//         int l=1,r;
//         int ans=0;
//         while(l<=p){
//             r=l+1;
//             while(check(po[l].y,po[r].y))  r++;
//             r--;
//             rep(i,l,r-2){
//                 rep(j,i+2,r){
//                     double tmpx=(po[i].x+po[j].x)/2.0;
//                     rep(mid,i+1,j-1){
//                         if(check(tmpx,po[mid].x)){
//                             double tmpy1=po[i].y-(po[j].x-po[i].x),tmpy2=po[i].y+(po[j].x-po[i].x);
//                             rep(k,1,p){
//                                 if(k==i||k==j||k==mid)  continue;
//                                 if(check(po[k].x,tmpx)&&(check(po[k].y,tmpy1)||check(po[k].y,tmpy2)))  ans++;
//                             }
//                         }
//                     }
//                 }
//             }
//             l=r+1;
//         }
//         sort(po+1,po+p+1,cmpx);
//         l=1,r;
//         while(l<=p){
//             r=l+1;
//             while(check(po[l].x,po[r].x))  r++;
//             r--;
//             rep(i,l,r-2){
//                 rep(j,i+2,r){
//                     double tmpy=(po[i].y+po[j].y)/2.0;
//                     rep(mid,i+1,j-1){
//                         if(check(tmpy,po[mid].y)){
//                             double tmpx1=po[i].x-(po[j].y-po[i].y),tmpx2=po[i].x+(po[j].y-po[i].y);
//                             rep(k,1,p){
//                                 if(k==i||k==j||k==mid)  continue;
//                                 if(check(po[k].y,tmpy)&&(check(po[k].x,tmpx1)||check(po[k].x,tmpx2)))  ans++;
//                             }
//                         }
//                     }
//                 }
//             }
//             l=r+1;
//         }
//         printf("Set #%d: %d\n\n",cas,ans);
//     }
//     return 0;
// }

int ans;
set<set<int> > s;
pair<double, double> pa[55];
double minn = 1e-6;

void check(int a, int b, int c, int m)
{
	int flag = 1;
	set<int> t;
	double lenAB, lenCM;
	double xam, yam, xcm, ycm, tans1, tans2;
	double x1, y1, x2, y2, x3, y3, x4, y4, xx, yy;
	x1 = pa[a].first;
	y1 = pa[a].second;
	x2 = pa[b].first;
	y2 = pa[b].second;
	x3 = pa[c].first;
	y3 = pa[c].second;
	x4 = pa[m].first;
	y4 = pa[m].second;
	xam = x4-x1;
	yam = y4-y1;
	xcm = x4-x3;
	ycm = y4-y3;
	lenAB = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	lenCM = sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
	xx = (x1+x2)/2.0;
	yy = (y1+y2)/2.0;
	tans1 = xam*xcm+yam*ycm;
	tans2 = (x4-x2)*(x4-x3)+(y4-y2)*(y4-y3);
	if(fabs(lenAB-lenCM)> minn) flag = 0;
	if(fabs(xx-x4)>minn||fabs(yy-y4)>minn) flag = 0;
	if(fabs(tans1) > minn) flag = 0;
	if(fabs(tans2) > minn) flag = 0;

	if(flag)
	{
		t.clear();
		t.insert(a);
		t.insert(b);
		t.insert(c);
		t.insert(m);
		if(s.count(t) == 0)
		{
			s.insert(t);
			ans++;
		} 
	} 
}

int main()
{
	int n;
	//printf("%.10lf", minn);
	cin >>n;
	
	for(int t = 1; t <= n; t++)
	{
		int p;
		cin >>p;
		ans = 0;
		s.clear();
		
		for(int i = 1; i <= p; i++)
		cin >>pa[i].first >>pa[i].second;
		
		for(int a = 1; a <= p; a++)
		{
			for(int b = 1; b <= p; b++)
			{
				if(b != a)
				{
					for(int c = 1; c <= p; c++)
					{
						if(c != a && c != b)
						{
							for(int m = 1; m <= p; m++)
							{
								if(m != a && m != b && m != c)
								{
									check(a, b, c, m);
								}
							}
						}
					}
				}
			}
		}
		
		cout<< "Set #"<<t<<": "<<ans<< endl;
		if(t != n) cout<< endl;
	}
}

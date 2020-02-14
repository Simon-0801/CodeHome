#include<iostream>
#include<cmath>
using namespace std;
struct coord
{
	double x,y;
}A[100005];
double ans,l,r,mid,X;
int n;
const double eps = 1e-6;//精度设置

double check(double x){ //求出当前的点到N个点的最大值,即max函数对应点的值
	double tmax=0;
	for(int i = 0;i < n;++i){
		double dis = sqrt((A[i].x-x)*(A[i].x-x)+A[i].y*A[i].y);
		tmax=max(tmax,dis);
	}
    return tmax;
}

double tsearch(double left,double right){
    int i;
    double mid,midmid;
    for(i=0;i<100;i++){     //循环100次，其实可以小一点,满足精度要求即可
        mid=left+(right-left)/2;    //区间中点
        midmid=mid+(right-mid)/2;   //左半区间中点
        if(check(mid)>check(midmid)) //极大值求法
            left=mid;
        else
            right=midmid;
    }
    return mid;
}


int main(){
	scanf("%d",&n);
    l = 10005;
    r = -10005;
    int x,y;
    for(int i = 0;i < n;++i)
    {
        scanf("%d%d",&x,&y);
        A[i].x=x;
        A[i].y=y;
        if(A[i].x < l)	l = A[i].x;
        if(A[i].x > r)	r = A[i].x;//寻找左右边界l,r
    }
    ans=tsearch(l,r);
    printf("%.9lf\n",check(ans));
	return 0;
}
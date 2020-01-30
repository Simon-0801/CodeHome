#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <cstdio> 
#include <map> 
#include <iomanip>
 
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
//#define INF 0x3f3f3f3f
 
using namespace std;

const int maxn=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
 
struct segtree{
	int l,r;
	ll sum;		//sumά���������������� 
//	ll tag; 	//�ӳٱ��	
};
 
segtree t[maxn*4];

ll a[maxn];

void pushup(int p){//����ϲ���������չ 
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
}

//void pushdown(int p){//�����ڵ��״̬���´��ݣ��ӳٱ�ǵĴ��ݣ� 
//	if(t[p].tag){//˵�����ڵ��״̬�ѱ��ı� 
//		int lson=p*2,rson=p*2+1;
//		int mid=(t[p].l+t[p].r)/2;
//		t[lson].tag+=t[p].tag;		//ע������һ����Ҫ�ۼӣ���Ϊ�������п��ܱ����ڵ��θ��� 
//		t[rson].tag+=t[p].tag;
//		t[lson].sum+=(t[lson].r-t[lson].l+1)*t[p].tag;
//		t[rson].sum+=(t[rson].r-t[rson].l+1)*t[p].tag;
//		t[p].tag=0;//���ڵ㴫����ɺ��־��ԭ 
//	}
//}
 
void build(int p,int l,int r){//���� 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
//	t[p].tag=0;			//��ʼ���ӳٱ�� 
	if(l==r){
		scanf("%lld",&t[p].sum);
		return;
	}
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
 
ll query(int p,int L,int R){
	if(L<=t[p].l&&R>=t[p].r){
		return t[p].sum;
	}
	int lson=p*2;
	int rson=p*2+1;
	ll tsum=0;
	int mid=(t[p].l+t[p].r)/2;
//	pushdown(p);		//�����·���֮ǰ�������¸��� 
	if(L<=mid){		//�����໹������ 
		tsum+=query(lson,L,R);
	}
	if(R>mid){ 		//����Ҳ໹������
		tsum+=query(rson,L,R);
	} 
	return tsum;
} 
 

 
void update(int p,int L,int R){
	int lson=p*2,rson=p*2+1;
	if(t[p].sum==t[p].r-t[p].l+1)  return;
	if(t[p].l==t[p].r){//���䱻��ȫ���� 
//		t[p].tag+=num;		//�����ۼӣ�ԭ��ͬ�� 
		t[p].sum=(ll)sqrt(t[p].sum);
		return;//���ڴ˴�ֱ�ӷ��أ�������Ҫ�ӳٱ�ǣ��˴�δ���¸ýڵ������ 
	}
//	pushdown(p);//�����ӽڵ�ǰ�ȴ����ӳٱ�ǣ����ڽ������ĵݹ���� 
	int mid=(t[p].l+t[p].r)/2;
	if(L<=mid){
		update(lson,L,R);
	} 
	if(R>mid){
		update(rson,L,R);
	}
	pushup(p);//�ӽڵ���·��غ�Ҫ���¸��ڵ� 
}

 
 
int main(){
	int n,q,cas=0;
	while(scanf("%d",&n)!=EOF){
		++cas;
		printf("Case #%d:\n",cas);
		build(1,1,n);
		int t,x,y;
		scanf("%d",&q);
		
		for(int i=1;i<=q;i++){
			scanf("%d%d%d",&t,&x,&y);
			if(x>y)  swap(x,y);
			if(t==0){
				update(1,x,y);
			}
			else{
				printf("%lld\n",query(1,x,y));
			}
		} 
		printf("\n");
	}
	return 0;
}

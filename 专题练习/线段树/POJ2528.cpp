#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <cstdio> 
#include <cstdlib>
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
	int id;//lsum����˿�ʼ���������䳤�ȣ�rsum���Ҷ˿�ʼ���������䳤��
	int tag; 
};
 
segtree t[maxn*4];

int a[maxn*3],le[maxn],ri[maxn],vis[maxn];
int cnt;

//void pushup(int p){//����ϲ� 
//	t[p].sum=t[2*p].sum+t[2*p+1].sum;
//}

void pushdown(int p){//�����ڵ��״̬���´��ݣ��ӳٱ�ǵĴ��ݣ� 
	if(t[p].tag){//˵�����ڵ��״̬�ѱ��ı� 
		int lson=p*2,rson=p*2+1;
		int mid=(t[p].l+t[p].r)/2;
		t[lson].tag=t[p].tag;
		t[rson].tag=t[p].tag;
		t[lson].id=t[p].tag;
		t[rson].id=t[p].tag;
		t[p].tag=0;//���ڵ㴫����ɺ��־��ԭ 
	}
}
 
void build(int p,int l,int r){//���� 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	t[p].id=0;
	t[p].tag=0;
	if(l==r){
		return;
	}
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
//	pushup(p);
}
 




//void change(int p,int pos,int num){
//	if(t[p].l==t[p].r){
//		t[p].sum+=num;
//		return;
//	}
//	int mid=(t[p].l+t[p].r)/2;
//	if(pos<=mid)  change(2*p,pos,num);
//	else  change(2*p+1,pos,num);
//	pushup(p);
//}
 
void query(int p,int L,int R){
	if(t[p].l==t[p].r){
		if(t[p].id&&!vis[t[p].id]){
			cnt++;
			vis[t[p].id]=1;
		}
		return;
	}
//	if(L<=t[p].l&&R>=t[p].r){
//		return t[p].sum;
//	}
	int lson=p*2;
	int rson=p*2+1;
//	ll tsum=0;
	int mid=(t[p].l+t[p].r)/2;
	pushdown(p);
	if(L<=mid){//������Ŀ��г����㹻���ȼ����ࣨ��֤��С�ı�ţ� 
		query(lson,L,R);
	}
	if(R>mid){//���ǿ�Խ������������� 
		query(rson,L,R);
	} 
//	return tsum;
} 
 

 
void update(int p,int L,int R,int num){//flag=1��ʾռ�ã�flag=0��ʾ���� 
	int lson=p*2,rson=p*2+1;
	if(L<=t[p].l&&R>=t[p].r){//���䱻��ȫ���� 
		t[p].tag=num;
		t[p].id=num;
		return;//���ڴ˴�ֱ�ӷ��أ�������Ҫ�ӳٱ�ǣ��˴�δ���¸ýڵ������ 
	}
	pushdown(p);//�����ӽڵ�ǰ�ȴ����ӳٱ�ǣ����ڽ������ĵݹ���� 
	int mid=(t[p].l+t[p].r)/2;
	if(L<=mid){
		update(lson,L,R,num);
	} 
	if(R>mid){
		update(rson,L,R,num);
	}
//	pushup(p);//�ӽڵ���·��غ�Ҫ���¸��ڵ� 
}

 
 
int main(){
	int n,q,t;
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		cnt=0;
		scanf("%d",&n);
		int tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&le[i],&ri[i]);
			a[++tot]=le[i];
			a[++tot]=ri[i];
		}
		sort(a+1,a+tot+1);
		tot=unique(a+1,a+2*n+1)-a-1;
		int tmp=tot;
		for(int i=1;i<tmp;i++){
			if(a[i+1]-a[i]>1){
				a[++tot]=a[i]+1;
			}
		}
		sort(a+1,a+tot+1);
		tot=unique(a+1,a+tot+1)-a-1;
		build(1,1,tot);
		for(int i=1;i<=n;i++){
			int x=lower_bound(a+1,a+tot+1,le[i])-a;
			int y=lower_bound(a+1,a+tot+1,ri[i])-a;
			update(1,x,y,i);
		}
		query(1,1,tot);
		printf("%d\n",cnt);
	}

//	for(int i=1;i<=n;i++){
//		scanf("%lld",&a[i]);
//	}
//	build(1,1,n);
//	char ch[5];
//	for(int i=1;i<=q;i++){
//		
//		scanf("%s",ch);
//		if(ch[0]=='C'){
//			int a,b;
//			ll c;
//			scanf("%d%d%lld",&a,&b,&c);
//			update(1,a,b,c);
//		}
//		else{
//			int a,b;
//			scanf("%d%d",&a,&b);
//			printf("%lld\n",query(1,a,b));
//		}
//	} 
	return 0;
}

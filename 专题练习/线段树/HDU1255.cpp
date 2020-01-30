#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2005;
struct Line {
	int k; //代表1 -1 2种状态 
	double s, e, x;
	bool operator < (const Line & w) const {
		return x < w.x; //按照x小的排在前面 
	}
} line[N];
struct Node {
    int l,r;
	int cnt; //代表被包含的次数 
	double len1,len2; //这个区间被包含的长度 
} tr[N << 2]; 
int n, cnt, t = 1; // cnt代表离散化后数组里面元素的个数 
double fy[N]; 
double x1, x2, y11, y2; 
void build(int id, int l, int r) {
    tr[id].l=l;
    tr[id].r=r;
	tr[id].cnt = tr[id].len1 = tr[id].len2 = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
}
void pushup(int id) {
    if (tr[id].cnt>0){ // 代表id这个区间被覆盖了  
		tr[id].len1 = fy[tr[id].r + 1] - fy[tr[id].l]; //因为一个点代表的是一个区间 那r这个点的区间 就是[fy[r], fy[r + 1]]这段长度 
	} else if (tr[id].l != tr[id].r){ //如果这整个区间没有被包含 那么就由儿子区间组成 
		tr[id].len1 = tr[id << 1].len1 + tr[id << 1 | 1].len1; 
	} else tr[id].len1 = 0; //叶子结点  

    if(tr[id].cnt>=2){
        tr[id].len2=tr[id].len1;
    }
    else if(tr[id].l==tr[id].r)  tr[id].len2=0;
    else if(tr[id].cnt==1){
        tr[id].len2=tr[id<<1].len1+tr[id<<1|1].len1;
    }
    else{
        tr[id].len2=tr[id<<1].len2+tr[id<<1|1].len2;
    }

	
}
void update(int id, int x, int y, int d) {
	if (x <= tr[id].l && tr[id].r <= y) {
		tr[id].cnt += d;
		pushup(id); //及时更新这段区间 因为父亲区间可能需要用到我这个区间的len 
		return;
	}
	int mid = (tr[id].l + tr[id].r) >> 1;
	if (x <= mid) update(id << 1, x, y, d);
	if (y > mid) update(id << 1 | 1, x, y, d);
	pushup(id); 
} 
int  find(double y) {
	return lower_bound(fy + 1, fy + 1 + cnt, y) - fy; 
}
int main() {
    int tt;
    scanf("%d",&tt);
	while (tt--) {
        scanf("%d", &n);
		for (int i = 1, j = 1; i <= n; i++) {
			scanf("%lf%lf%lf%lf", &x1, &y11, &x2, &y2);
			line[j].s = y11, line[j].e = y2, line[j].x = x1, line[j].k = 1, fy[j++] = y11;
			line[j].s = y11, line[j].e = y2, line[j].x = x2, line[j].k = -1, fy[j++] = y2;
		}
		sort(line + 1, line + 1 + 2 * n);
		sort(fy + 1, fy + 1 + 2 * n);
		cnt = unique(fy + 1, fy + 1 + 2 * n) - fy - 1; //获取去重后元素的个数
		build(1, 1, cnt - 1); //一个点代表的是一个区间， 一共有cnt个点 所以只有cnt-1个区间
		double ans = 0;
		for (int i = 1; i <= 2 * n; i++) {
			ans += tr[1].len2 * (line[i].x - line[i - 1].x);
			update(1, find(line[i].s), find(line[i].e) - 1, line[i].k); //这里-1是因为每个点代表的是一个区间 我们不能包含e那个点所代表的区间 
		} 
		printf("%.2lf\n", ans); 
	}
	return 0;
}

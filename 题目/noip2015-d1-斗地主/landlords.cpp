#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*	题意中的映射关系
	A 2 3 4 5 6 7 8 9 10 J  Q  K  mg bg
	1 2 3 4 5 6 7 8 9 10 11 12 13 01 02
	新映射
	3 4 5 6 7 8 9 10 J Q  K  A  2  mg bg
	1 2 3 4 5 6 7 8  9 10 11 12 13 15 16
	由于题目数据设定混乱
	故重新建立映射关系
*/
//					   0 A  2  3 4 5
const int mapping[17]={0,12,13,1,2,3,4,5,6,7,8}
struct poker{
	int type;//花色
	int point;//点数
}a[40];
int t,n;
inline bool operator <(poker &a,poker &b){
	return a.point<b.point;
}
inline bool operator >(poker &a,poker &b){
	return a.point>b.point;
}
inline void swap(poker &a,poker &b){
	poker c=a;
	a=b;
	b=c;
}
void quicksort(int l,int r){
	if(l>=r)return;
	poker k=a[rand()%(r-l+1)+l];
	int i=l,j=r;
	while(i<j){
		while(i<j&&a[j]>k)j--;
		while(i<j&&a[i]<k)i++;
		if(i<j)swap(a[i],a[j]);
	}
	a[i]=k;
	quicksort(l,i-1);
	quicksort(i+1,r);
}
int main(int argc,char *argv[]){
	srand(time(0));
	scanf("%d%d",&t,&n);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			scanf("%d%d",&a[i].point,&a[i].type);
			if(a[i].point)
		}
	}
	return 0;
}

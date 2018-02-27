/*
利用拓扑删除链,剩下的就是一个个的圈
分别计算每个圈的大小,取最小即可
	拓扑:找到所有入度为0的点,删除它,并更新其连接的点
	若连接的点入度为0,则加入待删除的点集中
ps:被删除的点入度都为0,可以用来判断是否在环中
*/
#include <stdio.h>
#include <queue>
#define MAX 200001
using namespace std;
int n;
int insiz[MAX];//每个结点入度
bool isvis[MAX];//已经访问过的结点
int nex[MAX];//每个点指向的结点
int minans=MAX+5;
queue<int> q;
bool isinq[MAX];//是否在队列中
int main(int argc,char *argv[]){
	freopen("message10.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&nex[i]);
		insiz[nex[i]]++;
	}
	for(int i=1;i<=n;i++)
		if(insiz[i]==0){
			q.push(i);
			isinq[i]=true;
		}
	int tmp;
	while(!q.empty()){
		tmp=nex[q.front()];
		q.pop();
		insiz[tmp]--;
		if(insiz[tmp]<=0&&!isinq[tmp])
			q.push(tmp);
	}
	int count;
	for(int i=1;i<=n;i++){
		if(insiz[i]<=0||isvis[i])continue;
		tmp=nex[i];
		count=1;
		isvis[i]=true;
		while(tmp!=i){
			if(count>=min)break;
			count++;
			isvis[tmp]=true;
			tmp=nex[tmp];
		}
		if(count<minans)minans=count;
	}
	printf("%d\n",minans);
	fclose(stdin);
	return 0;
}

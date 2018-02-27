#include <iostream>
#include <queue>
#include <stdio.h>
#define DEBUG
using namespace std;
struct qdata{
	int x,y,layout;
}qtmp,qtmp2,qtmp3;
int map[51][51],direct[1001];
int r,n,c,sx,sy,posr,posc;
char ctmp;
string stmp;
queue<qdata> q;
/*
NORTH=0;
SOUTH=1;
WEST=2;
EAST=3;
*/
const int dr[4]={-1,1,0,0},dc[4]={0,0,-1,1};
inline int strtdc(string s){
	if(s=="NORTH")return 0;
	else if(s=="SOUTH")return 1;
	else if(s=="WEST")return 2;
	else if(s=="EAST")return 3;
}
/*
.=0;
X=1;
*=2;
*/
inline int chtin(char c){
	switch(c){
		case '.':return 0;
		case 'X':return 1;
		case '*':return 2;
	}
}
inline char intch(int d){
	switch(d){
		case 0:return '.';
		case 1:return 'X';
		case 2:return '*';
	}
}
int main(int argc,char *argv[]){
	#ifdef DEBUG
		freopen("test.in","r",stdin);
	#endif
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>ctmp;
			map[i][j]=chtin(ctmp);
			if(map[i][j]==2){
				sx=i;
				sy=j;
				map[i][j]=0;
			}
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stmp;
		direct[i]=strtdc(stmp);
	}
	//bfs
	qtmp.x=sx;
	qtmp.y=sy;
	qtmp.layout=1;
	q.push(qtmp);
	while(!q.empty()){
		qtmp2=q.front();
		q.pop();
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cout<<intch(map[i][j]);
		}
		cout<<endl;
	}
	return 0;
}

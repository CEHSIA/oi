#include <stdio.h>
#define DEBUG

#define B 0
#define W 1
#define O 2

int map[5][5];

struct pos{
	int x,y;
}queue[100000];
int head=0,tail=0;
inline void ins(pos tmp){
	head++;
	head=head==100000?0:head;
	queue[head]=tmp;
}
inline pos del(){
	pos tmp=queue[tail];
	tail--;
	tail=tail==100000?0:tail;
	return tmp;
}
inline bool isEmpty(){
	return head==tail;
}
/*
  1 2 3 4
1 w b w o
2 b w b w
3 w b w b
4 b w b o
*/
inline bool isOkay(int &tmp[5][5]){
	bool isq=true;
	for(int i=1;i<=4;i++){
		isq=true;
		if(tmp[i][2]!=tmp[i][1])isq=false;
		if(tmp[i][3]!=tmp[i][1])isq=false;
		if(tmp[i][4]!=tmp[i][1])isq=false;
		if(isq)return true;
		
		isq=true;
		if(tmp[2][i]!=tmp[1][i])isq=false;
		if(tmp[3][i]!=tmp[1][i])isq=false;
		if(tmp[4][i]!=tmp[1][i])isq=false;
		if(isq)return true;
	}
	isq=true;
	if(tmp[2][2]!=tmp[1][1])isq=false;
	if(tmp[3][3]!=tmp[1][1])isq=false;
	if(tmp[4][4]!=tmp[1][1])isq=false;
	if(isq)return true;
	isq=true;
	if(tmp[2][3]!=tmp[1][4])isq=false;
	if(tmp[3][2]!=tmp[1][4])isq=false;
	if(tmp[4][1]!=tmp[1][4])isq=false;
	if(isq)return true;
	return false;
}

void bfs(int tmp[5][5]);

int main(int argc,char *argv[]){
	return 0;
}

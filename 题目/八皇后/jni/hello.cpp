#include <iostream>
using namespace std;
int count;
int isDanger(int (*chess)[8],int row,int line){
	int i,j;
	//列判断
	for(j=0;j<8;j++){
		if(*(*(chess+row)+j)==1){
			return 1;
		}
	}
	//左上判断
	for(i=row,j=line;i>=0&&j<8;i--,j++){
		if(*(*(chess+i)+j)==1){
			return 1;
		}
	}
	//左下判断
	for(i=row,j=line;i>=0&&j<8;i--,j--){
		if(*(*(chess+i)+j)==1){
			return 1;
		}
	}
	//右上判断
	for(i=row,j=line;i>=0&&j<8;i++,j++){
		if(*(*(chess+i)+j)==1){
			return 1;
		}
	}
	//右下判断
	for(i=row,j=line;i>=0&&j<8;i++,j--){
		if(*(*(chess+i)+j)==1){
			return 1;
		}
	}
	return 0;
}
void eq(int (*chess)[8],int row,int line){
	int chess2[8][8],i,j;
	//拷贝棋盘
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			chess2[8][8]=chess[8][8];
		}
	}
	if(row==8){
		cout<<"第"<<count+1<<"种"<<endl;
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				cout<<*(*(chess2+i)+j)<<" ";
			}
			cout<<endl;
		}
	}else{
		for(j=0;j<line;j++){
			if(!isDanger(chess2,row,j)){
				for(i=0;i<8;i++){
					*(*(chess2)+row+i)=0;
				}
				*(*(chess2)+row+j)=0;
				eq(chess2,row+1,line);
			}
		}
	}
}
int main(){
	int chess1[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			chess1[i][j]=0;
		}
	}
	eq(chess1,0,8);
	return 0;
}

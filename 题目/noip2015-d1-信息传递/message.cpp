#include <stdio.h>
#define MAX 200001
FILE *in,*out;
int n,t[MAX],pos[MAX],k;
//对每个信息的位置进行模拟
//t[]为邻接数组，表示每个人的关系
//pos[i]为i信息的位置
int main(int argc,char *argv[]){
	//freopen("message.in","r",stdin);
	in=fopen("message2.in","r");
	out=fopen("message2.out","w");
	fscanf(in,"%d",&n);
	do{
		for(int i=1;i<=n;i++){
			if(t[i]==0){
				fscanf(in,"%d",&t[i]);
				pos[i]=i;
			}
			pos[i]=t[pos[i]];
			if(pos[i]==i){
				fprintf(out,"%d\n",k+1);
				fclose(in);
				fclose(out);
				return 0;
			}
		}
		k++;
	}while(true);
	fclose(in);
	fclose(out);
	return 0;
}

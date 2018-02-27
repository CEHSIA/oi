#include <stdio.h>
FILE *in,*out;
int map[40][40],n,lh,ll,nh,nl;
int main(int argc,char *argv[]){
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);
	in=fopen("magic3.in","r");
	out=fopen("magic3.out","w");
	
	fscanf(in,"%d",&n);
	lh=1;ll=(1+n)/2;//<--关键
	map[lh][ll]=1;
	for(int k=2;k<=n*n;k++){
		if(lh==1&&ll!=n){
			nh=n;
			nl=ll+1;
		}else if(ll==n&&lh!=1){
			nl=1;
			nh=lh-1;
		}else if(lh==1&&ll==n){
			nh=lh+1;
			nl=ll;
		}else if(lh!=1&&ll!=n){
			nh=lh-1;
			nl=ll+1;
			if(map[nh][nl]!=0){
				nh=lh+1;
				nl=ll;
			}
		}
		map[nh][nl]=k;
		lh=nh;ll=nl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fprintf(out,"%d ",map[i][j]);
		}
		fprintf(out,"\n");
	}
	
	fclose(in);
	fclose(out);
	return 0;
}

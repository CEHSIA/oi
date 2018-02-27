type tree=^tnode;
	link=^lnode;
	tnode=record
		ischar:bool;
		dataw:integer;
		datac:char;
		left,right:node;
	end;
	lnode=record
		data:integer;
		next:link;
	end;
var i,j,k,n:longint;
	si,so:string;
function build-tree(s:string):tree;
	var p,head:link;
		sw:string;
		tmpc:char;
		i,j,n:integer;
		a:array[1..30,1..2]of integer;
	begin
		sw:=s;
		for i:=1 to length(sw)-1 do
			for j:= i+1 to length(sw) do
				if sw[i]>sw[j] then begin
					tmpc:=sw[i];
					sw[i]:=sw[j];
					sw[j]:=tmpc;
				end;
		j:=1;
		n:=0;
		for i:=1 to length(sw)-1 do
			if sw[i]=s[i+1] then
				n:=n+1
			else begin
				a[j,1]:=ord(sw[i]);
				a[j,2]:=n;
				j:=j+1;
				n:=0;
			end;
		for i:=1 to j-1 do
			for n:= i+1 to j do
				if a[i,2]>a[n,2] then begin
					a[j+1,1]:=a[i,1];
					a[j+1,2]:=a[i,2];
					a[i,1]:=a[n,1];
					a[i,2]:=a[n,2];
					a[n,1]:=a[j+1,1];
					a[n,2]:=a[j+1,2];
				end;
		
	end;

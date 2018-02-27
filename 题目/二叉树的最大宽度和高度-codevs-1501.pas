const
	MAX=16;
var
	tmp:array[1..MAX]of integer;
	tree:array[1..MAX,1..2] of integer;
	i,n,maxlays,maxwidth:integer;
procedure
	bintree(u,lays:integer);
		begin
			if tree[u,1]<>0 then begin
				tmp[lays]:=tmp[lays]+1;
				bintree(tree[u,1],lays+1);
			end;
			if tree[u,2]<>0 then begin
				tmp[lays]:=tmp[lays]+1;
				bintree(tree[u,2],lays+1);
			end;
			if lays>maxlays then maxlays:=lays;
		end;
begin
	readln(n);
	for i:=1 to n do
		readln(tree[i,1],tree[i,2]);
	bintree(1,2);
	tmp[1]:=1;
	for i:=1 to MAX do
		if tmp[i]>maxwidth then maxwidth:=tmp[i];
	writeln(maxwidth,' ',maxlays-1);
end.

const
	MAX=200000;
	BLACK=false;
	WHITE=true;
var
	a:array[1..MAX]of boolean;
	m,n,i,j,l,r,tmp:longint;
begin
	readln(n,m);
	tmp:=n;
	for i:=1 to m do begin
		readln(l,r);
		for j:=l to r do
			if a[j]=BLACK then begin
				a[j]:=WHITE;
				dec(tmp);
			end;
		writeln(tmp);
	end;
end.

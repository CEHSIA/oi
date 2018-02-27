var n,i,j,target,t,count:integer;
	a:array[1..100]of integer;
function all(n:integer):integer;
	var tmp,i:integer;
	begin
		tmp:=0;
		for i:=1 to n do
			tmp:=tmp+a[i];
		all:=tmp;
	end;
begin
	readln(n);
	for i:=1 to n do
		read(a[i]);
	target:=all(n) div n;
	count:=0;
	for i:=1 to n-1 do begin
		if a[i]<>target then begin
			a[i+1]:=a[i+1]+(a[i]-target);
			a[i]:=target;
			count:=count+1;
		end;
	end;
	writeln(count);
end.

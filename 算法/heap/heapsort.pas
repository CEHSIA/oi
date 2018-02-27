var
	a:array[1..100]of integer;
	i,j,l,r,n,c:integer;
procedure insheap(x:integer);
	var
		i:integer;
	begin
		r:=r+1;
		i:=r;
		while ((i shr 1)>l)or(a[i shr 1]<a[i]) do begin
			a[i]:=a[i shr 1];
			i:=i shr 1;
		end;
		a[i]:=x;
	end;
begin
	readln(n);
	l:=1;
	for i:=1 to n do begin
		read(j);
		insheap(j);
	end;
	write(a[1],' ');
	for l:=2 to r do begin
		for j:=l to r do insheap(a[j]);
		write(a[i],' ');
	end;
	writeln;
end.

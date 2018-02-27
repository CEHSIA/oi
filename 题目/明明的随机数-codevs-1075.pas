var a:array[0..100]of integer;
	i,j,n,k:integer;
procedure selectsort(n:integer);
	var i,j,k:integer;
	begin
		for i:=1 to n-1 do
			for j:=i+1 to n do 
				if a[j]<a[i] then begin
					k:=a[j];
					a[j]:=a[i];
					a[i]:=k;
				end;
	end;
function dosth(n:integer):integer;
	var i,j,k:integer;
	begin
		k:=0;
		i:=1;
		while i<=n-1 do begin
			j:=i+1;
			while a[i]=a[j] do begin
				a[j]:=-1;
				j:=j+1;
				k:=k+1;
			end;
			i:=j;
		end;
		dosth:=k;
	end;
begin
	readln(n);
	for i:=1 to n do
		read(a[i]);
	selectsort(n);
	writeln(n-dosth(n));
	for i:=1 to n do
		if a[i]<>-1 then write(a[i],' ');
end.

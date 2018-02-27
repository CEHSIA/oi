var a:array[1..40]of longint;
	i,n:integer;
begin
	readln(n);
	a[1]:=1;
	a[2]:=1;
	for i:=3 to n do begin
		a[i]:=a[i-1]+a[i-2];
		writeln(a[i]);
	end;
	writeln(a[n]);
end.

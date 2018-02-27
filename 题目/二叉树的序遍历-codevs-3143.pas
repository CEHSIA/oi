var a:array[1..16,1..2]of integer;
	n,i:integer;
procedure front(i:integer);
	begin
		if i=0 then exit;
		write(i,' ');
		front(a[i,1]);
		front(a[i,2]);
	end;
procedure behind(i:integer);
	begin
		if i=0 then exit;
		behind(a[i,1]);
		behind(a[i,2]);
		write(i,' ');
	end;
procedure middle(i:integer);
	begin
		if i=0 then exit;
		middle(a[i,1]);
		write(i,' ');
		middle(a[i,2]);
	end;
begin
	readln(n);
	for i:=1 to n do
		readln(a[i,1],a[i,2]);
	front(1);
	writeln;
	middle(1);
	writeln;
	behind(1);
end.

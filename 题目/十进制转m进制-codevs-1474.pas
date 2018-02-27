var n,m,i:integer;
	a:array[1..7]of integer;
begin
	readln(n,m);
	for i:=1 to 7 do 
		a[i]:=100;
	i:=1;
	while n<>0 do begin
		a[i]:=n mod m;
		n:=n div m;
		i:=i+1;
	end;
	for i:=7 downto 1 do
		if a[i]<>100 then
			case a[i] of
				15:write('F');
				14:write('E');
				13:write('D');
				12:write('C');
				11:write('B');
				10:write('A');
				else write(a[i]);
			end;
end.

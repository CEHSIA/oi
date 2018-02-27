var n:integer;
	t,i:longint;
procedure move(x:integer;a,b,c:char);
	begin
		if x=1 then
			writeln(x,' from ',a,' to ',c)
		else begin
			move(x-1,a,c,b);
			writeln(x,' from ',a,' to ',c);
			move(x-1,b,a,c);
		end;
	end;
begin
	readln(n);
	t:=1;
	for i:=1 to n do 
		t:=t*2;
	writeln(t-1);
	move(n,'A','B','C');
end.

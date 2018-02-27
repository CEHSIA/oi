var i,n:integer;
begin
	readln(n);
	for i:=2 to n-1 do
		if n mod i=0 then begin
			writeln('\n');
			halt;
		end;
	writeln('\t');
end.

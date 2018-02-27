var n,i:longint;
begin
	i:=1;
	readln(n);
	while n-i>0 do begin
		n:=n-i;
		i:=i+1;
	end;
	if i mod 2=0 then writeln(n,'/',i+1-n)
		else writeln(i+1-n,'/',n);
end.

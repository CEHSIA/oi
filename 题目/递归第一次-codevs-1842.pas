var x:longint;
function f(n:longint):longint;
	begin
		if n>=0 then f:=5;
		if n<0 then f:=f(n+1)+f(n+2)+1;
	end;
begin
	readln(x);
	writeln(f(x));
end.

var x,y:longint;
function gcd(a,b:longint):longint;
	var r:longint;
	begin
		if a<b then begin
			r:=a;
			a:=b;
			b:=r;
		end;
		repeat
			r:=a mod b;
			a:=b;
			b:=r;
		until r=0;
		gcd:=a;
	end;
begin
	readln(x,y);
	writeln(gcd(x,y));
end.

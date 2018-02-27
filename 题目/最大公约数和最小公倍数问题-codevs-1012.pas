const MAXM=100000;
var i,x,y,k,s:longint;
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
function lcm(a,b:longint):longint;
	begin
		lcm:=(a*b) div gcd(a,b);
	end;
{begin
	readln(x,y);
	s:=x*y;
	i:=x;
	while i<=sqrt(s) do begin
		if gcd(s div i,i)=x then
			if lcm(s div i,i)=y  then
				k:=k+1;
		i:=i+x;
	end;
	writeln(k*2);
end.}
begin
	readln(x,y);
	writeln(gcd(x,y),' ',lcm(x,y));
end.

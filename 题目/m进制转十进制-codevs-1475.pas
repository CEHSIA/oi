var m,n,i,x:integer;
	a:array[1..7]of integer;
	s,l:string;
	ans:longint;
function pow(x,y:integer):longint;
	var i:integer;
		a:longint;
	begin
		if y=0 then pow:=1
		else if y=1 then 
			pow:=x
		else begin
			a:=x;
			for i:=2 to y do
				a:=a*x;
			pow:=a;
		end;
	end;
begin
	readln(s);
	i:=1;
	while s[i]<>' ' do
		i:=i+1;
	val(copy(s,i+1,length(s)),n,x);
	s:=copy(s,1,i-1);
	for i:=1 to length(s) do begin
		case s[i] of
			'A':a[i]:=10;
			'B':a[i]:=11;
			'C':a[i]:=12;
			'D':a[i]:=13;
			'E':a[i]:=14;
			'F':a[i]:=15;
			else val(s[i],a[i],x);
		end;
	end;
	for i:=length(s) downto 1 do
		ans:=ans+pow(n,length(s)-i)*a[i];
	writeln(ans);
end.

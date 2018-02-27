var
	upperlim,sum,n:longint;
procedure t(row,ld,rd:longint);
	var
		pos,p:longint;
	begin
		if row<>upperlim then begin
			pos:=upperlim and not(row or ld or rd);
			while pos<>0 do begin
				p:=pos and -pos;
				pos:=pos-p;
				t(row+p,(ld+p)shl 1,(rd+p)shr 1);
			end;
		end else inc(sum);
	end;
begin
	readln(n);
	upperlim:=(1 shl n)-1;
	t(0,0,0);
	writeln(sum);
end.

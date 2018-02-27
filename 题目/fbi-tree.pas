var
	n,lim,lim2,i:qword;
	a:array[1..10000]of qword;
	s:ansistring;
procedure dvd(data,pos,k:qword);
	begin
		if k=0 then exit;
		a[pos]:=data shr (k shr 1);
		dvd(a[pos],pos shl 1,k shr 1);
		a[pos+1]:=data-(a[pos] shl (k shr 1));
		dvd(a[pos+1],(pos+1) shl 1,k shr 1);
	end;
function fbi(pos:qword):qword;
	var
		m,n:qword;
	begin
		if pos>=lim then exit(a[pos]);
		m:=fbi(pos shl 1);
		n:=fbi((pos shl 1)+1);
		if (m=2)or(n=2)or(m xor n=1) then begin
			a[pos]:=2;
			exit(2);
		end else begin
			a[pos]:=m;
			exit(m);
		end;
	end;
procedure printb(pos:qword);
	begin
		if pos>=lim2 then exit;
		printb(pos shl 1);
		printb((pos shl 1)+1);
		case a[pos] of
			0:write('B');
			1:write('I');
			2:write('F');
		end;
	end;
function b(s:ansistring):qword;
	var
		ans,i:qword;
	begin
		ans:=0;
		for i:=1 to lim do begin
			ans:=ans shl 1;
			if s[i]='1' then inc(ans);
		end;
		exit(ans);
	end;
begin
	readln(n);
	readln(s);
	lim:=1 shl n;
	lim2:=(1 shl (n+1));
	a[1]:=b(s);
	dvd(a[1],2,lim);
	fbi(1);
	printb(1);
end.

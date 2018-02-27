var a:array[0..100,0..100]of longint;
	i,j,n,ans,k,edge:longint;
begin
	readln(n);
	i:=(n div 2)+1;
	j:=i;
	edge:=2;
	k:=0;
	ans:=n*n;
	
	a[i,j]:=1;
	k:=1;
	i:=i+1;
	
	while k<>ans do begin
		if edge=1 then begin
			while (k<>ans)and(a[i,j-1]<>0) do begin
				k:=k+1;
				a[i,j]:=k;
				i:=i+1;
			end;
			edge:=2;
		end else if edge=2 then begin
			while (k<>ans)and(a[i-1,j]<>0) do begin
				k:=k+1;
				a[i,j]:=k;
				j:=j-1;
			end;
			edge:=3;
		end else if edge=3 then begin
			while (k<>ans)and(a[i,j+1]<>0) do begin
				k:=k+1;
				a[i,j]:=k;
				i:=i-1;
			end;
			edge:=4;
		end else if edge=4 then begin
			while (k<>ans)and(a[i+1,j]<>0) do begin
				k:=k+1;
				a[i,j]:=k;
				j:=j+1;
			end;
			edge:=1;
		end;
	end;
	ans:=0;
	for j:=1 to n do begin
		for i:=1 to n do begin
			write(a[i,j],' ');
			if (i=j)or(i+j=n) then ans:=ans+a[i,j];
		end;
		writeln;
	end;
	writeln(ans);
end.

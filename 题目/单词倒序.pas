var s,m:string;
	i,j:longint;
begin
	readln(s);
	s:=' '+s+' ';
	for i:=length(s)-1 downto 0 do begin
		if s[i]=' ' then begin
			j:=i+1;
			while s[j]<>' ' do begin
				write(s[j]);
				j:=j+1;
			end;
			write(' ');
		end;
	end;
end.

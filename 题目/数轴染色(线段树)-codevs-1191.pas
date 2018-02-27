const
	MAX=200000;
type
	linetree=^node;
	node=record
		data:boolean;
		l,r:longint;
		left,right:linetree;
	end;
var
	sum,n,m,i,tmpl,tmpr:longint;
	head:linetree;
procedure createNode(var p:linetree;l,r:longint);
	begin
		if p<>nil then exit;
		new(p);
		p^.l:=l;
		p^.r:=r;
		p^.data:=false;
		p^.left:=nil;
		p^.right:=nil;
	end;
procedure s(var p:linetree);
	begin
		if p=nil then exit;
		if p^.data then begin
			inc(sum,p^.r-p^.l+1);
			exit;
		end;
		s(p^.left);
		s(p^.right);
	end;
procedure cover(var p:linetree;l,r:longint);
	var
		mid:longint;
	begin
		if p^.data then exit;
		if (p^.l=l)and(p^.r=r) then begin
			p^.data:=true;
			exit;
		end;
		mid:=(p^.l+p^.r) shr 1;
		if (l<=mid)and(r<=mid) then begin
			createNode(p^.left,p^.l,mid);
			cover(p^.left,l,r);
		end else if (l>=mid+1)and(r>=mid+1) then begin
			createNode(p^.right,mid+1,p^.r);
			cover(p^.right,l,r);
		end else begin
			createNode(p^.left,p^.l,mid);
			cover(p^.left,l,mid);
			createNode(p^.right,mid+1,p^.r);
			cover(p^.right,mid+1,r);
		end;
		if (p^.left=nil)or(p^.right=nil) then exit;
		if (p^.left^.data)and(p^.right^.data) then begin
			p^.data:=true;
			dispose(p^.left);
			dispose(p^.right);
		end;
	end;
begin
	readln(n,m);
	createNode(head,1,n);
	for i:=1 to m do begin
		readln(tmpl,tmpr);
		sum:=0
		cover(head,tmpl,tmpr);
		s(head);
		writeln(n-sum);
	end;
end.

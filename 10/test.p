program PL1A;
var n, temp,x;
procedure fact(n);
begin
      if n <= 1 then
	 temp:=1
      else
      begin
	 fact(n - 1);
	 temp := temp * n
      end
end;
begin
    n := 0

end.

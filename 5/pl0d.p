program PL0D;
var n, temp;
procedure fact;
var m;
begin
    m := 1;
    m ;= m-1;
    if n <= 1 then
        temp:=1
    else
    begin
        m:=n;
        n:=n-1;
        fact;
        temp:=temp*m
    end
end;
begin
    read(n);
    fact;
    write(temp);
end.

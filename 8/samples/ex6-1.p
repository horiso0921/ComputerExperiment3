program ex3;
var x,y,z;
function exp(y);
begin
   if y <= 0 then exp := 1
   else begin
      exp := x * exp(y-1)
   end
end;
begin
   x:=2; z:=7; y:=exp(z);
   write(y);
end.

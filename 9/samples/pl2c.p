program PL2C;
var n, sum,tmp;
function result(n);
begin
sum := sum + n;
result := sum;
end;
procedure result;
write(sum);
begin
   n := 10;
   sum := 0;
   while n > 0 do
   begin      
      tmp := result(n);
      n := n - 1
   end;
   result
end.

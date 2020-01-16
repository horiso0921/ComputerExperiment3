program PL2B;
var m, n, a[1];
function power(m,n);
if n <= 0 then
   power := 1
else
   power := power(m,n - 1) * m;
begin
   read(m);
   read(n);
   write(power(m,n))
end.

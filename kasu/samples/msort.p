program MSORT;
var n, a[1..100], b[1..100]; 
procedure init(n);
var i;
begin
   for i := 1 to n do
   begin
      read(a[i]);
      b[i] := a[i];
   end
end;
procedure output(n);
var i;
begin
   for i := 1 to n do
      write(a[i])
end;
procedure merge(p, n);
var i, j, k, mid;
begin
   mid := n div 2;
   i := p;
   j := p + mid;
   for k := p to p + n - 1 do
   begin
      if j = p + n then
      begin
         b[k] := a[i];
         i := i + 1
      end
      else
         if i < p + mid then
         begin
            if a[i] <= a[j] then
            begin
               b[k] := a[i];
               i := i + 1;
            end
            else
            begin
               b[k] := a[j];
               j := j + 1;
            end
         end
         else
         begin
            b[k] := a[j];
            j := j + 1;
         end;
   end;
   for k := p to p + n - 1 do
         a[k] := b[k]
end;
procedure msort(p, n);
var mid;
begin
   if n > 1 then
   begin
      mid := n div 2;
      msort(p, mid);
      msort(p + mid, n - mid);
      merge(p, n);
   end;
end;
begin
   read(n);
   if n <= 100 then
   begin
      init(n);
      msort(1, n);
      output(n);
   end
end.
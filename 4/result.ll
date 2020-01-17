@n = common global i32 0, align 4
@x = common global i32 0, align 4

define void @prime() {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @x, align 4
  %3 = sdiv i32 %2, 2
  store i32 %3, i32* %1, align 4
  %4 = load i32, i32* @x, align 4
  %5 = load i32, i32* @x, align 4
  %6 = load i32, i32* %1, align 4
  %7 = sdiv i32 %5, %6
  %8 = load i32, i32* %1, align 4
  %9 = mul nsw i32 %7, %8
  %10 = load i32, i32* %1, align 4
  %11 = sub nsw i32 %10, 1
  store i32 %11, i32* %1, align 4
  %12 = load i32, i32* %1, align 4
  %13 = load i32, i32* @x, align 4
  ret void
}

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = load i32, i32* @n, align 4
  %3 = load i32, i32* @n, align 4
  store i32 %3, i32* @x, align 4
  %4 = load i32, i32* @n, align 4
  %5 = sub nsw i32 %4, 1
  store i32 %5, i32* @n, align 4
  ret i32 0
}

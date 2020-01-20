@x = common global i32 0, align 4
@y = common global i32 0, align 4
@z = common global i32 0, align 4

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 12, i32* @x, align 4
  store i32 20, i32* @y, align 4
  %2 = load i32, i32* @x, align 4
  %3 = load i32, i32* @y, align 4
  %4 = add nsw i32 %2, %3
  store i32 %4, i32* @z, align 4
  ret i32 0
}

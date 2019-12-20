@x = common global i32 0, align 4
@y = common global i32 0, align 4
@z = common global i32 0, align 4

define void @A() {
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  ret void
}

define void @B() {
  %1 = alloca i32, align 4
  store i32 2, i32* %1, align 4
  store i32 5, i32* @x, align 4
  ret void
}

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 3, i32* @z, align 4
  ret i32 0
}

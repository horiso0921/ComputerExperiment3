@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, ...)
declare i32 @printf(i8*, ...)
@x = common global i32 0, align 4

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 2, i32* @x, align 4
  store i32 32, i32* @x, align 4
  store i32 15, i32* @x, align 4
  ret i32 0
}

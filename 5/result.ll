@.str = private constant [3 x i8] c"%d\00", align 1
@.str.1 = private constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, ...)
declare i32 @printf(i8*, ...)
@Begin = common global i32 0, align 4

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = load i32, i32* @Begin, align 4
  %3 = load i32, i32* @Begin, align 4
  %4 = add nsw i32 %3, 1
  store i32 %4, i32* @Begin, align 4
  store i32 %2, i32* @Begin, align 4
  ret i32 0
}

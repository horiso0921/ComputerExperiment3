@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, ...)
declare i32 @printf(i8*, ...)
@n = common global i32 0, align 4
@temp = common global i32 0, align 4

define void @fact() {
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  %3 = sub nsw i32 0, %2
  store i32 %3, i32* %1, align 4
  %4 = load i32, i32* @n, align 4
  store i32 1, i32* @temp, align 4
  %5 = load i32, i32* @n, align 4
  store i32 %5, i32* %1, align 4
  %6 = load i32, i32* @n, align 4
  %7 = sub nsw i32 %6, 1
  store i32 %7, i32* @n, align 4
  call void @fact()
  %8 = load i32, i32* @temp, align 4
  %9 = load i32, i32* %1, align 4
  %10 = mul nsw i32 %8, %9
  store i32 %10, i32* @temp, align 4
  ret void
}

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* @n)
  call void @fact()
  %3 = load i32, i32* @temp, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %3)
  ret i32 0
}

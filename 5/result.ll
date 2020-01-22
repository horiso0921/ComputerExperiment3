@.str = constant [3 x i8] c"%d\00", align 1
@.str.1 = constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, i32*)
declare i32 @printf(i8*, i32)
@n = common global i32 0, align 4
@x = common global i32 0, align 4

define void @prime() {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @x, align 4
  %3 = sdiv i32 %2, 2
  store i32 %3, i32* %1, align 4
  br label %4

4:
  %5 = load i32, i32* @x, align 4
  %6 = load i32, i32* @x, align 4
  %7 = load i32, i32* %1, align 4
  %8 = sdiv i32 %6, %7
  %9 = load i32, i32* %1, align 4
  %10 = mul nsw i32 %8, %9
  %11 = icmp ne i32 %5, %10
  br i1 %11, label %12, label %15

12:
  %13 = load i32, i32* %1, align 4
  %14 = sub nsw i32 %13, 1
  store i32 %14, i32* %1, align 4
  br label %4

15:
  %16 = load i32, i32* %1, align 4
  %17 = icmp eq i32 %16, 1
  br i1 %17, label %18, label %21

18:
  %19 = load i32, i32* @x, align 4
  %20 = call i32 @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %19)
  br label %21

21:
  ret void
}

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* @n)
  br label %3

3:
  %4 = load i32, i32* @n, align 4
  %5 = icmp slt i32 1, %4
  br i1 %5, label %6, label %10

6:
  %7 = load i32, i32* @n, align 4
  store i32 %7, i32* @x, align 4
  call void @prime()
  %8 = load i32, i32* @n, align 4
  %9 = sub nsw i32 %8, 1
  store i32 %9, i32* @n, align 4
  br label %3

10:
  ret i32 0
}

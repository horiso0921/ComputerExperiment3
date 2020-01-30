@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, ...)
declare i32 @printf(i8*, ...)
@a = common global [10 x i32] zeroinitializer, align 16
@i = common global i32 0, align 4
@s = common global i32 0, align 4

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 1, i32* @i, align 4
  br label %2

2:
  %3 = load i32, i32* @i, align 4
  %4 = icmp sle i32 %3, 10
  br i1 %4, label %5, label %21

5:
  %6 = load i32, i32* @i, align 4
  %7 = sub nsw i32 %6, 1
  %8 = sext i32 %7 to i64
  %9 = getelementptr inbounds [10 x i32], [10 x i32]* @a, i64 0, i64 %8
  %10 = load i32, i32* @i, align 4
  %11 = sub nsw i32 %10, 1
  %12 = sext i32 %11 to i64
  %13 = getelementptr inbounds [10 x i32], [10 x i32]* @a, i64 0, i64 %12
  %14 = load i32, i32* %13, align 4
  %15 = sub nsw i32 %14, 1
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [10 x i32], [10 x i32]* @a, i64 0, i64 %16
  %18 = load i32, i32* %17, align 4
  store i32 %18, i32* %9, align 4
  %19 = load i32, i32* @i, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, i32* @i, align 4
  br label %2

21:
  store i32 1, i32* @i, align 4
  br label %22

22:
  %23 = load i32, i32* @i, align 4
  %24 = icmp sle i32 %23, 10
  br i1 %24, label %25, label %35

25:
  %26 = load i32, i32* @i, align 4
  %27 = sub nsw i32 %26, 1
  %28 = sext i32 %27 to i64
  %29 = getelementptr inbounds [10 x i32], [10 x i32]* @a, i64 0, i64 %28
  %30 = load i32, i32* %29, align 4
  %31 = load i32, i32* @s, align 4
  %32 = add nsw i32 %30, %31
  store i32 %32, i32* @s, align 4
  %33 = load i32, i32* @i, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* @i, align 4
  br label %22

35:
  ret i32 0
}

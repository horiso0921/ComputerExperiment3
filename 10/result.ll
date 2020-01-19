@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, ...)
declare i32 @printf(i8*, ...)
@a = common global [99 x i32] zeroinitializer, align 16
@i = common global i32 0, align 4
@j = common global i32 0, align 4
@k = common global i32 0, align 4
@l = common global i32 0, align 4

define i32 @main() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 10, i32* @i, align 4
  store i32 0, i32* @j, align 4
  store i32 0, i32* @k, align 4
  store i32 0, i32* @l, align 4
  %2 = sext i32 99 to i64
  %3 = getelementptr inbounds [99 x i32], [99 x i32]* @a, i64 0, i64 %2
  store i32 182345, i32* %3, align 4
  %4 = sext i32 0 to i64
  %5 = getelementptr inbounds [99 x i32], [99 x i32]* @a, i64 0, i64 %4
  store i32 19, i32* %5, align 4
  %6 = sext i32 0 to i64
  %7 = getelementptr inbounds [99 x i32], [99 x i32]* @a, i64 0, i64 %6
  %8 = load i32, i32* %7, align 4
  %9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %8)
  %10 = load i32, i32* @i, align 4
  %11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %10)
  %12 = load i32, i32* @j, align 4
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %12)
  %14 = load i32, i32* @k, align 4
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %14)
  %16 = load i32, i32* @l, align 4
  %17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %16)
  ret i32 0
}

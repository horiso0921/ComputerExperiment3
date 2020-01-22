@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @__isoc99_scanf(i8*, i32*)
declare i32 @printf(i8*, i32)
@n = common global i32 0, align 4
@x = common global i32 0, align 4

define void @prime(i32, ...){
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %5 = load i32 , i32* %2, align 4
  call i32 @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i64 0, i64 0), i32 %5)
  ret void
}

define i32 @main(){
    %1 = alloca i32, align 4
    store i32 10, i32* %1, align 4
    %2 = load i32, i32* %1, align 4
    call void (i32, ...) @prime(i32 %2, i32 %2)
    call void (i32, ...) @prime(i32 %2)
    ret i32 0
}
; ModuleID = 'test.c'
source_filename = "test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.__va_list_tag = type { i32, i32, i8*, i8* }

@.str = private unnamed_addr constant [5 x i8] c"ddcd\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"ss\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"abc\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c"def\00", align 1
@.str.4 = private unnamed_addr constant [4 x i8] c"dfc\00", align 1
@.str.5 = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.6 = private unnamed_addr constant [4 x i8] c"%f \00", align 1
@.str.7 = private unnamed_addr constant [4 x i8] c"%c \00", align 1
@.str.8 = private unnamed_addr constant [4 x i8] c"%s \00", align 1
@.str.9 = private unnamed_addr constant [25 x i8] c"!\22\E4\B8\8D\E6\AD\A3\E3\81\AA\E5\A4\89\E6\8F\9B\E6\8C\87\E5\AE\9A\22\00", align 1
@.str.10 = private unnamed_addr constant [7 x i8] c"test.c\00", align 1
@__PRETTY_FUNCTION__.print = private unnamed_addr constant [30 x i8] c"void print(const char *, ...)\00", align 1
@.str.11 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void (i8*, ...) @print(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 10, i32 20, i32 120, i32 30)
  call void (i8*, ...) @print(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i64 0, i64 0), i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i64 0, i64 0))
  call void (i8*, ...) @print(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i64 0, i64 0), i32 50, double 0x400A666660000000, i32 90)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @print(i8*, ...) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca [1 x %struct.__va_list_tag], align 16
  %4 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %5 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  %6 = bitcast %struct.__va_list_tag* %5 to i8*
  call void @llvm.va_start(i8* %6)
  %7 = load i8*, i8** %2, align 8
  store i8* %7, i8** %4, align 8
  br label %8

8:                                                ; preds = %98, %1
  %9 = load i8*, i8** %4, align 8
  %10 = load i8, i8* %9, align 1
  %11 = sext i8 %10 to i32
  %12 = icmp ne i32 %11, 0
  br i1 %12, label %13, label %101

13:                                               ; preds = %8
  %14 = load i8*, i8** %4, align 8
  %15 = load i8, i8* %14, align 1
  %16 = sext i8 %15 to i32
  switch i32 %16, label %96 [
    i32 100, label %17
    i32 102, label %37
    i32 99, label %57
    i32 115, label %76
  ]

17:                                               ; preds = %13
  %18 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  %19 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %18, i32 0, i32 0
  %20 = load i32, i32* %19, align 16
  %21 = icmp ule i32 %20, 40
  br i1 %21, label %22, label %28

22:                                               ; preds = %17
  %23 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %18, i32 0, i32 3
  %24 = load i8*, i8** %23, align 16
  %25 = getelementptr i8, i8* %24, i32 %20
  %26 = bitcast i8* %25 to i32*
  %27 = add i32 %20, 8
  store i32 %27, i32* %19, align 16
  br label %33

28:                                               ; preds = %17
  %29 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %18, i32 0, i32 2
  %30 = load i8*, i8** %29, align 8
  %31 = bitcast i8* %30 to i32*
  %32 = getelementptr i8, i8* %30, i32 8
  store i8* %32, i8** %29, align 8
  br label %33

33:                                               ; preds = %28, %22
  %34 = phi i32* [ %26, %22 ], [ %31, %28 ]
  %35 = load i32, i32* %34, align 4
  %36 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.5, i64 0, i64 0), i32 %35)
  br label %97

37:                                               ; preds = %13
  %38 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  %39 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %38, i32 0, i32 1
  %40 = load i32, i32* %39, align 4
  %41 = icmp ule i32 %40, 160
  br i1 %41, label %42, label %48

42:                                               ; preds = %37
  %43 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %38, i32 0, i32 3
  %44 = load i8*, i8** %43, align 16
  %45 = getelementptr i8, i8* %44, i32 %40
  %46 = bitcast i8* %45 to double*
  %47 = add i32 %40, 16
  store i32 %47, i32* %39, align 4
  br label %53

48:                                               ; preds = %37
  %49 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %38, i32 0, i32 2
  %50 = load i8*, i8** %49, align 8
  %51 = bitcast i8* %50 to double*
  %52 = getelementptr i8, i8* %50, i32 8
  store i8* %52, i8** %49, align 8
  br label %53

53:                                               ; preds = %48, %42
  %54 = phi double* [ %46, %42 ], [ %51, %48 ]
  %55 = load double, double* %54, align 8
  %56 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.6, i64 0, i64 0), double %55)
  br label %97

57:                                               ; preds = %13
  %58 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  %59 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %58, i32 0, i32 0
  %60 = load i32, i32* %59, align 16
  %61 = icmp ule i32 %60, 40
  br i1 %61, label %62, label %67

62:                                               ; preds = %57
  %63 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %58, i32 0, i32 3
  %64 = load i8*, i8** %63, align 16
  %65 = getelementptr i8, i8* %64, i32 %60
  %66 = add i32 %60, 8
  store i32 %66, i32* %59, align 16
  br label %71

67:                                               ; preds = %57
  %68 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %58, i32 0, i32 2
  %69 = load i8*, i8** %68, align 8
  %70 = getelementptr i8, i8* %69, i32 8
  store i8* %70, i8** %68, align 8
  br label %71

71:                                               ; preds = %67, %62
  %72 = phi i8* [ %65, %62 ], [ %69, %67 ]
  %73 = load i8, i8* %72, align 1
  %74 = sext i8 %73 to i32
  %75 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.7, i64 0, i64 0), i32 %74)
  br label %97

76:                                               ; preds = %13
  %77 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  %78 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %77, i32 0, i32 0
  %79 = load i32, i32* %78, align 16
  %80 = icmp ule i32 %79, 40
  br i1 %80, label %81, label %87

81:                                               ; preds = %76
  %82 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %77, i32 0, i32 3
  %83 = load i8*, i8** %82, align 16
  %84 = getelementptr i8, i8* %83, i32 %79
  %85 = bitcast i8* %84 to i8**
  %86 = add i32 %79, 8
  store i32 %86, i32* %78, align 16
  br label %92

87:                                               ; preds = %76
  %88 = getelementptr inbounds %struct.__va_list_tag, %struct.__va_list_tag* %77, i32 0, i32 2
  %89 = load i8*, i8** %88, align 8
  %90 = bitcast i8* %89 to i8**
  %91 = getelementptr i8, i8* %89, i32 8
  store i8* %91, i8** %88, align 8
  br label %92

92:                                               ; preds = %87, %81
  %93 = phi i8** [ %85, %81 ], [ %90, %87 ]
  %94 = load i8*, i8** %93, align 8
  %95 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.8, i64 0, i64 0), i8* %94)
  br label %97

96:                                               ; preds = %13
  call void @__assert_fail(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str.9, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.10, i64 0, i64 0), i32 49, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.print, i64 0, i64 0)) #4
  unreachable

97:                                               ; preds = %92, %71, %53, %33
  br label %98

98:                                               ; preds = %97
  %99 = load i8*, i8** %4, align 8
  %100 = getelementptr inbounds i8, i8* %99, i32 1
  store i8* %100, i8** %4, align 8
  br label %8

101:                                              ; preds = %8
  %102 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.11, i64 0, i64 0))
  %103 = getelementptr inbounds [1 x %struct.__va_list_tag], [1 x %struct.__va_list_tag]* %3, i64 0, i64 0
  %104 = bitcast %struct.__va_list_tag* %103 to i8*
  call void @llvm.va_end(i8* %104)
  ret void
}

; Function Attrs: nounwind
declare void @llvm.va_start(i8*) #1

declare dso_local i32 @printf(i8*, ...) #2

; Function Attrs: noreturn nounwind
declare dso_local void @__assert_fail(i8*, i8*, i32, i8*) #3

; Function Attrs: nounwind
declare void @llvm.va_end(i8*) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.0 (Red Hat 9.0.0-1.el7)"}

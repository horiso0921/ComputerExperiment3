#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void print(const char* format, ...);

int main(void)
{
    print( "ddcd", 10, 20, 'x', 30 );
    print( "ss", "abc", "def" );
    print( "dfc", 50, 3.3f, 'Z' );

    return 0;
}

/*
    標準出力へ任意の個数・型の値を出力する
    引数：
        format: 出力フォーマットを表す文字を並べたもの。
                d … 符号付き整数型
                f … 浮動小数点型
                c … 文字型
                s … 文字列型
            とする。
            たとえば、"dds" と指定すると、
            後続の実引数が 整数型, 整数型, 文字列型 の順番で並んでいるものと判断される。
        ...:    出力する値のリスト
*/
void print(const char* format, ...)
{
    va_list args;
    va_start( args, format );

    for( const char* p = format; *p != '\0'; ++p ){
        switch( *p ){
        case 'd':
            printf( "%d ", va_arg(args, int) );
            break;
        case 'f':
            printf( "%f ", va_arg(args, double) );
            break;
        case 'c':
            printf( "%c ", va_arg(args, char) );
            break;
        case 's':
            printf( "%s ", va_arg(args, const char*) );
            break;
        default:
            assert( !"不正な変換指定" );
            break;
        }
    }
    printf( "\n" );

    va_end( args );
}
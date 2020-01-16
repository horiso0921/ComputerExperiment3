/*
 * symbols.h
 *
 * 注意: このファイルは課題1 でのみ使用する
 */

enum {
    SBEGIN = 1,                  /* begin */
    DIV,
    DO,
    ELSE,
    SEND,                       /* end */
    FOR,
    FORWARD,
    FUNCTION,
    IF,
    PROCEDURE,
    READ,
    PROGRAM,
    THEN,
    TO,
    VAR,
    WHILE,
    WRITE,

    PLUS,
    MINUS,
    MULT,
    EQ,                         /* = */
    NEQ,                        /* <> */
    LE,                         /* <= */
    LT,                         /* < */
    GE,                         /* >= */
    GT,                         /* > */
    LPAREN,                     /* ( */
    RPAREN,                     /* ) */
    LBRACKET,                     /* [ */
    RBRACKET,                     /* ] */
    COMMA,
    SEMICOLON,
    COLON,
    INTERVAL,                   /* .. */
    PERIOD,
    ASSIGN,                     /* := */
    NUMBER,
    IDENT,
};

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXLINE 1000

int sp = 0;
double val[MAXVAL];
char line[MAXLINE];
int line_idx = 0; // 行内の現在の読み込み位置

void push(double f) { if (sp < MAXVAL) val[sp++] = f; else printf("error: stack full\n"); }
double pop(void) { if (sp > 0) return val[--sp]; printf("error: stack empty\n"); return 0.0; }

// 1行読み込むカスタムgetline
int my_getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

// 行バッファから次のトークンを取り出す
int getop(char s[]) {
    int i, c;

    if (line[line_idx] == '\0') {
        if (my_getline(line, MAXLINE) == 0) return EOF;
        line_idx = 0;
    }

    while ((s[0] = c = line[line_idx++]) == ' ' || c == '\t');
    s[1] = '\0';

    if (!isdigit(c) && c != '.') return c;

    i = 0;
    if (isdigit(c)) while (isdigit(s[++i] = c = line[line_idx++]));
    if (c == '.') while (isdigit(s[++i] = c = line[line_idx++]));
    s[i] = '\0';
    line_idx--; // 1文字進みすぎた分を戻す
    return NUMBER;
}

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER: push(atof(s)); break;
        case '+': push(pop() + pop()); break;
        case '*': push(pop() * pop()); break;
        case '-': op2 = pop(); push(pop() - op2); break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop() / op2);
            else printf("error: zero divisor\n");
            break;
        case '\n': printf("\t%.8g\n", pop()); break;
        default: printf("error: unknown command %s\n", s); break;
        }
    }
    return 0;
}

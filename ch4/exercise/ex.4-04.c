#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) { if (bufp >= BUFSIZE) printf("ungetch: too many chars\n"); else buf[bufp++] = c; }

void push(double f) { if (sp < MAXVAL) val[sp++] = f; else printf("error: stack full\n"); }
double pop(void) { if (sp > 0) return val[--sp]; printf("error: stack empty\n"); return 0.0; }

// スタック先頭を見る (popせずに表示)
void show_top(void) {
    if (sp > 0) printf("top element: %g\n", val[sp - 1]);
    else printf("error: stack empty\n");
}

// 先頭要素を複製
void duplicate(void) {
    if (sp > 0) push(val[sp - 1]);
    else printf("error: stack empty\n");
}

// 先頭2つの要素を入れ替える
void swap(void) {
    if (sp > 1) {
        double op1 = pop();
        double op2 = pop();
        push(op1);
        push(op2);
    } else printf("error: not enough elements\n");
}

// スタックをクリアする
void clear_stack(void) { sp = 0; }

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') return c;
    i = 0;
    if (isdigit(c)) while (isdigit(s[++i] = c = getch()));
    if (c == '.') while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}

int main(void) {
    int type;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER: push(atof(s)); break;
        case '+': push(pop() + pop()); break;
        case '?': show_top(); break;      // '?' で先頭確認
        case 'd': duplicate(); break;     // 'd' で複製
        case 's': swap(); break;          // 's' で入れ替え
        case 'c': clear_stack(); break;   // 'c' でクリア
        case '\n': printf("\t%.8g\n", pop()); break;
        default: printf("error: unknown command %s\n", s); break;
        }
    }
    return 0;
}

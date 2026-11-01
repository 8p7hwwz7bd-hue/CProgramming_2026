#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n' // 数学関数の識別子
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

void math_func(char s[]) {
    double op2;
    if (strcmp(s, "sin") == 0) push(sin(pop()));
    else if (strcmp(s, "exp") == 0) push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else printf("error: %s not supported\n", s);
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    
    if (isalpha(c)) { // 英字の場合は関数名として読み込む
        i = 0;
        while (isalpha(s[i++] = c)) c = getch();
        s[i - 1] = '\0';
        if (c != EOF) ungetch(c);
        return NAME;
    }
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
        case NAME: math_func(s); break;
        case '\n': printf("\t%.8g\n", pop()); break;
        default: printf("error: unknown command %s\n", s); break;
        }
    }
    return 0;
}

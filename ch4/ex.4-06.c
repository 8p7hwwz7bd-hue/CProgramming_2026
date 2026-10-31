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
double vars[26]; // a ~ z の変数を格納
double last_val = 0.0; // 直前に表示された値

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) { if (bufp >= BUFSIZE) printf("ungetch: too many chars\n"); else buf[bufp++] = c; }

void push(double f) { if (sp < MAXVAL) val[sp++] = f; else printf("error: stack full\n"); }
double pop(void) { if (sp > 0) return val[--sp]; printf("error: stack empty\n"); return 0.0; }

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
    int type, var = 0;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER: push(atof(s)); break;
        case '+': push(pop() + pop()); break;
        case '=': // 代入 (例: 10 a =)
            pop();
            if (var >= 'a' && var <= 'z') vars[var - 'a'] = pop();
            break;
        case 'v': push(last_val); break; // 直前の値
        case '\n':
            last_val = pop();
            printf("\t%.8g\n", last_val);
            break;
        default:
            if (type >= 'a' && type <= 'z') {
                push(vars[type - 'a']);
                var = type;
            } else printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

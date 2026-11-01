#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* ソートする最大行数 */
char *lineptr[MAXLINES];    /* 文字列へのポインタの配列 */

#define MAXSTOR 50000       /* linestor の最大容量 */
char linestor[MAXSTOR];     /* main側で保持するストレージ */

int readlines_ex7(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int get_line(char *s, int lim);

int main(void)
{
    int nlines;

    // main側で用意した linestor を引数として渡す
    if ((nlines = readlines_ex7(lineptr, linestor, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int get_line(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Exercise 5-7: alloc を使わず、引数で受け取った linestor に直接格納する実装 */
int readlines_ex7(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *lim = linestor + MAXSTOR;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p + len) > lim)
            return -1;
        else {
            line[len - 1] = '\0'; /* 改行文字を削除 */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;             /* 次の格納位置へポインタを進める */
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
#include <stdio.h>
#include <stdlib.h> // atof (文字列を数値に変換する関数) を使うため
#include <ctype.h>  //isdigit などを使うため

#define MAXVAL 100  // スタックの最大深度

int sp = 0;         // 次のスタック位置
double val[MAXVAL]; // 値のスタック

// スタック操作用のプロトタイプ宣言
void push(double f);
double pop(void);

/* 
 * expr: コマンドライン引数から逆ポーランド記法を評価するプログラム
 * 例: expr 2 3 4 + *  -> 結果は 14
 */
int main(int argc, char *argv[])
{
    int i;
    double op2;

    printf("=== Exercise 5-10: Polish Calculator (expr) ===\n");

    // 引数が足りない場合のチェック
    if (argc < 2) {
        printf("Usage: expr <RPN expression>\n");
        return 1;
    }

    // 各コマンドライン引数を順番に処理する
    for (i = 1; i < argc; i++) {
        // 引数が数値（あるいはマイナスから始まる数値）の場合
        // 簡単のため、ここでは最初の文字が数字かどうかで判定する
        if (isdigit(argv[i][0]) || (argv[i][0] == '-' && isdigit(argv[i][1]))) {
            push(atof(argv[i]));
        } 
        else {
            // 演算子の場合に応じた計算を行う
            switch (argv[i][0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                default:
                    printf("error: unknown command %s\n", argv[i]);
                    break;
            }
        }
    }

    // 最終的な計算結果を出力する
    printf("Result = %.8g\n", pop());

    return 0;
}

/* push: f を値スタックにプッシュする */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: スタックからトップの値をポップして返す */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

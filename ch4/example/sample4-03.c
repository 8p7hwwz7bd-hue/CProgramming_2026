#include <stdio.h>
#include <stdlib.h> // atof() 用

#define MAXVAL  100   // スタックの深さの最大値
int sp = 0;           // 次に使うスタックのインデックス（外部変数）
double val[MAXVAL];   // 値を保持するスタック（外部変数）

// スタックに値を積む関数 (push)
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// スタックから値を取り出す関数 (pop)
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int main(void)
{
    /*
     * -----------------------------------------------------------------
     * 【4.3 外部変数 (External Variables) の特徴】
     * -----------------------------------------------------------------
     * ・関数の外側で定義されるため、どの関数からも名前で直接アクセスできます。
     * ・ローカル変数と違って関数が終了しても消えず、値が永続的に保持されます。
     * ・関数同士で大量のデータをやり取りするとき、引数のリストを長くせずに
     *   効率よくデータを共有できるメリットがあります。
     */
    
    printf("=== Postfix (RPN) Calculator Concept ===\n");
    printf("Example: \"1 2 - 4 5 + *\" means (1 - 2) * (4 + 5)\n\n");

    // 動作イメージのテスト（手動でpush/popをシミュレーション）
    printf("Pushing 4.0 and 5.0 to stack...\n");
    push(4.0);
    push(5.0);

    printf("Simulating '+' operator (pop two, add, push result)...\n");
    double op2 = pop(); // 5.0を取り出す
    double op1 = pop(); // 4.0を取り出す
    push(op1 + op2);    // 足し算結果の 9.0 を積む

    printf("Current stack top value (Result): %g\n", pop());

    return 0;
}

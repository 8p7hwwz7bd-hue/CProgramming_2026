#include <stdio.h>

int main(void)
{
    /*
     * -----------------------------------------------------------------
     * 【1. 基本的な If-Else 構文】
     * -----------------------------------------------------------------
     * ・条件式 (expression) が真（非ゼロ）なら statement-1 が実行され、
     *   偽（ゼロ）なら、あれば else の中の statement-2 が実行されます。
     * ・else 部分は省略可能です[cite: 22]。
     */
    int score = 85;

    printf("=== 1. Basic If-Else Test ===\n");
    if (score >= 80) {
        printf("Great! Pass (合格)\n");
    } else {
        printf("Try again (不合格)\n");
    }


    /*
     * -----------------------------------------------------------------
     * 【2. 懸垂else（ダングリングelse）問題の注意点】
     * -----------------------------------------------------------------
     * ・ネスト（入れ子）された if 文で else を省略・または中括弧を付け忘れると、
     *   「どの if にこの else が対応しているのか」という曖昧さ（Ambiguity）が生じます[cite: 22]。
     * ・ルールとして、**「else は、最も近くにある内側の if」**に結びつきます[cite: 22]。
     */
    int n = 5;
    int a = 10;
    int b = 20;
    int z = 0;

    // 【意図した挙動にするための正しい中括弧 `{}` の使い方】
    // スライド右側の例：n > 0 の外側の if に else を対応させたい場合
    if (n > 0) {
        if (a > b) {
            z = a;
        }
    } 
    else { // ← この else は最初の 「if (n > 0)」に対応する
        z = b;
        printf("n is not positive, z set to b (%d)\n", z);
    }


    /*
     * -----------------------------------------------------------------
     * 【3. Else-If による多岐分岐 (3.3 Else-if)】
     * -----------------------------------------------------------------
     * ・3つ以上の選択肢（multi-way decision）があるときは、
     *   if - else if - else を繋げてスッキリ書くことができます。
     */
    printf("\n=== 3. Multi-way Decision (Else-if) ===\n");
    int point = 75;

    if (point >= 90) {
        printf("Grade: A\n");
    } else if (point >= 70) {
        printf("Grade: B\n"); // ここが実行される
    } else if (point >= 50) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}

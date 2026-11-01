#include <stdio.h>
#include <string.h>

// プロトタイプ宣言
int trim(char s[]);

int main(void)
{
    /*
     * -----------------------------------------------------------------
     * 【1. Break と Continue の基本】
     * -----------------------------------------------------------------
     * ・break    : 最も内側のループや switch から強制的に抜け出す。
     * ・continue : その回のループの残りの処理をスキップし、次のループの判定へ進む。
     */
    printf("=== 1. Continue Test (Skip negative values) ===\n");
    int numbers[] = {3, -1, 5, -2, 8};
    for (int i = 0; i < 5; i++) {
        // 負の数だった場合は処理をスキップして次のループへ
        if (numbers[i] < 0) {
            continue; 
        }
        printf("Positive number: %d\n", numbers[i]);
    }


    /*
     * -----------------------------------------------------------------
     * 【2. trim 関数のテスト（スライド掲載の break 活用例）】
     * -----------------------------------------------------------------
     * ・文字列の末尾にある余分な空白、タブ、改行を取り除く関数
     */
    printf("\n=== 2. Trim Function Test ===\n");
    char text[100] = "Hello World! \t\n   ";
    
    printf("Before trim: [%s] (with trailing spaces/newlines)\n", text);
    trim(text);
    printf("After trim:  [%s]\n", text);


    /*
     * -----------------------------------------------------------------
     * 【3. Goto と Labels の使い方】
     * -----------------------------------------------------------------
     * ・何重にもネストされた深いループから「一気に外へ飛び出したい」ときなどに使います。
     * ・break は1つのループしか抜けられませんが、goto ならラベルを指定してワープできます。
     */
    printf("\n=== 3. Goto Test (Breaking out of nested loops) ===\n");
    int found = 0;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            printf("Checking x=%d, y=%d\n", x, y);
            // 例として、x=1, y=1 の場所で見つかったとする
            if (x == 1 && y == 1) {
                found = 1;
                goto search_end; // 一気にループの外へジャンプ！
            }
        }
    }

search_end: // ← ここがジャンプ先のラベル
    if (found) {
        printf("Successfully broke out of nested loops using goto!\n");
    }

    return 0;
}

/* 
 * trim: 文字列 s の末尾の空白、タブ、改行を削除する関数（スライド掲載）
 */
int trim(char s[])
{
    int n;

    // 文字列の最後尾から前へ向かって文字をチェックしていく
    for (n = strlen(s) - 1; n >= 0; n--) {
        // 空白でもタブでも改行でもない文字が見つかったらそこでループを抜ける
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }
    }
    s[n + 1] = '\0'; // 意味のある文字の直後を新しい終端文字にする
    return n;
}

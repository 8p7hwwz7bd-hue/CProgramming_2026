#include <stdio.h>

int any(const char s1[], const char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i; // 最初に見つかったインデックス
            }
        }
    }
    return -1; // 見つからない場合
}

int main(void) {
    char s1[] = "programming";
    char s2[] = "ram";
    char s3[] = "xyz";

    printf("Position in s1 matching s2: %d\n", any(s1, s2)); // 1 ('r')
    printf("Position in s1 matching s3: %d\n", any(s1, s3)); // -1
    return 0;
}

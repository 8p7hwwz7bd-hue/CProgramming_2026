#include <stdio.h>
#include <ctype.h>

int htoi(const char s[]) {
    int i = 0;
    int n = 0;

    // プレフィックス 0x または 0X のスキップ
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    for (; s[i] != '\0'; ++i) {
        int hex_val;
        if (isdigit(s[i])) {
            hex_val = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hex_val = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hex_val = s[i] - 'A' + 10;
        } else {
            break; // 16進数以外の文字に遭遇した場合は終了
        }
        n = 16 * n + hex_val;
    }
    return n;
}

int main(void) {
    printf("htoi('84ada') = %d\n", htoi("84ada"));
    printf("htoi('f') = %d\n", htoi("f"));
    printf("htoi('F0') = %d\n", htoi("F0"));
    printf("htoi('12fab') = %d\n", htoi("12fab"));
    printf("htoi('0x12fab') = %d\n", htoi("0x12fab"));
    return 0;
}

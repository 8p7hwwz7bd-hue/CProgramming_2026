#include <stdio.h>

// 改行やタブを "\n", "\t" という文字列に変身させる
void escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}

// "\n", "\t" を本物の改行・タブに戻す
void unescape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\') {
            switch (t[i + 1]) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                    break;
                case 't':
                    s[j++] = '\t';
                    i++;
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

int main() {
    char text[] = "Hello\tworld\nThis is a test.";
    char escaped[100];
    char unescaped[100];

    escape(escaped, text);
    printf("Escaped string: %s\n", escaped);

    unescape(unescaped, escaped);
    printf("Unescaped string:\n%s\n", unescaped);

    return 0;
}

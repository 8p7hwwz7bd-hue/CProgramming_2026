#include <stdio.h>

// 2次元配列による月ごとの日数（平年とうるう年）
static char day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// プロトタイプ宣言
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int yearday, month, day;

    printf("=== Exercise 5-8: Error Checking in Date Functions ===\n\n");

    // 1. 正しい日付のテスト (1988年はうるう年)
    yearday = day_of_year(1988, 2, 29);
    printf("1988.2.29 -> day of year = %d (Expected: 60)\n", yearday);

    // 2. 存在しない日付のテスト (2月31日はエラーになるべき)
    yearday = day_of_year(2020, 2, 31);
    printf("2020.2.31 -> day of year = %d (Expected: -1 as error)\n", yearday);

    // 3. 正しい通算日のテスト (1988年の60日目)
    month_day(1988, 60, &month, &day);
    printf("1988, 60th day -> Month: %d, Day: %d (Expected: 2, 29)\n", month, day);

    // 4. 範囲外の通算日のテスト (範囲を超える366日目など)
    month_day(1999, 366, &month, &day);
    printf("1999, 366th day -> Month: %d, Day: %d (Expected: -1 as error)\n\n", month, day);

    return 0;
}

/* day_of_year: 年、月、日からその年の何日目かを計算する（エラーチェック付き） */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    // 年の妥当性チェック（例として 1年未満はエラー）
    if (year < 1)
        return -1;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    // 月と日の範囲チェック
    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > day_tab[leap][month])
        return -1;

    for (i = 1; i < month; i++) {
        day += day_tab[leap][i];
    }
    return day;
}

/* month_day: 年とその年の何日目かから、何月何日かを計算する（エラーチェック付き） */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    // 年の妥当性チェック
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    // 通算日の範囲チェック（平年は365日、うるう年は366日まで）
    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > day_tab[leap][i]; i++) {
        yearday -= day_tab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;
}

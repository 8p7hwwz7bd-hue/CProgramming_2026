#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS 1500
#define MAX_NAME_LEN 100

// 条件付きコンパイル用のマクロ（どちらか一方を有効にしてコンパイルします）
// 例: gcc -DQUICK_SORT student_grade.c -o student_grade
//     gcc -DQSORT_LIB student_grade.c -o student_grade
#if !defined(QUICK_SORT) && !defined(QSORT_LIB)
#define QUICK_SORT // デフォルトはクイックソート
#endif

// 学生情報の構造体
typedef struct {
  char reg_no[20];
  char name[MAX_NAME_LEN];
  int kor, eng, math;
  int total;
  float average;
  char grade;
} Student;

// グレード（評価）を計算する関数
char calculate_grade(float avg) {
  if (avg >= 90)
    return 'A';
  else if (avg >= 80)
    return 'B';
  else if (avg >= 70)
    return 'C';
  else if (avg >= 60)
    return 'D';
  else
    return 'F';
}

// 1. 自作のクイックソート（ポインタ操作を使用）
void swap(Student *a, Student *b) {
  Student temp = *a;
  *a = *b;
  *b = temp;
}

int compare_students_desc(const Student *a, const Student *b) {
  // 合計点の高い順（降順）にソート
  return b->total - a->total;
}

// クイックソートの実装
void quick_sort(Student arr[], int low, int high) {
  if (low < high) {
    Student pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
      if (arr[j].total > pivot.total) { // 降順
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i + 1], &arr[high]);
    int pi = i + 1;

    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

// 標準ライブラリの qsort 用の比較関数
int qlib_compare(const void *a, const void *b) {
  Student *s1 = (Student *)a;
  Student *s2 = (Student *)b;
  return s2->total - s1->total; // 降順
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf(
        "Usage: %s <input_file> <output_file> [search_query (optional)]\n",
        argv[0]);
    return 1;
  }

  char *input_filename = argv[1];
  char *output_filename = argv[2];
  char *search_query = (argc >= 4) ? argv[3] : NULL;

  FILE *input_file = fopen(input_filename, "r");
  if (input_file == NULL) {
    printf("Error opening input file: %s\n", input_filename);
    return 1;
  }

  Student *students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
  if (students == NULL) {
    printf("Memory allocation failed!\n");
    fclose(input_file);
    return 1;
  }

  int count = 0;
  // ファイルからのデータ読み込み (Reg.NO name KOR ENG MATH)
  while (count < MAX_STUDENTS &&
         fscanf(input_file, "%s %s %d %d %d", students[count].reg_no,
                students[count].name, &students[count].kor,
                &students[count].eng, &students[count].math) == 5) {

    // 合計、平均、グレードの計算
    students[count].total =
        students[count].kor + students[count].eng + students[count].math;
    students[count].average = students[count].total / 3.0f;
    students[count].grade = calculate_grade(students[count].average);
    count++;
  }
  fclose(input_file);

  printf("Successfully loaded %d student records.\n", count);

  // --- ソート処理と処理時間の計測 ---
  clock_t start_time = clock();

#ifdef QUICK_SORT
  printf("Sorting method: Custom Quick Sort (Conditional Compile)\n");
  if (count > 0) {
    quick_sort(students, 0, count - 1);
  }
#elif defined(QSORT_LIB)
  printf("Sorting method: Standard Library qsort (Conditional Compile)\n");
  if (count > 0) {
    qsort(students, count, sizeof(Student), qlib_compare);
  }
#endif

  clock_t end_time = clock();
  double elapsed_time =
      (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;
  printf("Sorting processing time: %.4f ms\n", elapsed_time);

  // --- 結果のファイル出力 ---
  FILE *output_file = fopen(output_filename, "w");
  if (output_file == NULL) {
    printf("Error opening output file: %s\n", output_filename);
    free(students);
    return 1;
  }

  // ヘッダーの書き込み
  fprintf(output_file, "Reg.NO\tname\tKOR\tENG\tMATH\ttotal\tavg\tgrade\n");

  // ポインタ操作を用いたファイル書き込み
  Student *ptr = students;
  for (int i = 0; i < count; i++) {
    fprintf(output_file, "%s\t%s\t%d\t%d\t%d\t%d\t%.2f\t%c\n", (ptr + i)->reg_no,
            (ptr + i)->name, (ptr + i)->kor, (ptr + i)->eng, (ptr + i)->math,
            (ptr + i)->total, (ptr + i)->average, (ptr + i)->grade);
  }
  fclose(output_file);
  printf("Results successfully written to %s\n", output_filename);

  // --- 学籍番号または名前による検索機能 (Looking for my grade) ---
  if (search_query != NULL) {
    int found = 0;
    printf("\n--- Search Results for \"%s\" ---\n", search_query);
    for (int i = 0; i < count; i++) {
      if (strcmp(students[i].reg_no, search_query) == 0 ||
          strcmp(students[i].name, search_query) == 0) {
        printf("Found! Reg.NO: %s, Name: %s, Total: %d, Avg: %.2f, Grade: %c\n",
               students[i].reg_no, students[i].name, students[i].total,
               students[i].average, students[i].grade);
        found = 1;
      }
    }
    if (!found) {
      printf("No student found with ID or Name: %s\n", search_query);
    }
  }

  free(students);
  return 0;
}
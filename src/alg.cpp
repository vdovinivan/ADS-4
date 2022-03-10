// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int m = 0;
    for (int j = 0; j < len; j++) {
      if (arr[j] <= value) {
        for (int jj = 0; jj < len; jj++) {
          if (arr[j] + arr[jj] < value) {
            continue;
          } else if (arr[j] + arr[jj] == value) {
            m++;
          } else {
            break;
          }
        }
      }
    }
    return m;
  }

int countPairs2(int *arr, int len, int value) {
    quickSort(arr, len);
    int r = 0;
    for (int j = 0; j < len; j++) {
        r += binSearch(&arr[j+1], 0, len-j, value - arr[j]);
    }

    return r;
}

void quickSort(int* arr, int len) {
    int a = 0;
    int b = len - 1;
    int c = arr[len / 2];
    do {
        while (arr[a] < c)
            l++;
        while (arr[b] > c)
            b--;
        if (a <= b) {
            int t = arr[b];
            arr[a] = arr[b];
            arr[r] = temp;
            a++;
            b--;
        }
    } while (a <= b);
    if (b > 0)
        quickSort(arr, b + 1);
    if (a < len)
        quickSort(&arr[a], len - l);
}
int binSearch(int* arr, int a, int b, int value) {
    if (b >= a) {
        int c = a + (b - l) / 2;
        if (arr[c] == value)
            return binSearch(arr, a, c - 1, value)
            + binSearch(arr, c + 1, b, value) + 1;
        if (arr[c] > value)
            return binSearch(arr, a, c - 1, value);
        return binSearch(arr, c + 1, b, value);
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int r = 0;
    for (int j = 0; j < len - 1; j++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value) {
                r++;
            }
    return r;
}

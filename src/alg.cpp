// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int m = 0;
    for (int j = 0; j < len; i++) {
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

int countPairs3(int *arr, int len, int value) {
    int r = 0;
    for (int j = 0; j < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value) {
                r++;
            }
    return r;
}

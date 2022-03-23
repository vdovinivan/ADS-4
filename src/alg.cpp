// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}


int countPairs2(int* arr, int len, int value) {
    int count = 0, left = 0, right = len, maxPart = 0, i, j;
    while (left < right) {
        maxPart = (left + right) / 2;
        if (arr[maxPart] > value) {
            right = maxPart;
        } else { left = maxPart + 1; }
    }
    int hVal = value / 2;

    for (i = 0; arr[i] < hVal; i++) {
        int secP = value - arr[i];
        for (j = maxPart; arr[j] >= secP; j--) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    for (j = 1; arr[i + 1] == hVal; i++, j++) {
        count += j;
    }
    return count;
}

int binS(int* arr, int size, int value) {
    int res = 0, r = -1, l = size;
    while (r < l - 1) {
        int m = (l + r) / 2;
        if (arr[m] < value) {
            r = m;
        } else { l = m; }
    }
    int rIn = l;
    int lIn = l - 1;
    while (rIn < size && arr[rIn] == value) {
        rIn++;
        res++;
    }
    while (lIn > 0 && arr[lIn] == value) {
        lIn--;
        res++;
    }
    return res;
}

int countPairs3(int* arr, int len, int value) {
    int kol = 0, i, j, count = 0;
    for (i = 0; i < len; i++) {
        if (arr[i] >= value / 2) {
            int cCtr = binS(arr, len, value - arr[i]);
            int cCtr2 = binS(arr, len, arr[i]);
            for (j = cCtr - 1; j > 0; j--) {
                if (value % 2 != 0) {
                    kol += cCtr * cCtr2;
                    break;
                }
                count += j;
            }
            break;
        }
        kol = binS(arr, len, value - arr[i]);
        count += kol;
    }
    return count;
}

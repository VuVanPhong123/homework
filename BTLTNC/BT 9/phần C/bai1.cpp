void reverse(char a[]) {
    int len = strlen(a);
    for (int i = 0; i < len/2; i++) {
        char temp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = temp;
    }
}

void delete_char(char a[], char c) {
    int len = strlen(a);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != c) {
            a[j++] = a[i];
        }
    }
    a[j] = '\0';
}

void pad_right(char a[], int n) {
    int len = strlen(a);
    if (len >= n) {
        return;
    }
    for (int i = len; i < n; i++) {
        a[i] = ' ';
    }
    a[n] = '\0';
}

void pad_left(char a[], int n) {
    int len = strlen(a);
    if (len < n) {
        int num_spaces = n - len;
        for (int i = len; i >= 0; i--) {
            a[i + num_spaces] = a[i];
        }
        memset(a, ' ', num_spaces);
    }
}

void truncate(char a[], int n) {
    int len = strlen(a);
    if (len > n) {
        a[n] = '\0';
    }
}

bool is_palindrome(char a[]) {
    int len = strlen(a);
    for (int i = 0; i < len / 2; i++) {
        if (a[i] != a[len - i - 1]) {
            return false;
        }
    }
    return true;
}


void trim_left(char a[]) {
    int len = strlen(a);
    int i = 0;
    while (a[i] == ' ' && i < len) {
        i++;
    }
    if (i > 0) {
        for (int j = 0; j < len - i; j++) {
            a[j] = a[j + i];
        }
        a[len - i] = '\0';
    }
}

void trim_right(char a[]) {
    int len = strlen(a);
    int i = len - 1;
    while (a[i] == ' ' && i >= 0) {
        i--;
    }
    if (i < len - 1) {
        a[i + 1] = '\0';
    }
}

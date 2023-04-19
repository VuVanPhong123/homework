char* reverse(const char a[]) {
    int len = strlen(a);
    char* result = new char[len + 1];
    for (int i = 0; i < len; i++) {
        result[i] = a[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

char* delete_char(const char a[], const char c) {
    int len = strlen(a);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == c) {
            count++;
        }
    }
    char* result = new char[len - count + 1];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != c) {
            result[j++] = a[i];
        }
    }
    result[j] = '\0';
    return result;
}

char* pad_right(const char a[], const int n) {
    int len = strlen(a);
    if (len >= n) {
        char* result = new char[len + 1];
        strcpy(result, a);
        return result;
    }
    char* result = new char[n + 1];
    strcpy(result, a);
    for (int i = len; i < n; i++) {
        result[i] = ' ';
    }
    result[n] = '\0';
    return result;
}

char* pad_left(const char a[], const int n) {
    int len = strlen(a);
    if (len >= n) {
        char* result = new char[len + 1];
        strcpy(result, a);
        return result;
    }
    char* result = new char[n + 1];
    int num_spaces = n - len;
    memset(result, ' ', num_spaces);
    strcpy(result + num_spaces, a);
    result[n] = '\0';
    return result;
}

char* truncate(const char a[], const int n) {
    int len = strlen(a);
    if (len <= n) {
        char* result = new char[len + 1];
        strcpy(result, a);
        return result;
    }
    char* result = new char[n + 1];
    strncpy(result, a, n);
    result[n] = '\0';
    return result;
}

char* trim_left(const char a[]) {
    int len = strlen(a);
    int i = 0;
    while (a[i] == ' ' && i < len) {
        i++;
    }
    char* result = new char[len - i + 1];
    strcpy(result, a + i);
    return result;
}

char* trim_right(const char a[]) {
    int len = strlen(a);
    int i = len - 1;
    while (a[i] == ' ' && i >= 0) {
        i--;
    }
    char* result = new char[i + 2];
    strncpy(result, a, i + 1);
    result[i + 1] = '\0';
    return result;
}

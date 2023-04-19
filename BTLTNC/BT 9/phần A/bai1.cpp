#include <iostream>
#include <cstring>

char* concat(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = new char[len1 + len2 + 1]; // cấp phát động bộ nhớ cho mảng kết quả

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    const char* str1 = "Hello";
    const char* str2 = "World";
    char* result = concat(str1, str2);

    std::cout << result << std::endl;

    delete[] result; // giải phóng bộ nhớ của mảng kết quả sau khi sử dụng

    return 0;
}

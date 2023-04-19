

int main() {
  char *s;  // Sửa: thay char** bằng char*
  char foo[] = "Hello World";
  s = foo;  // Sửa: thêm toán tử & trước foo, vì s là con trỏ
  printf("s is %s\n", s);
  char* s_array[1] = {s}; // Sửa: khởi tạo mảng s_array và gán s vào s_array[0]
  printf("s[0] is %s\n", s_array[0]);
  return 0;
}

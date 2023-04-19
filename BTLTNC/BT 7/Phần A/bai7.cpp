#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char* argv[])
{
    const char* str1 = argv[1];
    const char* str2 = argv[2];
    int count = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i <= len2 - len1; i++)
    {
        if (strncmp(str1, str2 + i, len1) == 0)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

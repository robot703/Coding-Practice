#include <iostream>

using namespace std;

int main()
{
    char str[] = "1234";

    bool isStringNumber = true;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]) == 0) {
            isStringNumber = false;
        }
    }

    if (isStringNumber) {
        cout << str << " is number";
    }
    else {
        cout << str << " is not number";
    }
}
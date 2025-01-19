#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        str[i] = std::toupper(str[i]);
    }

    std::cout << str << std::endl;

    return 0;
}
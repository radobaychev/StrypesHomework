#include <iostream>
#include <cstring>

bool areAnagrams(const char* str1, const char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    int count[256] = {0};

    for (int i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    const char* str1 = "listen";
    const char* str2 = "silent";

    if (areAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}

#include <iostream>

using std::cout;
using std::endl;

void strcpy(char* a, const char* b) {
    while (*a++ = *b++);
}

int strlen(const char* str) {
    const char* strtmp = str;
    while (*strtmp++);
    return (strtmp - str - 1);
}

char* strcat(char* destination, const char* source) {
    char* p = destination + strlen(destination);
    strcpy(p, source);
    return destination;
}

char* strrev(char* destination, const char* source) {
    const char* psrc = source + strlen(source) - 1;
    char* pdest = destination;
    while (psrc >= source) {
        *pdest++ = *psrc--;
    }
    *pdest = 0;
    return destination;
}

int strcmp(const char* str1, const char* str2) {
    while ((*str1) && (*str1++ == *str2++));
    return *str1 - *str2;
}

int main() {
    char s1[] = "";
    char s2[] = "Hello ";
    char s3[] = "World";
    char s4[64];
    s4[0] = 0;

    cout << strlen(s1) << endl;
    cout << strlen(s2) << endl;
    cout << strlen(s3) << endl;

    cout << strrev(s4, s2) << endl;
    cout << strrev(s4, s1) << endl;

    strcpy(s4, s2);

    cout << strcat(s4, s3) << endl;

    cout << strcmp(s2, s3) << endl;
    cout << strcmp(s1, s2) << endl;
    cout << strcmp(s4, s2) << endl;
    cout << strcmp(s2, s2) << endl;

    return 0;
}

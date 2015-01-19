#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>

void copy(const int* from, int* to, int count) {
    if (!count) {
        return;
    }
    int n = count / 18;
    switch (count % 18) {
    case 0: do {
        *to++ = *from++;
    case 17:
        *to++ = *from++;
    case 16:
        *to++ = *from++;
    case 15:
        *to++ = *from++;
    case 14:
        *to++ = *from++;
    case 13:
        *to++ = *from++;
    case 12:
        *to++ = *from++;
    case 11:
        *to++ = *from++; 
    case 10:
        *to++ = *from++;
    case 9:
        *to++ = *from++;
    case 8:
        *to++ = *from++;
    case 7:
        *to++ = *from++;
    case 6:
        *to++ = *from++;
    case 5:
        *to++ = *from++;
    case 4:
        *to++ = *from++;
    case 3:
        *to++ = *from++;
    case 2:
        *to++ = *from++;
    case 1:
        *to++ = *from++;
        } while (n-- > 0);
    }   
}

int main(int argc, char const *argv[]) {
    std::vector<int> v1(100000000);
    std::vector<int> v2(200000000, 2);
    clock_t t1 = clock();
    copy(&v1[0], &v2[0], 100000000);
    std::cout << "time: " << static_cast<float>(clock() - t1)/CLOCKS_PER_SEC << std::endl;  
    clock_t t2 = clock();
    std::copy(v1.begin(), v1.end(), v2.begin());
    std::cout << "time: " << static_cast<float>(clock() - t2)/CLOCKS_PER_SEC << std::endl;
    clock_t t3 = clock();
    for (std::vector<int>::iterator it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end(); ++it1, ++it2) {
        *it2 = *it1;
    }
    std::cout << "time: " << static_cast<float>(clock() - t3)/CLOCKS_PER_SEC << std::endl;
    return 0;
}



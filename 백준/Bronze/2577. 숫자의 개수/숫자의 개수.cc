#include <iostream>
#include <string>

int main () {
    int n1, n2, n3;
    
    std::cin >> n1;
    std::cin >> n2;
    std::cin >> n3;
    
    std::string mult = std::to_string(n1 * n2 * n3);
    
    int num_count[10] = { 0, };
    int len = mult.length();
    for(int i = 0; i < len; i++) {
        num_count[mult[i] - '0'] += 1;
    }
    
    for (int i = 0; i < 10; i++) {
        std::cout << num_count[i] << std::endl;
    }
    
    return 0;
}
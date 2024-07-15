#include <iostream>
#include <deque>
#include <string>

int main () {
  int N;
  std::cin >> N;
  std::deque<int> s;

  for (int i = 0; i < N; i++) {
    // 여기서 명령 처리
    std::string command;
    std::cin >> command;
    // push, pop, size, empty(비어 있으면 1 아니면 0 반환), front(없으면 -1), back(없으면 -1)
    if (command == "push") {
      int temp;
      std::cin >> temp;
      s.push_back(temp);
      continue;
    }

    if (command == "pop") {
      if (s.empty()) {
        std::cout << -1;
      } else {
        std::cout << s.front();
        s.pop_front();
      }
    } else if (command == "size") {
      std::cout << s.size();
    } else if (command == "empty") {
      std::cout << s.empty();
    } else if (command == "front") {
      if (s.empty()) {
        std::cout << -1;
      } else {
        std::cout << s.front();
      }
    } else if (command == "back") {
      if (s.empty()) {
        std::cout << -1;
      } else {
        std::cout << s.back();
      }
    }

    std::cout << '\n';
  } 

  return 0;
}

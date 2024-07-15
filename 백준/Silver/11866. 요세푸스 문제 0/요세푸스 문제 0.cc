#include <iostream>
#include <queue>

int main () {
  std::queue<int> queue;

  int length, step;

  std::cin >> length >> step;

  for (int i = 0; i < length; i++) queue.push(i + 1);

  std::cout << "<";

  for (int i = 1; !queue.empty(); i++) {
    int temp = queue.front();
    bool killable = i % step == 0;

    queue.pop();

    if (killable) {
      if (queue.size() == 0) {
        std::cout << temp;
      } else {
        std::cout << temp << ", ";
      }
    } else {
      queue.push(temp);
    }
  }

  std::cout << ">";

  return 0;
}
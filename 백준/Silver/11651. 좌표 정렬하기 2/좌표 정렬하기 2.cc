#include <iostream>
#include <algorithm>

int main () {
  int N;
  std::cin >> N;

  struct Point {
    int x;
    int y;
  };

  Point* points = new Point[N];

  for (int i = 0; i < N; i++) {
    int x, y;
    std::cin >> x >> y;
    points[i].x = x;
    points[i].y = y;
  }

  std::sort(points, points + N, [](Point a, Point b){
    if (a.y == b.y) {
      return a.x < b.x;
    }
    return a.y < b.y;
  });

  for (int i = 0; i < N; i++) {
    std::cout << points[i].x << ' ' << points[i].y << '\n';
  }

  return 0;
}
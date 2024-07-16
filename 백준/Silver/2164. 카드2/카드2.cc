#include <iostream>
#include <cstring>

template<typename T>
class Queue {
  public:
    Queue (int new_capacity = 2) {
      capacity_ = new_capacity;
      T* new_queue = new T[capacity_];
      queue_ = new_queue;
      rear_ = front_ = 0;
    }

    ~Queue () {
      if (queue_) delete[] queue_;
    }

    void Resize (int new_capacity) {
      T* new_queue = new T[new_capacity];

      for (int i = 0; i < capacity_; i++) {
        new_queue[i] = queue_[(front_ + i) % capacity_];
      }

      delete[] queue_;
      queue_ = new_queue;
      front_ = 0;
      rear_ = capacity_ - 1;
      capacity_ = new_capacity;
    }

    bool IsFull() {
      return (rear_ + 1) % capacity_ == front_;
    }

    bool IsEmpty() {
      return front_ == rear_;
    }

    void Enqueue(T item) {
      if (IsFull()) Resize(capacity_ * 2);

      if (rear_ == capacity_ - 1) {
        rear_ = 0;
      } else {
        rear_ += 1;
      }
      queue_[rear_] = item;
    }

    void Dequeue() {
      if (front_ == capacity_ - 1) {
        front_ = 0;
      } else {
        front_ += 1;
      }
    }

    T Front () {
      return queue_[(front_ + 1) % capacity_];
    }

    T Rear () {
      return queue_[rear_];
    }

    int Size () {
      if (front_ <= rear_) {
        return rear_ - front_;
      } else {
        return (capacity_ - front_) + rear_;
      }
    }

  private:
    T* queue_ = nullptr;
    int capacity_ = 0;
    int front_ = 0;
    int rear_ = 0;
};

int main () {
  Queue<int> q;

  int N;
  std::cin >> N;

  for (int i = 1; i < N + 1; i++) {
    q.Enqueue(i);
  }

  int i = 1;
  while (q.Size() != 1) {
    bool isEven = i % 2 == 0;
    if (isEven) {
      q.Enqueue(q.Front());
      q.Dequeue();
    } else {
      q.Dequeue();
    }
    i += 1;
  }

  std::cout << q.Front();

  return 0;
}
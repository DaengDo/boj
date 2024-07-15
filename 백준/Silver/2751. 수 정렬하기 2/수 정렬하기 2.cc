#include <iostream>
#include <cassert>
#include <cstring>

template<typename T>
class MinHeap {
  public:
    MinHeap (int new_capacity = 4) {
      T* new_heap = new T[new_capacity];
      capacity_ = new_capacity;
      heap_ = new_heap;
    }

    ~MinHeap () {
      if (heap_) delete[] heap_;
    }

    bool IsEmpty () {
      return size_ == 0;
    }

    T Top () {
      assert(!IsEmpty());
      return heap_[1];
    }

    int Size () {
      return size_;
    }

    void Resize (int new_capacity) {
      T* new_heap = new T[new_capacity];
      memcpy(new_heap, heap_, sizeof(T) * (size_ + 1));
      delete[] heap_;
      heap_ = new_heap;
      capacity_ = new_capacity;
    }

    void Push (T item) {
      if (size_ + 1 == capacity_) Resize(capacity_ * 2);      

      if (size_ == 0) {
        heap_[1] = item;
        size_ += 1;
        return;
      }      

      int index = size_ + 1;
      heap_[index] = item;

      while(index != 1 && heap_[index / 2] > heap_[index]){
        T temp = heap_[index];
        heap_[index] = heap_[index / 2];
        heap_[index / 2] = temp;
        index = index / 2;
      }

      size_ += 1;
    }

    void Pop () {
      assert(size_ != 0);
      int index = 1;
      heap_[1] = heap_[size_];
      size_ -= 1;
      while (index * 2 <= size_) {
        int indexToChange = heap_[index * 2] > heap_[index * 2 + 1] ? index * 2 + 1 : index * 2;

        if (heap_[index] > heap_[indexToChange]) {
          T temp = heap_[index];
          heap_[index] = heap_[indexToChange];
          heap_[indexToChange] = temp;
          index = indexToChange;
        } else {
          break;
        }
      }
    }

  private:
    T* heap_ = nullptr;
    int capacity_ = 0;
    int size_ = 0;
};


int main () {
  int N;
  std::cin >> N;

  MinHeap<int> heap;

  for (int i = 0; i < N; i++) {
    int temp;
    std::cin >> temp;
    heap.Push(temp);
  }

  while (!heap.IsEmpty()) {
    if (heap.Size() == 1) {
      std::cout << heap.Top();  
    } else {
      std::cout << heap.Top() << '\n';
    }
    heap.Pop();
  }

  return 0;
}
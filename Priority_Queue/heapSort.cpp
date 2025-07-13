#include<iostream>
#include<vector>
using namespace std;

class maxHeap {
  int i; // [0, i) will be the valid heap range
  vector<int> hp;

  void upHeapify(int ci) {
    while (ci > 0) {
      int pi = (ci - 1) / 2;
      if (hp[ci] > hp[pi]) {
        swap(hp[ci], hp[pi]);
        ci = pi;
      } else break;
    }
  }

  void downHeapify(int idx, int bound) {
    while (idx < bound) {
      int lc = 2 * idx + 1;
      int rc = 2 * idx + 2;
      int maxIdx = idx;

      if (lc < bound && hp[lc] > hp[maxIdx]) maxIdx = lc;
      if (rc < bound && hp[rc] > hp[maxIdx]) maxIdx = rc;
      if (maxIdx == idx) break;

      swap(hp[maxIdx], hp[idx]);
      idx = maxIdx;
    }
  }

public:
  void push(int el) {
    hp.push_back(el);
    i++; // increase heap bound
    upHeapify(hp.size() - 1);
  }

  void pop() {
    if (hp.size() == 0 || i == 0) {
      cout << "Heap is empty\n";
      return;
    }
    swap(hp[0], hp[i - 1]);
    i--; // reduce bound of valid heap
    downHeapify(0, i);
    hp.pop_back();
  }

  int peek() {
    return hp[0];
  }

  bool empty() {
    return i == 0;
  }

  void display() {
    cout << "[";
    for (int j = 0; j < i; j++) {
      cout << hp[j] << " ";
    }
    cout << "]\n";
  }

  maxHeap(vector<int> arr) {
    hp = arr;
    i = arr.size();
    for (int j = i / 2; j >= 0; j--) {
      downHeapify(j, i);
    }
  }

  vector<int> heapSort() {
    int original_i = i; // 🔧 Save original size
    int sz = i;
    while (sz > 1) {
      swap(hp[0], hp[sz - 1]);
      sz--;
      i--; // update i to reflect reduced heap during sort
      downHeapify(0, sz);
    }
    i = original_i; // 🔧 Restore i so heap can still be used after sort
    return hp;
  }
};

void heapSort(vector<int> &v) {
  maxHeap hp(v);
  v = hp.heapSort(); // 🔧 Copy sorted vector back
}

int main() {
  vector<int> v = {9, 6, 1, 19, 3, 2, 8, 12, 5};
  maxHeap heap(v);
  heap.display();

  heap.push(100);
  heap.display();

  vector<int> sorted = heap.heapSort();
  cout << "Sorted array: [";
  for (int x : sorted) cout << x << " ";
  cout << "]\n";

  return 0;
}

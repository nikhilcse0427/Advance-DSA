#include<iostream>
#include<vector>
using namespace std;

class maxHeap{
  //T.C - log(n)
  vector<int> hp;
  void upHeapify(int ci){
    while(ci > 0){
      int pi = (ci - 1)/2;
      if(hp[ci] > hp[pi]){
        swap(hp[ci], hp[pi]);
        ci = pi;
      }
      else break;
    }
  }

  void downHeapify(int idx){
    //T.C - log(n)
    while(idx < hp.size()){
      int lc = 2*idx + 1;
      int rc = 2*idx + 2;
      int maxIdx = idx;
      if(lc < hp.size() && hp[lc] > hp[maxIdx]) maxIdx = lc;
      else if(rc < hp.size() && hp[rc] > hp[maxIdx]) maxIdx = rc;
      else if(maxIdx == idx) break;
      swap(hp[maxIdx], hp[idx]);
      idx = maxIdx;
    }
  }
  public:
    void push(int el){
      //T.C - O(n)
      hp.push_back(el);
      upHeapify(hp.size()-1);
    }

    void pop(){
      //T.C - O(n)
      //delete highest priority element
      if(hp.size() == 0){
        cout<<"Heap is empty\n";
      }
      swap(hp[0], hp[hp.size()-1]);
      hp.pop_back();
      downHeapify(0);
    }

    int peek(){
      return hp[0];
    }

    bool empty(){
      return hp.size();
    }

    void display(){
      cout<<'[';
      for(int i=0;i<hp.size();i++){
        cout<<hp[i]<<" ";
      }
      cout<<"]\n";
    }
    maxHeap(vector<int> arr){
      //T.C - O(n)
      hp = arr;
      for(int i=hp.size()/2;i>=0;i--){
        downHeapify(i);
      }
    }
};

int main(){
  vector<int> v = {4,5,2,1,7,8};
  maxHeap heap(v);
  for(int i=1;i<9;i++){
    heap.push(i);
  }
  heap.display();
  heap.pop();
  heap.display();

  return 0;
}
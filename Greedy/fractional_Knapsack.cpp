#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<int, int> item1, pair<int,int> item2){
  double r1 = item1.second*1.0/item1.first*1.0;
  double r2 = item2.second*1.0/item2.first*1.0;
  return r1>r2;
}
double fractionalKnapsack(vector<int> &weights, vector<int> &profits, int w, int n){
  vector<pair<int, int>> arr;
  for(int i=0;i<n;i++){
    arr.push_back({weights[i], profits[i]});
  }
  sort(arr.begin(), arr.end(), comp);
  double profit = 0;
  for(int j=0;j<n;j++){
    if(arr[j].first < w){
      profit += arr[j].second;
      w -= arr[j].first;
    }
    else{
      profit += (arr[j].second/arr[j].first*1.0)*w*1.0;
      w=0;
      break;
      }
    }
  return profit;
}

int main(){
  vector<int> weights  = {10, 20, 30};  // Weights of the items
  vector<int> profit = {60, 100, 120}; // Corresponding values
  int w = 50; // Capacity of the knapsack
  int n = 3;  // number of items
  double output = fractionalKnapsack(weights, profit, w, n);
  cout<<"Maximum Profit: "<<output;
  return 0;
}
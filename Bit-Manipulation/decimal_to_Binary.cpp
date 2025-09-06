#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  int num = 27;
  string binary_number = "";
  while(num>0){
    int rem = num % 2;
    binary_number += to_string(rem);
    num /= 2;
  }
  reverse(binary_number.begin(), binary_number.end());
  cout<<binary_number;
  return 0;
}
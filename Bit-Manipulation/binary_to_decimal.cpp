#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  string binaryNum = "11011";
  int n = binaryNum.size();
  int right = 1;
  int decimal = 0;
  for(int i=n-1;i>=0;i--){
    if(binaryNum[i]=='1'){
      decimal += right;
    }
    right*=2;
  }
  cout<<decimal;
}
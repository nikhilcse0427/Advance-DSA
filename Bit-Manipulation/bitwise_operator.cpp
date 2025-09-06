#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=23, b=4;
  int bitwiseOr = (a|b);
  cout<<"bitwiseOr: "<<bitwiseOr;
  cout<<'\n';
  cout<<"bitwiseAnd: "<<(a&b);
  cout<<'\n';
  return 0;
}
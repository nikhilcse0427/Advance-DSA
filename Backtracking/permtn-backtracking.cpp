#include<iostream>
using namespace std;

void permutation(string &str, int i){
  if(i==str.size()-1){
    cout<<str<<" ";
    return;
  }
  for(int j=i;j<str.size();j++){
    swap(str[j], str[i]);
    permutation(str, i+1);
    swap(str[j], str[i]);
  }
}

int main(){
  string s = "abc";
  permutation(s, 0);
  return 0;
}
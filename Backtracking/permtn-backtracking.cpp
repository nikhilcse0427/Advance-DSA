#include<iostream>
#include<unordered_set>
using namespace std;

void permutation(string &str, int i){
  if(i==str.size()-1){
    cout<<str<<" ";
    return;
  }
  unordered_set<char> s;
  for(int j=i;j<str.size();j++){
    if(s.count(str[j])) continue;
    s.insert(str[i]);
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
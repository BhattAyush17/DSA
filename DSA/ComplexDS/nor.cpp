#include<stdio.h>
#include<stdlib.h>

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "sjggdjydg";
    int count = 0;
    for(int i =0; i<s.length(); i++){
        if(s[i]=='g'){
            count++;
        }
    }
    cout<<count;
}
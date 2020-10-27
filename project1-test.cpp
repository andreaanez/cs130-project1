#include "project1.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;



int main(int argc, char** argv) {

    Tst t;

    string funcs = argv[1];
    vector <string> v;
    int size = funcs.size();
    string words; 
    for (int i=0; i < size; i++){
        if (funcs[i] == 32){
           v.push_back(words);
           words="";
           i++;
        }
        if (funcs[i]== 44){
            v.push_back(words);
            words="";
            i++;
            i++;
        }
        words += funcs[i];
        if ( i == size -1){
            v.push_back(words);
            words="";
        }
              
    }
    

    int j = v.size();
    for (int i =0; i < j; i++){
        if (v[i] == "insert"){
            t.insert(v[i+1]);
            i++;
        }
        if (v[i] == "delete"){
            t.deleteWord(v[i+1]);
            i++;
        }
        if (v[i] == "lookup"){
            t.lookup(v[i+1]);
            i++;
        }
        if (v[i]== "range_search"){
            t.range_search(v[i+1], v[i+3]);
            i+=3;
        }
    }
}


   

    

  

  

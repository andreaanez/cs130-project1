#include "project1.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  
  Tst t;
  //std::ostringstream out1;


    t.insert ("expect");
    t.insert ("expect");
    t.insert ("cat");
    t.insert ("dog");
    t.insert ("rat");
    t.insert ("girl");
    t.insert ("dog");
    t.insert ("horse");
    t.insert ("rat");
    t.insert("andrea");
    t.lookup("america");
    t.lookup("rat");
    //t.deleteWord("cat");
    t.deleteWord("andrea");
    // t.insert ("girl");
    // t.insert("apple");
    // t.insert("andrea");
    // t.insert ("horse");
    // t.insert("andrea");
    // t.insert("anez");
    // t.insert("ardvark");
    // t.insert("anteater");
    // t.insert("america");
    // t.lookup("expect");
    // t.lookup("dog");
    // t.lookup("america");
    // t.lookup("horse");
    // t.lookup("rat");
    // t.lookup("andrea");


   

    

//   ASSERT_EQUALS(expect,out1.str());
// //   ASSERT_EQUALS(expect2, t.insert("dog"));
//   ASSERT_EQUALS(expect3, t.insert("expected"));
//   ASSERT_EQUALS(expect4, t.insert("cat"));
//   ASSERT_EQUALS(expect5, t.insert("mouse"));
//   ASSERT_EQUALS(expect6, t.insert("lizard"));
//   ASSERT_EQUALS(expect7, t.insert("rat"));
  return 0;
}
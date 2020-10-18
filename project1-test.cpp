#include "project1.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  
  Tst t;
  //std::ostringstream out1;

//   string expect = "expected inserted, new count = 1";// change 
//   string expect2 = "dog inserted, new count = 1";
//   string expect3 = "expected inserted, new count = 2";
//   string expect4 = "cat inserted, new count = 1";
//   string expect5 = "mouse inserted, new count = 1";
//   string expect6 = "lizard inserted, new count = 1";
//   string expect7 = "rat inserted, new count = 1";

    t.insert ("expect");
    t.insert ("expect");
    t.insert ("cat");
     t.insert ("dog");
    t.insert ("rat");
    t.insert ("girl");
     t.insert ("dog");
     t.insert ("horse");
    t.insert ("rat");
    t.insert ("girl");
     t.insert ("horse");
     t.insert("spectacular");
     t.insert("bavandeeeeeep");
     t.insert("gag");
     t.insert("choke");
     t.insert("punanie");
     t.insert("zebra");
     t.insert("sex");
     t.insert("sassy");
     t.insert("sex");
     t.insert("jacob");


//   ASSERT_EQUALS(expect,out1.str());
// //   ASSERT_EQUALS(expect2, t.insert("dog"));
//   ASSERT_EQUALS(expect3, t.insert("expected"));
//   ASSERT_EQUALS(expect4, t.insert("cat"));
//   ASSERT_EQUALS(expect5, t.insert("mouse"));
//   ASSERT_EQUALS(expect6, t.insert("lizard"));
//   ASSERT_EQUALS(expect7, t.insert("rat"));
  return 0;
}
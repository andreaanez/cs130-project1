// project1.cpp

//Andrea Anez 
// CS 130 Divy 
// 10/8/2020

#include "project1.h"
#include <iostream>
using namespace std; 

// CONSTRUCTOR
Tst::Tst()
{
    root = NULL; // initalizing the poiner to the root as NULL we have no root 

}


//DESTRUCTOR

void Tst::deleteTst(TstNode *root){ // pointer to a TstNode 
    if (root){ // if not a NULL pointer 
        deleteTst(root -> left); // ** dereferance so we can get what is in the structure ? -> already does that ?
        deleteTst(root -> right); // **gives us a pointer to a node 
        deleteTst(root -> mid); 
        delete root; // finally we delete the orignal node after we have deleted all of its children 

    }
 }

Tst:: ~Tst()
{
    deleteTst(root);
}

// INSERT 
string Tst::insert (string word, TstNode* node){ // pointer to a node 
    string response = "oops !"; 

     if (node == NULL) {
        root = createNode(word);
        response = word + "inserted, new count = 1";
        return response;
    }

    if (node != NULL){
        // checking to see if already exists in the node we are in
        if (node -> keyRight == word){
            node -> countRight +=1;
            response = word + " inserted, new count =" + std::to_string(node -> countRight); 
            return response;
        }
        if (node -> keyLeft == word){
            node -> countLeft +=1;
            response = word + " inserted, new count =" + std::to_string(node -> countLeft); 
            return response;
        }
    
        // if node is full -- find what path should go down left, right, mid 
        if ((((node -> countLeft) >= 1)) && ((node -> countRight) >= 1)){
            if ( word < (node -> keyLeft)) {
                insert(word, node -> left);
            }
            if ( word > (node -> keyRight)){
                insert (word, node -> right);
            }

            if ( (word > (node -> keyLeft) ) && (word < (node -> keyRight))){
                insert (word, node -> mid);
            }
        }
        
        // if node is not full
    
        if ((node -> countRight) == 0 ){
            if (word < (node ->keyLeft)){
                node -> countRight = node -> countLeft;
                node -> keyRight = node -> keyLeft;
                node -> countLeft = 1;
                node -> keyLeft = word;
                response = word + " inserted, new count = 1";
                return response; 
            }
            if (word >= (node -> keyLeft)) {

                response = word + " inserted, new count = 1";
                return response; 

            }
        }
    }
        return response;
    }
        
   

    //else do level order traversal until find the word, semi empty node or no word and a 
    // NULL pointer 

    // do we find it in any of the nodes as we traverse the tree ?
    // no ? 
        // then we add it to an exisitng node 
        // or we make a new node 
    // yes ?
        // increase the count 


 
 //HELPER FUNCTIONS 
 
 TstNode* Tst::createNode(string key){
     TstNode* newTstNode = new TstNode(); // setting a pointer to a new node we have jsut created 
     if (!newTstNode){
         return NULL;
     }
    newTstNode -> countLeft = 1;
    newTstNode -> keyLeft = key;
    newTstNode -> left = newTstNode -> right = newTstNode -> mid = NULL;
    return newTstNode;
 }



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

void Tst::insert (string word){
    insertHelp(word,root);
}


void Tst::insertHelp (string word, TstNode* node){ // pointer to a node  
    
     if (root == NULL) {
        node = root = createNode(word);
        cout << node -> keyLeft << " inserted, new count = 1"<<endl;    
        return;
    }

    if (node != NULL){
        // checking to see if already exists in the node we are in
        if (node -> keyRight == word){
            node -> countRight +=1;
            cout << node -> keyRight << " inserted, new count = " << std::to_string(node -> countRight)<<endl;
            return;
        }
        if (node -> keyLeft == word){
            node -> countLeft +=1;
            cout << node -> keyLeft << " inserted, new count = " << std::to_string(node -> countLeft) <<endl;
            return;
        }
    
    
        if ((node -> countRight) == 0 ){
            if (word < (node ->keyLeft)){
                node -> countRight = node -> countLeft;
                node -> keyRight = node -> keyLeft;
                node -> countLeft = 1;
                node -> keyLeft = word; 
                cout << node -> keyLeft << " inserted, new count = 1" <<endl;
                return; 
            }
            if (word > (node -> keyLeft)) {
                node -> keyRight = word;
                node -> countRight += 1; 
                cout << node -> keyRight << " inserted, new count = 1" <<endl;
                return; 

            }
        }

         // if node is full -- find what path should go down left, right, mid 
        if ((((node -> countLeft) >= 1)) && ((node -> countRight) >= 1)){
            if ( word < (node -> keyLeft)) {
                if ((node ->left) == NULL){
                    node->left = createNode(word);
                    cout << (node -> left)-> keyLeft << " inserted, new count = 1"<<endl;
                    return;
                }
                else {
                    insertHelp(word, node -> left);
                }
            
            }
            if ( word > (node -> keyRight)){
                if ((node ->right) == NULL){
                    node->right = createNode(word);
                    cout << (node -> right) -> keyLeft << " inserted, new count = 1"<<endl;
                    return;
                }
                else {
                    insertHelp(word, node -> right);
                }
            }

            if ( (word > (node -> keyLeft) ) && (word < (node -> keyRight))){
                if ((node ->mid) == NULL){
                    node->mid = createNode(word);
                    cout << (node->mid) -> keyLeft << " inserted, new count = 1"<<endl;
                    return;
                }
                else {
                    insertHelp(word, node -> mid);
                }
            }
         }
    }
}



 
 //HELPER FUNCTIONS 
 
 TstNode* Tst::createNode(string key){
     TstNode* newTstNode = new TstNode(); // setting a pointer to a new node we have jsut created 
     if (!newTstNode){
         return NULL;
     }
    newTstNode -> countLeft = 1;
    newTstNode -> keyLeft = key;
    newTstNode -> left = NULL;
    newTstNode -> right = NULL;
    newTstNode -> mid = NULL;
    newTstNode -> countRight =0;
    newTstNode -> keyRight = "";
    return newTstNode;
 }



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


//LOOKUP *********************************************************************

void Tst::lookup(string word){
    lookupHelp(word,root);
}

void Tst::lookupHelp(string word, TstNode* node){
    if (node == NULL){
        cout << word<< " not found"<< endl;
        return;
    }
    // does it equal anything in this node ?
    if (node -> keyLeft == word){
        cout << word << " found, count = "<< node -> countLeft <<endl;
        return;
    }

    if (node -> keyRight == word){
        cout << word << " found, count = "<< node -> countRight <<endl;
        return;
    }
    
    // Lets go check other nodes 
    if ( word < node -> keyLeft ){
        lookupHelp(word,node -> left);
    }
    if ( (word > node -> keyRight) && (node -> keyRight != "") ){
        lookupHelp(word,node->right);
    }
    if ( (word > node -> keyLeft) && ((word < node -> keyRight) && (node -> keyRight != ""))){
        lookupHelp(word,node->mid);
    }

}

// RANGE SEARCH *********************************************************************
void Tst::range_search(string word1, string word2){
    range_searchHelper(word1, word2, root);
}

void Tst::range_searchHelper(string word1, string word2, TstNode* node){
    if (node == NULL){
        return;
    }

    if (word1 < node -> keyLeft){
       range_searchHelper(word1, word2, node -> left); 
    }
    if ((word1 <= node -> keyLeft) && (word2 >= (node -> keyLeft))){
        cout << node -> keyLeft<< endl;
    }
    if  ((((node -> keyRight) >= word1) && (word1 >= (node ->keyLeft))) || ((((node -> keyRight) >= word2)&& (word2 >= (node ->keyLeft))) )  || 
        ((word1 <= (node -> keyLeft) )&&(word2 >= (node->keyRight)))){
        range_searchHelper(word1, word2, node -> mid); 
    }
    if ((word1 <= node -> keyRight) && (word2 >= (node -> keyRight))){
        cout << node -> keyRight<< endl;
    }
     if (word2 > node -> keyRight) {
        range_searchHelper(word1, word2, node -> right); 
        }
    }




// INSERT *********************************************************************

void Tst::insert (string word){
    insertHelp(word,root);
}


void Tst::insertHelp (string word, TstNode* node){ // pointer to a node  
    
     if (root == NULL) {
        node = root = createNode(word);
        cout << root -> keyLeft << " inserted, new count = 1"<<endl;    
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
            if ( (word > (node -> keyRight))&&(node->keyRight != "")){
                if ((node ->right) == NULL){
                    node->right = createNode(word);
                    cout << (node -> right) -> keyLeft << " inserted, new count = 1"<<endl;
                    return;
                }
                else {
                    insertHelp(word, node -> right);
                }
            }

            if ( (word > (node -> keyLeft) ) && (word < (node -> keyRight)&&(node->keyRight != ""))){
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

//DELETE*********************************************************************************

void Tst::deleteWord (string word){
    deleteHelp(word);
    
}

void Tst::deleteHelp (std::string word){
    TstNode* node;
    node = search(word, root);

    if (node == NULL){
        return;
    }
    // null check -- notice any null pointers
    string side;

    if (node -> keyLeft == word){
        side ="left";
    }

    if (node -> keyRight == word){
        side = "right";
    }
    
    if (side == "left"){ 
        // if has count greater than 1 
        if ((node -> countLeft) > 1 ){
            node -> countLeft --;
            cout << word << " deleted 1, new count = " << node ->countLeft << endl;
            return;
        }
        // if has no children 
        // DONT NEED SUCESSOR
        if (!(node -> left || node-> mid || node -> right)){
            if (node -> countRight == 0 ){
                // is it the root ?
                if (node == root){
                    root = NULL;
                    delete node;
                    cout << word << " deleted" << endl;
                    return; 
                }
              
                if (node != root){
                   TstNode* aboveNode = searchAbove(word,root);
                   if (aboveNode == NULL){
                        cout << "ERROR NULL" << endl;
                    }
             
                   if (aboveNode -> left){
                  
                        if (((aboveNode -> left)->keyLeft) == word ){
                            aboveNode -> left =NULL;
                        }    
                    }
                    if (aboveNode -> mid ){
                        if (((aboveNode -> mid)->keyLeft) == word ){
                            aboveNode -> mid = NULL;
                        }
                    }

                    if (aboveNode -> right){
                        if (((aboveNode -> right)->keyLeft) == word ){
                            aboveNode -> right = NULL;
                        }
                    }
                    cout << word << " deleted" << endl;
                    delete node;
                    return;
                    }
                }
                // it has two elements (aka it has a right element) - we only need to delete one 
                if (node -> countRight >= 1){
                    node -> countLeft = node->countRight;
                    node -> keyLeft = node -> keyRight;
                    node -> countRight = 0;
                    node -> keyRight = "";
                    cout << word << " deleted" << endl;

                } 
                 
            } 
       

            // we need a sucessor to the left element!!!!!!!
            // perlimnary check to see if its children are partialy empty 
            // make into equaitons
             
            if ((node -> left || node-> mid || node -> right)){
            sucessorLeft(word,node);
            cout<< word<< " deleted"<<endl;
  
                
            }
    }

    if (side == "right"){ 
        
        if ((node -> countRight) > 1 ){
            node -> countRight --;
            cout << word << " deleted, new count = " << node ->countRight << endl;
            return;
        }
        if (!(node -> left || node-> mid || node -> right)){
            node -> countRight = 0;
            node -> keyRight = "";
            cout << word << " deleted" << endl;                   
        }
        // we just want to see if the node is partialy empty 
        // so for right and left we will be checking to see if the right side is empty  
        if ((node -> left || node-> mid || node -> right)){ 
            sucessorRight(word,node);
            cout << word << " deleted"<<endl;
        }
    }
}
        //finds the node of the sucessor to relpace an element taken from the right side of a node
        // choose left most element from the sucessor node 
        // takes a node that has the word that needs to be deleted 
        // finds a sucessor 
        void Tst::sucessorRight(string word, TstNode* node){
            // sucessor node 
            int flag = 0;
            flag = checkparRight(word, node);
            if (flag <1) {
    
            TstNode* node2 =nullptr;
            // finding a scucessor first !!
            if (node -> right){
                    node2 = recursiveLeft(node->right);
                    node -> countRight = node2 -> countLeft;
                    node -> keyRight = node2 -> keyLeft;
                    node2 -> countLeft = 0;
                    node2 -> keyLeft = "?";
                    elementLeft(node2,node);
                    return;
            }
            // no right node 
            if (!(node->right) && (node -> mid)){
                    node2 = recursiveRight(node->mid);
                    node -> countRight = node2 -> countRight;
                    node -> keyRight = node2 -> keyRight;
                    node2 -> countRight = 0;
                    node2 -> keyRight = "?";
                    elementRight(node2,node);
                    return;
            }
            // no right or mid node 
            if (!(node->right) && !(node -> mid) && (node->left)){
                    node2 = recursiveRight(node ->left);
                    node -> countRight = node2 -> countRight;
                    node -> keyRight = node2 -> keyRight;
                    node2 -> countRight = 0;
                    node2 -> keyRight = "?";
                    elementRight(node2,node);
                    return;
            }
                // choose left element b/c want something smaller than all other elements on this side 
            }   // sucessor filled 
        }
        void Tst::sucessorLeft(string word, TstNode* node){
            // sucessor node
            int flag = 0;
            flag = checkparLeft(word, node);
            if (flag <1) {
                TstNode* node2 = nullptr;
            // finding a scucessor first !!
            
            if (!((node -> left)==NULL)){
                node2 = recursiveRight(node->left);
                node -> countLeft = node2 -> countRight;
                node -> keyLeft = node2 -> keyRight;
                // zeroing out dog 
                node2 -> countRight = 0;
                node2 -> keyRight = "?";
                elementRight(node2,node);
                return;
            }
            // no right node 
            if (((node->right)==NULL) && !((node -> mid) == NULL)){
                    node2 = recursiveLeft(node->mid);
                    node -> countLeft = node2 -> countLeft;
                    node -> keyLeft = node2 -> keyLeft;
                    node2 -> countLeft = 0;
                    node2 -> keyLeft = "?";
                    elementLeft(node2,node);
                    return;
            }
            // no right or mid node 
            if (!(node->right) && !(node -> mid) && (node->left)){
                    node2 = recursiveLeft(node ->left);
                    node -> countLeft = node2 -> countLeft;
                    node -> keyLeft = node2 -> keyLeft;
                    node2 -> countLeft = 0;
                    node2 -> keyLeft = "?";
                    elementLeft(node2,node);
                    return;
                }

            }
                // choose left element b/c want something smaller than all other elements on this side 
        } 
    // to see if the children of the Left node element  
    //about to be replaced are only half full 
    //and do not need a sucessor themselves b/c will be deleted
    int Tst::checkparLeft(string word, TstNode* node){
        TstNode* node2 =nullptr;
        int flag = 0;
            if ((node -> left || node-> mid || node -> right)){
                if (node -> left ){
                if (((node -> left) -> keyRight) == ""){
                node2 = node -> left;
                node -> countLeft = node2 -> countLeft;
                node -> keyLeft = node2 -> keyLeft;
                node -> left = NULL;
                delete node2;
                flag++;
                return flag;
            }
        }
            
                if (node -> mid ){
                bool val = ((node -> mid) -> countRight ==0);
                if (!(node -> left)&&(val)){
                node2 = node -> mid;
                node -> countLeft = node2 -> countLeft;
                node -> keyLeft = node2 -> keyLeft;
                node -> mid = NULL;
                delete node2;
                flag++;
                return flag; 
            }
        }
                if (node -> right){
                bool value = ((node -> right) -> countRight == 0);
                if (!((node -> left))&&(!(node -> mid)&&(value))){
                node2 = node -> left;
                node -> countLeft = node2 -> countLeft;
                node -> keyLeft = node2 -> keyLeft;
                node -> right = NULL;
                delete node2;
                flag++;
                return flag;
            }
            }

        }
        return flag;
    }
    
    int Tst::checkparRight(string word, TstNode* node){
        
        int flag = 0;
        if ((node -> left || node-> mid || node -> right)){ 
             TstNode* node2 =nullptr;  
                if (node -> right ){
                if (((node -> right) -> keyRight) == ""){
                node2 = node -> right;
                node -> countRight = node2 -> countLeft;
                node -> keyRight = node2 -> keyLeft;
                node -> right = NULL;
                delete node2;
                flag++;
                return flag;
            }
        }
            
                if (node -> mid ){
                bool val = ((node -> mid) -> countRight ==0);
                if (!(node -> right)&&(val)){
                node2 = node -> mid;
                node -> countRight = node2 -> countLeft;
                node -> keyRight = node2 -> keyLeft;
                node -> mid = NULL;
                delete node2;
                flag++;
                return flag;
            }
        }
                if (node -> left){
                bool value = ((node -> left) -> countRight == 0);
                if (!((node -> right))&&(!(node -> mid)&&(value))){
                node2 = node -> left;
                node -> countRight = node -> countLeft;
                node -> keyRight = node -> keyLeft;
                node -> countLeft = node2 -> countLeft;
                node -> keyLeft = node2 -> keyLeft;
                node -> left = NULL;
                delete node2;
                flag++;
                return flag;
                }
            }
       
        }
         return flag;
    }

            // relpacement process if taking leftmost element  
            // stopping and taking left most element 
    void Tst::elementLeft(TstNode* node2, TstNode* node){

        if (!(node2 -> left || node2-> mid || node2-> right)){

            // if its the only element -- delete node !
            if (node2->countRight == 0){

                TstNode* aboveNode = searchAbove("?",root);
                if (aboveNode == NULL){
                    cout << "ERROR NULL" << endl;
                }
                
                if (aboveNode -> left){
                    if (((aboveNode -> left)->keyLeft) == "?" ){
                        aboveNode -> left =NULL;
                    }    
                }
                if (aboveNode -> mid ){
                    if (((aboveNode -> mid)->keyLeft) == "?" ){
                        aboveNode -> mid = NULL;
                    }
                }

                if (aboveNode -> right){
                    if (((aboveNode -> right)->keyLeft) == "?" ){
                        aboveNode -> right = NULL;
                    }
                }
            
                // node replaced !
                delete node2;
                return;
                
            }
            if (!(node2->countRight == 0)){
                node2 -> countLeft = node2->countRight;
                node2 -> keyLeft = node2 -> keyRight;
                node2 -> countRight = 0;
                node2 -> keyRight = "";
                return;
            }
        }
        // ****** make into function before we call this lets just make sure node 2 doesn't have mostly empty children 
        if ((!(node2->left)) && ((node2->mid)||(node2->right))){
                sucessorLeft(node2->keyLeft, node2);
        }
    }

        // if taking right most element 
    void Tst::elementRight(TstNode* node2, TstNode* node){
        // its not going to be the only element 
        if (!(node2 -> left || node2-> mid || node2-> right)){
            // need to check the left side as well 
            node2 -> countRight = 0;
            node2 -> keyRight = "";
            return;
        }
        
        if (node2 -> left || node2-> mid || node2-> right){
                sucessorRight(node2->keyRight, node2);
                return;
        }
    }

        
        
        // a recursive function to search for the left most node 
        TstNode* Tst::recursiveLeft(TstNode* node){
            if (node -> left){
                return recursiveLeft(node -> left);
            }
            if (!(node -> left)){
                return node;
            }
            return node;
        }
        // a recursive function to search for the right most node which has a right element 
        TstNode* Tst::recursiveRight(TstNode* node){

            if (!(node -> right)){
               
                return node;
            }
            if (node ->right){
                if (((node -> right) -> countRight) < 1){
                 
                    return node;
                }
            }
            if (node -> right){
                    {
                    return recursiveRight(node -> right);
                }
            }
            return node;
        }

//SEARCH *************************************************************************
TstNode* Tst::search(string word,TstNode* node){
    
    if (node == NULL){
        return NULL;
    }
    if (node -> keyLeft == word){
        return node;
    }

    if (node -> keyRight == word){
        return node;
    }
    
    // Lets go check other nodes 
    if ( word < node -> keyLeft ){
        return search(word,node -> left);
    }
    if ( (word > (node -> keyRight))&&(node->keyRight != "") ){
        return search(word,node->right);
    }
    if ( (word > node -> keyLeft) && ((word < (node -> keyRight))&&(node->keyRight != ""))){
        return search(word,node->mid);
    }
    return NULL;
}

TstNode* Tst::searchAbove(string word, TstNode* node){
    if (node == NULL){
        return NULL;
    }
    // we are going to look at the left key b/c thats the only thing left if we are deleting it
    if (!((node -> left) == NULL)){
        if ((((node -> left)->keyLeft) == word)){
            return node;
        }     
    }

    if (!((node -> mid) == NULL)){
        if ((((node -> mid)->keyLeft) == word)){
            return node;
        }
    }

    if (!((node -> right) ==NULL)){
        if ((((node -> right)->keyLeft) == word )){
            return node;
        }
    }
    
    // Lets go check other nodes 
    if ( word < node -> keyLeft ){
        return searchAbove(word,node -> left);
    }
    if ( (word > (node -> keyRight))&&(node->keyRight != "") ){
        return searchAbove(word,node->right);
    }
    if ( (word > node -> keyLeft) && ((word < (node -> keyRight))&&(node->keyRight != ""))){
        return searchAbove(word,node->mid);
    }
    return NULL;
}

    //CASES
        // has a count greater than one 
        // at bottom of the tree and delete, moving other to the left if needed 
        //if at a root recursively move elements to fill tthe void 



 
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



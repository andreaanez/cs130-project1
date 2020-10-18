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


//LOOKUP 

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




// INSERT 

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

//DELETE
//MAKE SURE THAT ANY TIME WE DELETE ELEMENT WE MAKE SURE ITS PARTNER FILLS THE LEFT EVERY TIME !!!
void Tst::deleteWord (string word){
    deleteHelp(word);
}

void Tst::deleteHelp (std::string word){
    TstNode* node;
    node = search(word, root);
    cout << "I got this far" << node->keyLeft << endl;
    string side;

    if (node -> keyLeft == word){
        cout << "we got here"<< endl;
        side ="left";
    }

    if (node -> keyRight == word){
        side = "right";
    }
    
    if (side == "left"){
           cout << (node -> left)->keyLeft <<endl; 
        // if has count greater than 1 
        if ((node -> countLeft) > 1 ){
            cout << "I got here 8"<<endl;
            node -> countLeft --;
            cout << word << "deleted, new count = " << node ->countLeft << endl;
            return;
        }
        // if has no children 
        if (!(node -> left || node-> mid || node -> right)){
            cout << "here 7"<<endl;
            // does it have two elements  ?
            // ok lets just delete the one we want 
            // move the other to the left if needed 

            // if only has one element -- we want to delete the node entirely 
            if (node -> countRight == 0 ){
                // is it the root ?
                if (node == root){
                    root = NULL;
                    delete node;
                    cout << word << " deleted" << endl;
                    return; 
                }
                // not the root ? 
                // Lets make the pointer to the node we are deleting null
                //Ok lets actually delete the node 
                if (node != root){
                    cout << "got here 3"<< endl;
                   TstNode* aboveNode = searchAbove(word,root);
                   if (aboveNode -> left){
                        if (((node -> left)->keyLeft) == word ){
                            aboveNode -> left =NULL;
                        }    
                    }
                    if (aboveNode -> mid ){
                        if (((node -> mid)->keyLeft) == word ){
                            aboveNode -> mid = NULL;
                        }
                    }

                    if (aboveNode -> right){
                        if (((aboveNode -> right)->keyLeft) == word ){
                            aboveNode -> right = NULL;
                        }
                    }
                    cout << word << "deleted" << endl;
                    delete node;
                    return;
                    }
                }
                // it has two elements (aka it has a right element) - we only need to delete one 
                if (node -> countRight == 1){
                    node -> countLeft = node->countRight;
                    node -> keyLeft = node -> keyRight;
                    node -> countRight = 0;
                    node -> keyRight = "";
                    cout << word << "deleted" << endl;

                }          
        }   
    }

}

TstNode* Tst::search(string word,TstNode* node){
    
    if (node == NULL){
        return NULL;
    }
    if (node -> keyLeft == word){
        cout << "I got here" << endl;
        cout << node -> keyLeft <<endl;
        return node;
    }

    if (node -> keyRight == word){
        return node;
    }
    
    // Lets go check other nodes 
    if ( word < node -> keyLeft ){
        search(word,node -> left);
    }
    if ( (word > (node -> keyRight))&&(node->keyRight != "") ){
        search(word,node->right);
    }
    if ( (word > node -> keyLeft) && ((word < (node -> keyRight))&&(node->keyRight != ""))){
        search(word,node->mid);
    }
    return NULL;
}

TstNode* Tst::searchAbove(string word, TstNode* node){
    cout << "I got here2"<<endl;
    if (node == NULL){
        return NULL;
    }
    // we are going to look at the left key b/c thats the only thing left if we are deleting it
    if (node -> left){
        if (((node -> left)->keyLeft) == word ){
            return node;
        }     
    }
    if (node -> mid ){
        if (((node -> mid)->keyLeft) == word ){
            return node;
        }
    }

    if (node -> right){
        if (((node -> right)->keyLeft) == word ){
            return node;
        }
    }
    
    // Lets go check other nodes 
    if ( word < node -> keyLeft ){
        searchAbove(word,node -> left);
    }
    if ( (word > (node -> keyRight))&&(node->keyRight != "") ){
        searchAbove(word,node->right);
    }
    if ( (word > node -> keyLeft) && ((word < (node -> keyRight))&&(node->keyRight != ""))){
        searchAbove(word,node->mid);
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



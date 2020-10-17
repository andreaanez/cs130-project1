// project1.h

#ifndef PROJECT1_H
#define PROJECT1_H

#include <iostream>
#include <string>

struct TstNode
{
    std::string keyLeft;
    std::string keyRight;
    int countLeft;
    int countRight;
    struct TstNode *left; // showing that these are part of the structure / memory of one node 
    struct TstNode *mid;  // initlaizing a pointer to the middle node (NULL pointer now)
    struct TstNode *right; //  need to set these as NULL when we create a new node 

};

// ** Q : is this how I should be aranging my private and public ?
class Tst 
{
    private:
        TstNode *root;
    public:
        // CONSTRUCTOR 
        Tst();

        // DESTRUCTOR   
        ~Tst(); 
        // helper function for the Destructor  
        void deleteTst(TstNode *root); 

        // SEARCH 
            // can use existing functions from insert and delete 

         // INSERT if already exists increase count to one
        std::string insert (std::string word, TstNode* node); 
            // Need to make a helper finction to convert words to ASCII number vesctors 
            // Function to search through tree looking to see if number exists in the tre
            // pointer to node that prints word and count 
        TstNode* createNode(std::string key);
        


        // DELETE 

        // RANGE SEARCH 
    
    
};
#endif
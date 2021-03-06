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



        // LOOKUP
        void lookup(std::string word);

        void lookupHelp(std::string word, TstNode* node);

            // can use existing functions from insert and delete 

         // INSERT if already exists increase count to one
        void insert (std::string word);
        void insertHelp (std::string word, TstNode *node); 
            // Need to make a helper finction to convert words to ASCII number vesctors 
            // Function to search through tree looking to see if number exists in the tre
            // pointer to node that prints word and count 
        TstNode* createNode(std::string key);
        

        // DELETE 
        void deleteWord (std::string word);
        void deleteHelp (std::string word);
        
        //finds the node 
        TstNode* search(std::string word, TstNode* node );
        // finds the node above the node so we can set the pointer to NULL
        TstNode* searchAbove(std::string word, TstNode* node);

        //finds the node of the sucessor to relpace an element taken from the left side of a node 
        void sucessorRight(std::string word, TstNode* node);
        void sucessorLeft(std:: string word, TstNode* node);

        // a recursive function to search for the left most node 
        TstNode* recursiveLeft(TstNode* node);
        TstNode* recursiveRight(TstNode* node);

        // replacing the element after the sucessosr has been found
        void elementLeft(TstNode* node2, TstNode* node);
        void elementRight(TstNode* node2, TstNode* node);

        //checking to see if the sucessor can be found easily in partially empty nodes
        int checkparLeft(std::string, TstNode* node);
        int checkparRight(std::string, TstNode* node);


        // RANGE SEARCH 
        void range_search(std::string word1, std::string word2);
        void range_searchHelper(std::string word1, std::string word2, TstNode* node);
        
    
};
#endif
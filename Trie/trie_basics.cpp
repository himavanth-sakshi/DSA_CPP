#include<iostream>

using namespace std; 

class TrieNode{
    public: 
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch; 
            for(int i=0; i<26;i++){
                children[i]=NULL;
            }
            isTerminal = false;
        }
};

class Trie{

    public: 
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal =true;
            return;
        }

        //assumption word will be in CAPS
        int index = word[0]-'A'; 
        TrieNode* child; 

        //present
        if(root-> children[index]!= NULL){
            child = root-> children[index];
        }

        else{
            child = new TrieNode(word[0]);
            root-> children[index] = child; 
        }

        //recursion
        insertUtil(child, word.substr(1));
    }


    void insertWord(string word){
        insertUtil(root,word);

    }

    bool searchUtil(TrieNode* root, string word){
        //base case 
        if(word.length()==0){
            return root-> isTerminal;
        }

        int index = word[0]-'A'; 
        TrieNode* child; 

        //present 
        if(root -> children[index]!=NULL){
            child = root-> children[index]; 
        }
        else{//if absent
            return false; 
        }

        //recursion 
        return searchUtil(child, word.substr(1));
    }


    bool search(string word){
        return searchUtil(root, word); 
    }

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++)
            if (node->children[i] != NULL)
                return false;
        return true;
    }
    
    TrieNode* removeUtil(TrieNode* root, string word, int depth = 0) {
        if (!root) return NULL;
    
        // Base case: end of word
        if (depth == word.size()) {
            // Unmark isTerminal
            if (root->isTerminal)
                root->isTerminal = false;
    
            // If node has no children, it can be deleted
            if (isEmpty(root)) {
                delete root;
                return NULL;
            }
    
            return root;
        }
    
        int index = word[depth] - 'A';
        root->children[index] = removeUtil(root->children[index], word, depth + 1);
    
        // After recursion, check if current root is still needed
        if (isEmpty(root) && !root->isTerminal) {
            delete root;
            return NULL;
        }
    
        return root;
    }
    
    // Wrapper function
    void removeWord(string word) {
        root = removeUtil(root, word);
    }
    

};

int main(){

    Trie *t = new Trie(); 
    t -> insertWord("ARM");
    t -> insertWord("DO");
    t -> insertWord("TIME");
    cout<< t -> search("TIME");



    return 0;
}
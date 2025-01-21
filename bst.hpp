//
// Created by skytl on 1/21/25.
//


#ifndef BST_HPP
#define BST_HPP
#include "person.h"


struct Node{
    Person person;
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
};

class BST {
    private:
        struct Node* root;
    public:
        BST() : root(nullptr) {}
        Node* insert(Person person);
        Node* deleteNode(Person person);
        bool search(Person person);
        Node* findNode(Person person);
        int height(Node* node);
        void inorder(Node* node);
        void preorder(Node* node);
        void postorder(Node* node);

};

std::ostream& operator<<(std::ostream& os, const BST& bst);

#endif //BST_HPP

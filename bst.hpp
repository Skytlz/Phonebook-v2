//
// Created by skytl on 1/21/25.
//


#ifndef BST_HPP
#define BST_HPP
#include <utility>

#include "person.h"


struct Node{
    Person person;
    Node* left;
    Node* right;
    //Node() : left(nullptr), right(nullptr) {}
    explicit Node(Person  person) : person(std::move(person)), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        struct Node* root;
        bool allowDuplicates = false;
    public:
        BST() : root(nullptr) {}
        //BST(const BST& other);
        explicit BST(bool allowDuplicates);
        Node* insert(const Person& person) const;
        Node* deleteNode(Person person);
        bool search(Person person);
        Node* findNode(Person person);
        int height(Node* node);
        void inorder(Node* node);
        void preorder(Node* node);
        void postorder(Node* node);

};
Node* insertHelper(const Person &person, const Node* current, bool duplicates);
Node* deleteHelper(Person person, Node* current, Node* previous);
bool searchHelper(Person person, Node* current, Node* previous);

std::ostream& operator<<(std::ostream& os, const BST& bst);

#endif //BST_HPP

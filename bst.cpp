//
// Created by skytl on 1/21/25.
//
#include "bst.hpp"
#include <iostream>

BST::BST(const bool allowDuplicates) {
    root = nullptr;
    this->allowDuplicates = allowDuplicates;
}

Node *insertHelper(const Person &person, Node* current, bool duplicates) {
    if (current == nullptr) {
        return new Node(person);
    }

    if (current->person == person && !duplicates) {
        return current;
    }

    if (current->person < person) {
        current->right = insertHelper(person, current->right, duplicates);
    }else {
        current->left = insertHelper(person, current->left, duplicates);
    }
    return current;
}

Node *BST::insert(const Person& person) const {
    return insertHelper(person, root, allowDuplicates);
}

Node *BST::deleteNode(Person person) {
    return nullptr;
}

bool BST::search(Person person) {
    return false;
}

Node *BST::findNode(Person person) {
    return nullptr;
}

int BST::height(Node *node) {
    if (node == nullptr) return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void BST::inorder(Node *node) {
    if  (node) {
        inorder(node->left);
        std::cout << node->person << std::endl;
        inorder(node->right);
    }
}

void BST::preorder(Node *node) {
    if  (node) {
        std::cout << node->person << std::endl;
        preorder(node->left);
        preorder(node->right);
    }
}

void BST::postorder(Node *node) {
    if  (node) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->person << std::endl;
    }
}


std::ostream& operator<<(std::ostream& os, const BST& bst) {
    os << std::endl;
    return os;
}

//
// Created by skytl on 1/21/25.
//
#include "bst.hpp"
#include <iostream>

Node *BST::insert(Person person) {

}

Node *BST::deleteNode(Person person) {

}

bool BST::search(Person person) {

}

Node *BST::findNode(Person person) {

}

int BST::height(Node *node) {

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

}

//
// Created by skytl on 1/21/25.
//
#include "bst.hpp"
#include <iostream>

BST::BST(const bool allowDuplicates) {
    root = nullptr;
    this->allowDuplicates = allowDuplicates;
}

bool BST::duplicates() const {
    return allowDuplicates;
}

bool BST::insertHelper(const Person &person, Node* current, bool duplicates) {
    if (current == nullptr) {
        return new(std::nothrow) Node(person);
    }

    if (current->person == person && !duplicates) {
        return false;
    }

    if (current->person > person) {
        if (current->left == nullptr) {
            current->left = new(std::nothrow) Node(person);
            return current->left != nullptr;
        }
        return insertHelper(person, current->left, duplicates);
    } else {
        if (current->right == nullptr) {
            current->right = new(std::nothrow) Node(person);
            return current->right != nullptr;
        }
        return insertHelper(person, current->right, duplicates);
    }
}

bool BST::insertPerson(const Person &person) {
    if (root == nullptr) {
        root = new(std::nothrow) Node(person);
        return root != nullptr;
    }
    return insertHelper(person, root, allowDuplicates);
}

Node *BST::deletePerson(const Person& person) const {
    bool deleted = false;
    root = deleteNode(person, root, deleted);
    return deleted;
}


Node *BST::deleteHelper(Node *current){
    current = current->right;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
    return current;
}


Node *BST::deleteNode(Node* current, const Person& person, bool deleted) {
    if (current == nullptr) {
        return nullptr;
    }

    if (current->person > person) {
        root->left = deleteNode(root->left, person);
    } else if (root->person < person) {
        root->right = deleteNode(root->right, person);
    } else {
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        const Node *temp = deleteHelper(root);
        root->person = temp->person;
        root->right = deleteNode(root->right, temp->person);
    }
    return root;
}

Node* BST::searchHelper(Node *current, const Person& person) {
    if (current == nullptr) {
        return nullptr;
    }
    if (current->person > person) {
        return searchHelper(current->left, person);
    }
    if (current->person < person) {
        return searchHelper(current->right, person);
    }
    if (current->person == person) {
        return current;
    }
    return nullptr;
}

bool BST::search(const Person& person) const {
    if (searchHelper(root, person)) {
        return true;
    }
    return false;
}

void BST::findHelper(const Node *current, const std::string& key, const int type, std::vector<Person> &result) {
    switch (type) {
        case 1:
            if (current == nullptr) {
                return;
            } if (current->person.firstname == key) {
                result.push_back(current->person);
            }
            findHelper(current->left, key, type, result);
            findHelper(current->right, key, type, result);
        case 2:
            if (current == nullptr) {
                return;
            } if (current->person.lastname == key) {
                result.push_back(current->person);
            }
        findHelper(current->left, key, type, result);
        findHelper(current->right, key, type, result);
        case 3:
            if (current == nullptr) {
                return;
            } if (current->person.phone == key) {
                result.push_back(current->person);
            }
        findHelper(current->left, key, type, result);
        findHelper(current->right, key, type, result);
        default: ;
    }
}

std::vector<Person> BST::findByFirstname(const std::string& firstname) const {
    std::vector<Person> result;
    findHelper(root, firstname, 1, result);
    return result;
}
std::vector<Person> BST::findByLastname(const std::string& lastname) const {
    std::vector<Person> result;
    findHelper(root, lastname, 2, result);
    return result;
}
std::vector<Person> BST::findByPhone(const std::string& phone) const {
    std::vector<Person> result;
    findHelper(root, phone, 3, result);
    return result;
}

int BST::height(const Node *node) {
    if (node == nullptr) return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void BST::inorder(const Node *node, std::ostream& os) {
    if  (node) {
        inorder(node->left, os);
        os << node->person << std::endl;
        inorder(node->right, os);
    }

}

void BST::preorder(const Node *node, std::ostream& os) {
    if  (node) {
        os << node->person << std::endl;
        preorder(node->left, os);
        preorder(node->right, os);
    }
    os << "END OF TREE";
}

void BST::postorder(const Node *node, std::ostream& os) {
    if  (node) {
        postorder(node->left, os);
        postorder(node->right, os);
        os << node->person << std::endl;
    }
    os << "END OF TREE";
}

int BST::height() const {
    return height(root);
}

void BST::inorder(std::ostream& os) const {
    inorder(root, os);
}

void BST::preorder(std::ostream& os) const {
    preorder(root, os);
}

void BST::postorder(std::ostream& os) const {
    postorder(root, os);
}

std::ostream& operator<<(std::ostream& os, const BST& bst) {
    bst.inorder(os);
    os << "END OF TREE";
    return os;
}

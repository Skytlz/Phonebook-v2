//
// Created by skytl on 1/21/25.
//


#ifndef BST_HPP
#define BST_HPP
#include <utility>
#include <vector>
#include <ostream>

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
        Node* root;
        bool allowDuplicates = true;

        static bool insertHelper(const Person &person, Node* current, bool duplicates);
        static Node* deleteHelper(Node* current);
        static Node* deleteNode(Node* root, const Person& person);
        static Node* searchHelper(Node *current, const Person& person);
        static void findHelper(const Node* current, const std::string& key, int type, std::vector<Person>& result);
        static int height(const Node* node);
        static void inorder(const Node* node, std::ostream& os);
        static void preorder(const Node* node, std::ostream& os);
        static void postorder(const Node* node, std::ostream& os);

    public:
        BST() : root(nullptr) {}
        //BST(const BST& other);
        explicit BST(bool allowDuplicates);
        bool duplicates() const;
        bool insertPerson(const Person& person);
        Node* deletePerson(const Person& person) const;
        bool search(const Person& person) const;
        std::vector<Person> findByFirstname(const std::string& firstname) const;
        std::vector<Person> findByLastname(const std::string& lastname) const;
        std::vector<Person> findByPhone(const std::string& phone) const;
        int height() const;
        void inorder(std::ostream& os) const;
        void preorder(std::ostream& os) const;
        void postorder(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, const BST& bst);

#endif //BST_HPP

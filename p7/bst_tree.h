//
//  bst_tree.h
//sun,yongding
//ysun
#ifndef BST_TREE
#define BST_TREE

#include <string>
#include<vector>
using namespace std;
class Bst_tree
{
private:
    class Node
    {
    public:
        Node(string words)
        {
            m_words = words;
            m_left = NULL;
            m_right = NULL;
        }
        string m_words;
        Node *m_left;
        Node *m_right;
        ~Node()
        {
            delete m_left;
            delete m_right;
        }
    };
    Node *m_root;
    bool insert_p(string words,Node* cur_root);
    int size_p(Node *cur_root);
    bool find_p(string words, Node* cur_root);
    void print_p(Node* cur_root,vector<string> &my_vector);
    double total_distance_p(Node* cur_root,int depth);
    int blanced_p(Node* cur_root,int);
    void rebalance_p(vector<string> &elements,int start, int end);
public:
     Bst_tree();
    ~Bst_tree();
    bool insert(string words);
    int size();
    bool find(string words);
    void print(vector<string> &my_vector);
    void breadth(vector<string> &my_vector);
    double total_distance();
    int blanced();
    void rebalance(vector<string> &elements);
    
};

#endif
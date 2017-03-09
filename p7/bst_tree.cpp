//
//  bst_tree.cpp
//  p7
//
//  Created by SunYongding on 4/22/15.
//  Copyright (c) 2015 SunYongding. All rights reserved.
//

#include "bst_tree.h"
#include<string>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

Bst_tree::Bst_tree()
{
    m_root = NULL;
}
Bst_tree::~Bst_tree()
{
    delete m_root;
}
bool Bst_tree::insert(string words)
{
    if(m_root == NULL)
   {
       m_root = new Node(words);
       return true;
  }
    return insert_p(words,m_root);
}
bool Bst_tree::insert_p(string words, Node *cur_root)
{
    if(cur_root->m_words == words)
    {
        return false;
    }
    if(words < cur_root->m_words)
    {
        if(cur_root->m_left ==NULL)
        {
            cur_root->m_left = new Node(words);
            return true;
        }
        return insert_p(words,cur_root->m_left);
    }
    else
    {
        if(cur_root->m_right == NULL)
        {
            cur_root->m_right = new Node(words);
            return true;
        }
        return insert_p(words,cur_root->m_right);
    }
}
int Bst_tree::size()
{
    return size_p(m_root);
}
int Bst_tree::size_p(Node *cur_root)
{
    if(cur_root == NULL)
    {
        return 0;
    }
    return 1+size_p(cur_root->m_right)+size_p(cur_root->m_left);
}
bool Bst_tree::find(string words)
{
    if(m_root ==NULL)
    {
        return false;
    }
    return find_p(words,m_root);
}
bool Bst_tree::find_p(string words, Node* cur_root)
{
       if(cur_root == NULL)
       {
           return false;
       }
       if(words == cur_root->m_words)
     {
         return true;
      }
   
    if(words < cur_root->m_words)
    {
        return find_p(words,cur_root->m_left);
    }
    return find_p(words,cur_root->m_right);
}
void Bst_tree::print(vector<string> &my_vector)
{
     print_p(m_root,my_vector);
}
void Bst_tree::print_p(Node* cur_root,vector<string> &my_vector)
{
    if(cur_root != NULL)
    {
        print_p(cur_root->m_left, my_vector);
        my_vector.push_back(cur_root->m_words);
        print_p(cur_root->m_right, my_vector);
    }
}
void Bst_tree::breadth(vector<string> &my_v)
{
    Node* cur_root ;
    queue<Node*> my_q;
    if(m_root != NULL)
    {
        my_q.push(m_root);
    }
    while(!my_q.empty())
    {
        cur_root = my_q.front();
        my_q.pop();
        my_v.push_back(cur_root->m_words);
        if(cur_root->m_left != NULL)
        {
            my_q.push(cur_root->m_left);
        }
        if(cur_root->m_right != NULL)
        {
            my_q.push(cur_root->m_right);
        }

        
    }
}

double Bst_tree::total_distance()
{
    return total_distance_p(m_root,0);
}
double Bst_tree::total_distance_p(Node* cur_root, int depth)
{
    if(cur_root == NULL)
    {
        return 0;
    }
    return depth+total_distance_p(cur_root->m_left,depth+1)+total_distance_p(cur_root->m_right,depth+1);
}
int Bst_tree::blanced()
{   if(m_root == NULL)
{
    return 0 ;
}
    return blanced_p(m_root,0);
}
int Bst_tree::blanced_p(Node* cur_root,int height)
{
     if(cur_root ==NULL)
     {
         return height-1;
     }
    int left_height = blanced_p(cur_root->m_left,height+1);
    int right_height = blanced_p(cur_root->m_right,height+1);
    if(left_height == -1 || right_height == -1)
    {
        return -1;
    }
    if((left_height - right_height)==1 || (left_height - right_height)==0 ||(left_height - right_height)==-1 )
    {
        if(left_height>right_height)
        {
            return left_height;
        }
        else
        {
            return right_height;
        }
    }
    else
    {
        
    return -1;
    }
}
void Bst_tree::rebalance(vector<string> &elements)
{
    
    delete m_root;
    m_root = NULL;
    int end =elements.size()-1;
    rebalance_p(elements,0,end);

}
void Bst_tree::rebalance_p(vector<string> &elements, int start, int end)
{
    int middle = (start+end)/2;
    insert(elements[middle]);
    if((end-start)==1)
    {
        
        insert(elements[end]);
      
        
    }
    else if((end -start) ==0)
    {
        insert(elements[start]);
    }
    else
    {
        rebalance_p(elements, middle+1, end);
        rebalance_p(elements, start, middle-1);
    }
    
    
}




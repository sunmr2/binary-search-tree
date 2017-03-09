//main.cpp
//sun,yongding
//ysun

#include<iostream>
#include<string>
#include"bst_tree.h"
#include<vector>
#include<queue>
using namespace std;

int main()
{  string command;
    string words;
    Bst_tree tree;
   while(cin>>command)
   {
       if(command == "echo")
       {
           cin.ignore();
           getline(cin,words);
           cout<<words<<endl;
       }
       else if(command == "insert")
       {
           cin.ignore();
           getline(cin,words);
           if(tree.insert(words) ==false)
           {
               cerr<<"insert <"<<words<<"> failed. String already in tree."<<endl;
           }
                  }
       else if(command == "size")
       {
           int size=0;
           size = tree.size();
           cout<<size<<endl;
       }
       else if(command =="find")
       {
           cin.ignore();
           getline(cin,words);
           if(tree.find(words) ==false)
           {
               cout<<"<"<<words<<">"<<" is not in tree."<<endl;
           }
           else
           {
               cout<<"<"<<words<<">"<<" is in tree."<<endl;
           }

       }
       else if(command =="print")
       {    vector<string> my_vprint;
           tree.print(my_vprint);
           int size = my_vprint.size();
           cout<<"{";
           for(int i = 0;i<size;i++)
           {   if(i == size-1)
            {
                cout<<my_vprint[i];
            }
           else{ cout<<my_vprint[i]<<", ";}
           }
           cout<<"}"<<endl;
       }
       else if(command =="breadth")
       {
           vector<string> my_v;
           tree.breadth(my_v);
           int size =my_v.size();
           cout<<"{";
           for(int i = 0;i<size;i++)
           {   if(i == size-1)
           {
               cout<<my_v[i];
           }
           else{ cout<<my_v[i]<<", ";}
           }

           
           cout<<"}"<<endl;
       }
   
    else if(command == "distance")
    {
        double size = tree.size();
        double total_distance = tree.total_distance();
        double result = total_distance/size;
        cout<<"Average distance of nodes to root = "<<result<<endl;
    }
       else if(command == "balanced")
       {
           if(tree.blanced() == -1)
           {
               cout<<"Tree is not balanced."<<endl;
           }
           else
           {
               cout<<"Tree is balanced."<<endl;
           }
       }
       else if(command == "rebalance")
       {
            vector<string> my_vstore;
            tree.print(my_vstore);
            tree.rebalance(my_vstore);
           
       }
       else
       {
           cerr<<"Illegal command "<<"<"<<command<<">."<<endl;
           getline(cin,command);
         
           
       }
   }
    
    return 0;
}

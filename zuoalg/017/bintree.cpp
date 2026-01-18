#include <iostream>
#include <stack>

using namespace std;
struct Tree
{
    int v;
    Tree* left=nullptr;
    Tree* right=nullptr;

};

void preOrder(Tree*);
void midOrder(Tree*);
void posOrder(Tree*);
int main()
{
    Tree head,left,right;
    head.v=1;
    left.v=2;
    right.v=3;
    head.left=&left;
    head.right=&right;
    preOrder(&head);
    std::cout<<"\n";
    midOrder(&head);
    std::cout<<"\n";
    posOrder(&head);
}

void preOrder(Tree* head)
{
    if(head==nullptr)
        return;
    std::cout<<head->v<<" ";
    preOrder(head->left);
    preOrder(head->right);
}

void midOrder(Tree* head)
{
    if(head==nullptr)
        return;
    midOrder(head->left);
    std::cout<<head->v<<" ";
    midOrder(head->right);
}
void posOrder(Tree* head)
{
    if(head==nullptr)
        return;
    posOrder(head->left);
    posOrder(head->right);
    std::cout<<head->v<<" ";
}


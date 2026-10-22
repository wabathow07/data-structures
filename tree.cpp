/*
binary tree:
- only 2 childs for every other node
- nonempty binary tree has a root node

diff. binary tree/tree: number of child, tree cannot be empty

arithmetic expressions:
- operators (+, -, *, /)
- delimiters: treated as single operands, independant of other expressions
- operands (numbers and variables)
- 1 operator work with 2 operands
- operator priorities

infix form (normal way) of writing an expression -> post/prefix expression forms

postfix: a+b -> ab+; a+b*c -> abc*+; a*b+c -> ab*c+v; (a+b)*(c-d)/(e+f) -> ab+cd-*ef+/
- scan postfic expression from left to right -> push operands onto a stack
- operator -> pop as many operands as the operator need

prefix:

number of nodes and height:
- h <= n <= (2^h) - 1
- log2(n+1) <= h <= n

full binary tree: all nodes has 2 child

node number properties:
- parent node of i is i/2, unless i = 1;
- left child: 2i, unless 2i > n (has no left child);
- right child: 2i+1, unless 2i+1 > n (has no right child);




tree traversal:
- preorder traversal: root -> left -> right
void preOrder (treePointer ptr) {
    if (ptr != nullptr) {
        visit(t);
        preOrder(ptr->leftChild); preOrder(ptr->rightChild);
    }
}

- inorder traversal: left -> root -> right 
void inOrder(treePointer ptr) {
    if (ptr != nullptr) {
        inOrder(ptr->leftChild);
        visit(t);
        inOrder(ptr->rightChild);
    }
}

- postorder traversal: left-> right-> root
void postOrder(treePointer ptr) {
    if (ptr != nullptr) {
        postOrder(ptr->leftChild);
        postOrder(ptr->rightChild);
        visit(t);
    }
}

- levelorder: level 0 -> 1 -> 2 -> 3 -> ...
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct treeNode
{
    char data;
    treeNode *leftC, *rightC;
};

class Tree
{
private:
    treeNode *head;

public:
    Tree() {}

    void inOrder() {
        treeNode* traverse = head;
        while (traverse != nullptr) traverse = traverse->leftC;

        if (traverse != nullptr) {
            cout << traverse.data << " \n";
            tr
        }
    }
};

int main()
{
}
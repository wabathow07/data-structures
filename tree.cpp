/*
binary tree:
- only 2 childs for every other node
- nonempty binary tree has a root node

diff. binary tree/tree: number of child, binary tree can be empty, subtrees of a binary tree are ordered

height = depth = number of levels
node degree = number of children
tree degree = max node degree

number of nodes and height:
- h <= n <= (2^h) - 1
- log2(n+1) <= h <= n

full binary tree: all nodes has 2 child

complete binary tree: a special type of binary tree where all the levels of the tree are filled completely 
except the lowest level nodes which are filled from as left as possible (https://www.programiz.com/dsa/complete-binary-tree)

node number properties:
- parent node of i is i/2, unless i = 1;
- left child: 2i, unless 2i > n (has no left child);
- right child: 2i+1, unless 2i+1 > n (has no right child);

arithmetic expressions:
- operators (+, -, *, /)
- delimiters: treated as single operands, independant of other expressions
- operands (numbers and variables)
- 1 operator work with 2 operands

infix form (normal way) of writing an expression -> post/prefix expression forms

postfix: a+b -> ab+; a+b*c -> abc*+; a*b+c -> ab*c+v; (a+b)*(c-d)/(e+f) -> ab+cd-*ef+/
- scan postfic expression from left to right -> push operands onto a stack
- operator -> pop as many operands as the operator need

prefix: a+b -> +ab; a+b*c -> +*bca; a*b+c -> +*abc; (a+b)*(c-d)/(e+f) -> /*+ab-cd+ef

tree traversal:
- preorder traversal: root -> left -> right
- inorder traversal: left -> root -> right 
- postorder traversal: left-> right-> root
- levelorder: level 0 -> 1 -> 2 -> 3 -> ...
*/

#include <iostream>
#include <queue>
#include<cmath>
using namespace std;

class ArrayTree {
private:
    int capacity;
    char arr[capacity];
    int node;

public:
    ArrayTree(int cap) {capacity = cap; node = 0; for (int i = 1; i <= capacity; i++) arr[i] = '-';}

    void insertNode(char x, int index) {
        if (index == 0) {
            cout << "Invalid index\n"; 
            return;
        }

        if (arr[index] != '-') {
            cout << "Modified node " << index << " to " << x << "\n";
            arr[index] = x;
        }

        arr[index] = x;
        node++;
    }

    int determineHeight() {
        int ans = log2(node + 1);
        double ans1 = log2(node + 1);
        if (ans1 > ans) return ans + 1;
        else return ans;
    }

    void clone(ArrayTree a) {
        for (int i = 1; i <= capacity; i++) {
            a.arr[i] = this->arr[i];
        }
    }

    bool isClone(ArrayTree a) {
        for (int i = 1; i <= capacity; i++) {
            if (a.arr[i] != this.arr[i]) return false;
        }

        return true;
    }

    void display() {
        for (int i = 1; i <= capacity; i++) {
            cout << i << ": " << arr[i] << "\n";
        }
    }
};

struct treeNode
{
    char data;
    treeNode *leftC, *rightC;

    treeNode()
    {
        leftC = nullptr;
        rightC = nullptr;
    }

    treeNode(char a)
    {
        data = a;
        leftC = nullptr;
        rightC = nullptr;
    }
};

int determineHeight(treeNode *node)
{
    if (node == nullptr)
        return 0;

    int leftHeight = determineHeight(node->leftC);
    int rightHeight = determineHeight(node->rightC);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int numberOfNode(treeNode *node)
{
    if (node == nullptr)
        return 0;

    return 1 + numberOfNode(node->leftC) + numberOfNode(node->rightC);
}

class LinkedListTree
{
public:
    treeNode *root;

    LinkedListTree() { root = nullptr; }

    void preOrder(treeNode *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrder(node->leftC);
            preOrder(node->rightC);
        }
    }

    void inOrder(treeNode *node)
    {
        if (node != nullptr)
        {
            inOrder(node->leftC);
            cout << node->data << " ";
            inOrder(node->rightC);
        }
    }

    void postOrder(treeNode *node)
    {
        if (node != nullptr)
        {
            postOrder(node->leftC);
            postOrder(node->rightC);
            cout << node->data << " ";
        }
    }

    void levelOrder(treeNode *node)
    {
        queue<treeNode *> child;
        while (node != nullptr)
        {
            if (node->leftC != nullptr)
                child.push(node->leftC);
            if (node->rightC != nullptr)
                child.push(node->rightC);

            if (child.empty())
                node = nullptr;
            else
            {
                node = child.front();
                child.pop();
                cout << node->data << " ";
            }
        }
    }

    bool isClone(treeNode *root, treeNode *otherRoot)
    {
        if (root == nullptr || otherRoot == nullptr)
            return root == otherRoot;

        return root->data == otherRoot->data && isClone(root->leftC, otherRoot->leftC) && isClone(root->rightC, otherRoot->rightC);
    }

    treeNode *clone(treeNode *node)
    {
        if (node == nullptr)
            return nullptr;

        treeNode *copy = new treeNode;
        copy->data = node->data;
        copy->leftC = clone(node->leftC);
        copy->rightC = clone(node->rightC);

        return copy;
    }

    int determineHeight() { return ::determineHeight(root); }

    int numberOfNode() { return ::numberOfNode(root); } // '::' is for calling global functions (outside the class)
};

int main()
{
    LinkedListTree t0;
    LinkedListTree t1, t2;

    t1.root = new treeNode('/');
    t1.root->leftC = new treeNode('*');
    t1.root->rightC = new treeNode('+');
    t1.root->leftC->leftC = new treeNode('+');
    t1.root->leftC->rightC = new treeNode('-');
    t1.root->leftC->leftC->leftC = new treeNode('a');
    t1.root->leftC->leftC->rightC = new treeNode('b');
    t1.root->leftC->rightC->leftC = new treeNode('c');
    t1.root->leftC->rightC->rightC = new treeNode('d');
    t1.root->rightC->leftC = new treeNode('e');
    t1.root->rightC->rightC = new treeNode('f');

    cout << "Prefix form of the expression: ";
    t1.preOrder(t1.root);
    cout << "\n";
    cout << "Infix form of the expression: ";
    t1.inOrder(t1.root);
    cout << "\n";
    cout << "Postfix form of the expression: ";
    t1.postOrder(t1.root);
    cout << "\n";

    t2.root = t2.clone(t1.root);
    if (t2.isClone(t2.root, t1.root))
        cout << "This tree is a clone of the other tree\n";
    else
        cout << "This tree is not a clone of the other tree\n";

    return 0;
}
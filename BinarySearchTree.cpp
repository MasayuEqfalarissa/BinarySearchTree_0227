#include <iostream>
using namespace std;

class node 
{
public :
    int info;
    node * leftchild;
    node * rightchild;

    node ()
    {
        leftchild = nullptr;
        rightchild = nullptr;
    }

};

class binarytree
{
public :
    node * root;

     binarytree()
    {
        root = nullptr;
    }

    void insert ()
    {
        int x;
        cout << "masukkan nilai: ";
        cin >> x;

        node *newnode = new node();

        newnode->info = x;

        newnode->leftchild = nullptr;
        newnode->rightchild = nullptr;

        node *parent = nullptr;
        node *currentnode = nullptr;
        search(x, parent, currentnode);

        if (parent == nullptr)
        {
            root = newnode;
            return;
        }

        if (x < parent->info)
        {
            parent -> leftchild = newnode;
            return ;
        }

        else if (x > parent -> info)
        {
            parent -> rightchild = newnode;
            return ;
        }
    }

    void search(int element, node *&parent, node *&currentnode)
    {
        currentnode = root;
        parent = nullptr;
        while ((currentnode != nullptr) && (currentnode->info != element))
        {
            parent = currentnode;
            if (element < currentnode->info)
                currentnode = currentnode->leftchild;
            else 
                currentnode = currentnode->rightchild;
        }
    }

    void inorder(node *ptr)
    {
        if (isempty())
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr = nullptr)
        return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }

    void preorder(node *ptr)
    {
        if (isempty())
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr = nullptr)
        return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postorder(node *ptr)
    {
        if (isempty())
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr = nullptr)
        return;

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

    bool isempty()
    {
        return root == nullptr;
    }
    
};

int main ()
{
    binarytree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.root);
            break;
        }
        case '3':
        {

            x.preorder(x.root);
            break;
        }
        case '4':
        {

            x.postorder(x.root);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}
#include<iostream>
#include "node.h"
#include "tool.h"
#include "add.h"
#include "view.h"
#include "delete.h"

int main()
{
    int size,ele;
    Node* root=NULL;

    //size
    std::cout<<"Enter size:\t";
    std::cin>>size;

    //Insert
    for(size_t i{0};i<size;i++)
    {
        std::cout<<"\nEnter element-"<<i+1<<":\t";
        std::cin>>ele;
        root=insert(root,ele);
    std::cout<<"\nhi :\n";
    }

    //View
    view(root);

    //Delete
    std::cout<<"Enter the element to be deleted:\t";
    std::cin>>ele;
    root=del(root,ele);

    in(root);

    return 0;
}
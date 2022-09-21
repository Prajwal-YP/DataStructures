#include<iostream>

struct Graph
{
    int val;
    Graph *down;
    Graph *right;
};

Graph* createGraph(Graph *g,int i)
{
    if(g==NULL)
    {
        g = new Graph();
        g->val=i;
        g->right=NULL;
        g->down=NULL;
    }
    else
    {
        Graph *temp=g;
        while(temp->down!=NULL)
            temp=temp->down;
        Graph *gNew = new Graph();
        gNew->val=i;
        gNew->right=NULL;
        gNew->down=NULL;
        
        temp->down=gNew;
    }
    return g;
}

Graph* connect(Graph *realg,int v1,int v2)
{
    Graph *g=realg;
    while(g->val!=v1)
        g=g->down;
    while(g->right!=NULL)
        g=g->right;
    
    Graph *gNew = new Graph();
    gNew->val=v2;
    gNew->right=NULL;
    gNew->down=NULL;

    g->right=gNew;
    return realg;
}

void printGraph(Graph *g)
{
    Graph *p=g;
    Graph *p1;
    while(p!=NULL)
    {
        std::cout<<std::endl<<p->val<<":\t";

        p1=p->right;
        while(p1!=NULL)
        {
            std::cout<<p1->val<<" -> ";
            p1=p1->right;
        }
        std::cout<<"NULL";

        p=p->down;
    }
}

int main()
{
    Graph *g=NULL;
    int v,e,v1,v2;
    
    //CREATING VERTEX NODES IN GRAPH
    std::cout<<"\nVertex:\t";
    std::cin>>v;
    for(int i=1;i<=v;i++)
    {
        g=createGraph(g,i);
    }


    std::cout<<"Enter number of Edges:\t";
    std::cin>>e;
    for(int i=1;i<=e;i++)
    {
        std::cout<<"\nEDGE-"<<i;
        std::cout<<"\nEnter vertex1 and vertex2:\t";
        std::cin>>v1>>v2;
        g=connect(g,v1,v2);
        g=connect(g,v2,v1);
    }

    //PRINTING
    printGraph(g);

    delete g;
    
    return 0;
}
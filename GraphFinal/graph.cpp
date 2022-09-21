#include<iostream>

struct Node
{
    int data;
    Node *right;
};

struct Graph
{
    int vertex;
    Node *right;
    Graph *down;
};

Graph* createGraph(Graph *g,int vertex)
{
    if(g==NULL)
    {
        g = new Graph();
        g->down = NULL;
        g->right =NULL;
        g->vertex=vertex;
    }
    else
    {
        Graph *p=g;
        while(p->down!=NULL)
           p=p->down;
        Graph *newVertex = new Graph();
        newVertex->down = NULL;
        newVertex->right =NULL;
        newVertex->vertex=vertex;
        p->down=newVertex;
    }
    return g;
}

Node* getNode(int val)
{
    Node *newNode = new Node();
    newNode->data=val;
    newNode->right=NULL;
    return newNode;
}

Graph* connect(Graph *realg,int v1,int v2)
{
    Graph *g=realg;
    Node *p=NULL;
    while(g->vertex!=v1)
        g=g->down;
    p=g->right;
    
    Node *newNode = getNode(v2);
    
    if(p==NULL)
    {
        g->right=newNode;
    }
    else
    {
        while(p->right!=NULL) 
            p=p->right;
        p->right=newNode;
    }
    return realg;
}

void printGraph(Graph *g)
{
    Graph *p=g;
    Node *p1;
    while(p!=NULL)
    {
        std::cout<<std::endl<<p->vertex<<":\t";

        p1=p->right;
        while(p1!=NULL)
        {
            std::cout<<p1->data<<" -> ";
            p1=p1->right;
        }
        std::cout<<"NULL";

        p=p->down;
    }
}

// B F S
struct Queue
{
    Node *front;
    Node *rear;
};

int isEmpty(Queue *q)
{
    if(q->front==NULL)
        return 1;
    else
        return 0;
}

int isPresent(Queue *q,int val)
{
    Node *p=q->front;
    while(p!=NULL)
    {
        if(p->data==val)
            return 1;
        p=p->right;
    }
    return 0;
}

Queue* enqueue(Queue *q,int val)
{
    if( (q->front==NULL) && (q->rear==NULL) )
    {
        q->rear = getNode(val);
        q->front =q->rear;
        return q;
    }

    Node* newNode=getNode(val);
    q->rear->right=newNode;
    q->rear=newNode;
    return q;
}

Queue* dequeue(Queue *q)
{
    if(q->front==NULL)
        return q;
    
    Node *p = q->front;
    q->front = p->right;
    delete p;
    if(q->front==NULL)
        q->rear=NULL;
    return q;
}

void disp(Queue* p)
{
    Node *node=p->front;
    std::cout<<std::endl;
    while(node != NULL)
    {
        std::cout<<node->data<<" -> ";
        node=node->right;
    }
}

Node* getAjacentVertices(Graph *g,int val)
{
    while(g->vertex!=val)
        g=g->down;
    return g->right;
}

void bfs(Graph *g)
{
    Node *node=NULL;
    Queue *visited = new Queue();
    Queue *buffer = new Queue();

    visited->front = visited->rear=NULL;
    buffer->front = buffer->rear=NULL;
    buffer=enqueue(buffer,g->vertex);

    while(!isEmpty(buffer))
    {
        node = getAjacentVertices(g,buffer->front->data);
        while(node!=NULL)
        {
            if( (!isPresent(visited,node->data)) && (!isPresent(buffer,node->data)))
                buffer=enqueue(buffer,node->data);
            node=node->right;
        }
        int val{buffer->front->data};
        visited=enqueue(visited,val);
        buffer=dequeue(buffer);
    }

    disp(visited);
}

int main()
{
    int v,e,v1,v2;
    Graph *g=NULL;

    // CREATE VERTICES
    std::cout<<"\nEnter the number of vertices:\t";
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

    //ADJACENCY MATRIX
    printGraph(g);

    // BFS- Breadth First Search
    std::cout<<"\n\nBreadth First Search";
    std::cout<<"\n--------------------\n";
    bfs(g);

    delete g;

    return 0;
}
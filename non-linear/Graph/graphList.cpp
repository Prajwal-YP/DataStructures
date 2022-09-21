#include<iostream>
#define V 4

struct Node
{
    int vertex;
    Node *next;
};

Node* createNode(int v)
{
    Node* newNode = new Node();
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
};

struct Graph
{
    int numVertices;
    Node** adjLists;
};

Graph* createGraph(int vertices)
{
    Graph *graph =new Graph();

    graph->numVertices = vertices;
    graph->adjLists = new Node*();
    
    for(size_t i{0};i<vertices;i++)
        graph->adjLists[i]=NULL;

    return graph;
}

// Add Edges
void addEdges(Graph* Graph, int s, int d)
{
    // Add edges from s to d
        Node* newNode = new Node();
        newNode->next=Graph->adjLists[s];
        Graph->adjLists[d]=newNode;
        newNode=createNode(s);
}

void printGraph(Graph *graph)
{
    for(int v{0};v<graph->numVertices;v++)
    {
        Node* temp = graph ->adjLists[v];
        std::cout<<std::endl<<"Vertex-"<<v<<":\t";
        // printf("\nVertex-%d:\t",v);
        while(temp)
        {
            std::cout<<temp->vertex<<" -> ";
            // printf("%d ->",temp->vertex);
            temp=temp->next;
        }
        std::cout<<std::endl;
        // printf("\n");
    }
}



int main()
{
    Graph *graph=createGraph(4);

    addEdges(graph,0,1);
    addEdges(graph,0,2);
    addEdges(graph,0,3);
    addEdges(graph,1,2);

    printGraph(graph);

    return 0;
}
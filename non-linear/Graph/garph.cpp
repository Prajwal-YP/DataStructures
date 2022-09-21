#include<iostream>
#define V 4

//initialise adjacency matrix
void init(int a[][V])
{
    for(size_t i{0};i<V;i++)
        for(size_t j{0};j<V;j++)
            a[i][j]=0;
}

//connect edges
void addEdge(int a[][V], int i,int j)
{
    a[i][j] = a[j][i] = 1;
}

void printMatrix(int a[][V])
{
    for(size_t i{0};i<V;i++)
    {
        std::cout<<std::endl<<i<<": ";
        for(size_t j{0};j<V;j++)
            std::cout<<a[i][j]<<" ";
    }
}

int main()
{
    int a[V][V];
    init(a);

    addEdge(a,0,1);
    addEdge(a,0,2);
    addEdge(a,1,2);
    addEdge(a,2,3);
    
    printMatrix(a);

    return 0;
}
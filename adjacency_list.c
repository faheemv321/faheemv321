#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct graph
{
    int numberOfVertices;
    int numberOfEdges;
    struct node **adjacencyList;
};

struct node *createNode(int vertex)
{
    struct node *v = (struct node *)malloc(sizeof(struct node));
    v->vertex = vertex;
    v->next = NULL;
    return v;
}

void addDirectedEdge(int source, int destination, struct graph *g)
{
    struct node *p = g->adjacencyList[source - 1];
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = g->adjacencyList[destination - 1];
}

void addUndirectedEdge(int source, int destination, struct graph *g)
{
    addDirectedEdge(source, destination, g);
    addDirectedEdge(destination, source, g);
}

void printGraph(struct graph *g)
{
    // print graph

    struct node* p;

    for (int i = 0; i < g->numberOfVertices; i++)
    {
        p= g->adjacencyList[i];
        printf("%d->", i+1);
        while(p->next !=NULL){
            printf(" %d", p->next->vertex);
            p=p->next;
        }
    }
}

struct graph *createGraph(int numberOfVertices, int numberOfEdges)
{
    struct node *t;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->adjacencyList = (struct node **)malloc(numberOfVertices * sizeof(struct node *));
    int source, destination;

    for (int i = 0; i < numberOfVertices; i++) // initialization for n nodes
    {
        t = createNode(i + 1);
        g->adjacencyList[i] = t;
    }
    for (int i = 0; i < numberOfEdges; i++)
    {
        printf("enter souce vertex, destination vertex ");
        scanf("%d %d", &source, &destination);
        addUndirectedEdge(source, destination, g);
    }
    
}

int main()
{

    int n, e;
    struct graph *g;
    printf("enter number of nodes ");
    scanf("%d", &n);
    printf("enter number of edges ");
    scanf("%d", &e);
    g = createGraph(n, e);
    printGraph(g);
    return 0;
}
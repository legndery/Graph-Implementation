#ifndef GRAPH_IMPLEMENTATION
#define GRAPH_IMPLEMENTATiON
typedef struct GraphStruct{
	int vertex_number;
	struct VertexRootStruct *vertices;
} Graph;
typedef struct VertexRootStruct{
	int visited;
	int name;
	struct EdgeStruct *edges;
} Vertex_root;
typedef struct VertexStruct{
	int name;
	int weight;
} Vertex;
typedef struct EdgeStruct{
	struct VertexStruct vertx;
	struct EdgeStruct *next;

} Edge;

Graph *create_adj_list(int v);
void print_graph(Graph *graphModel);
#endif

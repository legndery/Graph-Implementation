#ifndef GRAPH_IMPLEMENTATION
#define GRAPH_IMPLEMENTATiON
typedef struct GraphStruct{
	int vertex_number;
	struct VertexRootStruct **vertices;
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
	struct VertexRootStruct *vertx;
	int weight;
	struct EdgeStruct *next;

} Edge;

Graph *create_adj_list(int v);
void print_graph(Graph *graphModel);
int *get_edge_list(int k, int *out_counter,int v);
#endif

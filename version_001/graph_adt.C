#include<stdio.h>
#include<stdlib.h>
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

Graph *create_adj_list();
void print_graph(Graph *graphModel);
int main(){

	Graph *graphmodel = create_adj_list();
	printf("\n%d", graphmodel->vertex_number);
	print_graph(graphmodel);
	return 0;
}

Graph *create_adj_list(){
	int i,j,v;
	char ch='y';
	Graph *graphModel=(Graph *)malloc(sizeof(Graph));//the whole graph like a wrapper
	Vertex *vert;//the number of vertices
	Edge *tempEdge;
	//Vertex_root *vertices;//the vertex lists
	
	printf("\nEnter the Number of Vertex:");fflush(stdout);
	scanf("%d", &v);
	vert = (Vertex *)malloc(v*sizeof(Vertex));
	graphModel->vertices = (Vertex_root *)malloc(v*sizeof(Vertex_root));
	graphModel->vertex_number = v;
	/*make vertex objects
	for(i=0;i<v;i++){
		vert[i].name = i;
	}
	//--done*/
	for(i =0;i<v;i++){
	//initalize the graph model
	graphModel->vertices[i].name = i;
	graphModel->vertices[i].edges= NULL;
	graphModel->vertices[i].visited = 0;
		for(j=0;j<v;j++){
			if(j!=i){
				/*printf("Is there an Edge from %d to %d?(y/n):", (i+1), (j+1));
				scanf("%c\n", &ch);*/
				//DEBUG DEBUG DEBUG
				if(ch == 'Y' || ch == 'y'){
					if(graphModel->vertices[i].edges == NULL){//first edge
						//make vertex object
						vert = (Vertex *)malloc(sizeof(Vertex));
						vert->name = j;vert->weight=1;
						//--done
						tempEdge = (Edge *)malloc(sizeof(Edge));
						tempEdge->vertx = *vert;
						tempEdge->next = NULL;
						graphModel->vertices[i].edges = tempEdge;
					}else{
						vert = (Vertex *)malloc(sizeof(Vertex));
						vert->name = j;vert->weight=1;
						//--done
						//not the first edge;						
						Edge *localTemp=graphModel->vertices[i].edges;
						while(localTemp->next != NULL){
							localTemp = localTemp->next;
						
						}
						tempEdge = (Edge *)malloc(sizeof(Edge));
						tempEdge->vertx = *vert;
						tempEdge->next = NULL;
						localTemp->next = tempEdge;

					}
				}
			}
		}
	}

	return graphModel;
}

void print_graph(Graph *graphModel){
	int i;
	printf("%d", graphModel->vertex_number);
	for(i=0;i<(graphModel->vertex_number);i++){
		printf("\n%d", graphModel->vertices[i].name);
		printf("-->");
		Edge *tempE = graphModel->vertices[i].edges;
		if(tempE != NULL){
			while(tempE != NULL){
				printf("| %d | ",tempE->vertx.name);
				tempE = tempE->next;
			}
			printf("\n");
		}else{
			printf("None\n");
		}


	}	
}

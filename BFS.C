#include<stdio.h>
#include<stdlib.h>
#include "graph_adt.h"



Vertex_root **BFS_algo(Graph *graphModel, Vertex_root *start){

	int curr_vertex = start->name,j=0;
	Vertex_root *current = start;
	int vertex_num = graphModel->vertex_number;
	Vertex_root **visited = (Vertex_root **)malloc(vertex_num*sizeof(Vertex_root));
	Vertex_root **queue   = (Vertex_root **)malloc(vertex_num*sizeof(Vertex_root));
	for(int i=0;i<vertex_num;i++){
		visited[i] = NULL;
		queue[i] = NULL;
	}
	Edge *tempEdge;
	visited[j] = current;
	enqueue(queue, vertex_num, current);

	while(queue[0] != NULL){
	
		tempEdge = queue[0]->edges;
			
		while(tempEdge != NULL){
			current = tempEdge->vertx;

			if(!is_Visited(visited, current)){
				//printf("--%d--\n", current->name);
				visited[++j] = current;
				enqueue(queue, vertex_num, current);
			}
			tempEdge= tempEdge->next;
		}
		dequeue(queue, vertex_num);
	}

	//printf("I am returning successfully\n");
	return visited;

}

int main(){
	int v=5,s=2;
	int max = v;
	printf("\n Enter How many Vertex:");
	scanf("%d", &v);
	printf("\n Enter Starting Point:");
	scanf("%d", &s);
	Graph *graphModel = create_adj_list(v);
	Vertex_root *start = search_vertex(graphModel,s);
	Vertex_root **bfs = BFS_algo(graphModel, start);

	printf("\n");
	for(int i=0;i<graphModel->vertex_number;i++){
		printf("%d ", bfs[i]->name+1);
	}
	
	printf("\n");	
	print_graph(graphModel);
return 0;
}

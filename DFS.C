#include<stdio.h>
#include<stdlib.h>
#include "graph_adt.h"
int j=0;
void DFS_visit(Vertex_root *start, Vertex_root **visited){
	Edge *tempEdge;
	if(start !=NULL){
		if(!is_Visited(visited, start)){
			visited[j++] = start;
			tempEdge = start->edges;
			while(tempEdge != NULL){
				DFS_visit(tempEdge->vertx, visited);
				tempEdge= tempEdge->next;
			}	
		}
	}
	return;
}


Vertex_root **DFS_algo(Graph *graphModel){
	
	Vertex_root **visited = (Vertex_root **)malloc((graphModel->vertex_number)*sizeof(Vertex_root));

	for(int i=0;i<graphModel->vertex_number;i++){
		if(!is_Visited(visited, graphModel->vertices[i])){
			DFS_visit(graphModel->vertices[i], visited);
		}
	}
	return visited;

}
int main(){
	int v,s;
	printf("\nEnter Number of Vertex:");
	scanf("%d", &v);
	printf("\nEnter the starting Point:");
	scanf("%d", &s);
	Graph *graphModel = create_adj_list(v);
	Vertex_root **visited = DFS_algo(graphModel);
	printf("line 40, %d\n",j);
	for(int i=0;i<j;i++){
		printf("%d ", visited[i]->name+1);fflush(stdout);
	}
	printf("\n");

return 0;
}

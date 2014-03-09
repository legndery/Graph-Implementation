#include<stdio.h>
#include<stdlib.h>
#include "graph_adt.h"

void DFS_visit(Vertex_root *start, Vertex_root **visited, int j){
	if(start->edges != NULL){
		visited[j] = start;
	}
}


Vertex_root **DFS_algo(Graph *graphModel){
	
	Vertex_root **visited = (Vertex_root **)malloc(graphModel->vertex_number*sizeof(Vertex_root));

	for(int i=0;i<graphModel->vertex_number;i++){
		if(!is_Visited(visited, graphModel->vertices[i])){
			DFS_visit(graphModel->vertices[i], visited);
		}
	}

}
int main(){



}

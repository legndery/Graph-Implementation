#include<stdio.h>
#include<stdlib.h>
#include "graph_adt.h"
//queue Implementation
Vertex_root *search_vertex(Graph *graphModel, int needle){
	for(int i=0;i<graphModel->vertex_number;i++){
		if(graphModel->vertices[i].name == needle){
			return &(graphModel->vertices[i]);
		}
	}
	return NULL;
}
int main(){
	int v=5;
	int max = v;
	int flag=1;
	Graph *graphModel = create_adj_list(v);
	int queue[graphModel->vertex_number];
	Vertex_root *current = search_vertex(graphModel, 0);
	while(flag){
		if(graphModel->vertices[i].visited != 0){
			
		}
	}
	


	print_graph(graphModel);

return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include "graph_adt.h"



void relaxation(Vertex_root *u, Vertex_root *v, int w){

	//printf("-- (%d,%d,%d) ",u->name+1, v->name+1, v->shortest_path_estimate);
	if(v->shortest_path_estimate > u->shortest_path_estimate + weightGet(u,v)){
		 
		v->shortest_path_estimate = u->shortest_path_estimate+ weightGet(u,v);
		v->predecessor = u;
		//printf(" (%d,%d)--\n",v->name+1, v->shortest_path_estimate);
	}
}

int Bella_Ford(Graph *graphModel, Vertex_root *start){
	//initialize the start shortest path

	start->shortest_path_estimate = 0;
	for(int j=0;j<graphModel->vertex_number;j++){
		for(int i=0;i<graphModel->vertex_number;i++){
			Edge *tempE = graphModel->vertices[i]->edges;
			while(tempE != NULL){
				//printf("in while loop %d\n",i);
				relaxation(graphModel->vertices[i], tempE->vertx, tempE->weight);
				tempE = tempE->next;
			}
		}
	}
	/*for(int i=0;i<graphModel->vertex_number;i++){
		printf("(%d,%d) ", graphModel->vertices[i]->name+1,graphModel->vertices[i]->shortest_path_estimate); 
	}*/
	for(int i=0;i<graphModel->vertex_number;i++){
		Edge *tempE = graphModel->vertices[i]->edges;
		while(tempE != NULL){
			if(tempE->vertx->shortest_path_estimate > (graphModel->vertices[i]->shortest_path_estimate + tempE->weight)){
				return 0;
			}
			tempE=tempE->next;
		}
	}
	return 1;
}
int main(){
	int v,s;
	printf("\nHow many vertex?");
	scanf("%d", &v);
	printf("Where to start:");
	scanf("%d", &s);
	Graph *graphModel = create_adj_list(v);
	Vertex_root *start = search_vertex(graphModel, s);
	if(!Bella_Ford(graphModel, start)){
		printf("\nThere exist a negative cycle");
	}
	for(int i=0;i<graphModel->vertex_number;i++){
		if(graphModel->vertices[i]->predecessor != NULL){
		printf("\n%d:%d:%d\n", graphModel->vertices[i]->name, graphModel->vertices[i]->predecessor->name,graphModel->vertices[i]->shortest_path_estimate);
		}else{
		printf("\n%d:start:0\n", graphModel->vertices[i]->name);
		}
	}

return 0;
}

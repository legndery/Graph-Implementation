#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "graph_adt.h" 

Vertex_root *search_vertex(Graph *graphModel, int needle){
	for(int i=0;i<graphModel->vertex_number;i++){
		if(graphModel->vertices[i]->name == needle){
			return graphModel->vertices[i];
		}
	}
	return NULL;
}
int is_Visited(Vertex_root **visited, Vertex_root *needle){
	int i=0;
	while(visited[i] != NULL){
		if(visited[i] == needle){
			return 1;
		}
		i++;
	}
	return 0;
}
void enqueue(Vertex_root **queue, int v, Vertex_root *value){
	int i=0;
	for(i=0;i<v;i++){
		if(queue[i] == NULL){
			break;
		}
	}
	if(i==v){
		printf("Cannot Enqueuw, Queue Full");
		return;
	}
	queue[i] = value;

}
Vertex_root *dequeue(Vertex_root **queue, int v){
	Vertex_root *returnVal;
	if(queue[0] == NULL){
		printf("Queue Empty");
		return NULL;
	}else{
		returnVal = queue[0];
		for(int i=0;i<v;i++){
			if(queue[i] != NULL){
				queue[i] = queue[i+1];
			}
		}
		return returnVal;
	}

}
int *get_edge_list(int k,int *out_counter, int v){
	int d,temp=0,j=0,edges=0,isCorrect=0,i=0;
	int *result;
	char *str=(char *)malloc(80*sizeof(char));
	printf("Enter the Edges from vertex %d separated by comma:",(k+1));
	scanf("%s", str);
//	puts(str);
	///////////////////////////////////////
	int flag=0;
	for(i=0;i<strlen(str);i++){
		if(str[i] ==','&& !flag){
			flag=0;
		}else if(str[i] !=',' && !flag){
			flag=1;
		}
		if(str[i] == ',' && flag){
			edges++;
		}
	}
	edges++;
	printf("Edges %d\n", edges);
	//////////////////////////////////
	result = (int *)malloc(edges*sizeof(int));
	*out_counter = edges;
	while(!isCorrect){
		for(i=0;i<strlen(str);i++){
			if(str[i]!= ' '){
				if(str[i] == ','&& temp){
					if(temp <=v && temp >0){
						result[j++] = temp-1;
					}else{	
						printf("Invalid Edge, Start from the top");
						break;
					}
					temp=0;
				}else{
					temp = temp*10+str[i]-'0';
				}
			}
		}
			
		
		if(temp){
			result[j++] = temp-1;
		}
		/*for(int i=0;i<edges;i++){
			printf("%d ", result[i]);
		}*/
		isCorrect = 1;
	}
	//printf("I am returning\n");
	return result;
}



Graph *create_adj_list(int v){
	int i,j;
	char ch='y';
	Graph *graphModel=(Graph *)malloc(sizeof(Graph));//the whole graph like a wrapper
	Vertex *vert;//the number of vertices
	Edge *tempEdge;
	//Vertex_root *vertices;//the vertex lists
	vert = (Vertex *)malloc(v*sizeof(Vertex));//NOT GONNA NEED IT!
	graphModel->vertices = (Vertex_root **)malloc(v*sizeof(Vertex_root));
	graphModel->vertex_number = v;
	//*init and make vertex objects
	for(i=0;i<v;i++){
		graphModel->vertices[i] = (Vertex_root *)malloc(sizeof(Vertex_root));
		graphModel->vertices[i]->name = i;
		graphModel->vertices[i]->edges = NULL;
		graphModel->vertices[i]->visited = 0;
	}
	//--done*/
	for(i =0;i<v;i++){
		int edgeCounter,k;
		int *edges_exist = get_edge_list(i, &edgeCounter, v);
		/*for(int l=0;l<edgeCounter;l++){
			printf("%d ", edges_exist[l]);
		}*/
		//printf("%d edges\n", edgeCounter);
		for(j=0;j<edgeCounter;j++){
			k = edges_exist[j];
			//printf("is it here?");
			if(graphModel->vertices[i]->edges == NULL){//first edge
				//printf("--%d,%d---\n", j,k);	
					tempEdge = (Edge *)malloc(sizeof(Edge));
					tempEdge->vertx = (graphModel->vertices[k]);
					tempEdge->next = NULL;
					tempEdge->weight = 1;
					graphModel->vertices[i]->edges = tempEdge;
				}else{
					
					//not the first edge;	
					//printf("--%d, %d, %d--\n", j,k,i);
					Edge *localTemp=graphModel->vertices[i]->edges;
					while(localTemp->next != NULL){
						localTemp = localTemp->next;
					
					}
					//printf("--%d, %d, %d--\n", j,k,i);
					tempEdge = (Edge *)malloc(sizeof(Edge));
					tempEdge->vertx =(graphModel->vertices[k]);
					tempEdge->next = NULL;
					tempEdge->weight = 1;
					localTemp->next = tempEdge;
				}
		}
		free(edges_exist);
		/*///////////////////
		for(j=0;j<v;j++){
			if(j!=i){
				printf("Is there an Edge from %d to %d?(y/n):", (i+1), (j+1));
				fflush(stdout);
				scanf("%c\n", &ch);
				getchar();
				get_edge_list(j, 0);
				//DEBUG DEBUG DEBUG
				
				if(ch == 'Y' || ch == 'y'){
					if(graphModel->vertices[i]->edges == NULL){//first edge
					printf("--%d---\n", j);	
						tempEdge = (Edge *)malloc(sizeof(Edge));
						tempEdge->vertx = (graphModel->vertices[j]);
						tempEdge->next = NULL;
						tempEdge->weight = 1;
						graphModel->vertices[i]->edges = tempEdge;
					}else{
						
						//not the first edge;						
						Edge *localTemp=graphModel->vertices[i]->edges;
						while(localTemp->next != NULL){
							localTemp = localTemp->next;
						
						}
						tempEdge = (Edge *)malloc(sizeof(Edge));
						tempEdge->vertx =(graphModel->vertices[j]);
						tempEdge->next = NULL;
						tempEdge->weight = 1;
						localTemp->next = tempEdge;

					}
				}
			}
		}*/
	}

	return graphModel;
}

void print_graph(Graph *graphModel){
	int i;
	printf("%d", graphModel->vertex_number);
	for(i=0;i<(graphModel->vertex_number);i++){
		printf("\n%d", graphModel->vertices[i]->name+1);
		printf("-->");
		Edge *tempE = graphModel->vertices[i]->edges;
		if(tempE != NULL){
			while(tempE != NULL){
				printf("| %d | ",tempE->vertx->name+1);
				tempE = tempE->next;
			}
			printf("\n");
		}else{
			printf("None\n");
		}


	}	
}

#include<stdio.h>
#include<stdlib.h>
#include "graph_adt.h"


int main(){
	Graph *graphModel = create_adj_list(5);
	print_graph(graphModel);

return 0;
}

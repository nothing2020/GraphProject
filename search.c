#define INF 1000000
#define MAXSIZE 500000

typedef struct Node_dfs{
	int no;
	int weight;
	struct Node_dfs*next;
}AdjNode;


typedef struct Node_bfs{
    int no;
	int pre;	
}QUENode;
AdjNode* Graph[MAXSIZE];

int* shortestPath(int u, int v, char algorithm[], char name[])
{
    int* path;
	AdjNode* node;
	for(int i = 0; i < MAXSIZE; i++){
		Graph[i] = NULL;
	}
	FILE* fp = fopen(name, "rb");
	if(fp == NULL){
		printf("open fail\n");
		exit(1);
	}
	
	if( *algorithm == 'D'&&*(algorithm+1) == 'F'){
		int u1, v1, weight1;
    	while(!feof(fp)){
		fscanf(fp, "%d%d%d", &u1, &v1, &weight1);//构建邻接表 
		node = (Adj*)malloc(sizeof(Adj));
		node->data = v1;
		node->weight = weight1;
        node->next = G[u1];
        Grapph[u1] = no;
      	}
	}
		
	else if(*algorithm == 'B'){
		path = BFS(u, v);
	}
	else
	path = int* Dijkstra(int u, int v);
	fclose(fp);
	return path;
} 

int* DFS(int u, int v)
{
	AdjNode *p_dfs;
	int* st = (int*)malloc(MAXSIZE*sizeof(int));
	char* visited_dfs = (char*)malloc(MAXSIZE*sizeof(char));
	int i;
	//访问数组初始化
	for(i = 0; i < MAXSIZE; i++){
		visited_dfs[i] = 0;
	}
	
	int top = -1;
	top++;
	st[top] = u;
	visited_dfs[u] = 1;
	
	int process_point; 
	while(top != -1) {
		process_point = st[top];
		if(process_point == v){
			break;
		}
		p_dfs = Graph[process_point];
		while(p_dfs!= NULL){
			if(visited_dfs[p_dfs->no] == 0){
				top++;
				st[top] = p_dfs->no;
				visited_dfs[p_dfs->no] = 1;
				break;
			}
			p_dfs = p_dfs->next;
		}
		if(p_dfs == NULL){
			top--;
		}
	}
	int *path = (int*)malloc(MAXSIZE*sizeof(int)); 
	int k = top;
	for(i = top; i > 0; i--) {
		path[st[i]] = st[i-1];
	}
	
	path[st[0]] = -1;
	return path;
}

int* BFS(int u, int v)
{
	Adj *p_bfs;
	int *path = (int*)malloc(MAXSIZE*sizeof(int));
	
	QUENode *qu = (QUEUNode*)malloc(MAXSIZE*sizeof(QUENode));
	int front = -1, rear = -1;
	
	int *visited_bfs = (int*)malloc(MAXSIZE*sizeof(int));
	int i;
	for(i = 0; i < MAXSIZE; i++){//初始化 
		visited_bfs[i] = INF;
	}
	
	rear++;
	qu[rear].data = u;
	visited_bfs[u] = 0;
	path[u] = -1;
	int process_point; 
	while(front != rear){
		front++;
		process_point = qu[front].data;
		p = G[process_point];
		while(p_bfs != NULL){
			if(dist[process_point] + p_bfs->weight < dist[p_bfs->data]){
				int find;
				int flag = 0; 
				for(find = front+1; find <= rear; find++){
					if(qu[find].no == p_bfs->no){
						flag = 1;
						break;
					}
				}
				if(flag == 1){
					break;
				} 
				else{
					rear++;
					qu[rear].no = p->no;
					visited_bfs[p->no] = dist[process_point] + p_bfs->weight;
					path[p_bfs->no] = process_point;
				}
			}
			p_bfs = p_bfs->next;
		}
	}
	return path;
}
int* Dijkstra(int u, int v){
	
	
}

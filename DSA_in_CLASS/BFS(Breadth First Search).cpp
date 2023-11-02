#include<iostream>
using namespace std;

void enqueue(int* queue, int & rear, int vertex){
	queue[rear++] = vertex;
}

int dequeue(int*queue, int& front){
	return queue[front++];
}

void bfsofgraph(int v, int**adjlist){
	int*visited = new int [v];
	for(int i=0; i<v; i++){
		visited[i]=0;
	}
	int*queue=new int[v];
	int front=0, rear=0;
	
	int startvertex = 0;
	enqueue(queue, rear, startvertex);
	visited[startvertex]=1;
	
	while(front<rear){
		int currvertex=dequeue(queue, front);
		
		cout<<currvertex<<" ";
		
		for(int i=0; i<v; i++){
			if(adjlist[currvertex][i] == 1 && visited[i]==0){
			enqueue(queue, rear, i);
			visited[i] = 1;
			}
		}
	}
	delete[] visited;
	delete[] queue;
}

int main(){
	int v, e;
	cin>>v>>e;
	
	int** adjlist = new int*[v];
	for(int i=0; i<v;i++){
		adjlist[i]=new int[v];
		for(int j=0; j<v;j++){
			adjlist[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adjlist[u][v] = 1;
	}
	
	bfsofgraph(v,adjlist);
	for(int i=0; i<v; i++){
		delete[] adjlist[i];
	}
	delete[] adjlist;
	
  return 0;
}

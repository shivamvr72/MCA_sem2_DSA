#include <stdio.h>
#include <stdlib.h>
#define maxq 100

typedef struct node{
    int data;
    struct node *next;
}node; 

node *head=NULL, *newnode=NULL, *temp=NULL, *tail=NULL;
node *create(int val){
    // node *newnode = NULL;
    newnode = (node *) malloc(sizeof(node));
    if(newnode == NULL){
        printf("malloc error \n");
        exit(0);
    }else{
        newnode->next = NULL;
        newnode->data = val;
        return newnode;
    }
}


void createGraph(int nodes, node **adj, int (*adjmax)[nodes]){
    int nb=0, val=0;
    for(int i=0; i<nodes; i++){
        tail = NULL;
        printf("Enter No of Neighbor Vertices %d : ", i);
        scanf("%d", &nb);
        if(nb>nodes){
            printf("\nNeighbour vertex are greater than entered total vertex !\n");
            return;
        }
        for(int j=0; j<nb; j++){
            printf("Enter Neighbor for %d to %d : ", i, j );
            scanf("%d", &val);
            //adj
            adjmax[i][val] = 1;
            //adj list 
            newnode = create(val);
            if(adj[i] == NULL)
                adj[i] = newnode;
                // head = newnode;
            else
                tail->next = newnode;
            tail = newnode; 
        }
    }
}

void displayGraph(int n_vtx,node **adj, int (*adjmat)[n_vtx]){
    printf("\ndisplaying adj list...\n");
    for(int i=0; i<n_vtx; i++){
        temp = adj[i];
        printf("neighbour of vertex %d : ",  i);
        while(temp!= NULL){
            printf(" %d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\ndisplaying adj matrix... \n");
    for(int i=0; i<n_vtx; i++){
        for(int j=0; j<n_vtx; j++){
            printf(" %d ", adjmat[i][j]);
        }
        printf("\n");
    }
}


void Degree(int n_vtx,node **adj){
    int i=0, outCnt=0;
    for(;i<n_vtx;i++){
        outCnt=0;
        temp = adj[i];
        while(temp!=NULL){
            temp =temp->next;
            outCnt++;
        }
        printf("Degree %d : %d\n", i,outCnt);
    }
    printf("\n");
}




//queue oprations
int front = -1 , rear = -1;
int queue[maxq];

void enq(int q){
    if(rear == maxq-1){
        printf("Q is full\n");
        exit(1);
    }
    if(front == -1)
        front+=1;
    rear+=1;
    queue[rear] = q;
}
int dQ(){
    int dqval = queue[front];
    if(front == -1 || front>rear){
        printf("\nQ is empty\n");
        exit(0);
    }
    if(front == rear){
        front = rear = -1;
    }
    front+=1;
    return dqval;
}
//queue is over 



//bfs code for matrix 
void bfsMatrix(int s, int n_vtx, int *visited , int (*adjmat)[n_vtx]){
    //using matrix
    printf("%d ", s);
    enq(s);
    visited[s] = 1;
    int x;
    while(rear != front){
        x = dQ();
        // printf(" %d ", x);
        for(int i=0; i<n_vtx; i++){
            if(adjmat[x][i]== 1 && visited[i]==0){
                printf("%d ", i);
                enq(i);
                visited[i] = 1;
            }
        }
    }
}
//bfs using for     list
void bfsList(int start, int n_vtx, int *visited, node **adj){
    int i=start;
    enq(start);   //q[1]
    visited[start] = 1;  //v[0,1,0,0]
    printf("%d ", start); //1
        while(front != -1){ //f = 1
            temp = adj[i]; //ptr[1]->0->3
            // printf("x %d ", *temp); 
            dQ(); //f = -1
            while(temp!=NULL){ //3
                if(visited[temp->data]==0){ 
                    enq(temp->data);
                    visited[temp->data] = 1;
                    printf("%d ", temp->data);
                }
                temp = temp->next;
            }
            i++;
            temp = NULL;
        }
    }    

//dfs code using recurssion
// void dfsMatrix(int s, int n_vtx, int *visited, int (*adjmat)[n_vtx]){
//     printf("%d ",s);
//     visited[s] = 1;
//     for(int i=0; i<n_vtx; i++){
//         if(adjmat[s][i]==1 && !visited[i]){
//             dfsMatrix(i, n_vtx, visited,adjmat);
//         }
//     }
// }
//dfs code recurrsion end

//stack opration start
int stack[maxq];
int top = -1;
void push(int data){
    if(top == maxq-1){
        printf("stack is full\n");
        exit(0);
    }
    stack[top++] = data;
}
int pop(){
    int rp = stack[top];
    if(top == -1){
        printf("stack is empty");
        exit(0);
    }
    top--;
    return rp;
}
//stack operation over

//dfs matrix 
void dfsMatrix(int s, int n_vtx, int *visited, int (*adjmat)[n_vtx]){
    int i;
    printf("%d ", s);
    visited[s] = 1;
    push(s);
    while(top != -1){
        s = stack[top];
        for(i=0; i<n_vtx; i++){
            if(adjmat[s][i] == 1 && !visited[i]){
                push(i);
                visited[i]=1;
                printf("%d ", i);
                break;
            }
        }
        if(i==n_vtx)
            pop();
    }
}
//dfs matrix end

//dfs list start
void dfsList(int start, int n_vtx, int *visited, node **adj){
    int i=start; //1
    visited[start] =1; //[0,1,0,0,0]
    push(start);  //[1|]
    printf("%d ", start); // 1
    while(top != -1){ // 0
        start = stack[top]; // [0]=1
        temp = adj[i]; // 1 = a[1]
        // printf("y\n");
        while(temp != NULL){
            if(visited[temp->data]==0){
                visited[temp->data] = 1;
                push(temp->data);
                printf("%d ", temp->data);
            // printf("x\n");
                break;
            }
            // printf("z\n");
            temp = temp->next;

        }
        if(i!=n_vtx && visited[i]==0){
            // printf("p\n");
            visited[i]=1;
            printf("|v %d| ", i);
            pop();
        }
        i++;
        temp = NULL;
    }
}
//dfs list end 

int main(){
    int n_vtx=0;
    printf("Enter the no of vertex : ");
    scanf("%d", &n_vtx);
    
    //adj list
    node *adj[n_vtx];

    //adj matrix
    int adjmat[n_vtx][n_vtx];

    //visited nodes array;
    int visited[n_vtx];

    // printf("Enter value for vertex through matrix \n\n");
    printf("Setting up values to adjucency matrix and list to zero and null...\n");
    for(int i=0; i<n_vtx; i++){
        adj[i] = NULL;
        visited[i] = 0;
        for(int j=0; j<n_vtx; j++){
            adjmat[i][j] = 0;
        }
    }

    printf("\nEnter vertex edge through ajucency list..\n\n");
    createGraph(n_vtx, adj, adjmat);
    displayGraph(n_vtx, adj, adjmat);

    printf("\nPrinting degree of node...\n");
    Degree(n_vtx, adj);

	
    int s;
    printf("Menu\n1.DFS \n2.BFS\nSelect : ");
    scanf("%d", &s);
	switch(s){
		case 1: 
			printf("Enter start vertex for bfs : ");
		    scanf("%d", &s);
		    if(s>n_vtx){
     		   printf("vertex not present in graph...\n");
     		   return 0;
    		}
		    for(int i=0; i<n_vtx; i++){
     		   visited[i] = 0;
		    }
		    printf("\nDFS Called...\n");
		    dfsMatrix(s, n_vtx, visited, adjmat);
		    break;
		case 2:
			printf("Enter start vertex for bfs : ");
		    scanf("%d", &s);
		    if(s>n_vtx){
        		printf("vertex not present in graph...\n");
        		return 0;
		    }
		    for(int i=0; i<n_vtx; i++){
     		   visited[i] = 0;
     		}
     		printf("\nBFS Calling...\n");
		    bfsMatrix(s, n_vtx, visited, adjmat);
		    break;
		default:
			printf("Enter Appropirate option\n");

	    }
		
    // bfsList(s, n_vtx, visited, adj);
    printf("\nfinished\n");

    return 0;
}

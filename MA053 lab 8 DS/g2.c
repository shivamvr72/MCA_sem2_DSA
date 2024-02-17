#include <stdio.h>
#include <stdlib.h>
#define max 30

typedef struct n{
    int data;
    struct n *next;
}node;

node *newnode=NULL, *temp=NULL, *tail = NULL;

node *create(int value){
    newnode = (node *) malloc(sizeof(node));
    if(newnode == NULL){
        printf("malloc error\n");
        exit(1);
    }
    newnode->next = NULL;
    newnode->data = value;
}

void createGraph(int n_vtx, node **adjlist, int (*matrix)[n_vtx]){
    int nb=0,val;
    for(int i=0; i<n_vtx; i++){
        printf("\nEnter no of neighbour vertices %d : ", i);
        scanf("%d", &nb);
        tail = NULL;
        for(int j=0; j<nb; j++){
            printf("\nEnter neighbor for %d to %d : ", i, j);
            scanf("%d", &val);
            matrix[i][val] = 1;
            //adj list
            newnode = create(val);
            if(adjlist[i] == NULL)
                adjlist[i] = newnode;
            else 
                tail->next = newnode;
            tail = newnode;
        }
    }
}

void display(int n_vtx, node **adjlist, int (*matrix)[n_vtx]){
    printf("\nMatrix for graph\n");
    for(int i=0; i<n_vtx; i++){
        for(int j=0; j<n_vtx; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nList For Graph\n");
    for(int i=0; i<n_vtx; i++){
        temp = adjlist[i];
        printf("vertex %d : ", i);
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// queue
int front = -1, rear = -1;
int queue[max];
void enq(int data){
    if(rear == max-1){
        printf("queue is full\n");
        exit(1);
    }
    if(front == -1)
        front++;
    queue[rear++] = data;
}
int dq(){
    int rv = queue[front];
    if(front == -1 || front>rear){
        printf("queue is empty\n");
        exit(1);
    }
    if(front == rear){
        front = rear = -1;
    }
    front++;
    return rv;
}
void bfsMatrix(int s, int n_vtx, int *visited , int (*adjmat)[n_vtx]){
    //using matrix
    printf("%d ", s);
    enq(s);
    visited[s] = 1;
    int x;
    while(front != -1){
        x = dq();
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
void bfsList(int start, int n_vtx, int *visited, node **adj){
    int i=start;
    enq(start);   //q[1]
    visited[start] = 1;  //v[0,1,0,0]
    printf("%d ", start); //1
        while(front != -1){ //f = 1
            temp = adj[i]; //ptr[1]->0->3
            // printf("x %d ", *temp); 
            dq(); //f = -1
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

//
int stack[max];
int top = -1;
void push(int data){
    if(top == max-1){
        printf("stack overflow\n");
        exit(1);
    }
    stack[top++]=data;
}
int pop(){
    int rval = stack[top];
    if(top == -1){
        printf("stack is empty");
        exit(1);
    }
    top--;
    return rval;
}
void dfsList(int start, int n_vtx, int *visited, node **adj){
    int i=start; //1
    visited[start] =1; //[0,1,0,0,0]
    push(start);  //[1|]
    printf("%d ", start); // 1
    while(top != -1){ // 0
        start = stack[top]; // [0]=1
        temp = adj[i]; // 1 = a[1]
        printf("y\n");
        while(temp != NULL){
            if(visited[temp->data]==0){
                visited[temp->data] = 1;
                push(temp->data);
                printf("%d ", temp->data);
             printf("x\n");
                break;
            }
             printf("z\n");
            temp = temp->next;

        }
        if(i!=n_vtx && visited[i]==0){
             printf("p\n");
            visited[i]=1;
            printf("|v %d| ", i);
            pop();
        }
        i++;
        temp = NULL;
    }
}

//dfs matrix
void dfsMatrix(int s, int n_vtx, int *visited, int (*adjmat)[n_vtx]){
    int i;
    printf("%d ", s);
    visited[s] = 1;
    push(s);
    while(top != -1){
        s = stack[top];
        // printf("z\n ");
        for(i=0; i<n_vtx; i++){
            // printf("x ");
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

void outDegree(int n_vtx,node **adj){
    int i=0, outCnt=0;
    for(;i<n_vtx;i++){
        outCnt=0;
        temp = adj[i];
        while(temp!=NULL){
            temp =temp->next;
            outCnt++;
        }
        printf("Out Degree %d : %d\n", i,outCnt);
    }
    printf("\n");
}

void inDegree(int n_vtx, int (*adj)[n_vtx]){
    int inDg =0;
    for(int i=0; i<n_vtx; i++){
        inDg=0;
        for(int j=0; j<n_vtx;j++){
            if(adj[j][i]==1){
                inDg++;
            }
        }
        printf("In Degree %d : %d\n", i, inDg);
    }
    printf("\n");
}



int main(){
    int n_vtx;
    printf("enter no of vertex : ");
    scanf("%d", &n_vtx);
    
    //int matrix[5][5] = {{0, 1, 1 ,1 ,0} ,{0, 0 ,0 ,1 ,0 },{0, 0, 0 ,0 ,0 },{0, 0, 1 ,0 ,1 },{0, 0, 0 ,0 ,0}};
    int matrix[n_vtx][n_vtx];
    node *adjlist[n_vtx];
    int visited[n_vtx];

    for(int i=0; i<n_vtx ; i++){
        adjlist[i] = NULL;
        visited[i] = 0;
         for(int j=0; j<n_vtx ; j++){
             matrix[i][j] = 0;
         }
    }

    createGraph(n_vtx, adjlist, matrix);
    display(n_vtx, adjlist, matrix);
    int s;

    printf("degree\n");
    inDegree(n_vtx, matrix);
    outDegree(n_vtx, adjlist);


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
		    dfsMatrix(s, n_vtx, visited, matrix);
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
			bfsMatrix(s,n_vtx, visited, matrix);
		    break;
		default:
			printf("Enter Appropirate option\n");

	    }
/*	   
while(1){
    printf("enter start vertex for bfs and dfs : ");
    scanf("%d", &s);
    printf("dfs..\n");
    //dfsList(s, n_vtx, visited,adjlist);
    dfsMatrix(s, n_vtx, visited, matrix);

    for(int i=0; i<n_vtx ; i++)
        visited[i] = 0;
    printf("bfs...\n");
    bfsList(s,n_vtx, visited, adjlist);
    
   }  */
    return 0;
}

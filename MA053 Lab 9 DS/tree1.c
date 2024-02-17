#include <stdio.h>
#include <stdlib.h>
typedef struct t{
    int data;
    struct t *left;
    struct t *right;
}node;
node *newnode=NULL, *temp=NULL, *root=NULL;

node * create(int val){
    newnode = (node *) calloc(1, sizeof(node));
    if(newnode == NULL){
        printf("Calloc failed\n");
        exit(1);
    }
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insertNode(int val){
    node *newp=NULL, *parent=NULL;
    newp = create(val);
    if(root == NULL){
        root = newp;
    }else{
        temp = root;
        //travese until null node checking high and low value
        while (temp!=NULL){
            parent = temp;
            // left insert
            if(val < temp->data){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        //insertion
        if(val < parent->data){
            parent->left = newp;
        }else{
            parent->right = newp;
        }
    }
    return root;
}

void preOrder(node *root){
    if(root!=NULL){
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}
int hightTree(node *root){
    int leftH=0, rightH=0;
    if(root==NULL){
        return 0;
    }else{
        leftH = hightTree(root->left);
        rightH = hightTree(root->right);
        if(leftH > rightH){
            return(leftH+1);
        }else{
            return(rightH+1);
        }
    }
}

//its not working properly
int currentLevel(node *root,int h){
            if(root == NULL){
                return 0;
            }
            if(h==1){
                printf("%d ", root->data);
            }else if(h>1){
                currentLevel(root->left, h-1);
                currentLevel(root->right, h-1);
            }
}
void levelOrder(node *root){
    int h = hightTree(root);
    
   for(int i=1; i<=h; i++){
        currentLevel(root, i);
   }
}

//end

int totalNodes(node *root){
    if(root==NULL){
        return 0;
    }else{
        return(totalNodes(root->left) + totalNodes(root->right) + 1);
    }
}

int internalNode(node *root){
    if(((root->left == NULL) && (root->right == NULL))){
        return 0;
    }else{
        return(internalNode(root->left) + internalNode(root->right) + 1);
    }
}

int externalNode(node *root){
    if((root == NULL) || ((root->left == NULL) && (root->right == NULL))){
        return 1;
    }else{
        return(externalNode(root->left) + externalNode(root->right));
    }
}

int searchElement(int sval, node *root){
    if(root!=NULL){
        if(sval == root->data){
            return 1;
        }
        node *sdata = root;
        if(sval > root->data){
            searchElement(sval, root->right);
        }else{
            searchElement(sval, root->left);
        }
        
        
    }
}



int main(){
    while(1){
        int chval;
        printf("\nMenu : \n 1. Insert Node \n 2. Pre Order \n 3. In Order \n 4. Post Order \n 5. Level Order Traversal \n 6. Total Node \n 7. Insternal Nodes \n 8. External Nodes \n 9. Hight of Tree \n10. Search Element \n Select : ");
        scanf("%d", &chval);
        switch(chval){
            case 1: printf("Enter Value : "); scanf("%d", &chval); insertNode(chval); break;
            case 2: printf("Pre Order Traversal \n"); preOrder(root); break;
            case 3: printf("In Order Traversal \n"); inOrder(root); break;
            case 4: printf("Post Order Traversal \n"); postOrder(root); break;
            case 5: printf("level order Traversal \n"); levelOrder(root); break;
            case 6: printf("Total Nodes in Tree : %d", totalNodes(root)); break;
            case 7: printf("Total Internal Nodes : %d", internalNode(root)-1); break;
            case 8: printf("Total External Nodes : %d",externalNode(root)); break;
            case 9: printf("Hight Of Tree : %d", hightTree(root)); break;
            case 10: printf("Enter Value to search : "); scanf("%d", &chval);
                    int flag =0;
                    flag = searchElement(chval, root);
                    if(flag == 1)
                        printf("%d found", chval);
                    else
                        printf("%d not found\n", chval);
                    break;
            default : printf("select apporite choice \n");
        }
    }
    return 0;
}
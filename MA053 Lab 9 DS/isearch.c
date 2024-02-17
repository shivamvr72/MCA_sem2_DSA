#include <stdio.h>
#include <stdlib.h>

void lsearch(int *arr, int n, int val){
    int sflag = 0, inx = 0;
    for(int i=0; i<n; i++){
        if(*(arr+i) == val){
            sflag = 1;
            inx = i;
            break;
        }
    }
    if(sflag == 1){
        printf("value %d found at index %d \n", val, inx);
    }else{
        printf("value %d not found\n",val);
    }
}

int binarysearch(int *arr, int n, int val){
    int m, s = 0;
    
    while (s < n) {
        m = s + (n - s) / 2;
        if (arr[m] == val) {
            return m;
        }else if (val < arr[m]) {
            n = m;
        }else {
            s = m + 1;
        }
    }
    return -1;
}


int main(){
    int n, chv;
    printf("Enter size of an array : ");
    scanf("%d", &n);
    int *sarr = (int*) malloc(sizeof(n));

    for(int i=0; i<n; i++){
        printf("Enter element : ");
        scanf("%d", sarr+i);
    }

    while(1){
        printf("Menu \n 1.Linear Search \n 2.Bubble Search \n 3.Exit \nSelect: ");
        scanf("%d", &chv);
        switch (chv){
        case 1:  printf("Enter Value : "); scanf("%d", &chv);  lsearch(sarr, n, chv); break;
        case 2: printf("Enter Value : "); scanf("%d", &chv);
                int x = binarysearch(sarr, n, chv);
                if(x>=0)
                    printf("found at index : %d\n ", x);
                else
                    printf("element not found\n");
                break;
        case 3: exit(0);
        default:
            printf("Enter appropriate option\n");
            break;
        }
    }
    
    return 0;
}


// int inx = 0, s = 0, sflag =0;
//     int n1 = n;
//     if(val < *(arr+0) || val > *(arr+(n-1))){
//         printf("element %d is not in the array\n", val);
//         return;
//     }else if(val == *(arr+0) || val == *(arr+(n-1))){
//         if( val == *(arr+(n-1)))
//             inx = n-1;
//         sflag = 1;
//         goto x;
//     }
//     while(s<=n){
//     inx = s+(n-1)/2;
//     printf(" [ s = %d, n = %d inx = %d] ", s, n, inx);
//         if(val == *(arr+inx)){
//             sflag = 1;
//             break;
//         }
//         if(val < *(arr+inx))
//             n = inx-1;
//         else
//             s = inx-1;
        
//         if(s < 0 || inx > n || n>n1 ){
//             break;
//         }
//     } 
//     x:
//     if(sflag==1)
//         printf("value %d found at index %d \n", *(arr+inx), inx);
//     else
//         printf("value %d not found \n", val);


// void binarysearch(int *arr, int n, int val){
//     int flag = 0, s = 0, m = 0;
//     n = n-1;
//     while(s<=n){
//         if(val = *(arr+m)){
//             printf("value %d found at index %d", *(arr+m), m);
//             flag = 1;
//             break;
//         }
//         if(val < *(arr+m))
//             n = m-1;
//         else
//             s = m+1;
//     }
//     if(s>n && flag == 0)
//         printf("value %d in not in array", val);
//         return;
// }

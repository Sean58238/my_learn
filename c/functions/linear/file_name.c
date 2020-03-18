#include <stdio.h>
#include <stdlib.h>

typedef struct filename{
    int station_num;
    char *station_name;
    char date_time[10];
    struct filename *next;
} fn;

fn* createNode();
fn* insertNode(int n, fn* new_node, fn* list_head);
fn* delNode(int n, fn* list_head);
fn* modifyNode(int n, fn* modify_node, fn* list_head);
int getLength(fn* list_head);
fn* init_dsc(int list_size);
fn* init_asc(int list_size);
void display(fn *list_head);

int main(){

    //init a list    
    printf("------init list:------\n");
    fn* file_list = init_asc(2); 
    display(file_list);
    printf("\n");

    //get list length
    printf("------get lenght:------\n");
    int len = getLength(file_list);   
    printf("list lenght:%d\n", len); 
    printf("\n");

    //insert a node
    printf("------insert new node:------\n");
    fn* new_node = createNode();
    insertNode(0, new_node , file_list);              
    display(file_list);
    printf("\n");

    //delete a node
    printf("------delete a node:------\n");
    delNode(1, file_list);   
    display(file_list);
    printf("\n");

    //modify a node
    printf("------modify a node:------\n");
    fn* modify_node = createNode();
    modifyNode(1, modify_node, file_list);
    display(file_list);
    printf("\n");

    return 0;
}


fn* createNode(){
    fn* node = (fn*)malloc(sizeof(fn));
    
    printf("please input station_num:\n");
    scanf("%d", &node->station_num);
    printf("please input station_name:\n");
    char * station_name = (char *)malloc(5);    
    scanf("%s", station_name);
    node->station_name = station_name;    

    printf("please input date_time:\n");
    scanf("%s", &node->date_time[0]);
    
    node->next = NULL;
    return node;
}

int getLength(fn* list_head){
    int len=0;
    fn* list = NULL;
    if(list_head->next ==NULL){
        return 0;
    }
    else{
        list = list_head->next;
        while(list){
             len++;
             list=list->next;
        }
        return len;       
    }      
}

fn* modifyNode(int n, fn* modify_node, fn* list_head){
    int len = getLength(list_head);
    if(n <= len){
        fn* list = list_head;
        int index = 0;
        while(list){
            if(index == n){
                fn* old_node = list->next;
                if(list->next->next != NULL){
                    modify_node->next = list->next->next;
                    list->next = modify_node;
                    free(old_node);
                }
                else{
                    list->next = modify_node;
                    free(old_node);
                }                
            }
            break;
        }
        index++;
    }
    else{
        printf("[error] Can't modify node at index: %d\n",n);
    }
    return list_head;
}


fn* delNode(int n, fn* list_head){
    int len = getLength(list_head);
    if(n <= len){
       fn* list = list_head;
       int index = 0;
       while(list){
           if(index == n){
                if(list->next->next == NULL){
                    free(list->next);
                    break;
                }
                else{
                    fn* delNode = list->next;
                    list->next = list->next->next;
                    free(delNode);
                    break;
                }
           }
           index++;
       } 
    }
    else{
        printf("[error] Can't delete node at index: %d\n",n);
    }
    return list_head;
}


fn* insertNode(int n, fn* new_node , fn* list_head){
    int len = getLength(list_head);
    if(n <= len){
         fn* list = list_head; 
         int index=0;
         while(list){
            if(index == n){
               new_node->next=list->next;
               list->next=new_node;
               break;             
            }
            index++;
         } 
    }
    else{
        printf("[error] Can't insert node at index: %d\n",n);
    }
    return list_head;      
}


fn* init_dsc(int list_size){
    //create a head
    fn* head = NULL;
    fn* new_node = NULL;
    
    int i;
    for( i = 0; i < list_size; i++ ){
        new_node = createNode();
        
        if(head == NULL){
            head = new_node;
        }else{
            new_node->next = head;
            head = new_node;
        }     
    }
    return head;
}

fn* init_asc(int list_size){
    //create a head
    fn* head = NULL;
    fn* new_node = NULL;
    fn* temp = NULL; 
    int i;
    for( i = 0; i < list_size; i++ ){
        new_node = createNode();
        
        if(head == NULL){
            head = new_node;
            temp = new_node;
        }else{
            temp->next = new_node;
            temp = new_node;
        }     
    }
    return head;
}

void display(fn* head){
    fn* node = head;
    printf("-----list the element-------\n");
    int index = 0;
    while(node){
        printf("-->(%d) station_num:%d\tstation_name:%s\tdate_time:%s\t\n", index,node->station_num,
                                                                    node->station_name,         
                                                                    node->date_time );
        node=node->next;
        index++;
    }  
    printf("\n");
}




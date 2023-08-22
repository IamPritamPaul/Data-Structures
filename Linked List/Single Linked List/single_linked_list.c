#include<stdio.h>
#include<stdlib.h>

// start->1stnode->2nd node->3rd node

struct node{
    int data;
    struct node *link;
};


//functions or operations in the list
struct node *create_list(struct node *);
void display(struct node *);
int count(struct node *);
void search(struct node *,int);
struct node *add_at_empty(struct node *,int);
struct node *add_at_beg(struct node *,int);
struct node *add_at_end(struct node *,int);
struct node *add_before_node(struct node *,int,int);
struct node *add_after_node(struct node *,int,int);
struct node *add_at_position(struct node *,int,int);
struct node *delete(struct node *,int);
struct node *reverse(struct node *);



int main(){
    struct node *start=NULL;  //making empty list.
    int choice,s_element,i_element,d_element,node_value,pos;
    while(1){
        printf("\n1. Create List\n2. Display\n3. Count The total nodes\n4. Search\n5. Add a node in the beginning\n6. Add a node at the end\n7. Add after a node\n8. Add before a node\n9. Add at any position\n10. delete a node\n11. reverse the list\n12. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                start=create_list(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                int count_the_number_of_nodes=count(start);
                printf("\nThe total number of nodes in the list is: %d.\n",count_the_number_of_nodes);
                break;
            case 4:
                printf("Enter the element to be searched: ");
                scanf("%d",&s_element);
                search(start,s_element);
                break;
            case 5:
                printf("Enter the data to be inserted: ");
                scanf("%d",&i_element);
                start=add_at_beg(start,i_element);
                break;
            case 6:
                printf("Enter the data to be inserted: ");
                scanf("%d",&i_element);
                start=add_at_end(start,i_element);
                break;
            case 7:
                printf("Enter the data to be inserted: ");
                scanf("%d",&i_element);
                printf("Enter the node value after which the data will be inserted: ");
                scanf("%d",&node_value);
                start=add_after_node(start,node_value,i_element);
                break;
            case 8:
                printf("Enter the data to be inserted: ");
                scanf("%d",&i_element);
                printf("Enter the node value before which the data will be inserted: ");
                scanf("%d",&node_value);
                start=add_before_node(start,node_value,i_element);
                break;
            case 9:
                printf("Enter value to be inserted: ");
                scanf("%d",&i_element);
                printf("Enter the position where the value will be inserted: ");
                scanf("%d",&pos);
                start=add_at_position(start,pos,i_element);
                break;
            case 10:
                printf("Enter the node value which is to be deleted: ");
                scanf("%d",&d_element);
                start=delete(start,d_element);
                break;
            case 11:
                start=reverse(start);
                break;
            case 12:
                return 0;
            default:
                printf("Thik vabe input den.");
        }
    }
    return 0;
}

//1. create list
struct node * create_list(struct node *start){
    int n,i_element;
    printf("Enter how many nodes you want to insert into the list: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0) return start;
    printf("Enter the element to be inserted: ");
    scanf("%d",&i_element);
    start=add_at_empty(start,i_element);
    for(int i=2;i<=n;i++){
        printf("Enter the element to be inserted: ");
        scanf("%d",&i_element);
        start=add_at_end(start,i_element);
    }
    return start;
}


//2. display
void display(struct node * start){
    struct node *p=start;
    if(p==NULL){
        printf("\nThe list is empty.\n");
        return;
    }
    printf("\nThe list is: ");
    while(p){
        printf("%d\t",p->data);
        p=p->link;
    }
    printf("\n\n");
}


//3. count the number total nodes in the list
int count(struct node *start){
    struct node *p = start;
    int i = 1;
    while(p->link){
        i++;
        p = p->link;
    }
    return i;
}


//4. search for any element in the list
void search(struct node * start,int s_element){
    if(start==NULL){
        printf("\nList is empty.\n");
        return;
    }
    struct node *p=start;
    int pos=1;
    while(p){
        if(p->data==s_element){
            printf("\nElement %d is found at position %d.\n",s_element,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("\n%d is not found.\n",s_element);
}


struct node *add_at_empty(struct node *start,int i_element){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i_element;
    temp->link=NULL;
    start=temp;
    return start;
}


struct node *add_at_beg(struct node *start,int i_element){
    struct node * temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i_element;
    temp->link=start;
    start=temp;
    return temp;
}


struct node *add_at_end(struct node * start,int i_element){
    struct node *p=start;
    while(p->link){
        p=p->link;
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    p->link=temp;
    temp->data=i_element;
    temp->link=NULL;
    return start;
}


int check_if_last_node(struct node *p,int value){
    struct node *q=p;
    while(q->link) q=q->link;
    if(q->data==value) return 1;
    else return 0;
}


struct node *add_after_node(struct node *start,int node_value,int i_element){
    struct node *temp,*p=start;
    if(check_if_last_node(p,node_value)){    // check if the given value is in the last node or not
        start=add_at_end(start,i_element);
    }
    while(p){
        if(p->data==node_value){
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=i_element;
            temp->link=p->link;
            p->link=temp;
            return start;
        }
        p=p->link;
    }
    printf("\n%d is not present in the list.\n",node_value);
    return start;
}


int check_if_first_node(struct node *start,int node_value){
    if(start->data==node_value){
        return 1;
    }else return 0;
}

struct node *add_before_node(struct node *start,int node_value,int i_element){
    if(check_if_first_node(start,node_value)){     // check if the given value is in the first node or not
        start=add_at_beg(start,i_element);
    }
    struct node *temp,*p=start;
    while(p){
        if(p->link->data==node_value){
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=i_element;
            temp->link=p->link;
            p->link=temp;
            return start;
        }
        p=p->link;
    }
    printf("\n%d is not present in the list.\n",node_value);
    return start;
}


struct node *add_at_position(struct node *start,int pos,int i_element){
    struct node *p=start;
    if(pos==1){
        start=add_at_beg(start,i_element);
        return start;
    }
    for(int i=1;i<pos-1 && p!=NULL;i++){
        p=p->link;
    }
    if(!p){ // !p means p!=NULL
        printf("\n%d is not a valid position in the list.\n",pos);
    }else{
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->data=i_element;
        temp->link=p->link;
        p->link=temp;
    }
    return start;
}


struct node *delete(struct node *start,int d_element){
    if(start==NULL){
        printf("The list is empty.\n");
        return start;
    }
    struct node *deleted_node;
    if(start->data==d_element){   //deletion of first node
        deleted_node=start;
        start=start->link;
        deleted_node->link=NULL;
        printf("\n%d is deleted from the list\n",deleted_node->data);
        return start;
    }
    struct node *p=start;
    while(p->link){
        if(p->link->data==d_element){
            deleted_node=p->link;
            p->link=deleted_node->link;
            deleted_node->link=NULL;
            printf("\n%d is deleted from the list\n",deleted_node->data);
            return start;
        }
        p=p->link;
    }
    printf("\n%d is not present in the list.\n",d_element);
    return start;
}


struct node *reverse(struct node * start){
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}
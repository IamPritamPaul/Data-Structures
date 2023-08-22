#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_list(struct node *);
struct node *add_at_beg(struct node *,int);
struct node *add_at_end(struct node *,int);
struct node *add_before(struct node *,int,int);
struct node *add_after(struct node *,int,int);
struct node *add_at_a_position(struct node *,int,int);
struct node *add_at_empty(struct node *,int);
struct node *delete(struct node *,int);
struct node *reverse(struct node *);
int max_value(struct node *);
int min_value(struct node *);
int count_the_number_of_nodes(struct node *);
void display(struct node *);
void search(struct node *,int);
struct node *delete_from_beg(struct node *);
struct node *delete_from_end(struct node *);
struct node *delete_from_between(struct node *,int);


int main(){
    int choice,i_element,node_value,d_element,s_element,position;
    struct node *start;
    start=NULL;
    while(1){
        printf("\n1. creaate a doubly linked list");
        printf("\n2. Display");
        printf("\n3. Count the Number of Nodes");
        printf("\n4. Add at empty");
        printf("\n5. Add at Beginning");
        printf("\n6. Add at End");
        printf("\n7. Add before a node");
        printf("\n8. Add after a node");
        printf("\n9. Add at a position.");
        printf("\n10. Delete");
        printf("\n11. Reverse");
        printf("\n12. Print the maximum value");
        printf("\n13. Print the Minimum value");
        printf("\n14. Search");
        printf("\n15. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                start=create_list(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("\nThe total number of nodes in the list is: %d.\n",count_the_number_of_nodes(start));
                break;
            case 4:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&i_element);
                start=add_at_empty(start,i_element);
                break;
            case 5:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&i_element);
                start=add_at_beg(start,i_element);
                break;
            case 6:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&i_element);
                start=add_at_end(start,i_element);
                break;
            case 7:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&i_element);
                printf("Enter the node(value) before which the element will be inserted: ");
                scanf("%d",&node_value);
                start=add_before(start,node_value,i_element);
                break;
            case 8:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&i_element);
                printf("Enter the node(value) after which the element will be inserted: ");
                scanf("%d",&node_value);
                start=add_after(start,node_value,i_element);
                break;
            case 9:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&i_element);
                printf("Enter the position at which the element will be inserted: ");
                scanf("%d",&position);
                start=add_at_a_position(start,position,i_element);
                break;
            case 10:
                printf("Enter the element to be deleted: ");
                scanf("%d",&d_element);
                start=delete(start,d_element);
                break;
            case 11:
                printf("\nThe List has been reversed.\n");
                start=reverse(start);
                break;
            case 12:
                printf("\nThe maximum value in the list is: %d.\n",max_value(start));
                break;
            case 13:
                printf("\nThe minimum value in the list is: %d.\n",min_value(start));
                break;
            case 14:
                printf("Enter the value to be searched: ");
                scanf("%d",&s_element);
                search(start,s_element);
                break;
            case 15:
                return 0;
            default:
                printf("Invalid Input.\n");
        }
    }
}


//1. creation of the list
struct node *create_list(struct node *start){
    int n,element;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0) return start;
    printf("\nEnter any number: ");
    scanf("%d",&element);
    start=add_at_empty(start,element);
    for(int i=2;i<=n;i++){
        printf("\nEnter any number: ");
        scanf("%d",&element);
        start=add_at_end(start,element);
    }
    return start;
}

//2. display
void display(struct node * start){
    if(start==NULL){
        printf("\nThe list is empty.\n");
        return;
    }
    struct node *p=start;
    printf("\nThe list is:\t");
    while(p){
        printf("%d\t",p->data);
        p=p->right;
    }
}

//3. total number of nodes in the list
int count_the_number_of_nodes(struct node *start){
    int count=0;
    struct node *p=start;
    if(p==NULL){
        return 0;
    }
    else{
        return 1+count_the_number_of_nodes(p->right);
    }
}

//4. add at empty
struct node *add_at_empty(struct node *start,int i_element){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i_element;
    temp->left=NULL;
    temp->right=NULL;
    start=temp;
    return start;
}



//5. add at beginning
struct node *add_at_beg(struct node *start,int i_element){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i_element;
    temp->left=NULL;
    temp->right=start;
    start=temp;
    return start;
}


//6. add at end
struct node *add_at_end(struct node *start,int i_element){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i_element;
    struct node *p=start;
    while(p->right){
        p=p->right;
    }
    temp->right=NULL;
    temp->left=p;
    p->right=temp;
    return start;
}


//7. insert before a node
struct node *add_before(struct node *start,int node_value,int i_element){
    struct node *p=start;
    while(p){
        if(p->data==node_value){
            struct node *temp=(struct node *)malloc(sizeof(struct node));
            p->left->right=temp;
            temp->left=p->left;
            temp->right=p;
            p->left=temp;
            temp->data=i_element;
            return start;
        }
        p=p->right;
    }
    printf("\n%d is not presernt in the list.\n",node_value);
    return start;
}


//8. insert after a node
struct node *add_after(struct node *start,int node_value,int i_element){
    struct node *p=start;
    while(p){
        if(p->data==node_value){
            struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->right=p->right;
            p->right->left=temp;
            p->right=temp;
            temp->left=p;
            temp->data=i_element;
            return start;
        }
        p=p->right;
    }
    printf("\n%d is not presernt in the list.\n",node_value);
    return start;
}


//9. add at a position
struct node *add_at_a_position(struct node *start,int position,int i_element){
    if(position ==1){
        start=add_at_beg(start,i_element);
    }
    if(position==count_the_number_of_nodes(start)){
        start=add_at_end(start,i_element);
    }
    struct node *p=start->right;
    for(int i=2;i<count_the_number_of_nodes(start);i++){
        if(i==position){
            start=add_before(start,p->data,i_element);
            return start;
        }
        p=p->right;
    }
    printf("Invalid position.\n");
    return start;
}


//10. delete 
struct node *delete(struct node *start,int d_element){
    if(start==NULL){
        printf("List is empty.\n");
        return start;
    }else if(start->data==d_element){
        start=delete_from_beg(start);
        return start;
    }else{
        struct node *p=start;
        for(int i=1;i<count_the_number_of_nodes(start);i++){
            p=p->right;
        }
        if(p->data==d_element){
            start=delete_from_end(start);
            return start;
        }
    }
    start=delete_from_between(start,d_element);
    return start;
}


struct node *delete_from_beg(struct node *start){
    printf("\n%d has been deleted from the list.\n",start->data);
    start=start->right;
    start->left=NULL;
    return start;
}

struct node *delete_from_end(struct node *start){
    struct node *p=start;
    while(p->right->right){
        p=p->right;
    }
    printf("\n%d has been deleted from the list.\n",p->right->data);
    p->right=NULL;
    return start;
}

struct node *delete_from_between(struct node *start,int d_element){
    struct node *p=start;
    while(p){
        if(p->data==d_element){
            printf("\n%d has been deleted from the list.\n",p->data);
            struct node *q=p->right;
            q->left=p->left;
            p->left->right=q;
            return start;
        }
        p=p->right;
    }
    printf("\n%d is not present in the list.\n",d_element);
    return start;
}



//11. reverse the list
struct node *reverse(struct node *start){
    struct node *p1,*p2;
    p1=start;
    p2=p1->right;
    p1->right=NULL;
    while(p2){
        p2->left=p2->right;
        p2->right=p1;
        p1=p2;
        p2=p2->left;
    }
    start=p1;
    printf("\nThe list is reversed.\n");
    return start;
}


//12. max value in the list
int max_value(struct node *start){
    int max=start->data;
    struct node *p=start->right;
    while(p){
        if(max<p->data){
            max=p->data;
        }
        p=p->right;
    }
    return max;
}


//13. min value in the list
int min_value(struct node *start){
    int min=start->data;
    struct node *p=start->right;
    while(p){
        if(min>p->data){
            min=p->data;
        }
        p=p->right;
    }
    return min;
}


//14. search
void search(struct node *start,int s_element){
    struct node *p=start;
    int pos=1;
    while(p){
        if(p->data==s_element){
            printf("%d found at position %d\n",s_element,pos);
            return;
        }
        pos++;
        p=p->right;
    }
    printf("%d is not in the list.\n",s_element);
}
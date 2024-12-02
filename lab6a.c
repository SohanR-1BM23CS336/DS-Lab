#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void appendNode(struct Node** head, int data){
    struct Node* newNode= createNode(data);
    if(*head==NULL){
        *head= newNode;
        return;
    }
    struct Node* temp= *head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= newNode;
}

void sortList(struct Node** head){
    struct Node* i = *head;
    struct Node* j = NULL;
    int temp;
    while(i!= NULL){
        j = i->next;
        while(j!= NULL){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}

void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    *head= prev;
}
void concatenateLists(struct Node** head1, struct Node** head2){
    if(*head1 == NULL){
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while(temp-> next!=NULL)
        temp= temp->next;
    temp->next = *head2;
}

void displayList(struct Node* head){
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, n, data;

    while(1){
        printf("\nMenu\n");
        printf("1.Add elements to List1\n");
        printf("2.Add elements to List2\n");
        printf("3.Sort List1\n");
        printf("4.Reverse List1\n");
        printf("5.Concatenate List2 to List1\n");
        printf("6.Display List1\n");
        printf("7.Display List2\n");
        printf("8.Exit\n");
        printf("\nEnter a Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the Number of elements to add to List1: ");
                    scanf("%d",&n);
                    printf("Enter the elements: ");
                    for(int i=0; i<n; i++){
                        scanf("%d",&data);
                        appendNode(&list1,data);
                    }
                    break;
            case 2: printf("Enter the Number of elements to add to List2: ");
                    scanf("%d",&n);
                    printf("Enter the elements: ");
                    for(int i=0; i<n; i++){
                        scanf("%d",&data);
                        appendNode(&list2,data);
                    }
                    break;
            case 3: sortList(&list1);
                    printf("List1 sorted.\n");
                    break;
            case 4: reverseList(&list1);
                    printf("List1 reversed.\n");
                    break;
            case 5: concatenateLists(&list1,&list2);
                    printf("list2 has been concatenated to list1\n");
                    break;
            case 6: printf("List1: ");
                    displayList(list1);
                    break;
            case 7: printf("List2: ");
                    displayList(list2);
                    break;
            case 8: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int key;
    Node* next;
    Node(int x){
        key=x;
        next=NULL;
    }
};

Node* insertBegin(Node* head, int key){
    Node* temp = new Node(key);
    temp->next=head;
    return temp;
}

Node* insertAtEnd(Node* head, int key){
    if(head==NULL){
        return new Node(key);
    }
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=new Node(key);
    return head;

}

void printList(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        cout<<curr->key<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void middleOfLinkedListNaive(Node* head){
    Node* curr;
    int count = 0;
    for(curr=head; curr!=NULL; curr=curr->next){
        count++;
    }
    curr = head;
    for(int i=0; i<count/2; i++){
        curr=curr->next;
    }
    cout<<"Middle of the linked list Naive: "<<curr->key<<endl;
}

void middleOflinkedListMethod1(Node*head){
    if(head==NULL) return;
    Node *slow=head, *fast=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle Of Linked List Method 1: "<<slow->key<<endl;
}

void findNthNodeFromEnd(Node *head, int n){
    int count=0;
    Node*curr = head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    if(n>count) return;
    curr=head;
    for(int i=0; i<count-n; i++){
        curr=curr->next;
    }
    cout<<"Nth item from End-Naive: "<<curr->key<<endl;
}
void findNthNodeFromEndEfficient(Node*head, int n){
    Node* first=head;
    for(int i=0; i<n-1; i++){
        first=first->next;
    }
    if(first==NULL){
        return;
    }
    Node *second = head;
    for(first; first->next!=NULL; first=first->next){
        second=second->next;
    }
    cout<<"Nth item from End-Naive: "<<second->key<<endl;
}

void reverseNaive(Node* head){
    vector<int> v;
    Node* curr=head;
    int count=0;
    while(curr!=NULL){
        v.push_back(curr->key);
        curr=curr->next;
    }
    curr=head;
    while(v.size()>0){
        curr->key= v.back();
        v.pop_back();
        curr=curr->next;
    }
}

Node* recursiveReverse1(Node* head){
    if(head==NULL||head->next==NULL) return head;
    Node* rest_head = recursiveReverse1(head->next);
    Node* rest_tail = head->next;
    rest_tail->next = head;
    head->next=NULL;
    return rest_head;
}

Node* recursiveReverse2(Node* curr, Node* prev){
    if(curr==NULL) return prev;
    Node* next = curr->next;
    curr->next=prev;
    recursiveReverse2(next, curr);
}

int main(){
    Node* head=NULL;
    head = insertAtEnd(head, 10);
    head = insertBegin(head, 20);
    head = insertAtEnd(head, 35);
    head = insertBegin(head, 40);
    head = insertBegin(head, 55);
    head = insertBegin(head, 53);
    printList(head);
    middleOfLinkedListNaive(head);
    middleOflinkedListMethod1(head);
    findNthNodeFromEnd(head, 5);
    findNthNodeFromEndEfficient(head, 3);
    reverseNaive(head);
    cout<<"Reverse Linked List Naive method: ";
    printList(head);

    cout<<"Reverse Linked List Recursive 1: "<<endl;
    head = recursiveReverse1(head);
    printList(head);

    cout<<"Reverse Linked List Recursive 2: "<<endl;
    head = recursiveReverse2(head, NULL);
    printList(head);
    printList(head);
}
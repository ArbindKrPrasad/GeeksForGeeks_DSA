#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data=x;
        next = NULL;
        prev = NULL;
    }
};

Node* insertAtBeginning(Node* head, int x){
    Node* temp = new Node(x);
    temp->next = head;
    if(head!=NULL){
        head->prev = temp;
    }
    return temp;
}

Node* insertAtEnd(Node* head, int x){
    Node* temp = new Node(x);
    if(head==NULL) return temp;
    Node* curr = head;
    while (curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev = curr;
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    else{
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
}

Node* deleteTail(Node* head){
    if(head ==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    else if(head->next->next==NULL){
        Node* temp = head->next;
        head->next=NULL;
        delete temp;
        return head;
    }
    else{
        Node* curr = head;
        while(curr->next->next!=NULL) curr=curr->next;
        Node* temp=curr->next;
        curr->next=NULL;
        delete temp;
        return head;
    }
}

void print(Node* head){
    for(Node* curr = head; curr!=NULL; curr=curr->next){
        cout<<curr->data<<" ";
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    print(head);
    head = deleteHead(head);
    print(head);
    head = deleteTail(head);
    print(head);
}
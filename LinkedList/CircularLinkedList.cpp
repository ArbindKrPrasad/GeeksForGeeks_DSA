#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void print(Node* head){
    Node* curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}

Node* insertAtBegin(Node* head, int x){
    Node* temp = new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        Node* curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        return temp;
    }
}
Node* insertAtBeginEfficient(Node* head, int x){
    Node* temp = new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}

Node* insertAtEnd(Node* head, int x){
    Node* temp= new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        Node* curr= head;
        while(curr->next!=head)
            curr=curr->next;
        temp->next=curr->next;
        curr->next=temp;
        return head;
    }
}

Node* insertAtEndEfficient(Node* head, int x){
    Node* temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return temp;
    }
}

Node* delHead(Node* head){
    if(head==NULL) return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    Node* curr= head;
    while( curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete head;
    return curr->next;
}

Node* delHeadEfficient(Node* head){
    if(head==NULL) return NULL;
    if(head->next==head){ delete head; return NULL;}
    Node*temp = head->next;
    head->data = temp->data;
    head->next = temp->next;
    delete temp;
    return head;

}

int main(){
    Node* head=NULL;
    head=insertAtBegin(head, 10);
    head=insertAtBegin(head, 20);
    head=insertAtBegin(head, 30);
    head=insertAtBeginEfficient(head, 40);
    head=insertAtEnd(head, 50);
    head=insertAtEndEfficient(head, 60);
    print(head);
    head=delHead(head);
    print(head);
    head = delHeadEfficient(head);
    print(head);
}
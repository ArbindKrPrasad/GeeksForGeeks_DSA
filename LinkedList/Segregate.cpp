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

Node* segragate(Node *head){
    Node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
    for(Node *curr=head; curr!=NULL; curr=curr->next){
        int x = curr->key;
        if(x%2==0){
            if(es==NULL){
                es = curr;
                ee = es;
            }
            else{
                ee->next = curr;
                ee = ee->next;
            }
        }
        else{
            if(os==NULL){
                os = curr;
                oe = os;
            }
            else{
                oe->next = curr;
                oe = oe->next;
            }
        }
    }
    if(os==NULL||es==NULL) return head;
    ee->next = os;
    oe->next = NULL;
    return es;
}

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

int main(){
    Node* head=NULL;
    head = insertAtEnd(head, 10);
    head = insertBegin(head, 20);
    head = insertAtEnd(head, 35);
    head = insertBegin(head, 40);
    head = insertBegin(head, 55);
    head = insertBegin(head, 53);
    head = segragate(head);
    printList(head);
}
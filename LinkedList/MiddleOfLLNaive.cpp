#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* next;
    Node(int x){
        key=x;
        next=NULL;
    }
};

void middleOfLinkedList(Node* head){
    Node* curr;
    int count = 0;
    for(curr=head; curr!=NULL; curr=curr->next){
        count++;
    }
    curr = head;
    for(int i=0; i<count/2; i++){
        curr=curr->next;
    }
    cout<<curr->key<<endl;
}
void printList(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        cout<<curr->key<<endl;
    }
}

int main(){
    
}

int main(){

}

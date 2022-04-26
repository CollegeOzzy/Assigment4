#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
//Node* head = NULL; // global variable that I will most likely take away later

void Print(Node* head){
	Node* temp = head;
    cout << "List currently is: " << endl;
	while(temp != NULL) {
		cout << temp ->data << " ";
        temp = temp->next;
	}
	cout << "\n";
}

void Insert(Node** ptrToHead, int data, int pos){
    Node* temp1 = new Node();
    temp1-> data = data;
    temp1-> next = NULL;
    if (pos <= 0){
        cout << "Negative positions are not valid. Please try a different position" << endl;
        return;
    }
    if(pos == 1){
        temp1 ->next = * ptrToHead;
        * ptrToHead = temp1;
        return;
    }
    Node* temp2 = *ptrToHead;
    for(int i = 0; i < pos -2; i++){
        temp2 = temp2-> next;
        // temp2 points to (n-1)th Node
    }
    temp1-> next = temp2-> next; // I kinda think of this as "adding a chain link"
    temp2 -> next = temp1;
    //The only case not covered is when the pos is over the size of the linked list...
}

void Remove(Node** ptrToHead, int pos){
    if(* ptrToHead == NULL){
    cout << "List is empty" << endl;
    return;
    }
    Node* temp1 = * ptrToHead;
    if (pos == 1){
        * ptrToHead = temp1-> next;
        free(temp1); //or return temp1;
        return;
    }
    for(int i = 0; i < pos -2; i++){
        temp1 = temp1-> next;
        // temp1 points to (n-1)th Node
    }
    Node* temp2 = temp1->next; // nth node
    temp1-> next = temp2-> next;
    free(temp2); //or return temp2;
    // project requirement says return but I remember in the lecture you said this is a lose requirement...
    // I don't see a point but I could just not free temp2 and return it as a node instead
    
}

Node* Get(Node** ptrToHead, int pos){
    Node* temp1 = * ptrToHead;
    if (pos == 1){
        cout << "The node at position " << pos << " is number: " << temp1->data << endl; 
        return temp1;
    }
    for(int i = 0; i < pos -2; i++){
        temp1 = temp1-> next;
        // temp1 points to (n-1)th Node
    }
    Node* temp2 = temp1->next; // nth node
    cout << "The node at position " << pos << " is number: " << temp2->data << endl;
    return temp2;
}

int main(){
    Node * head = NULL;
    Insert(&head, 25, 1); // 25
    Print(head);
    Insert(&head, 36, 2); // 25, 36
    Print(head);
    Insert(&head, 87, 1); // 87, 25, 36
    Print(head);    
    Insert(&head, 19, 3); // 87, 25, 19, 36
    Print(head);
    Insert(&head, 13, 2); // 87, 13, 25, 19, 36
    Print(head);
    Insert(&head, 6, 6); // 87, 13, 25, 19, 36, 6
    Print(head);
    Remove(&head, 2); // 87, 25, 19, 36, 6
    Print(head);
    Remove(&head, 2); // 87, 19, 36, 6
    Print(head);
    Remove(&head, 1); // 19, 36, 6
    Print(head);
    Insert(&head, 77, 3); // 19, 36, 77, 6
    Print(head);
    Remove(&head, 3); // 19, 36, 6
    Print(head);
    Get(&head, 3);
}
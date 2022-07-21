#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node* takeInput()
{
int data;
cin >> data;
Node *head = NULL; // holds address of first node of ::, NULL indicates the LL is empty initially
while (data != -1)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cin >> data;
}
return head;
}
Node* getNode(Node* head, int i)
{
    if(i == 0)
    {
        return head;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL && count < i)
    {
        temp = temp->next;
        count++;
    }
    if(temp != NULL)
    return temp;
}
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
    
}
int length(Node* head)
{
  
    // Recursive app
    int count = 0;
    if(head == NULL)
    {
        return 0;
    }
    int smallLen = length(head->next);
    //final ans will be 1 more
    return smallLen+1;
}
Node* insertHead(Node* head,int data)
{
    // if(head == NULL)
    // {
    //     return NULL;
    // }
    Node* temp = new Node (data);
    // creating a new node
    // temp->data = data;
    // To make it head
    temp->next = head;
    head = temp;

    return head;
    // O(1)

}
//print ith node
void printith(Node* head,int index)
{
    if(index == 0)
    {
        cout<<"0th node is : "<<head->data<<endl;
        return;
    }
    if(head == NULL || index < 0)
    {
        return;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL && count < index)
    {
        count++;
        temp = temp->next;

    }
    if(temp != NULL)
    cout<<"ith node is : "<<temp->data<<endl;
    
}
Node* insertTail(Node* head,int data)
{
    Node* temp = head;
    Node* newTail = new Node (data);
    // find the tail
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // We have the tail now
    temp->next = newTail;
    newTail->next = NULL;
    return head;
    //O(n)
}
//insert at ith
Node* insertith(Node* head, int i,int data)
{
    Node* temp = head;
    Node* newNode = new Node(data);
    int count = 0;
    while(temp != NULL && count < i-1)
    {
        count++;
        temp = temp->next;
    }
    // it reaches i-1th index
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
    
}
Node *reverseList(Node *head)
{
    Node* curr = head;
    Node *prev = NULL;
    Node *fwd  = NULL;
    while(curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}
int middle(Node* head)
{
    Node* slow = head;
    Node* fast = slow->next;
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
// delete ith
Node* deleteHead (Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
// We are simply deleting head and updating it
Node* temp = head;
head = temp->next;
temp->next = NULL;
delete(temp);
return head;


}
Node* deleteTail(Node* head)
{
    // Taking it to tail
    Node* temp = head;
    Node *secLast;
    secLast->next = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        secLast = secLast->next;
    }
    cout<<secLast->data<<endl;
    secLast->next = NULL;
    delete(temp);
    return head;

}
Node* deleteith(Node* head, int i)
{
    // head and tail at the same pos
    if(i == 0)
    {
        head = head->next;
        //becomes null
        delete(head);
        return head;
    }
    Node* temp = head;
    Node* fast = head->next;
    int count = 0;
    while(fast != NULL && count < i-1)
    {
        
        temp = temp->next;
        fast = fast->next;
        count++;
    }
    if(temp->next != NULL)
    {
    temp->next = fast->next;
    fast->next = NULL;
    delete(fast);
    }
    return head;


}
Node *evenAfterOdd(Node *head)
{
    Node *eH = NULL;
    Node *eT = NULL;
    Node *oH = NULL;
    Node *oT = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            // it is even
            if (eH == NULL)
            {
                eH = temp;
                eT = temp;
            }
            else
            {
                eT = temp;
                eH->next = eT;
                eT->next = NULL;
            }
        }
        else
        {
            if (oH == NULL)
            {
                oH = temp;
                oT = temp;
            }
            else
            {
                oT = temp;
                oH->next = oT;
                oT->next = NULL;
            }
        }
    }
    // oT->next = NULL;
    // eT->next = NULL;
    oT->next = eH;

    return oH;
}
    int main()
    {
        Node *head = takeInput();
        print(head);
        cout << length(head) << endl;

        Node *newHead = insertHead(head, 8);
        cout << "\nThe new head is : " << endl;
        print(newHead);
        cout << "The new length is : " << length(newHead) << endl;

        Node *newTail = insertTail(head, 9);
        cout << "The new tail is : " << endl;
        print(newTail);

        printith(head, 2);

        Node *ihead = insertith(head, 2, 5);
        print(ihead);

        cout << "The middle element is : " << middle(head) << endl;

        // Node* delHead = deleteHead(head);
        // print(delHead);

        // Node* delTail = deleteTail(head);
        // print(delTail);

        Node *idhead = deleteith(head, 2);
        print(idhead);

        Node *getH = getNode(head, 2);
        cout << getH->data << endl;
    }

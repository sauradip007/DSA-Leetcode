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
Node *takeInput()
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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int length(Node *head)
{

    // Recursive app
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    int smallLen = length(head->next);
    // final ans will be 1 more
    return smallLen + 1;
}
int length_cycle(Node *head)
{
    // Assuming there is a cycle
    Node *slow = head;
    Node *fast = head;
    int count = 1;
    while (fast != NULL && fast->next != NULL)
    {
        if (fast->next == slow)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    // keep fast as it is and traverse slow one by 1
    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }
    return count;
}
Node* detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    int length = 0;
    while(fast != NULL && fast->next != NULL)
    {
        
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            length = length_cycle(head);
        }
    }
    if(length == 0)
    return NULL; 
    //no cycle present
    //placement of ptrs
    Node* first = head;
    Node* sec = head;
    while(length > 0)
    {
        sec = sec->next;
        length--;
    }
    //now both ptrs in position

    //now increment each until they meet
    while(first != sec)
    {
        first = first->next;
        sec = sec->next;
    }
    return first;
}
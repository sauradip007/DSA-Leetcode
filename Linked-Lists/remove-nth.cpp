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
Node *removeNthFromEnd(Node *head, int n)
{
    if(head == NULL)
    return head;
    if(n > length(head))
    return head;
    int k = length(head) - n;
    int count = 0;
    Node* temp = head;
    Node* q = head->next;
    if(k == 0 || length(head) == n)
    {
        //delete at head
        Node* q = head;
        head = temp->next;
        q->next = NULL;
        delete(q);
        return head;


    }
    while(temp != NULL && q != NULL && count < k-1)
    {
        temp = temp->next;
        q = q->next;
        count++;


    }
    if(q == NULL)
    {
        temp = temp->next;
        return temp;
    }
    temp->next = q->next;
    q->next = NULL;
    delete(q);
    return head;
}
int main()
{
    Node* head = takeInput();
    Node* nH = removeNthFromEnd(head,2);
    print(nH);

}
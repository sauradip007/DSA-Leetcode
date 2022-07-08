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
int main()
{
    Node* head = takeInput();
    Node* oH = evenAfterOdd(head);
    print(oH);
}
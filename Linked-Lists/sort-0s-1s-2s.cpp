#include<iostream>
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
Node* segregate(Node* head)
{
    //count and create new sorted LL
    Node* temp = head;
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
        count_0++;
        }
        if(temp->data == 1)
        {
        count_1++;
        }
        if (temp->data == 2)
        {
        count_2++;
        }

        temp = temp->next;

    }
    cout<<count_0;
    cout<<count_1;
    cout<<count_2;
    //create
    Node* nH = NULL;
    Node* nT = NULL;
    while(count_0 != 0)
    {
        Node* newNode = new Node (0);
        if(nH == NULL)
        {
            nH = newNode;
            nT = newNode;
        }
        else{
            nT->next = newNode;
            nT = nT->next;
        }
        count_0--;
        
    }
    while(count_1 != 0)
    {
        Node *newNode = new Node(1);
        if (nH == NULL)
        {
            nH = newNode;
            nT = newNode;
        }
        else
        {
            nT->next = newNode;
            nT = nT->next;
        }
        count_1--;
    }
    while(count_2 != 0)
    {
        Node* newNode = new Node(2);
        if (nH == NULL)
        {
            nH = newNode;
            nT = newNode;
        }
        else
        {
            nT->next = newNode;
            nT = nT->next;
        }
        count_2--;
    }
    nT->next = NULL;
    nT = nT->next;
    return nH;
}
Node* segregate_2(Node* head)
{
    //3 ptr approach
    Node* ptr0 = new Node(-1);
    Node* ptr1  = new Node(-1);
    Node* ptr2 = new Node(-1);
    Node* p0 = ptr0;
    Node* p1 = ptr1;
    Node* p2 = ptr2;
    Node* temp = head;

    Node* nH = NULL;
    Node* nT = NULL;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            Node* newNode = new Node(0);
            if(nH == NULL)
            {
                nH = newNode;
                nT = newNode;
            }
            else
            {
                nT->next = newNode;
                nT = nT->next;
            }

        }
        else if (temp->data == 1)
        {
            Node *newNode = new Node(1);
            if (nH == NULL)
            {
                nH = newNode;
                nT = newNode;
            }
            else
            {
                nT->next = newNode;
                nT = nT->next;
            }
        }
        else{
            Node *newNode = new Node(2);
            if (nH == NULL)
            {
                nH = newNode;
                nT = newNode;
            }
            else
            {
                nT->next = newNode;
                nT = nT->next;
            }
        }
        temp = temp->next;
    }
    nT->next = NULL;
    nT = nT->next;
    return nH;
}
int main()
{
    Node* head = takeInput();
    Node* sH = segregate(head);
    print(sH);
}
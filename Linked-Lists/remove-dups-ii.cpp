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
Node* reverse_iter(Node* head)
{
    Node* prev = NULL;
    Node* pres = head;
    Node* nxt = pres->next;
    while(pres != NULL)
    {
        pres->next = prev;
        prev = pres;
        pres = nxt;
        if(nxt != NULL)
        nxt = nxt->next;
    }
    //lastly prev will be at tail
    head = prev;
    return head;
}
Node* deleteDuplicates(Node* head)
{
    Node* q = NULL;
    q->next =  head;
    Node* temp = head;
    Node* p = head->next;
    while(temp != NULL && p != NULL)
    {
        if(temp->data == p->data)
        {
            //duplicate found
            while(p->data != temp->data && p != NULL)
            {
                p->next = NULL;
                p = p->next;
            }
            temp->next = p;

            
        }
        temp = temp->next;
        p = p->next;
    }
    
}
Node* remove_2(Node* head)
{
    Node* p = head;
    Node* q = head->next;
    Node* prev = NULL;
    while(q != NULL && p != NULL)
    {
        if(p->data == q->data)
        {
           
            while(q!= NULL && q->data == p->data)
            {
                q = q->next;
                
            }
            p = q;
            cout<<"p : "<<p->data<<endl;
            q= q->next;
            if(prev != NULL)
            {
            prev->next = p;
            }
            else
            {
                while(head != NULL && head != p)
                {
                    Node* temp = head;
                    head = head->next;
                    delete(temp);
                }
            }

        }
        
        else{
        prev = p;
        q = q->next;
        p = p->next;
        }
    

    }
    cout<<prev->data<<endl;
    // cout<<"q: "<<q->data<<endl;
    cout<<head->data<<endl;
    return head;
}
int main()
{
    Node* head = takeInput();
    Node* rH = remove_2(head);
    print(rH);
}
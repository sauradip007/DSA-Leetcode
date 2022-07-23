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
Node *reverse_iter(Node *head)
{
    Node *prev = NULL;
    Node *pres = head;
    Node *nxt = pres->next;
    while (pres != NULL)
    {
        pres->next = prev;
        prev = pres;
        pres = nxt;
        if (nxt != NULL)
            nxt = nxt->next;
    }
    // lastly prev will be at tail
    head = prev;
    return head;
}
Node *deleteDuplicates(Node *head)
{
    Node *q = NULL;
    q->next = head;
    Node *temp = head;
    Node *p = head->next;
    while (temp != NULL && p != NULL)
    {
        if (temp->data == p->data)
        {
            // duplicate found
            while (p->data != temp->data && p != NULL)
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
Node* reverseBetween(Node* head, int left, int right)
{
    int c1 = 0;
    int c2 = 0;
    Node* t1 = head;
    Node* t2 = head;
//     while(t1 != NULL && c1 < left-1)
//     {
//         t1 = t1->next;
//         c1++;

//     }
//     cout<<"t1 : "<<t1->data<<endl;
//     while(t2 != NULL && c2 < right - 1)
//     {
//         t2 = t2->next;
//         c2++;
//     }
//     cout<<"t2 : "<<t2->data<<endl;
//    //using 3 ptrs
// //    Node* prev = NULL;
// //    Node* curr = head;
// //    Node* nxt = head->next;


   Node* prev = head;
   Node* prev_it = NULL;
   for(int i = 0; i < left-1; i++)
   {
    prev_it = prev;
    prev = prev->next;
   }
   //curr and next assignment
   Node* curr = prev->next;
   Node* nxt = curr->next;
   
   //Now reverse nodes right - left times
   int count = 0;
   for(int i = 0 ; i < right-left; i++)
   {
    curr->next = prev;
    prev = curr;
    curr = nxt;
    if(nxt->next != NULL)
    nxt = nxt->next;

   }
   
   Node* l = prev_it->next;
   l->next = curr;
   curr->next = NULL;
   prev_it->next = prev;
   //    while(count != right-left && curr != NULL)
   //    {
   //         curr->next = prev;
   //         prev = curr;
   //         curr = nxt;
   //         if(nxt != NULL)
   //         nxt = nxt->next;
   //         count++;
   //    }
   return head;


}
Node* reverseBetween_2(Node* head,int left,int right)
{
   if(left == right)
   return head;

   Node* curr = head;
   Node* prev = NULL;
   int c1 = 0;
   while(curr != NULL && c1 < left-1)
   {
    prev = curr;
    curr = curr->next;
    c1++;
   }
   Node* last = prev;
   Node* newEnd = curr;

   Node* nxt = curr->next;
   for(int i = 0;curr!= NULL && i < right-left+1; i++)
   {
    curr->next = prev;
    prev = curr;
    curr = nxt;
    if(nxt != NULL)
    nxt = nxt->next;

   }
   if(last != NULL)
   {
    last->next = prev;
   }else{
    head = prev;
   }
   newEnd->next = curr;
   return head;

}
int main()
{
    Node* head = takeInput();
    Node* nH = reverseBetween_2(head,2,4);
    print(nH);
}
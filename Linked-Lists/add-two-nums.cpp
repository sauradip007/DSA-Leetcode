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
Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}
Node* addTwoNumbers(Node* l1, Node* l2)
{
    int base = 1;
    //reversing LL
    //converting LL to dec
    //reversing result for final ans
    Node* rh1 = reverseList(l1);
    Node* rh2 = reverseList(l2);
    int d1 = 0;
    while (rh1 != NULL)
    {
        d1 = (d1*10)+rh1->data;
        // base *= 10;
        rh1 = rh1->next;

    }
    int d2 = 0;
    while(rh2 != NULL)
    {
        d2 = (d2*10)+rh2->data;
        rh2 = rh2->next;
    }
    //digits obtained
    int sum = d1 + d2;
    Node* sH = NULL;
    Node* sT = NULL;
    int l = sum;
    while(l != 0)
    {
        int newVal = l%10;
        Node* newNode = new Node(newVal);
        if(sT == NULL)
        {
            sH = newNode;
            sT = newNode;

        }
        else{
            sT->next = newNode;
            sT = sT->next;

        }
        // newVal = l / 10;
        l = l/10;
    }
    sT->next = NULL;
    //created list
    sT = sT->next;
    return sH;
}
Node *addTwoNumbers_2(Node *l1, Node *l2)
{
   //add 2 LLs
   Node* h1 = l1;
   Node* h2 = l2;
//    Node* dummy = new Node(0);
   Node* nH = NULL;
   Node* nT = NULL;
   int sum = 0;
   int carry = 0;
   while(h1 != NULL && h2 != NULL)
   {
    //  int carry = 0;

     sum = 0;
     if(carry != 0)
     {
     sum += carry;
     carry = 0;//test
     }
     else
     {
     carry = 0;
     }
     sum += h1->data;
     sum += h2->data;
     if(sum > 9)
     {
     
     carry = sum/10;
     sum = sum % 10;
     }
    //  sum += carry;
     Node* newNode = new Node(sum);
     //create a new sum node
     if(nH == NULL)
     {
        nH = newNode;
        nT = newNode;
     }
     else{
        nT->next = newNode;
        nT = nT->next;
     }

     h1 = h1->next;
     h2 = h2->next;
   }
   
   if(h1 == NULL && h2 != NULL)
   {
    while( h2 != NULL )
    {
        sum = 0;
        if(carry != 0)
        {
        sum += carry;
        carry = 0;
        }
        else
        carry = 0;
        sum += h2->data;
        if (sum > 9)
        {
            carry = sum / 10;
            sum  = sum % 10;
        }
        Node* newNode = new Node(sum);
        if(nH == NULL)
        {
            nH = newNode;
            nT = newNode;
        }
        else{
            nT->next = newNode;
            nT = nT->next;
        }
        h2 = h2->next;
    }
  

   }
   if(h2 == NULL)
   cout<<"Yes"<<endl;
   if(h2 == NULL && h1 != NULL)
   {
       while (h1 != NULL)
       {
            sum = 0;
           if (carry != 0)
           {
               sum += carry;
               carry = 0;
           }
           else{
               carry = 0;
           }
           sum += h1->data;
           if (sum > 9)
           {
               carry = sum / 10;
               sum = sum % 10;
           }
           Node *newNode = new Node(sum);
        //    if (nH == NULL)
        //    {
        //        nH = newNode;
        //        nT = newNode;
        //    }
        //    else
        //    {
               nT->next = newNode;
               nT = nT->next;
        //    }
           h1 = h1->next;
       }
   }
   if(carry != 0)
   {
    Node* newNode = new Node(carry);
    if(nH == NULL)
    {
        nH = newNode;
        nT = newNode;
    }
    else{
        nT->next = newNode;
        nT = nT->next;
    }

   }
   nT->next = NULL;
   nT = nT->next;
   return nH;
}
int main()
{
    // Node* h = takeInput();
    // Node* rh = reverseList(h);
    // print(rh);
    cout<<"Enter head1"<<endl;
    Node* head1 = takeInput();
    cout<<"Enter head2"<<endl;
    Node* head2 = takeInput();
    //add
    Node* head3 = addTwoNumbers_2(head1,head2);
    cout<<"The new sum is : "<<endl;
    print(head3);


}
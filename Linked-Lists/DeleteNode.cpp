#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};
void deleteNode(ListNode *node)
{

    ListNode *prev = NULL;
    prev->next = node;

    ListNode* after = node->next;



    prev->next = after;
    node->next = NULL;
    delete(node);

   

}
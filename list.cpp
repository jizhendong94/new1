#include<iostream>
using namespace std;

//整个反转
ListNode* reverseList(ListNode* head)
{
    if(NULL==head || NULL==head->next) return head;
    ListNode* pre=NULL;
    ListNode* cur = head;
    ListNode* newhead = NULL;
    while(cur)
    {
        if(cur->next == NULL)
            newhead=cur;
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return newhead;
}

ListNode* reverseList(ListNode* head)
{
    if(head == NULL ||　head->next==NULL) return head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next= NULL;
    return last;
}

ListNode* successor = NULL;
ListNode* reverseBeforN(ListNode* head,int n)
{
    if(n == 1)
    {
        successor = head->next;
        return head;
    }

    ListNode* last = reverseBeforN(head->next,n-1);
    head->next->next=head;
    head->next=successor;
    return last;
}

ListNode* reverseBetween(ListNode* head,int left,int right)
{
    if(left==1)
        return reverseBeforN(head,right);
    head->next = reverseBetween(head->next,left-1,right-1);
    return head;
}


//
ListNode* reseverseBetween(ListNode*head,int left,int right)
{
    ListNode* dummynode = new ListNode(-1);
    dummynode->next = head;
    ListNode* pre = dummynode;

    for(int i =0;i<left-1;i++)
        pre = pre->next;
    ListNode* cur = pre->next;
    ListNode* next;
    for(int i=0;i<right-left;i++)
    {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummynodei->next;
}







































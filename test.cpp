//
//  main.cpp
//  XcodeTest
//
//  Created by 祁煊 on 2019/8/17.
//  Copyright © 2019 祁煊. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *insertHead(ListNode *head,int data)
{
    if(head==NULL)
    {
        head=new ListNode;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        ListNode *p=new ListNode;
        p->data=data;
        p->next=head;
        head=p;
    }
    return head;
}


ListNode *insertTail(ListNode *head,int data)
{
    if(head==NULL)
    {
        head=new ListNode;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        ListNode *p=head;
        while (p!=NULL&&p->next!=NULL)
        {
            p=p->next;
        }
        ListNode *newNode=new ListNode;
        newNode->data=data;
        newNode->next=NULL;
        p->next=newNode;
    }
    return head;
}

ListNode *deleteHead(ListNode *head)
{
    if(head==NULL||head->next==NULL)
        return NULL;
    else
    {
        ListNode *p=head->next;
        delete head;
        return p;
    }
    
}

ListNode *deletetTail(ListNode *head)
{
    if(head==NULL||head->next==NULL)
        return NULL;
    else
    {
        for(ListNode *p=head;p!=NULL;p=p->next)
        {
            if(p->next->next==NULL&&p->next!=NULL)
            {
                delete p->next;
                p->next=NULL;
            }
        }
        return head;
    }
}



void printList(ListNode *head)
{
    if(head==NULL)
        cout<<"empty"<<endl;
    else
    {
        for(ListNode *p=head;p!=NULL;p=p->next)
        {
            
            cout<<p->data;
            if(p->next!=NULL)
                cout<<",";
        }
    }
    cout<<endl;
    
}

ListNode *reverseList(ListNode *head)
{
    ListNode *ans=NULL;
    for(ListNode *p=head;p!=NULL;p=p->next)
    {
        ans=insertHead(ans, p->data);
    }
    return ans;
}

int main()
{
    ListNode *head=NULL;
    
    int a[5]={4,2,7,1,3};
    for (int i=0; i<5; i++)
    {
        head=insertTail(head, a[i]);
    }
    printList(head);
    printList(reverseList(head));
    
}

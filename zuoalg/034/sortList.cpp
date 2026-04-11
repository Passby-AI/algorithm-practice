 // Definition for singly-linked list.
 //要求时间复杂度O(n*logn),额外空间复杂度O(1),还要求稳定性
 //数组排序做不到，链表可以
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
//注意为了空间复杂度，不能使用递归
//因为mergeSort需要O(logn)的额外空间
class Solution {
private:
    //记录整个链表的开头结尾
    ListNode* start;
    ListNode* end;
public:
    ListNode* sortList(ListNode* head) {
       int n=0;
       ListNode* cur=head;
       while(cur!=nullptr)
       {
           n++;//数数量
           cur=cur->next;
       }
       ListNode* l1;
       for(int step=1;step<n;step<<=1)
       {
           //第一组很特殊，因为要决定整个链表的头
           l1=head;
           ListNode* r1=findEnd(l1, step);
           ListNode* l2=r1->next;
           ListNode* r2=findEnd(l2,step);
           ListNode* next=r2->next;
           r1->next=nullptr;
           r2->next=nullptr;
           merge(l1,r1,l2,r2);
           head=start;
           ListNode* lastTeamEnd=end;
           while(next!=nullptr)
           {
               l1=next;
               r1=findEnd(l1,step);
               l2=r1->next;
               if(l2==nullptr)
            {
                lastTeamEnd->next=l1;
                break;//不够分两组
            }
               r2=findEnd(l2,step);
               next=r2->next;
               r1->next=nullptr;
               r2->next=nullptr;
               merge(l1,r1,l2,r2);
               lastTeamEnd->next=start;
               lastTeamEnd=end;

            }

       }
       return head;
    }
    ListNode* findEnd(ListNode* start,int step)
    {
        ListNode* end=start;
        while(--step!=0 && end->next!=nullptr)
        {
            end=end->next;

        }
        return end;
    }
    void merge(ListNode* l1,ListNode* r1,ListNode* l2,ListNode* r2)
    {
        ListNode* pre;
        if(l1->val<=l2->val)
        {
            start=l1;
            pre=l1;
            l1=l1->next;
        }
        else
        {
            start=l2;
            pre=l2;
            l2=l2->next;
        }
        while(l1!=nullptr && l2 !=nullptr)
        {
            if(l1->val<= l2->val)
            {
                pre->next=l1;
                pre=pre->next;
                l1=l1->next;
            }
            else
            {
                pre->next=l2;
                pre=pre->next;
                l2=l2->next;
            }
        }
        if(l1!=nullptr)
        {
            pre->next=l1;
            end=r1;
        }
        else
        {
            pre->next=l2;
            end=r2;
        }
    }
};

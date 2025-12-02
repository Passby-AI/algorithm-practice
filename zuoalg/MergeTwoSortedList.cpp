#include <cstddef>
//改编自标准答案
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


ListNode* mergeTwoLists(ListNode* h1,ListNode* h2)
{
    //如果有其中一个是NULL,返回另一个，两个都是NULL,逻辑也成立，因为返回那个都是NULL
    if(h1==NULL || h2==NULL)    return h1==NULL? h2: h1 ;
        
        //ListNode* head=(h1->val<=h2->val)? h1:h2;
        ListNode* head= h1->val<=h2->val? h1:h2;
        ListNode* main=head->next;
        ListNode* sub= head==h1? h2:h1;
         ListNode* pre=head;

         while(sub!=NULL && main !=NULL)
         {
             if(sub->val<=main->val)
             {
                 pre->next=sub;
                 sub=sub->next;

             }
             else
             {
                 pre->next=main;
                 main=main->next;

             }
             pre=pre->next;
             
         }
         pre->next= sub!=NULL? sub : main;
         return head;

}



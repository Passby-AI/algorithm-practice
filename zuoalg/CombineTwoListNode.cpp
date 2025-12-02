#include <cstddef>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


ListNode* CombineTwoList(ListNode* h1,ListNode*h2)
{
    //如果有其中一个是NULL,返回另一个，两个都是NULL,逻辑也成立，因为返回那个都是NULL
    if(h1==NULL || h2==NULL)    return h1==NULL? h2: h1 ;
        
        //ListNode* head=(h1->val<=h2->val)? h1:h2;
        ListNode* head;
        ListNode*sub;
        ListNode* main;
        if(h1->val<=h2->val)
        {
             head=h1;
             main=h1->next;
             sub=h2;
        }
        else
        {
             head=h2;
             main=h2->next;
             sub=h1;

        }
         ListNode *pre=head;
         ListNode* next=head->next;
         h2=next;

         while(sub!=NULL || main !=NULL)
         {
             if(sub==NULL)
             {
                 pre->next=main;
                 break;
             }
             if(main==NULL)
             {   
                 pre->next=sub;
                 break;
             }
             if(sub->val<=main->val)
             {
                 pre->next=sub;
                 pre=sub;
                 next=sub->next;
                 sub=next;
             }
             else
             {
                 pre->next=main;
                 pre=main;
                 next=main->next;
                 main=next;

             }
             
         }
         return head;

}

int main()
{
    
}

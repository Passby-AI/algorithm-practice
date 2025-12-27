/*
 *已知数组A[n]中元素为整型，设计算法将其调
整为左右两部分，左边所有元素为奇数，右边
所有元素为偶数。
3 9 1 7 5 2 6 8 4

基本思想
 将左边元素的调整到右边，右边的元素调整
到左边，关键在于调整的新位置如何确定。最理
想的情况：正好将左边的偶数和右边的奇数交换
一下。
 */
template<class T>
void swap(T& i,T& j)
{
    T temp=i;
    i=j;
    j=temp;

}

void Convert(int A[],int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        while(A[i]%2==0) i++;
        while(A[j]%2!=0) j++;
        if(i<j) swap(A[i],A[j]);
    }
}

/*
 *以单链表为存储结构，写出就地逆置的算法
思考步骤1:摘除头节点
思考步骤2：按照头插法的原则建立头节点
 */

template<class Node>
void reverse(Node* first)
{
    Node *p,*q;
    p=first->next;//保存后续原链表的元素
    first->next=nullptr; //用原链表的头建立新节点
    while(p!=nullptr)
    {
        //保存原链表的元素
        //当前节点插入新的链表
        //原链表后移
       q=p;
       p=p->next;
       q->next=first->next;
        first->next=q;
       /*
        *当然也可以让q保存当前链表这更符合前面的叙述
        q=p->next;
        p->next=first->next;
        first->next=p;
        p=q;
        * */

    }
}



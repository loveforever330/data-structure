#include <bits/stdc++.h>
using namespace std;
typedef struct LNode // 链表的建立
{
    int data;
    struct LNode *next;
} LNode, *Linklist;
bool InitList(Linklist &L) // LNode的节点的初始化的方式
{
    L = new LNode;
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}
Linklist Listinsert(int e, LNode *a) // 用于尾插法的插入的函数
{
    LNode *s = new LNode; // 其中的s指向其中的新的节点
    s->data = e;          // 其中的data元素赋值
    a->next = s;          // a指向的下一个为新元素s
    a = s;                // 将a指针更新为s
    a->next = NULL;       // 其中a指向的下一个为空指针
    return a;             // 将a指针的地址返回
}
void ShowList(Linklist L) // 输出链表中的全部的值
{
    LNode *p = L->next;
    while (p != NULL)
    {
        cout << " " << p->data << endl;
        p = p->next;
        /* code */
    }
}

/*与头插法的最大的不同在于尾插法的工作指针需要一直保留在末尾的位置
头插法每一次都需要将他的工作指针放在首位，每次都在L的位置。
*/
int main()
{
    int length, x;
    cin >> length;
    Linklist L;
    InitList(L);                        /*由于每一次都需要将工作指针的节点放在最后一位*/
     LNode *a = L;                      /* 所以将初始化的节点放在本地,所以在这里有LNode=L*/
    for (int i = 0; i < length; i++)
    {
        cin >> x; // 输入对应的值
        a = Listinsert(x, a);           //这里需要注意一下返回的必须是a的地址，不然会丢失a的地址，造成工作指针a丢失而无法插入
    }
    ShowList(L);
    return 0;
}

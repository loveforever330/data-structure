#include<bits/stdc++.h>
using namespace std;
typedef struct LNode
{
int data;
struct LNode *next;   /* data */
}LNode ,*linklist;
bool initList(linklist &L) //链表的初始化的方式
{
    L=new LNode;
    if(L==NULL) return false;
    L->next==NULL;return true;
}
linklist Listinsert(linklist &L,int e) //其中采用listinsert的方式插入一个LNode，其中的插入方式采用头插法
{
    LNode *s=new LNode;   //建立新节点  
    s->data=e;             //节点中输入数据
    s->next=L->next;        //先将原来头节点的下一个位置的地址赋值给新节点
    L->next=s;              //再将头节点的下一位更新为新节点，注意这里的顺序不可以调换，否则会丢失原来的头节点的下一位节点。
    return L; 
}
void showlist(linklist L)
{
    LNode *p=L->next;
    while (p!=NULL)
    {   
        cout<<" "<<p->data<<endl;
        p=p->next;
    }
        
}
int main()
{   int length;
    cin>>length;  //输入一定的长度
    linklist L; int x;
    initList(L);
    for(int i=0;i<length;i++)
    {
       cin>>x;
       Listinsert(L,x);

    }
    showlist(L);
    return 0;   
}
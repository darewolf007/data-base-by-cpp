#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *pnext;
    Node();
    ~Node();
} Node, *pnode;
Node::Node(void)
{
    cout << "调用了构造函数" << endl;
}
Node::~Node(void)
{
    cout << "调用了析构函数" << endl;
}
pnode creatlist(void);                //创建一个列表
void traverse(Node *);                //遍历矩阵
bool isempty(Node *);                 //判断是否为空 is_empty不可用？？
int len_list(Node *);                 //链表的长度
bool insert_list(Node *, int, int);   //在链表中插入数据是在结点前边，结点从一开始
bool delete_list(Node *, int, int *); //删除链表的结点
void sort_list(Node *);               //链表的排序
//定义列表首定义头指针
int main()
{
    pnode head = NULL;
    head = creatlist();
    traverse(head);
    if (isempty(head))
        cout << "shuchukong" << endl;
    sort_list(head);
    traverse(head);
    int pos, val;
    pos = 3;
    // cout << "请输入插入位置和值" << endl;
    // cin >> pos >> val;
    // insert_list(head, pos, val);
    delete_list(head, pos, &val);
    cout << val << endl;
    traverse(head);
    system("pause");
    // cin.get();//检测到输入结束会直接结束显示不出traver结果
    return 0;
}

pnode creatlist(void)
{
    int val; //定义链表中结点的值
    int len; //定义一个链表的有效长度

    cin >> len;
    pnode phead = (pnode)malloc(sizeof(Node)); //动态分配一个头指针
    if (NULL == phead)
    {

        cout << "分配失败" << endl;
        exit(-1);
    }
    pnode plast = phead;
    plast->pnext = NULL;
    for (int i = 0; i < len; i++)
    {
        cout << "输出需要的链表结点值" << endl;
        cin >> val;
        pnode pnewnode = (pnode)malloc(sizeof(Node));
        if (NULL == pnewnode)
        {
            cout << "分配失败" << endl;
            exit(-1);
        }
        pnewnode->data = val;
        plast->pnext = pnewnode;
        pnewnode->pnext = NULL;
        plast = pnewnode;
    }
    return phead;
}
void traverse(Node *phead)
{
    pnode p = phead->pnext;
    while (NULL != p)
    {
        cout << "输出" << p->data;
        p = p->pnext;
    }
    cout << "循环结束" << endl;
}
bool isempty(Node *phead)
{
    if (phead->pnext == NULL)
    {
        cout << "链表为空" << endl;
        return true;
    }
    else
    {
        return false;
    }
}
int len_list(Node *phead)
{
    int len = 0;
    pnode p = phead->pnext;
    while (p != NULL)
    {
        len++;
        p = p->pnext;
    }
    return len;
}
void sort_list(Node *phead)
{

    pnode p, q;
    for (p = phead->pnext; p != NULL; p = p->pnext)
    {
        for (q = p->pnext; q != NULL; q = q->pnext)
        {
            if (p->data > q->data)
            {
                int t;
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}
bool insert_list(Node *phead, int pos, int val)
{
    int i = 0;
    pnode p = phead;
    pnode pnew = (pnode)malloc(sizeof(Node));
    while (p != NULL && i < pos - 1)
    {
        p = p->pnext;
        i++;
    }
    if (p == NULL || i > pos - 1)
    {
        return false;
    }
    if (pnew == NULL)
    {
        return false;
        exit(-1);
    }
    pnew->data = val;
    pnew->pnext = p->pnext;
    p->pnext = pnew;
    // pnode q = p->pnext;
    // p->pnext = pnew;
    // pnew->pnext = q;
    return true;
}
bool delete_list(Node *phead, int pos, int *val)
{
    int i = 0;
    pnode p = phead;
    pnode q;
    while (p != NULL && i < pos - 1)
    {
        p = p->pnext;
        i++;
    }
    if (p == NULL || i > pos - 1)
    {
        return false;
    }
    q = p->pnext;
    p->pnext = q->pnext;
    *val = q->data;
    delete q;
    q = NULL;
    return true;
}
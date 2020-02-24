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
    cout << "�����˹��캯��" << endl;
}
Node::~Node(void)
{
    cout << "��������������" << endl;
}
pnode creatlist(void);                //����һ���б�
void traverse(Node *);                //��������
bool isempty(Node *);                 //�ж��Ƿ�Ϊ�� is_empty�����ã���
int len_list(Node *);                 //����ĳ���
bool insert_list(Node *, int, int);   //�������в����������ڽ��ǰ�ߣ�����һ��ʼ
bool delete_list(Node *, int, int *); //ɾ������Ľ��
void sort_list(Node *);               //���������
//�����б��׶���ͷָ��
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
    // cout << "���������λ�ú�ֵ" << endl;
    // cin >> pos >> val;
    // insert_list(head, pos, val);
    delete_list(head, pos, &val);
    cout << val << endl;
    traverse(head);
    system("pause");
    // cin.get();//��⵽���������ֱ�ӽ�����ʾ����traver���
    return 0;
}

pnode creatlist(void)
{
    int val; //���������н���ֵ
    int len; //����һ���������Ч����

    cin >> len;
    pnode phead = (pnode)malloc(sizeof(Node)); //��̬����һ��ͷָ��
    if (NULL == phead)
    {

        cout << "����ʧ��" << endl;
        exit(-1);
    }
    pnode plast = phead;
    plast->pnext = NULL;
    for (int i = 0; i < len; i++)
    {
        cout << "�����Ҫ��������ֵ" << endl;
        cin >> val;
        pnode pnewnode = (pnode)malloc(sizeof(Node));
        if (NULL == pnewnode)
        {
            cout << "����ʧ��" << endl;
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
        cout << "���" << p->data;
        p = p->pnext;
    }
    cout << "ѭ������" << endl;
}
bool isempty(Node *phead)
{
    if (phead->pnext == NULL)
    {
        cout << "����Ϊ��" << endl;
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
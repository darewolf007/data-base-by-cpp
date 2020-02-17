//�����洢����ͨ��c++ʵ��
#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;
//using namespace string;

struct listdata
{
    /* data */
    int *base; //�����ͷָ��
    int len;   //����ĳ���
    int cnt;   //�������Ч����

    listdata(){};
    ~listdata(){};
};
void init_list(listdata *, int);                //����ĳ�ʼ��
bool append(listdata *, int);                   //�����ĩ�˲���
bool defempty(listdata *);                      //�ж������Ƿ�Ϊ��
bool deffull(listdata *);                       //�ж������Ƿ�Ϊ��
void show_list(listdata *);                     //��ʾ����
bool insert_list(listdata *, int pos, int val); //��posλ�ò�������Ԫ��
bool delet_list(listdata *, int pos, int *val); //ɾ����������λ�õ�Ԫ��
int inverse_list(listdata *);                   //�û������ǰ��λ��
void sort_list(listdata *);                     //���������
int main()
{
    listdata data1; //������һ��listdata�͵Ķ���
    int len1 = 10;
    int val;
    init_list(&data1, len1);
    show_list(&data1);
    insert_list(&data1, 1, 2);
    insert_list(&data1, 2, 4);
    insert_list(&data1, 3, 6);
    insert_list(&data1, 4, 44);
    insert_list(&data1, 5, 244);
    show_list(&data1);
    inverse_list(&data1);
    show_list(&data1);
    sort_list(&data1);
    show_list(&data1);
    delet_list(&data1, 2, &val);
    cout << val << endl;
    show_list(&data1);
    cin.get();
    return 0;
}
void init_list(listdata *pdata1, int length)
{
    pdata1->base = (int *)malloc(sizeof(int) * length);
    if (NULL == pdata1->base)
    {
        cout << "1" << endl;
        exit(-1);
    }
    else
    {

        pdata1->len = length;
        pdata1->cnt = 0;
    }
}
bool defempty(listdata *pdata1)
{
    if (pdata1->cnt == 0)
        return true;
    else
    {
        return false;
    }
}
void show_list(listdata *pdata1)
{

    if (defempty(pdata1))
    {
        cout << "����˭" << endl;
    }
    else
    {
        for (int i = 0; i < pdata1->cnt; i++)
        {
            cout << pdata1->base[i] << '\t';
        }
        cout << endl;
    }
}
bool deffull(listdata *pdata1)
{

    if (pdata1->cnt == pdata1->len)
        return true;
    else
    {
        return false;
    }
}
bool append(listdata *pdata1, int val)
{

    if (deffull(pdata1))
    {
        return true;
    }
    else
    {
        pdata1->base[pdata1->cnt] = val;
        pdata1->cnt++;
        return false;
    }
}
bool insert_list(listdata *pdata1, int pos, int val)
{
    int i;
    if (deffull(pdata1) || pos < -1 || pos > pdata1->cnt + 1)
    {
        return false;
    }
    else
    {
        for (i = pdata1->cnt - 1; i >= pos - 1; --i)
        {

            pdata1->base[i + 1] = pdata1->base[i];
        }
        pdata1->base[pos - 1] = val;
        pdata1->cnt += 1;
        return true;
    }
}
bool delet_list(listdata *pdata1, int pos, int *val)
{

    if (deffull(pdata1) || pos < -1 || pos > pdata1->cnt + 1)
    {
        return false;
    }
    else
    {
        *val = pdata1->base[pos - 1];
        for (int i = pos; i < pdata1->cnt; i++)
        {
            pdata1->base[pos - 1] = pdata1->base[pos];
        }
        pdata1->cnt--;
        return true;
    }
}
int inverse_list(listdata *pdata1)
{

    int i = 0;
    int j = pdata1->cnt - 1;
    int t;
    while (i < j)
    {
        t = pdata1->base[i];
        pdata1->base[i] = pdata1->base[j];
        pdata1->base[j] = t;
        i++;
        j--;
    }
}
void sort_list(listdata *pdata1)
{

    int i, j, t;
    for (i = 0; i < pdata1->cnt - 1; ++i)
    {
        for (j = 0; j < pdata1->cnt; ++j)
        {
            if (i < j)
            {
                t = pdata1->base[i];
                pdata1->base[i] = pdata1->base[j];
                pdata1->base[j] = t;
            }
        }
    }
}

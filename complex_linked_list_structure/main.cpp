#include <bits/stdc++.h>
using namespace std;
//��ѭ���ڵ�
struct c_node {
    int data;
    c_node *next;
    c_node(){
        data;
        next = NULL;
    }
};
//˫ѭ���ڵ�
struct d_node {
    int data;
    d_node *next;
    d_node *prior;
    d_node(){
        data;
        next = NULL;
        prior = NULL;
    }
};
//��ͷ����˫ѭ������
class d_list1{
public:
    d_node *head;
    d_list1(){
        head = new d_node;
        head->prior = head;
        head->next = head;
    }
    d_list1(int n){
        if(n<=0){
            head = new d_node;
            head->prior = head;
            head->next = head;
        }
        else {
            head = new d_node;
            cout<<"��������ڵ�����"<<endl;
            d_node *ptr = head;
            for (int i = 0; i <n;i++){
                d_node *p = new d_node;
                cin>>p->data;
                ptr->next = p;
                p->prior = ptr;
                ptr = ptr->next;
            }
            ptr->next = head;
            head->prior = ptr;
        }
    }
    ~d_list1(){
        d_node *ptr = head->next;
        while(ptr!=head){
            ptr = ptr->next;
            delete ptr->prior;
        }
        delete head;
    }
    //������нڵ�����
    void Print(){
        d_node *ptr = head->next;
        while(ptr!=head){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    //�ж϶Գ�
    bool is_symmetry(){
        d_node *ptr1 = head->next;
        d_node *ptr2 = head->prior;
        while(ptr1->next!=ptr2&&ptr1!=ptr2){
            if(ptr1->data==ptr2->data){
                ptr1 = ptr1->next;
                ptr2 = ptr2->prior;
            }
            else
                return false;
        }
        return true;
    }
};
//����ͷ�ڵ���βָ�뵥ѭ������
class c_list0
{
public:
    c_node *head;
    c_list0(){head = new c_node;head->next = NULL;}
    c_list0(int n){
        head = new c_node;
        head = NULL;
        if(n <= 0) return;
        cout << "��������ڵ����ݣ� " << endl;
        c_node *d = head;
        c_node *m = new c_node;
        cin >> m->data;
        head = m;
        delete d;
        c_node *ptr = head;
        for (int i = 1; i < n; i++) {
            c_node *c = new c_node;
            cin >> c->data;
            ptr->next = c;
            ptr = ptr->next;
        }
            ptr->next = head;
    }
    ~c_list0(){
        if(!head)return;
        c_node *p = head->next;
        while(p!=head){
            c_node *ptr = p;
            p = p->next;
            delete ptr;
        }
        delete p;
    }
    //���η��ʸ��ڵ㲢�������
    void Print(){
        if(!head)return;
        c_node *ptr = head;
        cout<<ptr->data<<" ";
        ptr = ptr->next;
        while(ptr != head){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};
//��ͷ�����βָ�뵥ѭ������
class c_list1{
public:
    c_node *head;
    c_list1(){
        head = new c_node;
        head->next = head;
    }
    c_list1(int n){
        head = new c_node;
        if(n>0) cout<<"��������ڵ����ݣ� "<<endl;
        c_node *ptr = head;
        for(int i = 0;i<n;i++){
            c_node *p = new c_node;
            cin>>p->data;
            ptr->next = p;
            ptr = ptr->next;
        }
        ptr->next = head;
    }
    c_list1(const c_list1& m){
        head = new c_node;
        head->data = m.head->data;
        c_node *ptr1 = m.head->next;
        c_node *ptr2 = head;
        while(ptr1!=m.head){
            c_node *p = new c_node;
            p->data = ptr1->data;
            ptr2->next = p;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr2->next = head;
    }
    ~c_list1(){
        c_node *ptr = head->next;
        while(ptr!=head){
            c_node *p = ptr;
            ptr = ptr->next;
            delete p;
        }
        delete head;
    }
    //��ӽڵ�
    void add(int n){
        c_node *ptr;
        for(ptr = head;ptr->next!=head;ptr = ptr->next);
        c_node *p = new c_node;
        p->data = n;
        p->next = ptr->next;
        ptr->next = p;
    }
    //ɾ�����һ���ڵ�
    void pop_last(){
        c_node *ptr;
        if(head->next == head){
            return;
        }
        for(ptr = head;ptr->next->next!=head;ptr = ptr->next);
        c_node *p = ptr->next;
        ptr->next = head;
        delete p;
    }
    //������ڵ�����
    void Print(){
        c_node *ptr = head->next;
        while(ptr!=head){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    //�ж�������ÿ������Ԫ��ֵ������ŵĲ�ľ���ֵ�����ڣ�
    bool Abs_difference_fewer_3(){
        if(head->next == head) return false;
        c_node *ptr = head->next;
        int c = 0;
        while(ptr!=head){
            c++;
            if(abs(ptr->data - c)>3)
                return false;
            ptr = ptr->next;
        }
        return true;
    }

};
//����
c_list1 intersection(c_list1 &a, c_list1 &b) {
    c_list1 l;
    c_node *ptr1 = a.head->next;
    c_node *ptr2 = b.head->next;

    while(ptr1!=a.head && ptr2!=b.head){
        while(ptr1!=a.head && ptr1->data<ptr2->data){
            ptr1 = ptr1->next;
        }
        if(ptr1 == a.head)
            break;
        while(ptr2!=b.head && ptr2->data<ptr1->data){
            ptr2 = ptr2->next;
        }
        if(ptr2 == b.head)
            break;
        if(ptr1->data==ptr2->data) {
            l.add(ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    l.Print();
    return l;
}
//����
c_list1 union_set(c_list1 &a, c_list1 &b) {
    c_list1 l;
    c_node *ptr1 = a.head->next;
    c_node *ptr2 = b.head->next;
    c_node *ptr3;
    while(ptr1!=a.head&&ptr2!=b.head){
        ptr3 = ptr1->data<=ptr2->data?ptr1:ptr2;
        if(ptr1->data==ptr2->data){
            l.add(ptr3->data);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr3->data==ptr1->data){
            l.add(ptr3->data);
            ptr1=ptr1->next;
        }
        else if(ptr3->data==ptr2->data){
            l.add(ptr3->data);
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=a.head){
        while(ptr1!=a.head){
            ptr3 = ptr1;
            l.add(ptr3->data);
            ptr1=ptr1->next;
        }
    }
    else if(ptr2!=b.head){
        while(ptr2!=b.head){
            ptr3=ptr2;
            l.add(ptr3->data);
            ptr2=ptr2->next;
        }
    }
    l.Print();
    return l;
}
int main() {
    d_list1 a(11);
    cout<<a.is_symmetry();
}
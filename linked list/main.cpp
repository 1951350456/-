#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    string data;
    node *next;
}node;
node *CreateNode(){
    cout << "����ڵ������"<<endl;
    int n;
    cin >> n;
    if(n==0) return nullptr;
    node *head = new node;
    node *Node = head;
    cout << "������������ڵ����ݣ� "<<endl;
    for(int i = 0; i < n; i++){
            cin >> Node->data;
            node *a=new node;
            Node->next = a;
            Node = Node->next;
    }
    Node = nullptr;
    return head;
}
void print(node *head){
    if(head->data!=""){
        for(node *ptr = head;ptr;ptr = ptr->next){
            cout<<ptr->data<<" ";
        }
        cout<<endl;
    }
}
node *FindNode(int n,node *head) {
    for(int i =0;i<n-1;i++){
        if(head->data=="") return nullptr;
        head = head->next;
    }
    return head;
}
void InsertNode(int n,node *head){
    if(n<=0){cout<<"�޷����룡��λ�ò����ڣ�"<<endl;;return;}
    if(n==1){
        if(head->data=="") {cout<<"�޷����룡��λ�ò����ڣ�"<<endl;;return;}
        cout << "������ýڵ�����ݣ� "<<endl;
        node *a =new node;
        cin>>a->data;
        a->next = head;
        head = a;
    }
    else {
        cout << "������ýڵ�����ݣ� "<<endl;
        node *p = head;
        for(int i = 0;i<n-2;i++){
            if(p->data=="") {cout<<"�޷����룡��λ�ò����ڣ�"<<endl;return;}
            p = p->next;
        }
        if(p->data=="") {cout<<"�޷����룡��λ�ò����ڣ�"<<endl;return;}
        if(p->next->data=="") {cout<<"�޷����룡��λ�ò����ڣ�"<<endl;return;}
        node *a =new node;
        cin>>a->data;
        a->next = p->next;
        p->next = a;
    }
    cout<<"����ɹ�"<<endl;
}
node *DeleteNode(int n,node *head){
    if(n<=0){cout<<"�޷�ɾ������λ�ò����ڣ�"<<endl;;return nullptr;}
    if(n==1){
        if(head->data=="") {cout<<"�޷�ɾ������λ�ò����ڣ�"<<endl;;return nullptr;}
        node *ptr = head;
        head = head->next;
        delete ptr;
    }
    else {
        for (int i = 0; i < n - 2; i++) head = head->next;
        node *ptr = head->next;
        head->next = head->next->next;
        delete ptr;
    }
    cout<<"ɾ���ɹ���"<<endl;
    return head;
}
node *OrderedInsert(node *head,string v){
    node *s;
    if(stoi(v)<=stoi(head->data)){
        node *p = new node;
        p->data = v;
        p->next = head;
        head = p;
        return head;
    }
    for (node *ptr = head; stoi(ptr->next->data) < stoi(v); ptr = ptr->next,s = ptr){
            if(ptr->next->next->data == ""){
                ptr = ptr->next;
                node *p=new node;
                p->data = v;
                p->next = nullptr;
                ptr->next = p;
                return head;
            }
    }
    node *p = new node;
    p->data = v;
    p->next = s->next;
    s->next = p;
    return head;
}
void OddEvenPrint(node *head){
    if(head->data ==""){cout<<"����Ϊ�գ�"<<endl;return;}
    cout<<"ԭ���� "<<endl;
    print(head);
    cout<<"����� "<<endl;
    node *ptr1 = head;
    do{
        cout<<ptr1->data<<" ";
        ptr1=ptr1->next->next;
    }while(ptr1->next->data != ""&&ptr1->next->next->data != "");
    if(ptr1->data != "") cout<<ptr1->data<<endl;
    if(head->next->data ==""){cout<<"��ż���"<<endl;return;}
    cout<<"ż��� "<<endl;
    node *ptr2 = head->next;
    do{
        cout<<ptr2->data<<" ";
        ptr2=ptr2->next->next;
    }while(ptr2->next->data != ""&&ptr2->next->next->data != "");
    if(ptr2->data != "") cout<<ptr2->data<<endl;
}
node *SharedNodes(node *head1, node *head2){
    node *head = nullptr;
    node *pointer;
    node *p;
    node *ptr1= head1;
    node *ptr2= head2;
    while(ptr1->data!=""&&ptr1->data!=""){
        if(ptr1){
        while(ptr1&&ptr1->data<ptr2->data){
            ptr1 = ptr1->next;
            if(!ptr1->next){
                break;
            }
        }}
        if(ptr2){
        while(ptr2&&ptr2->data<ptr1->data){
            ptr2 = ptr2->next;
            if(!ptr2->next){
                break;
            }
        }}
        if(!ptr1||!ptr2)return head;
        if(!head){
            head = new node;
            head->data = ptr1->data;
            head->next = nullptr;
            pointer = head;
        }
        else {
            p = new node;
            p->data = ptr1->data;
            p->next = nullptr;
            pointer->next = p;
            pointer = p;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        //if(ptr1->data == ""||ptr2->data =="")
        //    return head;
    }
    return head;
}
int main(){
    node *head1 = CreateNode();
    node *head2 = CreateNode();
    node *head = SharedNodes(head1, head2);
    print(head);
}
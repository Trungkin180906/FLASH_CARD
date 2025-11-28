// xây dựng một flash card chạy trên màn hình console
// sử dụng double linked list vòng
#include <iostream>
#include <string>
using namespace std;
struct node{
    string question;// câu hỏi
    string answer;// trả lời
    node* next;// trỏ đến phần tử ở sau nó
    node* prev;// trỏ đến phần tử ở trước nó
};

struct double_linked_list{
    node* head;// con trỏ đến phần tử đầu
    node* tail;// con trỏ đến phần tử cuối
};

// khởi tạo danh sách rỗng
void init_list(double_linked_list &list){
    list.head=nullptr;
    list.tail=nullptr;
}

// thêm vào đầu 
void add_to_head(double_linked_list &list, const string &q, const string &a){
    node* new_node=new node();// cấp phát bộ nhớ cho node mới
    new_node->question=q;// gán giá trị câu hỏi
    new_node->answer=a;// gán giá trị câu trả lời
    if (list.head==nullptr) {
        list.head=list.tail=new_node;// danh sách rỗng thì cả head và tail đều trỏ đến node mới
        new_node->next=new_node;// trỏ vòng
        new_node->prev=new_node;// trỏ vòng
    }
    else{
        list.head->next=list.head;// next trỏ đến head hiện tại
        new_node->prev=list.tail;// prew trỏ đến tail hiện tại
        list.head->prev=new_node;// head hiện tại trỏ về node mới
        list.tail->next=new_node;// tail hiện tại trỏ đến node mới
        list.head=new_node;// cập nhật lại head là node mới
    }
}

// thêm vào cuối
void add_to_tail(double_linked_list &list, const string &q, const string &a){
    node* new_node=new node();
    new_code->question=q;
    new_node->answer=a;
    if (list.tail==nullptr) {
        list.head=list.tail=new_node;
        new_node->next=new_node;// trỏ vòng
        new_node->prev=new_node;// trỏ vòng
    }
    else {
        list.tail->next=new_node;
        new_node->prev=list.tail;
        list.tail->next=new_node;// trỏ vòng ngược lại với thêm vào đầu
        list.head->prev=new_node;
        list.tail=new_node;
    }
}

// hiển thị tất cả flash card
void display_flashcard(const double_linked_list &list){

}















int main(){
    double_linked_list flashcard;
    flashcard.head=nullptr;// cho con trỏ đầu tiên bằng null
    flashcard.tail=nullptr;// cho con trỏ cuối cùng bằng null
    // tôi muốn tạo menu với các chức năng mà do người dùng chọn
    int choice;
    do{
        cout<<"FLASH CARD APP"<<endl;
        cout<<"1. Thêm flash card mới vào đầu hoặc sau danh sách"<<endl;
        cout<<"2. Hiển thị tất cả flash card"<<endl;
        cout<<"3. Xóa flash card"<<endl;
        cout<<"4. Tìm kiếm flash card"<<endl;
        cout<<"5. Cập nhật flash card"<<endl;
        cout<<"6. Thoát"<<endl;
        cout<<"Nhập lựa chọn của bạn: ";
        cin>>choice;
        cin.ignore();// bỏ qua ký tự newline sau khi nhập số
        if (choise==1){
            // thêm flash card vào đầu danh sách
            node* new_node=new node();
            cout<<"Nhập từ vựng hoặc cụm từ muốn thêm vào (0/1): ";
            if (new_node->question=='0'){
                
            }
        }
    }
}

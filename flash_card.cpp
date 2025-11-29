// xây dựng một flash card chạy trên màn hình console
// sử dụng double linked list vòng
#include <iostream>
#include <string>
using namespace std;
struct node{
    string question;//câu hỏi
    string answer;//trả lời
    node* next;//trỏ đến phần tử ở sau nó
    node* prev;//trỏ đến phần tử ở trước nó
};

struct double_linked_list{
    node* head;//con trỏ đến phần tử đầu
    node* tail;//con trỏ đến phần tử cuối
};

// khởi tạo danh sách rỗng
void init_list(double_linked_list &list){
    list.head=nullptr;
    list.tail=nullptr;
}

// thêm vào đầu 
void add_to_head(double_linked_list &list, const string &q, const string &a){
    node* new_node=new node();//cấp phát bộ nhớ cho node mới
    new_node->question=q;//gán giá trị câu hỏi
    new_node->answer=a;//gán giá trị câu trả lời
    if (list.head==nullptr){//nếu danh sách rỗng
        list.head=list.tail=new_node;//danh sách rỗng thì cả head và tail đều trỏ đến node mới
        new_node->next=new_node;//trỏ vòng
        new_node->prev=new_node;//trỏ vòng
    }
    else{
        new_node->next=list.head;//node mới trỏ đến head hiện tại
        new_node->prev=list.tail;//node mới trỏ về tail hiện tại
        list.head->prev=new_node;//head hiện tại trỏ về node mới
        list.tail->next=new_node;//tail hiện tại trỏ đến node mới
        list.head=new_node;//cập nhật lại head là node mới
    }
}

//thêm vào cuối
void add_to_tail(double_linked_list &list, const string &q, const string &a){
    node* new_node=new node();
    new_node->question=q;
    new_node->answer=a;
    if (list.tail==nullptr){//danh sách rỗng
        list.head=list.tail=new_node;
        new_node->next=new_node;//trỏ vòng
        new_node->prev=new_node;//trỏ vòng
    }
    else{
        new_node->next=list.head    ;
        new_node->prev=list.tail;
        list.tail->next=new_node;//trỏ vòng ngược lại với thêm vào đầu
        list.head->prev=new_node;
        list.tail=new_node;
    }
}

// hiển thị tất cả flash card
void display_flashcard(const double_linked_list &list){//const không cho sửa danh sách khi hiển thị
    if (list.head==nullptr){//kiểm tra danh sách rỗng
        cout<<"Danh sách flash card rỗng"<<endl;
        return;//dừng
    }
    node* temp=list.head;//tạo con trỏ duyệt danh sách
    int count=1;
    do{//duyệt từ đầu đến cuối theo cơ chế vòng
        cout<<"===== Flash card ====="<<endl;
        cout<<count<<": "<<temp->question<<" : "<<temp->answer<<endl;
        cout<<"----------------------------------------\n";
        temp=temp->next;//cập nhật temp để di chuyển sang node tiếp theo
        count++;//tăng lên 1 để đếm thứ tự
    }while(temp!=list.head);//dừng khi quay lại head đầu
}

// xóa thẻ flash card hiện tại
void delete_flashcard(double_linked_list &list, node* &current){//current chuyền bảng địa chỉ để cập nhật con trỏ ngoài hàm
    if (list.head==nullptr || current==nullptr) return;
    if (current->next==current){//nếu còn lại 1 node thì sẽ trỏ về chính nó
        delete current;//giải phóng bộ nhớ
        list.head=list.tail=nullptr;//cập nhật lại từ đầu đến cuối để chuyển về ds rỗng
        current=nullptr;
    }else{
        node* temp=current->next;//lưu node kế tiếp vào temp
        current->prev->next=current->next;//trỏ đến node kế tiếp 
        current->next->prev=current->prev;//node kế tiếp trỏ ngược lại
        if (current==list.head) list.head=current->next;//nếu node hiện tại là head thì cập nhật head mới là node kế tiếp
        if (current==list.tail) list.tail=current->prev;//nếu node hiện tại là tail thì cập nhật tail mới là node trước nó
        delete current;//giải phóng bộ nhớ
        current=temp;//chuyển sang node tiếp theo
    }
}

// tìm kiếm flash card
void find_flashcard(const double_linked_list &list, const string &key){
    if (list.head==nullptr){
        cout<<"Danh sách rỗng"<<endl;
        return;
    }
    node* temp=list.head;//tạo con trỏ duyệt ds
    int count=1;
    do{
        if (temp->question==key){
            cout<<"===== FLASH CARD ====="<<endl;
            cout<<count<<": "<<temp->question<<" : "<<temp->answer<<endl;
            cout<<"-----------------------------------------\n";
            return;
        }temp=temp->next;//di chuyển đến nút tiếp theo để tìm kiếm
    }while(temp!=list.head);
    cout<<"Không tìm thấy flash card"<<endl;
}

// cập nhật flah carđ
void update_flashcard(double_linked_list &list, const string &update){
    if (list.head==nullptr){
        cout<<"Danh sách flash card rỗng"<<endl;
        return;
    }
    node* temp=list.head;//tạo con trỏ duyệt ds
    do{
        if (temp->question==update){
            cout<<"Tìm thấy flash card. Nhập new flash card (nhấn Enter để giữ nguyên): ";
            string new_question;
            cin.ignore();
            getline(cin, new_question);
            if (!new_question.empty()) temp->question=new_question;//nếu nhập khác rỗng thì cập nhật lại question

            cout<<"Nhập đáp án mới: ";
            string new_answer;
            cin.ignore();
            getline(cin, new_answer);
            if (!new_answer.empty()) temp->answer=new_answer;//nếu nhập khác rỗng cập nhật lại đáp án
            return;
        }temp=temp->next;//di chuyển đến nút tiếp theo để cập nhật
    }while(temp!=list.head);
    cout<<"Không tìm thấy flash card\n";
}

int main(){
    double_linked_list flashcard;//tạo ds flash card
    init_list(flashcard);//khởi tạo ds
    node* current=nullptr;
    int choice;
    do{
        cout<<"\n===== FLASH CARD APP ======"<<endl;
        cout<<"1. Thêm flash card mới vào đầu hoặc sau danh sách"<<endl;
        cout<<"2. Hiển thị tất cả flash card"<<endl;
        cout<<"3. Xóa flash card"<<endl;
        cout<<"4. Tìm kiếm flash card"<<endl;
        cout<<"5. Cập nhật flash card"<<endl;
        cout<<"6. Thoát"<<endl;
        cout<<"Nhập lựa chọn của bạn: ";
        cin>>choice;
        cin.ignore();// bỏ qua ký tự newline sau khi nhập số
        if (choice==1){
            string i, q, a;
            cout<<"Nhập vị trí muốn thêm (head/tail): ";
            getline(cin, i);//vị trí thêm
            cout<<"Nhập từ vựng: ";
            getline(cin, q);//vị trí hỏi
            cout<<"Nhập nghĩa: ";
            getline(cin, a);//vị trí trả lời
            if(i=="head") add_to_head(flashcard, q, a);//vào đầu
            else add_to_tail(flashcard, q, a);//vào cuối
            if(!current) current=flashcard.head;//nếu rỗng thì mặc định nào đầu ds
            cout<<"Thêm flash card thành công\n";
        }else if(choice==2){
            display_flashcard(flashcard);
        }else if(choice==3){
            string key;
            cout<<"Nhập từ vựng bạn cần xóa: ";
            getline(cin, key);
            node* temp=flashcard.head;//bắt đầu từ đầu ds
            bool found=false;//tạo cờ xem có thấy thẻ cần xóa không 
            if(temp){
                do{
                    if(temp->question==key){
                        current=temp;//gán node hiện tại cho node cần xóa
                        delete_flashcard(flashcard, current);
                        found=true;//đánh dấu đã tìm thấy
                        cout<<"Đã xóa flash card\n";
                        break;
                    }
                    temp=temp->next;//di chuyển đến node kế tiếp
                }while(temp!=flashcard.head);
            }if(!found) cout<<"Không tìm thấy flash card\n";
        }else if(choice==4){
            string key;
            cout<<"Nhập từ vựng mà bạn muốn tìm kiếm: ";
            getline(cin, key);
            find_flashcard(flashcard, key);
        }else if(choice==5){
            string key;
            cout<<"Nhập từ vựng mà bạn muốn cập nhật: ";
            getline(cin, key);
            update_flashcard(flashcard, key); 
        }else if(choice==6){
            cout<<"Thoát chương trình\n";
        }else{
            cout<<"Lựa chọn không hợp lệ\n";
        }
    }while(choice!=6);
    return 0;
}

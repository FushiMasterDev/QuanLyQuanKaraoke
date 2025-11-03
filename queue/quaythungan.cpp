#include <iostream>
#include <string>
using namespace std;

// ========================== CẤU TRÚC NÚT ==========================
struct Node
{
    string tenKhach;
    Node *next;
};

// ========================== LỚP HÀNG ĐỢI ==========================
class Queue
{
private:
    Node *front; // con trỏ đầu hàng
    Node *rear;  // con trỏ cuối hàng
public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    // Thêm khách vào hàng (enqueue)
    void enqueue(const string &ten)
    {
        Node *newNode = new Node{ten, nullptr};
        if (rear == nullptr)
        { // hàng trống
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "✅ Đã thêm khách \"" << ten << "\" vào hàng đợi.\n";
    }

    // Xử lý khách đầu tiên (dequeue)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "⚠️ Hàng đợi trống! Không có khách để xử lý.\n";
            return;
        }
        Node *temp = front;
        cout << "🧾 Đang xử lý khách: " << front->tenKhach << endl;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    // Hiển thị hàng đợi
    void display()
    {
        if (isEmpty())
        {
            cout << "📭 Hàng đợi hiện đang trống.\n";
            return;
        }
        cout << "\n📋 Danh sách khách trong hàng:\n";
        Node *temp = front;
        int i = 1;
        while (temp != nullptr)
        {
            cout << i++ << ". " << temp->tenKhach << endl;
            temp = temp->next;
        }
    }

    // Hủy hàng đợi
    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }
};

// ========================== CHƯƠNG TRÌNH CHÍNH ==========================
int main()
{
    Queue hangDoi;
    int chon;
    string ten;

    do
    {
        cout << "\n==== HÀNG ĐỢI SIÊU THỊ ====\n";
        cout << "1. Thêm khách hàng vào hàng\n";
        cout << "2. Xử lý khách tiếp theo\n";
        cout << "3. Hiển thị hàng đợi hiện tại\n";
        cout << "4. Thoát\n";
        cout << "Chọn: ";
        cin >> chon;
        cin.ignore(); // bỏ ký tự xuống dòng sau khi nhập số

        switch (chon)
        {
        case 1:
            cout << "Nhập tên khách hàng: ";
            getline(cin, ten);
            hangDoi.enqueue(ten);
            break;
        case 2:
            hangDoi.dequeue();
            break;
        case 3:
            hangDoi.display();
            break;
        case 4:
            cout << "👋 Kết thúc chương trình.\n";
            break;
        default:
            cout << "⚠️ Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }
    } while (chon != 4);

    return 0;
}

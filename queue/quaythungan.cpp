#include <iostream>
#include <string>
using namespace std;

// Cau truc node
struct Node
{
    string tenKhach;
    Node *next;
};

// Lop hang doi
class Queue
{
private:
    Node *front; // con tro dau hang
    Node *rear;  // con tro cuoi hang
public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    // Them khach vao hang (enqueue)
    void enqueue(const string &ten)
    {
        Node *newNode = new Node{ten, nullptr};
        if (rear == nullptr)
        { // hang trong
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Da them khach \"" << ten << "\" vao hang doi.\n";
    }

    // Xu ly khach dau tien (dequeue)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Hang doi trong! Khong co khach de xu ly.\n";
            return;
        }
        Node *temp = front;
        cout << "Dang xu ly khach: " << front->tenKhach << endl;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    // Hien thi hang doi
    void display()
    {
        if (isEmpty())
        {
            cout << "Hang doi hien dang trong.\n";
            return;
        }
        cout << "\nDanh sach khach trong hang:\n";
        Node *temp = front;
        int i = 1;
        while (temp != nullptr)
        {
            cout << i++ << ". " << temp->tenKhach << endl;
            temp = temp->next;
        }
    }

    // Huy hang doi
    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }
};

// ========================== CHUONG TRINH CHINH ==========================
int main()
{
    Queue hangDoi;
    int chon;
    string ten;

    do
    {
        cout << "\n==== HANG DOI SIEU THI ====\n";
        cout << "1. Them khach hang vao hang\n";
        cout << "2. Xu ly khach tiep theo\n";
        cout << "3. Hien thi hang doi hien tai\n";
        cout << "4. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            cout << "Nhap ten khach hang: ";
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
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (chon != 4);

    return 0;
}

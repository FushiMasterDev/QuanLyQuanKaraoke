#include <iostream>
using namespace std;

// Cau truc Node
struct Node
{
    string tenKhach;
    Node *next;
};

typedef struct Node *node;
// Tao Node moi
node makeNode(string ten)
{
    node tmp = new Node();
    tmp->tenKhach = ten;
    tmp->next = NULL;
    return tmp;
}

// Lop hang doi
class Queue
{
private:
    Node *first;
    Node *last;

public:
    Queue()
    {
        first = last = NULL;
    }
    bool empty()
    {
        return first == NULL;
    }

    // Them khach hang
    void add(string ten)
    {
        node tmp = makeNode(ten);
        if (empty())
        {
            first = last = tmp;
        }
        else
        {
            last->next = tmp;
            last = tmp;
            cout << "Da them khach " << ten << " vao hang doi.\n";
        }
    }

    // Xu li khach hang
    void dequeue()
    {
        if (empty())
        {
            cout << "Hang doi trong. Khong co khach de xu li";
            return;
        }
        node temp = first;
        cout << "Dang xu li khach " << first->tenKhach << endl;
        first = first->next;
        if (first == NULL)
            last = NULL;
        delete temp;
    }

    // Hien thi danh sach hang doi
    void display()
    {
        if (empty())
        {
            cout << "Hang doi hien dang trong.\n";
            return;
        }
        cout << "\nDanh sach khach trong hang:\n";
        node temp = first;
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
        while (!empty())
            dequeue();
    }
};

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
            hangDoi.add(ten);
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
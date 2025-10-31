#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// PHONG KARAOKE

// Loai phong
enum class LoaiPhong
{
    VIP,
    Thuong,
    GiaDinh
};

// Trang thai phong
enum class TrangThai
{
    Trong,
    CoKhach,
    BaoTri
};

// Chuyen enum sang chuoi
string loaiPhong(LoaiPhong loai)
{
    switch (loai)
    {
    case LoaiPhong::VIP:
        return "VIP";
    case LoaiPhong::Thuong:
        return "Thuong";
    case LoaiPhong::GiaDinh:
        return "Gia Dinh";
    }
    return "";
}

string trangThai(TrangThai tt)
{
    switch (tt)
    {
    case TrangThai::Trong:
        return "Trong";
    case TrangThai::CoKhach:
        return "Co Khach";
    case TrangThai::BaoTri:
        return "Bao Tri";
    }
    return "";
}

// Lop phong quan karaoke
class Phong
{
private:
    int ma;
    LoaiPhong loaiphong;
    double gia;
    int suc_chua;
    TrangThai trangthai;
    double tong_doanh_thu;

public:
    Phong() : ma(0), loaiphong(LoaiPhong::Thuong), gia(0), suc_chua(0), trangthai(TrangThai::Trong), tong_doanh_thu(0)
    {
        giatheoloai();
    }
    Phong(int ma, LoaiPhong loai, int suc, TrangThai trangt) : ma(ma), loaiphong(loai), gia(0), suc_chua(suc), trangthai(trangt), tong_doanh_thu(0)
    {
        giatheoloai();
    }

    // Gan gia tri cho loai phong
    void giatheoloai()
    {
        switch (loaiphong)
        {
        case LoaiPhong::VIP:
            gia = 500000;
            break;
        case LoaiPhong::Thuong:
            gia = 300000;
            break;
        case LoaiPhong::GiaDinh:
            gia = 400000;
            break;
        }
    }

    // setter doanh thu
    void doanhThu(double hoa_don)
    {
        tong_doanh_thu += hoa_don;
    }

    // Toan tu nhap
    friend istream &operator>>(istream &in, Phong &p)
    {
        int loai;
        cout << "Nhap ma phong: ";
        in >> p.ma;
        cout << "Chon loai phong (1: VIP, 2: Thuong, 3: Gia Dinh): ";
        in >> loai;
        switch (loai)
        {
        case 1:
            p.loaiphong = LoaiPhong::VIP;
            break;
        case 2:
            p.loaiphong = LoaiPhong::Thuong;
            break;
        case 3:
            p.loaiphong = LoaiPhong::GiaDinh;
            break;
        default:
            p.loaiphong = LoaiPhong::Thuong;
            break;
        }
        cout << "Nhap suc chua: ";
        in >> p.suc_chua;
        p.trangthai = TrangThai::Trong;
        p.giatheoloai();
        return in;
    }

    // Toan tu xuat
    friend ostream &operator<<(ostream &out, const Phong &p)
    {
        out << "Ma phong: " << p.ma
            << ", Loai: " << loaiPhong(p.loaiphong)
            << ", Gia/1h: " << p.gia
            << ", Suc chua: " << p.suc_chua
            << ", Trang thai: " << trangThai(p.trangthai)
            << ", Tong doanh thu: " << p.tong_doanh_thu;
        return out;
    }

    // Toan tu so sanh
    bool operator<(const Phong &other) const
    {
        return tong_doanh_thu < other.tong_doanh_thu;
    }

    // getter
    int getMa() const
    {
        return ma;
    }
    double getGia() const
    {
        return gia;
    }
    LoaiPhong getLoai() const
    {
        return loaiphong;
    }
    TrangThai getTT() const
    {
        return trangthai;
    }
    double getDoanhThu() const
    {
        return tong_doanh_thu;
    }

    // setter
    void setLoai(LoaiPhong l)
    {
        loaiphong = l;
        giatheoloai();
    }

    void setTT(TrangThai t)
    {
        trangthai = t;
    }

    void setMa(int m)
    {
        ma = m;
    }

    void setSucchua(int s)
    {
        suc_chua = s;
    }
};

// Khach hang
class KhachHang
{
private:
    vector<Phong> dsPhong;
    int ma;
    int SDT;
    string ten;

public:
    KhachHang() {}
    KhachHang(int ma, int SDT, string ten)
    {
        this->ma = ma;
        this->SDT = SDT;
        this->ten = ten;
    }

    friend istream &operator>>(istream &in, KhachHang &K)
    {
        cout << "Nhap ma khach hang: ";
        in >> K.ma;
        in.ignore();
        cout << "Nhap ten khach hang: ";
        getline(in, K.ten);
        cout << "Nhap so dien thoai: ";
        in >> K.SDT;
        return in;
    }

    friend ostream &operator<<(ostream &out, KhachHang &K)
    {
        out << "Ma: " << K.ma << ", Ten: " << K.ten << ", SDT: " << K.SDT;
        return out;
    }
};

// QUAN LY KARAOKE

class QuanlyKaraoke
{
private:
    vector<Phong> dsPhong;

public:
    // Them phong
    void them()
    {
        Phong p;
        cin >> p;
        dsPhong.push_back(p);
    }

    // Sua phong
    void sua()
    {
        int ma;
        cout << "Nhap ma can sua: ";
        cin >> ma;

        bool found = false;

        for (auto &p : dsPhong)
        {
            if (p.getMa() == ma)
            {
                found = true;
                cout << "\n Thong tin can sua \n";
                cout << p << "\n";

                // Nhap lai thong tin phong
                int maM, loai, suc_chuaM;
                cout << "Nhap ma phong moi: ";
                cin >> maM;
                p.setMa(maM);

                cout << "Chon loai phong moi (1: VIP, 2: Thuong, 3: Gia Dinh): ";
                cin >> loai;
                switch (loai)
                {
                case 1:
                    p.setLoai(LoaiPhong::VIP);
                    break;
                case 2:
                    p.setLoai(LoaiPhong::Thuong);
                    break;
                case 3:
                    p.setLoai(LoaiPhong::GiaDinh);
                    break;
                default:
                    p.setLoai(LoaiPhong::Thuong);
                    break;
                }
                cout << "Nhap suc chua moi: ";
                cin >> suc_chuaM;
                p.setSucchua(suc_chuaM);

                cout << "Da cap nhat thanh cong\n";
                break;
            }
        }

        if (!found)
        {
            cout << "Khong tim thay ma phong";
        }
    }

    // Xoa phong
    void xoa()
    {
        int ma;
        cout << "Nhap ma can xoa: ";
        cin >> ma;
        for (auto it = dsPhong.begin(); it != dsPhong.end(); ++it)
        {
            if (it->getMa() == ma)
            {
                dsPhong.erase(it);
                cout << "Da xoa thanh cong";
                return;
            }
        }
        cout << "Khong tim thay ma phong";
    }

    // Hien thi danh sach
    void hienthiPhong() const
    {
        if (dsPhong.empty())
        {
            cout << "Danh sach phong trong";
            return;
        }
        cout << "\n Danh sach phong \n";
        for (const auto &p : dsPhong)
        {
            cout << p << endl;
        }
    }

    // Sap xep doanh thu
    void merge(vector<Phong> &arr, int first, int mid, int last)
    {
        int n1 = mid - first + 1;
        int n2 = last - mid;

        vector<Phong> L(n1);
        vector<Phong> R(n2);

        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[first + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = first;

        while (i < n1 && j < n2)
        {
            if (L[i].getDoanhThu() <= R[j].getDoanhThu())
            {
                arr[k] = L[i];
                i++;
                k++;
            }
            else
            {
                arr[k] = R[j];
                j++;
                k++;
            }
        }

        while (i < n1)
        {
            arr[k++] = L[i++];
        }
        while (j < n2)
        {
            arr[k++] = R[j++];
        }
    }

    void mergeSort(vector<Phong> &arr, int first, int last)
    {
        if (first < last)
        {
            int mid = first + (last - first) / 2;
            mergeSort(arr, first, mid);
            mergeSort(arr, mid + 1, last);
            merge(arr, first, mid, last);
        }
    }

    void sapxep()
    {
        if (dsPhong.empty())
        {
            cout << "Danh sach trong\n";
            return;
        }
        mergeSort(dsPhong, 0, static_cast<int>(dsPhong.size()) - 1);
        cout << "Sap xep thanh cong\n";
    }

    // Tim Max
    void PhongMax()
    {
        if (dsPhong.empty())
        {
            cout << "Danh sach trong\n";
            return;
        }
        auto phongMax = max_element(dsPhong.begin(), dsPhong.end());
        cout << "Phong co doanh thu cao nhat: " << *phongMax << endl;
    }

    // Tim Min
    void PhongMin()
    {
        if (dsPhong.empty())
        {
            cout << "Danh sach trong\n";
            return;
        }
        auto phongMin = min_element(dsPhong.begin(), dsPhong.end());
        cout << "Phong co doanh thu thap nhat: " << *phongMin << endl;
    }

    // Dat Phong
    void datPhong()
    {
        if (dsPhong.empty())
        {
            cout << "Danh sach trong\n";
            return;
        }

        int ma;
        cout << "Nhap ma phong can dat: ";
        cin >> ma;

        for (auto &p : dsPhong)
        {
            if (p.getMa() == ma)
            {
                if (p.getTT() == TrangThai::Trong)
                {
                    p.setTT(TrangThai::CoKhach);
                    cout << "Dat phong thanh cong. Phong " << ma << " da co khach\n";
                }
                else if (p.getTT() == TrangThai::CoKhach)
                {
                    cout << "Phong nay co khach, khong the dat\n";
                }
                else
                {
                    cout << "Phong dan bao tri, khong the dat";
                }
                return;
            }
        }
        cout << "Khong tim thay ma phong";
    }

    // Tra Phong
    void traPhong()
    {
        int ma;
        cout << "Nhap ma phong can tra: ";
        cin >> ma;

        int thoi_gian;
        cout << "Nhap thoi gian su dung: ";
        cin >> thoi_gian;

        for (auto &p : dsPhong)
        {
            if (p.getMa() == ma)
            {
                if (p.getTT() == TrangThai::CoKhach)
                {
                    p.setTT(TrangThai::Trong);
                    double hoa_don = thoi_gian * p.getGia();
                    p.doanhThu(hoa_don);
                    cout << fixed << setprecision(0);
                    cout << "Phong " << ma << " da tra thanh cong.\n";
                    cout << "Hoa don: " << hoa_don << " VND\n";
                    cout << "Trang thai phong: Trong\n";
                }

                else
                {
                    cout << "Phong khong co khach de tra\n";
                }
                return;
            }
        }
        cout << "Khong tim thay ma phong";
    }

    void menu()
    {
        int chon;
        do
        {
            cout << "\n========= MENU QUẢN LÝ KARAOKE =========\n";
            cout << "1. Thêm phòng\n";
            cout << "2. Sửa phòng\n";
            cout << "3. Xóa phòng\n";
            cout << "4. Hiển thị danh sách phòng\n";
            cout << "5. Sắp xếp phòng theo doanh thu\n";
            cout << "6. Tìm phòng có doanh thu cao nhất\n";
            cout << "7. Tìm phòng có doanh thu thấp nhất\n";
            cout << "8. Đặt phòng\n";
            cout << "9. Trả phòng\n";
            cout << "0. Thoát\n";
            cout << "----------------------------------------\n";
            cout << "Lựa chọn: ";
            cin >> chon;

            switch (chon)
            {
            case 1:
                them();
                break;
            case 2:
                sua();
                break;
            case 3:
                xoa();
                break;
            case 4:
                hienthiPhong();
                break;
            case 5:
                sapxep();
                break;
            case 6:
                PhongMax();
                break;
            case 7:
                PhongMin();
                break;
            case 8:
                datPhong();
                break;
            case 9:
                traPhong();
                break;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ!\n";
            }
        } while (chon != 0);
    }
};

int main()
{
    QuanlyKaraoke app;
    app.menu();
    return 0;
}
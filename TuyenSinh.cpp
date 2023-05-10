#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

class HocSinh;
class HoSoDangKy;
class Nganh;
class QuanLyTuyenSinh;

class HocSinh
{
private:
    string _tenHS;
    string _maHS;
    string _diachi;
    double _diem3mon;
    vector<string> _nguyenVong;

public:
    string getTen() { return _tenHS; }
    void setTen(string value)
    {
        _tenHS = value;
    }
    string getMaHS() { return _maHS; }
    void setMaHS(string value)
    {
        _maHS = value;
    }
    string getDiachi() { return _diachi; }
    void setDiachi(string value)
    {
        _diachi = value;
    }
    double getDiem3mon() { return _diem3mon; }
    void setDiem3mon(double value)
    {
        _diem3mon = value;
    }
    vector<string> getNguyenVong()
    {
        return _nguyenVong;
    }
    void themNguyenVong(string maNganh)
    {
        _nguyenVong.push_back(maNganh);
    }

public:
    HocSinh(string ten, string maHs, string diachi, float diem3mon)
    {
        _tenHS = ten;
        _maHS = maHs;
        _diachi = diachi;
        _diem3mon = diem3mon;
    }

public:
    HocSinh();
};
HocSinh::HocSinh()
{
    // constructor code goes here
}

class Nganh
{
private:
    string _tenNganh;
    string _maNganh;
    double _diemChuan;
    int _chiTieu;

public:
    string getTennganh() { return _tenNganh; }
    void setTenNganh(string value)
    {
        _tenNganh = value;
    }
    string getMaNganh() { return _maNganh; }
    void setMaNganh(string value)
    {
        _maNganh = value;
    }
    double getDiemchuan() { return _diemChuan; }
    void setDiemchuan(double value)
    {
        _diemChuan = value;
    }
    int getChitieu() { return _chiTieu; }
    void setCHitieu(int value)
    {
        _chiTieu = value;
    }

public:
    Nganh(string tennganh, string manganh, double diemchuan, int chitieu)
    {
        _tenNganh = tennganh;
        _maNganh = manganh;
        _diemChuan = diemchuan;
        _chiTieu = chitieu;
    }

public:
    Nganh();
};
Nganh::Nganh()
{
    // constructor code goes here
}
class HoSoDangKy
{
private:
    HocSinh hocsinh;
    Nganh nganh;
    vector<string> _nguyenVong;

    // public:
    //     HoSoDangKy();
    //     HocSinh hocsinh();

public:
    HoSoDangKy(HocSinh hocsinh)
    {
        this->hocsinh = hocsinh;
    }
    HocSinh getHocSinh()
    {
        return hocsinh;
    }
    HoSoDangKy(Nganh nganh)
    {
        this->nganh = nganh;
    }
    Nganh getNganh()
    {
        return nganh;
    }
    vector<string> getNguyenVong()
    {
        return _nguyenVong;
    }
    void themNguyenVong(string maNganh)
    {
        _nguyenVong.push_back(maNganh);
    }
};

class QuanLyTuyenSinh
{
private:
    vector<HocSinh> danhSachHS;
    vector<Nganh> danhSachNganh;
    vector<HoSoDangKy> danhSachHoSo;

public:
    void themHocSinh(HocSinh hs)
    {
        // HocSinh hs(ten, maHs, diachi, diem3mon);
        danhSachHS.push_back(hs);
    }
    void themNganh(Nganh nganh)
    {
        // Nganh nganh(ten, manganh, chiTieu, diemChuan);
        danhSachNganh.push_back(nganh);
    }

    void dangKy(string tenHS, string maNganh)
    {
        for (int i = 0; i < danhSachHS.size(); i++)
        {
            if (danhSachHS[i].getTen() == tenHS)
            {
                danhSachHS[i].themNguyenVong(maNganh);
            }
        }
        for (int i = 0; i < danhSachHoSo.size(); i++)
        {
            if (danhSachHoSo[i].getHocSinh().getTen() == tenHS)
            {
                danhSachHoSo[i].themNguyenVong(maNganh);
            }
        }
    }
    void hienThiDanhSachHocSinh()
    {
        cout << "Danh sach hoc sinh:" << endl;
        for (int i = 0; i < danhSachHS.size(); i++)
        {
            cout << danhSachHS[i].getTen() << " - " << danhSachHS[i].getMaHS() << " - " << danhSachHS[i].getDiachi() << " - " << danhSachHS[i].getDiem3mon() << endl;
        }
    }
    void hienThiDanhSachNganh()
    {
        cout << "Danh sach nganh: " << endl;
        for (int i = 0; i < danhSachNganh.size(); i++)
        {
            cout << danhSachNganh[i].getMaNganh() << " - " << danhSachNganh[i].getTennganh() << " - " << danhSachNganh[i].getDiemchuan() << " - " << danhSachNganh[i].getChitieu() << endl;
        }
    }
    bool kiemTraSinhVienDau(HocSinh hs, Nganh nganh)
    {
        cout << "Diem 3 mon: " << hs.getDiem3mon() << endl;
        cout << "Diem chuan: " << nganh.getDiemchuan() << endl;
        if (hs.getDiem3mon() >= (nganh.getDiemchuan()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Nganh *timNganhTheoMa(string maNganh)
    {
        for (int i = 0; i < danhSachNganh.size(); i++)
        {
            if (danhSachNganh[i].getMaNganh() == maNganh)
            {
                return &danhSachNganh[i];
            }
        }
        return nullptr;
    }
    void themHoSo()
    {
        string tenHS, maNganh;
        cout << "Nhap ten hoc sinh: ";
        cin.ignore();
        getline(cin, tenHS);
        cout << "Nhap ma nganh: ";
        getline(cin, maNganh);
        Nganh *nganh = timNganhTheoMa(maNganh);
        if (nganh == nullptr)
        {
            cout << "Khong tim thay nganh!" << endl;
            return;
        }
        HoSoDangKy hsdk(*nganh);
        danhSachHoSo.push_back(hsdk);
        cout << "Them ho so thanh cong!" << endl;
    }
    void hienThiDanhSachHoSo()
    {
        cout << "Danh sach ho so: " << endl;

        for (int i = 0; i < danhSachHoSo.size(); i++)
        {
            HoSoDangKy hsdk = danhSachHoSo[i];
            cout << "Ten hoc sinh: " << hsdk.getHocSinh().getTen() << endl;
            cout << "Ma nganh: " << hsdk.getNganh().getMaNganh() << endl;
            cout << "Trang thai: ";
            Nganh *nganh = timNganhTheoMa(hsdk.getNganh().getMaNganh());
            if (nganh != nullptr && kiemTraSinhVienDau(hsdk.getHocSinh(), *nganh))
            {
                cout << "Sinh vien dau" << endl;
            }
            else if (nganh != nullptr)
            {
                cout << "Sinh vien rot" << endl;
            }
            else
            {
                cout << "Khong tim thay nganh!" << endl;
            }
            cout << endl;
        }
    }
};
int main()
{
    QuanLyTuyenSinh qlts;
    int Luachon;
    do
    {
        cout << " Quan ly chuong trinh tuyen sinh" << endl;
        cout << "1. Them Hoc Sinh: " << endl;
        cout << "2. Them nganh" << endl;
        cout << "3. Dang ky nguyen vong" << endl;
        cout << "4. Them Ho So" << endl;
        cout << "5. Hien thi danh sach sinh vien" << endl;
        cout << "6. Hien thi danh sach nganh" << endl;
        cout << "7. Hien thi danh sach ho so" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> Luachon;
        switch (Luachon)
        {
        case 1:
        {
            string ten;
            string maHs;
            string diachi;
            float diem3mon;
            cout << "nhap ten sinh vien: ";
            cin.ignore();
            getline(cin, ten);
            cout << "Nhap ma sinh vien: ";
            getline(cin, maHs);
            cout << "Nhap dia chi: ";
            getline(cin, diachi);
            cout << "Nhap diem sinh vien: ";
            cin >> diem3mon;
            HocSinh hs(ten, maHs, diachi, diem3mon);
            qlts.themHocSinh(hs);
            cout << "Them sinh vien thanh cong" << endl;
            break;
        }
        case 2:
        {
            string tenNganh;
            string maNganh;
            int chiTieu;
            float diemChuan;
            cout << "Nhap ten nganh: ";
            cin.ignore();
            getline(cin, tenNganh);
            cout << "Nhap ma nganh: ";
            getline(cin, maNganh);
            cout << "Nhap diem chuan: ";
            cin >> diemChuan;
            cout << "Nhap chi tieu: ";
            cin >> chiTieu;
            Nganh nganh(tenNganh, maNganh, diemChuan, chiTieu);
            qlts.themNganh(nganh);
            cout << "Them nganh thanh cong" << endl;
            break;
        }
        case 3:
        {
            string maHS;
            string maNganh;
            cout << "Nhap ma sinh vien: ";
            cin.ignore();
            getline(cin, maHS);
            cout << "Nhap ma nganh: ";
            getline(cin, maNganh);
            qlts.dangKy(maHS, maNganh);
            cout << "Dang ky nguyen vong thanh cong" << endl;
            break;
        }
        case 4:
        {

            qlts.themHoSo();
            break;
        }

        case 5:
        {
            qlts.hienThiDanhSachHocSinh();
            break;
        }
        case 6:
        {
            qlts.hienThiDanhSachNganh();
            break;
        }
        case 7:
        {
            qlts.hienThiDanhSachHoSo();
            break;
        }
        break;

        default:
        {
            cout << "Lua chon khong hop le:" << endl;
            break;
        }
        }
    } while (Luachon != 0);
    return 0;
}

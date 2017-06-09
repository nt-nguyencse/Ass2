#pragma once
#include "mLibpro_data.h"
#include <vector>

/*Load data*/
std::vector<Account> loadaccount_data();
std::vector<User> loaduser_data();
std::vector<Book> loadBook();
std::vector<Hosomuonsach> loadHSmuonsach();
std::vector<Tienno> loadtienno();
std::vector<AccountRoleMap> loadaccountrolemap();
std::vector<Role> loadrole();
std::vector<Giohang> loadGioHang();
std::vector<Account_User> loadAccountUser();
void load_tienno();

/*Save data*/

void savehosomuonsach();
void savefilebook();
void savefilegioHang();
void savefileaccount_user_data();
void savefileuser_data();
void savefileaccountrolemap_data();
void savefiletienno();
void savefileaccount_data();

/*cac hoat dong lien quan den muon tra sach*/
void themvaogiohang(std::string _account_name);
void tudonghuydonhang();
void xoadonhang(std::string account_name);
void guiyeucaumuonsach(std::string account_name);
void xemthongtinmuontra(std::string account_name);
void timsach(std::string _account_name);
bool xemgiohang(std::string _account_name);
bool xemdonhang(std::string _account_name);
void xoakhoidonhang(std::string _account_name);
void xoakhoigiohang(std::string _account_name);
void xacnhanmuonsach(std::string account_name);
void trasach();
void nhactrasach(std::string account_name);

/*Cac hoat dong lien quan den nguoi dung*/

void themnguoidung();
void timkiemnguoidung();
void xoanguoidung();

/*Cac hoat dong lien quan den tai khoan*/
void timkiemtheotaikhoan();
void mokhoataikhoan();
void xoataikhoan();
void themtaikhoan();

/*Cac hoat dong lien quan den tien no*/
void xemno(std::string account_name);
void nhantrano();

/*Cac hoat dong lien quan den sach*/

void themsach();

/*____________________________________________________________________*/
/*MOT SO XU LI QUAN TRONG*/

//get current time 
Time time();
// giai thuat kmp tim kiem chuoi
bool timkiem(std::string s, std::string w);
//dang nhap
std::string dangnhap();
void doimatkhau(std::string account_name);
bool kiemtramatkhau(std::string pass);
bool kiemtratrangthai(std::string account_name);
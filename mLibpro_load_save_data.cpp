#include "mLibpro_load_save_data.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <vector>
#include "sha512.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#define THOI_GIAN_MUON_TOI_DA 60
#define THOI_GIAN_NHAC 30
#define THOI_GIAN_GIU_DON_HANG 300
#define DON_VI_PHAT 1000
#define NGAY 7200
#define __STDC_WANT_LIB_EXT1__ 1
using namespace std;
vector<Account_User> account_user_data = loadAccountUser();
vector<Role> role_data = loadrole();
vector<AccountRoleMap> accountrolemap_data = loadaccountrolemap();
vector<Tienno> tienno_data = loadtienno();
vector<User> user_data = loaduser_data();
vector<Account> account_data = loadaccount_data();
vector<Book> book = loadBook();
vector<Giohang> giohang_data = loadGioHang();
vector<Hosomuonsach> hosomuonsach_data = loadHSmuonsach();// Biến toàn cục
/*load data*/
vector<Account> loadaccount_data() {
	vector<Account> account;
	Account x;
	fstream f;
	f.open("account_data.txt");
	string str, catchuoi;
	stringstream s;
	while (!f.eof()) {
		s.str("");
		s.clear();
		getline(f, str);
		if (str.empty()) continue;
		s << str;
		s >> catchuoi;
		x.setAccountId(catchuoi);
		s >> catchuoi;
		x.setPassword(catchuoi);
		s >> catchuoi;
		x.setActive(catchuoi);
		account.push_back(x);
	}
	f.close();
	return account;
}

vector<User> loaduser_data() {
	vector<User> user;
	User x;
	ifstream f;
	f.open("user_data.txt");
	string str, catchuoi;
	stringstream s;
	while (!f.eof()) {
		s.str("");
		s.clear();
		getline(f, str);
		if (str.empty()) continue;
		x.setUser_name(str);
		getline(f, str);
		s << str;
		s >> catchuoi;
		x.setUser_no(catchuoi);
		s >> catchuoi;
		x.setdob(catchuoi);
		s >> catchuoi;
		x.setemail(catchuoi);
		user.push_back(x);
		getline(f, str);
	}
	f.close();
	return user;
}

vector<Book> loadBook() {
	vector<Book> book;
	Book x;
	fstream f;
	f.open("book.txt");
	string str, catchuoi;
	int num_avai;
	stringstream s;
	while (!f.eof()) {
		s.str("");
		s.clear();
		getline(f, str);
		if (str.empty())continue;
		x.setbook_no(str);
		getline(f, str);
		if (str.empty())continue;
		x.setbook_name(str);
		getline(f, str);
		if (str.empty())continue;
		x.setbook_author(str);
		getline(f, str);
		s << str;
		s >> num_avai;
		x.setnum_avai(num_avai);
		getline(f, str);
		book.push_back(x);
	}
	f.close();
	return book;
}

vector<Hosomuonsach> loadHSmuonsach() {
	vector<Hosomuonsach> hsms;
	Hosomuonsach _hsms;
	fstream f;
	stringstream s;
	f.open("hosomuonsach.txt");
	string str;
	unsigned long long _time;
	int i;
	while (!f.eof()) {
		getline(f, str);
		if (str.empty()) continue;
		_hsms.account.setAccountId(str);
		vector<Book_MT> book;
		while (1) {
			Book_MT x;
			getline(f, str);
			if (str == "..............................................") {
				s.str("");
				s.clear();
				getline(f, str);
				if (str.empty()) continue;
				if (str.empty()) getline(f, str);
				x.book_no = str;
				getline(f, str);
				if (str.empty()) getline(f, str);
				x.tgm.date = str;
				getline(f, str);
				if (str.empty()) getline(f, str);
				s << str;
				s >> _time;
				x.tgm.time = _time;
				s.str("");
				s.clear();
				getline(f, str);
				if (str.empty()) getline(f, str);
				x.tgt.date = str;
				getline(f, str);
				if (str.empty()) getline(f, str);
				s << str;
				s >> _time;
				x.tgt.time = _time;
				book.push_back(x);
			}
			else {
				_hsms.listbook = book;
				hsms.push_back(_hsms);
				break;
			}
		}
	}
	f.close();
	return hsms;

}

vector<Tienno> loadtienno() {
	vector<Tienno> tienno;
	fstream f;
	f.open("tienno.txt");
	string str, catchuoi;
	unsigned int _tien;
	stringstream s;
	while (!f.eof()) {
		Tienno x;
		s.str("");
		s.clear();
		getline(f, str);
		if (str.empty()) continue;
		s << str;
		s >> catchuoi;
		x.account.setAccountId(catchuoi);
		s >> _tien;
		x.tienno = _tien;
		s >> _tien;
		x.tiendt = _tien;
		tienno.push_back(x);
	}
	f.close();
	return tienno;
}

vector<AccountRoleMap> loadaccountrolemap() {
	vector<AccountRoleMap> accountrolemap;
	AccountRoleMap x;
	fstream f;
	f.open("accountrolemap.txt");
	string str, catchuoi;
	stringstream s;
	while (!f.eof()) {
		s.str("");
		s.clear();
		getline(f, str);
		if (str.empty()) continue;
		s << str;
		s >> catchuoi;
		x.account_id = catchuoi;
		s >> catchuoi;
		x.role_id = catchuoi;
		accountrolemap.push_back(x);
	}
	f.close();
	return accountrolemap;
}

vector<Role> loadrole() {
	vector<Role> role;
	Role x;
	fstream f;
	f.open("role.txt");
	string str, catchuoi;
	stringstream s;
	while (!f.eof()) {
		s.str("");
		s.clear();
		getline(f, str);
		s << str;
		s >> catchuoi;
		x.role_id = catchuoi;
		s >> catchuoi;
		x.role_desc = catchuoi;
		role.push_back(x);
	}
	f.close();
	return role;
}

vector<Giohang> loadGioHang() {
	vector<Giohang> giohang;
	fstream f;
	f.open("Giohang.txt");
	string str;
	stringstream s;
	int i;
	while (!f.eof()) {
		getline(f, str);
		if (str.empty()) continue;
		Giohang x;
		x.account.setAccountId(str);
		getline(f, str);
		x.trangthai = str;
		getline(f, str);
		x.time.date = str;
		getline(f, str);
		s << str;
		unsigned int time;
		s >> time;
		x.time.time = time;
		s.str("");
		s.clear();
		while (1) {
			Book _x;
			getline(f, str);
			if (str == "..............................................") {
				getline(f, str);
				_x.setbook_no(str);
				getline(f, str);
				_x.setbook_name(str);
				getline(f, str);
				_x.setbook_author(str);
				x.listbook.push_back(_x);
			}
			else {
				giohang.push_back(x);
				break;
			}
		}
	}
	f.close();
	return giohang;

}

vector<Account_User> loadAccountUser() {
	vector<Account_User> acc_user;
	Account_User x;
	fstream f;
	f.open("user_account.txt");
	string str, catchuoi;
	stringstream s;
	while (!f.eof()) {
		s.str("");
		s.clear();
		getline(f, str);
		if (str.empty()) continue;
		s << str;
		s >> catchuoi;
		x.account.setAccountId(catchuoi);
		s >> catchuoi;
		x.user.setUser_no(catchuoi);
		acc_user.push_back(x);
	}
	f.close();
	return acc_user;
}

/*Luu data doc len tu file vao RAM*/ //biến toàn cục


// tu dong load tien no
void load_tienno() {
	for (int i = 0; i < hosomuonsach_data.size(); i++)
		for (int j = 0; j < tienno_data.size(); j++) {
			tienno_data[j].tienno = 0;
			if (hosomuonsach_data[i].account.getAccountId() == tienno_data[j].account.getAccountId())
				for (int k = 0; k < hosomuonsach_data[i].listbook.size(); k++) {
					if (hosomuonsach_data[i].listbook[k].tgt.date == "Chua Tra")
						if ((time(0) - hosomuonsach_data[i].listbook[k].tgm.time) > THOI_GIAN_MUON_TOI_DA) {
							int songayquahang;
							songayquahang = ((time(0) - hosomuonsach_data[i].listbook[k].tgm.time) - THOI_GIAN_MUON_TOI_DA) / NGAY + 1;
							tienno_data[j].tienno += 1000 * songayquahang;
						}
					if (hosomuonsach_data[i].listbook[k].tgt.date != "Chua Tra")
						if ((hosomuonsach_data[i].listbook[k].tgt.time - hosomuonsach_data[i].listbook[k].tgm.time) > THOI_GIAN_MUON_TOI_DA) {
							int songayquahang;
							songayquahang = ((hosomuonsach_data[i].listbook[k].tgt.time - hosomuonsach_data[i].listbook[k].tgm.time) - THOI_GIAN_MUON_TOI_DA) / NGAY + 1;
							tienno_data[j].tienno += 1000 * songayquahang;
						}

				}
		}
	savefiletienno();
}

/*save data*/

void savehosomuonsach() {
	ofstream f;
	f.open("hosomuonsach.txt");
	for (int i = 0; i < hosomuonsach_data.size(); i++) {
		f << hosomuonsach_data[i].account.getAccountId() << endl;
		f << ".............................................." << endl;
		int j;
		for (j = 0; j < hosomuonsach_data[i].listbook.size() - 1; j++) {
			f << hosomuonsach_data[i].listbook[j].book_no << endl;
			f << hosomuonsach_data[i].listbook[j].tgm.date << endl;
			f << hosomuonsach_data[i].listbook[j].tgm.time << endl;
			f << hosomuonsach_data[i].listbook[j].tgt.date << endl;
			f << hosomuonsach_data[i].listbook[j].tgt.time << endl;
			f << ".............................................." << endl;
		}
		f << hosomuonsach_data[i].listbook[j].book_no << endl;
		f << hosomuonsach_data[i].listbook[j].tgm.date << endl;
		f << hosomuonsach_data[i].listbook[j].tgm.time << endl;
		f << hosomuonsach_data[i].listbook[j].tgt.date << endl;
		f << hosomuonsach_data[i].listbook[j].tgt.time << endl;
		f << "--------------------------------------------" << endl;
	}
	f.close();
}

void savefilebook() {
	ofstream f;
	f.open("book.txt");
	for (int i = 0; i < book.size(); i++) {
		f << book[i].getbook_no() << endl;
		f << book[i].getbook_name() << endl;
		f << book[i].getbook_author() << endl;
		f << book[i].getnum_avai() << endl;
		f << "----------------------------------------------------------------------------------" << endl;
	}
	f.close();
}

void savefilegioHang() {
	ofstream f;
	f.open("Giohang.txt");
	for (int i = 0; i < giohang_data.size(); i++) {
		f << giohang_data[i].account.getAccountId() << endl;
		f << giohang_data[i].trangthai << endl;
		f << giohang_data[i].time.date << endl;
		f << giohang_data[i].time.time << endl;
		f << ".............................................." << endl;
		int j;
		for (j = 0; j < giohang_data[i].listbook.size() - 1; j++) {
			f << giohang_data[i].listbook[j].getbook_no() << endl;
			f << giohang_data[i].listbook[j].getbook_name() << endl;
			f << giohang_data[i].listbook[j].getbook_author() << endl;
			f << ".............................................." << endl;
		}
		f << giohang_data[i].listbook[j].getbook_no() << endl;
		f << giohang_data[i].listbook[j].getbook_name() << endl;
		f << giohang_data[i].listbook[j].getbook_author() << endl;
		f << "--------------------------------------------" << endl;
	}
	f.close();
}

void savefileaccount_user_data() {
	ofstream f;
	f.open("user_account.txt");
	for (int i = 0; i < account_user_data.size(); i++) {
		f << setw(15) << account_user_data[i].account.getAccountId();
		f << setw(15) << account_user_data[i].user.getUser_no() << endl;
	}
	f.close();
}

void savefileuser_data() {
	ofstream f;
	f.open("user_data.txt");
	for (int i = 0; i < user_data.size(); i++) {
		f << user_data[i].getUser_name() << endl;
		f << setw(20) << left << user_data[i].getUser_no();
		f << setw(25) << left << user_data[i].getdob();
		f << setw(25) << left << user_data[i].getemail() << endl;
		f << "--------------------------------------------------------------------------------" << endl;
	}
	f.close();
}

void savefileaccountrolemap_data() {
	ofstream f;
	f.open("accountrolemap.txt");
	for (int i = 0; i < accountrolemap_data.size(); i++) {
		f << setw(20) << accountrolemap_data[i].account_id;
		f << setw(15) << accountrolemap_data[i].role_id << endl;
	}
	f.close();
}

void savefiletienno() {
	ofstream f;
	f.open("tienno.txt");
	for (int i = 0; i < tienno_data.size(); i++) {
		f << setw(30) << tienno_data[i].account.getAccountId();
		f << setw(15) << tienno_data[i].tienno;
		f << setw(15) << tienno_data[i].tiendt << endl;
	}
	f.close();
}

void savefileaccount_data() {
	ofstream f;
	f.open("account_data.txt");
	for (int i = 0; i < account_data.size(); i++) {
		f << setw(15) << account_data[i].getAccountId();
		f << setw(15) << account_data[i].getPassword();
		f << setw(15) << account_data[i].getActive();
		f << endl;
	}
	f.close();
}

/*cac hoat dong lien quan den muon tra sach*/

void themvaogiohang(string _account_name) {
	string book_no;
	cout << "Nhap ma so sach can them: "; getline(cin, book_no);
	int kt1 = 0, kt2 = 0;
	for (int i = 0; i < book.size(); i++)
		if (book_no == book[i].getbook_no()) {
			kt2 = 1;
			for (int j = 0; j < giohang_data.size(); j++)
				if (giohang_data[j].account.getAccountId() == _account_name) {
					giohang_data[j].listbook.push_back(book[i]);
					giohang_data[j].trangthai = "Chua yeu cau";
					giohang_data[j].time.date = "0";
					giohang_data[j].time.time = 0;
					cout << "Sach da duoc them vao gio hang cua ban!" << endl;
					savefilegioHang();
					kt1 = 1;
					break;
				};
			if (kt1 == 0) {
				Giohang x;
				x.account.setAccountId(_account_name);
				x.listbook.push_back(book[i]);
				x.trangthai = "Chua yeu cau";
				x.time.date = "0";
				x.time.time = 0;
				giohang_data.push_back(x);
				savefilegioHang();
				cout << "Sach da duoc them vao gio hang cua ban!" << endl;
			}
			break;
		}
	if (kt2 == 0) cout << "Khong tim duoc sach theo ma so ban vua nhap!" << endl;
}

void tudonghuydonhang() {
	for (int i = 0; i < giohang_data.size(); i++)
		if (giohang_data[i].trangthai == "Da yeu cau")
			if ((time(0) - giohang_data[i].time.time) > THOI_GIAN_GIU_DON_HANG) {
				for (int j = 0; j < giohang_data[i].listbook.size(); j++)
					for (int k = 0; k < book.size(); k++)
						if (book[k].getbook_no() == giohang_data[i].listbook[j].getbook_no()) {
							book[k].setnum_avai(book[k].getnum_avai() + 1);
							break;
						}
				Giohang tam;
				tam = giohang_data[i];
				giohang_data[i] = giohang_data[giohang_data.size() - 1];
				giohang_data[giohang_data.size() - 1] = tam;
				giohang_data.pop_back();
				savefilegioHang();
			}
}

void xoadonhang(string account_name) {////////////////////////////////
	tudonghuydonhang();
	int kt = 0;
	for (int i = 0; i < giohang_data.size(); i++)
		if (giohang_data[i].account.getAccountId() == account_name)
			if (giohang_data[i].trangthai == "Da yeu cau") {
				kt = 1;
				cout << "DON HANG: " << endl;
				cout << "Thoi gian dat: " << giohang_data[i].time.date << endl;
				cout << left << setw(5) << "STT";
				cout << left << setw(20) << "MA SO SACH";
				cout << left << setw(50) << "TEN SACH";
				cout << left << setw(40) << "TAC GIA" << endl;
				for (int j = 0; j < giohang_data[i].listbook.size(); j++) {
					cout << left << setw(5) << j + 1;
					cout << left << setw(20) << giohang_data[i].listbook[j].getbook_no();
					cout << left << setw(50) << giohang_data[i].listbook[j].getbook_name();
					cout << left << setw(40) << giohang_data[i].listbook[j].getbook_author() << endl;
				}
				char choice;
				cout << "Ban co muon xoa khong?(y/n): ";
				cin >> choice;
				cin.ignore();
				if (choice == 'y') {
					for (int j = 0; j < giohang_data[i].listbook.size(); j++)
						for (int k = 0; k < book.size(); k++)
							if (book[k].getbook_no() == giohang_data[i].listbook[j].getbook_no()) {
								book[k].setnum_avai(book[k].getnum_avai() + 1);
								break;
							}
					Giohang tam;
					tam = giohang_data[i];
					giohang_data[i] = giohang_data[giohang_data.size() - 1];
					giohang_data[giohang_data.size() - 1] = tam;
					giohang_data.pop_back();
					savefilegioHang();
				}
				else cout << "Nhan enter de tiep tuc..." << endl;
			}
	if (kt == 0) cout << "Ban khong co don hang nao de xoa.Nhan enter de tiep tuc...." << endl;
}

void guiyeucaumuonsach(string account_name) {
	if (!kiemtratrangthai(account_name)) {
		cout << "Tai khoan cua ban da bi khoa khong the su dung tinh nang nay!" << endl;
		return;
	}
	int kt = 0;
	tudonghuydonhang();
	for (int i = 0; i<giohang_data.size(); i++)
		if (giohang_data[i].account.getAccountId() == account_name) {
			if (giohang_data[i].trangthai == "Chua yeu cau") {
				kt = 1;
				giohang_data[i].trangthai = "Da yeu cau";
				giohang_data[i].time = time();
				for (int j = 0; j < giohang_data[i].listbook.size(); j++)
					for (int k = 0; k < book.size(); k++)
						if (book[k].getbook_no() == giohang_data[i].listbook[j].getbook_no()) {
							book[k].setnum_avai(book[k].getnum_avai() - 1);
							break;
						}
				cout << "Don hang cua ban da duoc gui thanh cong!" << endl;
				cout << "Vui long den thu vien de xac nhan muon sach! Don hang se tu dong bi huy sau 3 ngay neu ban khong den xac nhan!" << endl;
				cout << "Nhan enter de tiep tuc....." << endl;
				savefilegioHang();
				break;
			}
			if (giohang_data[i].trangthai == "Da yeu cau") {
				kt = 1;
				cout << "Ban khong the gui yeu cau mot don hang moi khi da yeu cau mot don hang truoc do!" << endl;
				cout << "DON HANG: " << endl;
				cout << "Thoi gian dat: " << giohang_data[i].time.date << endl;
				cout << left << setw(5) << "STT";
				cout << left << setw(20) << "MA SO SACH";
				cout << left << setw(50) << "TEN SACH";
				cout << left << setw(40) << "TAC GIA" << endl;
				for (int j = 0; j < giohang_data[i].listbook.size(); j++) {
					cout << left << setw(5) << j + 1;
					cout << left << setw(20) << giohang_data[i].listbook[j].getbook_no();
					cout << left << setw(50) << giohang_data[i].listbook[j].getbook_name();
					cout << left << setw(40) << giohang_data[i].listbook[j].getbook_author() << endl;
				}
				cout << "Ban co the xoa don hang truoc do de yeu cau don hang nay!" << endl;
				cout << "Ban co muon xoa don hang truoc do khong?(y/n):  ";
				char choice; cin >> choice;
				cin.ignore();
				if (choice == 'y') {
					Giohang tam;
					tam = giohang_data[i];
					giohang_data[i] = giohang_data[giohang_data.size() - 1];
					giohang_data[giohang_data.size() - 1] = tam;
					giohang_data.pop_back();
					savefilegioHang();
					i--;
					continue;
				}
				else cout << "Nhan enter de tiep tuc....." << endl;
			}
		}
	if (kt == 0) cout << "Gio hang cua ban trong! Vui long tim va chon sach truoc khi yeu cau mot don hang!" << endl;
}

void xemthongtinmuontra(string account_name) {
	int kt = 0, demtc = 0, demct = 0, stt = 0;
	cout << left << "THONG TIN MUON TRA CUA TAI KHOAN: " << endl;
	for (int i = 0; i < hosomuonsach_data.size(); i++)
		if (hosomuonsach_data[i].account.getAccountId() == account_name) {
			kt = 1;
			cout << setw(4) << left << "STT" << setw(15) << "MA SO SACH" << setw(40) << "TEN SACH" << setw(30) << "TAC GIA" << setw(30) << "NGAY MUON" << setw(30) << "NGAY TRA" << endl;
			for (int j = 0; j < hosomuonsach_data[i].listbook.size(); j++)
				if (hosomuonsach_data[i].listbook[j].tgt.date == "Chua Tra") {
					stt++;
					demct++;
					demtc++;
					cout << left << setw(4) << stt;
					cout << left << setw(15) << hosomuonsach_data[i].listbook[j].book_no;
					for (int k = 0; k < book.size(); k++)
						if (book[k].getbook_no() == hosomuonsach_data[i].listbook[j].book_no) {
							cout << setw(40) << book[k].getbook_name();
							cout << setw(30) << book[k].getbook_author();
							break;
						}
					cout << left << setw(30) << hosomuonsach_data[i].listbook[j].tgm.date;
					cout << left << setw(30) << hosomuonsach_data[i].listbook[j].tgt.date << endl;
				}
			for (int j = 0; j < hosomuonsach_data[i].listbook.size(); j++)
				if (hosomuonsach_data[i].listbook[j].tgt.date != "Chua Tra") {
					stt++;
					demtc++;
					cout << left << setw(4) << stt;
					cout << left << setw(15) << hosomuonsach_data[i].listbook[j].book_no;
					for (int k = 0; k < book.size(); k++)
						if (book[k].getbook_no() == hosomuonsach_data[i].listbook[j].book_no) {
							cout << left << setw(40) << book[k].getbook_name();
							cout << left << setw(30) << book[k].getbook_author();
							break;
						}
					cout << left << setw(30) << hosomuonsach_data[i].listbook[j].tgm.date;
					cout << left << setw(30) << hosomuonsach_data[i].listbook[j].tgt.date << endl;
				}
			cout << "SO SACH DA MUON: " << demtc << endl;
			cout << "SO SACH CHUA TRA: " << demct << endl;
		}
	if (kt == 0) cout << "Lich su muon tra cua ban trong!" << endl;
}

void timsach(string _account_name) {
	string tukhoa, test;
	string cat_chuoi;
	int _num_avai;
	stringstream s;
	Book x;
	int dem = 0;//dem so ket qua tim thay
	cout << "Nhap tu khoa tim kiem: ";
	cin.ignore();
	getline(cin, tukhoa);
	for (int i = 0; i < book.size(); i++)
		if (timkiem(book[i].getbook_author(), tukhoa) || timkiem(book[i].getbook_name(), tukhoa)) {
			cout << left << setw(10) << book[i].getbook_no();
			cout << left << setw(50) << left << book[i].getbook_name();
			cout << left << setw(30) << book[i].getbook_author();
			cout << left << setw(10) << book[i].getnum_avai() << endl;
			dem++;
		}
	if (dem == 0) {
		cout << "Khong tim thay ket qua nao cho tu khoa tren." << endl;
	}
	else
		cout << "So ket qua duoc tim thay: " << dem << endl;
	if (!kiemtratrangthai(_account_name)) return;
	if (dem != 0) {
		cout << "Ban co muon them sach nao vao gio hang khong?(y/n): ";
		char choice;
		cin >> choice;
		cin.ignore();
		if (choice == 'y') {
			themvaogiohang(_account_name);
			savefilegioHang();
		}
		else cout << "Nhan enter de quay ve man hinh chinh! " << endl;
	}
}

bool xemgiohang(string _account_name) {
	int kt = 0;
	for (int i = 0; i < giohang_data.size(); i++)
		if (giohang_data[i].account.getAccountId() == _account_name)
			if (giohang_data[i].trangthai == "Chua yeu cau") {
				kt = 1;
				cout << "Gio hang cua ban:" << endl;
				cout << left << setw(5) << "STT";
				cout << left << setw(20) << "MA SO SACH";
				cout << left << setw(50) << "TEN SACH";
				cout << left << setw(40) << "TAC GIA" << endl;
				for (int j = 0; j < giohang_data[i].listbook.size(); j++) {
					cout << left << setw(5) << j + 1;
					cout << left << setw(20) << giohang_data[i].listbook[j].getbook_no();
					cout << left << setw(50) << giohang_data[i].listbook[j].getbook_name();
					cout << left << setw(40) << giohang_data[i].listbook[j].getbook_author() << endl;
				}
				return true;
			}
	if (kt == 0) {
		//cout << "Gio hang cua ban trong!" << endl;
		return false;
	}
}

bool xemdonhang(string _account_name) {
	tudonghuydonhang();
	int kt = 0;
	for (int i = 0; i < giohang_data.size(); i++)
		if (giohang_data[i].account.getAccountId() == _account_name)
			if (giohang_data[i].trangthai == "Da yeu cau") {
				kt = 1;
				cout << "Don hang da yeu cau cua ban:" << endl;
				cout << left << setw(5) << "STT";
				cout << left << setw(20) << "MA SO SACH";
				cout << left << setw(50) << "TEN SACH";
				cout << left << setw(40) << "TAC GIA" << endl;
				for (int j = 0; j < giohang_data[i].listbook.size(); j++) {
					cout << left << setw(5) << j + 1;
					cout << left << setw(20) << giohang_data[i].listbook[j].getbook_no();
					cout << left << setw(50) << giohang_data[i].listbook[j].getbook_name();
					cout << left << setw(40) << giohang_data[i].listbook[j].getbook_author() << endl;
				}
				return true;
			}
	if (kt == 0) {
		cout << "Don hang cua ban trong!" << endl;
		return false;
	}
}

void xoakhoidonhang(string _account_name) {
	tudonghuydonhang();
	string book_no;
	int kt1 = 0, kt2 = 0;
	cout << "Nhap ma so sach muon xoa: "; getline(cin, book_no);
	for (int i = 0; i < giohang_data.size(); i++) {
		if (giohang_data[i].account.getAccountId() == _account_name)
			if (giohang_data[i].trangthai == "Da yeu cau") {
				kt1 = 1;
				for (int j = 0; j < giohang_data[i].listbook.size(); j++) {
					if (giohang_data[i].listbook[j].getbook_no() == book_no) {
						kt2 = 1;
						for (int j = 0; j < giohang_data[i].listbook.size(); j++)
							for (int k = 0; k < book.size(); k++)
								if (book[k].getbook_no() == giohang_data[i].listbook[j].getbook_no()) {
									book[k].setnum_avai(book[k].getnum_avai() + 1);
									break;
								}
						Book tam;
						tam = giohang_data[i].listbook[j];
						giohang_data[i].listbook[j] = giohang_data[i].listbook[giohang_data[i].listbook.size() - 1];
						giohang_data[i].listbook[giohang_data[i].listbook.size() - 1] = tam;
						giohang_data[i].listbook.pop_back();
						if (giohang_data[i].listbook.size() == 0) {
							Giohang tam;
							tam = giohang_data[i];
							giohang_data[i] = giohang_data[giohang_data.size() - 1];
							giohang_data[giohang_data.size() - 1] = tam;
							giohang_data.pop_back();
						}
						savefilegioHang();
						cout << "Da xoa thanh cong sach vua chon khoi don hang cua ban!" << endl;
						_getch();
						break;
					}
				}
			}
	}
	if (kt1 == 0) cout << "Don hang cua ban trong!" << endl;
	else if (kt2 == 0)  cout << "Khong tim thay sach ban muon xoa trong gio hang cua ban!" << endl;
}

void xoakhoigiohang(string _account_name) {
	string book_no;
	int kt1 = 0, kt2 = 0;
	cout << "Nhap ma so sach muon xoa: "; getline(cin, book_no);
	for (int i = 0; i < giohang_data.size(); i++)
		if (giohang_data[i].account.getAccountId() == _account_name)
			if (giohang_data[i].trangthai == "Chua yeu cau") {
				kt1 = 1;
				for (int j = 0; j < giohang_data[i].listbook.size(); j++)
					if (giohang_data[i].listbook[j].getbook_no() == book_no) {
						kt2 = 1;
						Book tam;
						tam = giohang_data[i].listbook[j];
						giohang_data[i].listbook[j] = giohang_data[i].listbook[giohang_data[i].listbook.size() - 1];
						giohang_data[i].listbook[giohang_data[i].listbook.size() - 1] = tam;
						giohang_data[i].listbook.pop_back();
						if (giohang_data[i].listbook.size() == 0) {
							Giohang tam;
							tam = giohang_data[i];
							giohang_data[i] = giohang_data[giohang_data.size() - 1];
							giohang_data[giohang_data.size() - 1] = tam;
							giohang_data.pop_back();
						}
						savefilegioHang();
						cout << "Da xoa thanh cong sach vua chon khoi gio hang cua ban!" << endl;
						_getch();
						break;
					}
			}
	if (kt1 == 0) cout << "Gio hang cua ban trong!" << endl;
	else if (kt2 == 0)  cout << "Khong tim thay sach ban muon xoa trong gio hang cua ban!" << endl;
}

void xacnhanmuonsach(string account_name) {
	tudonghuydonhang();
	int kt = 0, kt1 = 0, dem = 0;
	for (int i = 0; i < giohang_data.size(); i++)
		if (giohang_data[i].account.getAccountId() == account_name)
			if (giohang_data[i].trangthai == "Da yeu cau") {
				giohang_data[i].time = time();
				kt1 = 1;
				for (int j = 0; j < hosomuonsach_data.size(); j++)
					if (hosomuonsach_data[j].account.getAccountId() == account_name) {
						kt = 1;
						for (int k = 0; k < giohang_data[i].listbook.size(); k++) {
							dem = giohang_data[i].listbook.size();
							Book_MT _x;
							_x.book_no = giohang_data[i].listbook[k].getbook_no();
							_x.tgm = time();
							_x.tgt.date = "Chua Tra";
							_x.tgt.time = 0;
							hosomuonsach_data[j].listbook.push_back(_x);
							savehosomuonsach();
							cout << "Dang ki muon sach thanh cong" << endl;
						}
						break;
					}
				if (kt == 0) {
					Hosomuonsach x;
					x.account.setAccountId(account_name);
					for (int j = 0; j < giohang_data.size(); j++)
						if (giohang_data[j].account.getAccountId() == account_name)
							if (giohang_data[j].trangthai == "Da yeu cau") {
								giohang_data[j].time = time();
								kt = 1;
								for (int k = 0; k < giohang_data[j].listbook.size(); k++) {
									dem = giohang_data[i].listbook.size();
									Book_MT _x;
									_x.book_no = giohang_data[j].listbook[k].getbook_no();
									_x.tgm = time();
									_x.tgt.date = "Chua Tra";
									_x.tgt.time = 0;
									x.listbook.push_back(_x);
								}
								break;
							}
					hosomuonsach_data.push_back(x);
					savehosomuonsach();
					cout << "Dang ki muon sach thanh cong" << endl;
				}
				for (int j = 0; j < giohang_data.size(); j++)
					if (giohang_data[j].account.getAccountId() == account_name)
						if (giohang_data[j].trangthai == "Da yeu cau") {
							Giohang tam;
							tam = giohang_data[j];
							giohang_data[j] = giohang_data[giohang_data.size() - 1];
							giohang_data[giohang_data.size() - 1] = tam;
							giohang_data.pop_back();
							savefilegioHang();
						}
			}
	if (dem == 4) cout << "Ban da muon toi da 4 quyen. Vui long tra het sach da muon de duoc yeu cau muon tiep!" << endl;
	else {
		while (dem<4) {
			int ktb = 0;
			cout << "Ban co muon muon muon them sach nao nua khong(y/n)?:  ";
			char choice; cin >> choice;
			cin.ignore();
			if (choice == 'y') {
				string book_no;
				cout << "Nhap ma so sach ban muon muon: "; getline(cin, book_no);
				for (int m = 0; m < book.size(); m++)
					if (book[m].getbook_no() == book_no) {
						if (book[m].getnum_avai() == 1) {
							ktb = 1;
							cout << "Sach nay chi con 1 cuon! Ban khong the muon cuon sach nay! " << endl;
							break;
						}
						ktb = 1;
						book[m].setnum_avai(book[m].getnum_avai() - 1);
						Book_MT a;
						a.book_no = book[m].getbook_no();
						a.tgm = time();
						a.tgt.date = "Chua Tra";
						a.tgt.time = 0;
						dem++;
						int kt_ = 0;
						for (int n = 0; n < hosomuonsach_data.size(); n++)
							if (hosomuonsach_data[n].account.getAccountId() == account_name) {
								kt_ = 1;
								hosomuonsach_data[n].listbook.push_back(a);
								savehosomuonsach();
								cout << "Dang ki muon sach thanh cong" << endl;
								break;
							}
						if (kt_ == 0) {
							Hosomuonsach q;
							q.account.setAccountId(account_name);
							q.listbook.push_back(a);
							hosomuonsach_data.push_back(q);
							savehosomuonsach();
						}
					}
				if (ktb == 0) cout << "Khong tim thay sach nao co ma so ban vua nhap trong he thong!" << endl;
			}
			else {
				cout << "Nhan enter de tiep tuc...." << endl;
				break;
			}
		}
	}
	if (dem == 4) {
		cout << "Ban da muon toi da 4 quyen. Vui long tra het sach da muon de duoc yeu cau muon tiep!" << endl;
		cout << "Nhan enter de tiep tuc...." << endl;
	}
}

void trasach() {
	string _account_name, book_no;
	cin.ignore();
	cout << "Nhap tai khoan tra sach: "; getline(cin, _account_name);
	int kt = 0, kt1 = 0, stt = 0;
	cout << left << "THONG TIN VE SACH CHUA TRA CUA TAI KHOAN" << endl;
	for (int i = 0; i < hosomuonsach_data.size(); i++)
		if (hosomuonsach_data[i].account.getAccountId() == _account_name) {
			kt = 1;
			cout << setw(4) << left << "STT" << setw(15) << "MA SO SACH" << setw(40) << "TEN SACH" << setw(30) << "TAC GIA" << setw(30) << "NGAY MUON" << setw(30) << "NGAY TRA" << endl;
			for (int j = 0; j < hosomuonsach_data[i].listbook.size(); j++)
				if (hosomuonsach_data[i].listbook[j].tgt.date == "Chua Tra") {
					stt++;
					cout << left << setw(4) << stt;
					cout << left << setw(15) << hosomuonsach_data[i].listbook[j].book_no;
					for (int k = 0; k < book.size(); k++)
						if (book[k].getbook_no() == hosomuonsach_data[i].listbook[j].book_no) {
							cout << setw(40) << book[k].getbook_name();
							cout << setw(30) << book[k].getbook_author();
							break;
						}
					cout << left << setw(30) << hosomuonsach_data[i].listbook[j].tgm.date;
					cout << left << setw(30) << hosomuonsach_data[i].listbook[j].tgt.date << endl;
				}
		}
	if (stt != 0) {
		for (int i = 0; i < hosomuonsach_data.size(); i++)
			if (_account_name == hosomuonsach_data[i].account.getAccountId()) {
				kt = 1;
				while (1) {
					cout << "Nhap ma so sach nguoi dung tra: "; getline(cin, book_no);
					for (int j = 0; j < hosomuonsach_data[i].listbook.size(); j++)
						if (hosomuonsach_data[i].listbook[j].book_no == book_no)
							if (hosomuonsach_data[i].listbook[j].tgt.date == "Chua Tra") {

								hosomuonsach_data[i].listbook[j].tgt = time();
								savehosomuonsach();
								cout << "Da tra thanh cong!" << endl;
								stt--;
								for (int m = 0; m<book.size(); m++)
									if (book[m].getbook_no() == book_no) {
										kt1 = 1;
										book[m].setnum_avai(book[m].getnum_avai() + 1);
										savefilebook();
										break;
									}
								_getch();
								break;
							}
					if (kt1 == 0) cout << "Khong tim thay sach co ma so ban vua nhap trong he thong!" << endl;
					if (stt>0) {
						cout << "Ban co muon tra sach nao nua khong?(y/n): ";
						char choice;
						cin >> choice;
						cin.ignore();
						if (choice == 'y') continue;
						else {
							cout << "Nhan enter de tiep tuc..." << endl;
							break;
						}
					}
					else {
						cout << "Nguoi dung da tra het sach da muon!" << endl;
						cout << "Nhan enter de tiep tuc...." << endl;
						break;
					}
				}
			}
	}
	else cout << "Tai khoan hien khong muon cuon sach nao! " << endl;
	if (kt == 0) cout << "Khong co du lieu cua tai khoan ve muon tra sach!" << endl;
}

void nhactrasach(string account_name) {
	int dem1 = 0, dem2 = 0, stt = 0;
	cout << left << setw(5) << "STT" << setw(20) << "MA SO" << setw(40) << "TEN SACH " << setw(40) << "TAC GIA" << setw(30) << "NGAY MUON" << setw(15) << "TINH TRANG" << endl;
	for (int i = 0; i < hosomuonsach_data.size(); i++)
		if (hosomuonsach_data[i].account.getAccountId() == account_name) {
			for (int j = 0; j<hosomuonsach_data[i].listbook.size(); j++)
				if (hosomuonsach_data[i].listbook[j].tgt.date == "Chua Tra")
					if ((time(0) - hosomuonsach_data[i].listbook[j].tgm.time)>THOI_GIAN_NHAC)
						if ((time(0) - hosomuonsach_data[i].listbook[j].tgm.time) < THOI_GIAN_MUON_TOI_DA) {
							for (int k = 0; k < book.size(); k++)
								if (hosomuonsach_data[i].listbook[j].book_no == book[k].getbook_no()) {
									stt++;
									dem1++;
									cout << setw(5) << stt;
									cout << setw(20) << book[k].getbook_no();
									cout << setw(40) << book[k].getbook_name();
									cout << setw(40) << book[k].getbook_author();
									cout << setw(30) << hosomuonsach_data[i].listbook[j].tgm.date;
									cout << setw(15) << "Gan den han" << endl;
								}
						}
						else {
							for (int k = 0; k < book.size(); k++)
								if (hosomuonsach_data[i].listbook[j].book_no == book[k].getbook_no()) {
									dem2++;
									stt++;
									cout << setw(5) << stt;
									cout << setw(20) << book[k].getbook_no();
									cout << setw(40) << book[k].getbook_name();
									cout << setw(40) << book[k].getbook_author();
									cout << setw(30) << hosomuonsach_data[i].listbook[j].tgm.date;
									cout << setw(15) << "Da qua han" << endl;
								}
						}
						break;
		}
	if (stt == 0) cout << "Khong co thong bao nao ve viec yeu cau tra sach!" << endl;
	else {
		cout << left << setw(25) << "SO SACH QUA HAN: " << dem2 << endl;
		cout << left << setw(25) << "SO SACH GAN DEN HAN: " << dem1 << endl;
	}
}

/*Cac hoat dong lien quan den nguoi dung*/

void themnguoidung() {
	User x;
	cin.ignore();
	cout << "Nhap ho va ten: "; x.setUser_name();
	cout << "Nhap CMND: "; x.setUser_no();
	cout << "Nhap ngay sinh: "; x.setdob();
	cout << "Nhap email:"; x.setemail();
	cout << "Tao nguoi dung moi thanh cong!" << endl;
	_getch();
	//luu nguoi dung vao vector user_data de lam viec tren RAM
	user_data.push_back(x);
	//ghi vao file de tranh mat du lieu
	savefileuser_data();
}

void timkiemnguoidung() {
	User x;
	cin.ignore();
	cout << "Nhap ma so sinh vien can tim kiem: "; x.setUser_no();
	int kt = 0;
	for (int i = 0; i < user_data.size(); i++)
		if (user_data[i].getUser_no() == x.getUser_no()) {
			cout << "Thong tin tai khoan:" << endl;
			cout << "Ten nguoi dung: " << user_data[i].getUser_name() << endl;
			cout << "Ma so: " << user_data[i].getUser_no() << endl;
			cout << "Ngay sinh: " << user_data[i].getdob() << endl;
			cout << "Email: " << user_data[i].getemail() << endl;
			cout << "Danh sach tai khoan lien ket: " << endl;
			int dem = 0;
			for (int j = 0; j < account_user_data.size(); j++)
				if (account_user_data[j].user.getUser_no() == user_data[i].getUser_no()) {
					cout << account_user_data[j].account.getAccountId() << endl;
					dem++;
				}
			if (dem == 0) cout << "Khong co tai khoan nao lien ket voi nguoi dung nay! " << endl;
			else cout << "So tai khoan lien ket voi tai khoan: " << dem << endl;
			_getch();
			kt = 1;
			break;
		}
	if (kt == 0) {
		cout << "Khong ton tai nguoi dung nay!" << endl;
		_getch();
	}
}

void xoanguoidung() {
	string user_no;
	cout << "Nhap vao ma so nguoi dung ban muon xoa: ";
	cin.ignore();
	getline(cin, user_no);
	int kt = 0;
	char choice;
	cout << "Xoa nguoi dung se dong nghia voi viec moi tai khoan lien ket voi nguoi dung se bi xoa!" << endl;
	cout << "Ban co dong y xoa tai khoan nay khong(y/n)?: "; cin >> choice;
	if (choice == 'y') {
		for (int k = 0; k < user_data.size(); k++)
			if (user_data[k].getUser_no() == user_no) {
				for (int i = 0; i < account_user_data.size(); i++)
					if (account_user_data[i].user.getUser_no() == user_no) {
						for (int j = 0; j < account_data.size(); j++)
							if (account_data[j].getAccountId() == account_user_data[i].account.getAccountId()) {
								Account _tam;
								_tam = account_data[j];
								account_data[j] = account_data[account_data.size() - 1];
								account_data[account_data.size() - 1] = _tam;
								account_data.pop_back();
								savefileaccount_data();
							}
						for (int j = 0; j < tienno_data.size(); j++)
							if (tienno_data[j].account.getAccountId() == account_user_data[i].account.getAccountId()) {
								Tienno tam2;
								tam2 = tienno_data[j];
								tienno_data[j] = tienno_data[tienno_data.size() - 1];
								tienno_data[tienno_data.size() - 1] = tam2;
								tienno_data.pop_back();
								savefiletienno();
							}
						for (int j = 0; j < accountrolemap_data.size(); j++)
							if (accountrolemap_data[j].account_id == account_user_data[i].account.getAccountId()) {
								AccountRoleMap tam4;
								tam4 = accountrolemap_data[j];
								accountrolemap_data[j] = accountrolemap_data[accountrolemap_data.size() - 1];
								accountrolemap_data[accountrolemap_data.size() - 1] = tam4;
								accountrolemap_data.pop_back();
								savefileaccountrolemap_data();
							}
						for (int j = 0; j < giohang_data.size(); j++)
							if (giohang_data[j].account.getAccountId() == account_user_data[i].account.getAccountId()) {
								Giohang tam5;
								tam5 = giohang_data[j];
								giohang_data[j] = giohang_data[giohang_data.size() - 1];
								giohang_data[giohang_data.size() - 1] = tam5;
								giohang_data.pop_back();
								savefilegioHang();
							}
						for (int j = 0; j < hosomuonsach_data.size(); j++)
							if (hosomuonsach_data[j].account.getAccountId() == account_user_data[i].account.getAccountId()) {
								Hosomuonsach tam6;
								tam6 = hosomuonsach_data[j];
								hosomuonsach_data[j] = hosomuonsach_data[hosomuonsach_data.size() - 1];
								hosomuonsach_data[hosomuonsach_data.size() - 1] = tam6;
								hosomuonsach_data.pop_back();
								savehosomuonsach();
							}
						Account_User tam1;
						tam1 = account_user_data[i];
						account_user_data[i] = account_user_data[account_user_data.size() - 1];
						account_user_data[account_user_data.size() - 1] = tam1;
						account_user_data.pop_back();
						i--;
						savefileaccount_user_data();
					}
				User tam_;
				tam_ = user_data[k];
				user_data[k] = user_data[user_data.size() - 1];
				user_data[user_data.size() - 1] = tam_;
				user_data.pop_back();
				savefileuser_data();
				kt = 1;
				cout << "Da xoa tai khoan thanh cong!" << endl;
				break;
			}
	}
	else {
		cout << "Nhan enter de tiep tuc...." << endl;
		return;
	}
	if (kt == 0) cout << "Khong tim thay tai khoan nao!" << endl;
}

/*Cac hoat dong lien quan den tai khoan*/
void timkiemtheotaikhoan() {
	Account  _x;
	cin.ignore();
	cout << "Nhap ten tai khoan : "; _x.setAccountId();
	int kt = 0;
	for (int i = 0; i < account_data.size(); i++)
		if (account_data[i].getAccountId() == _x.getAccountId()) {
			cout << "Thong tin tai khoan:" << endl;
			cout << "Ten dang nhap: " << account_data[i].getAccountId() << endl;
			cout << "Chu tai khoan: " << endl;
			for (int j = 0; j<account_user_data.size(); j++)
				if (account_user_data[j].account.getAccountId() == account_data[i].getAccountId()) {
					for (int k = 0; k < user_data.size(); k++)
						if (user_data[k].getUser_no() == account_user_data[j].user.getUser_no()) {
							cout << "Ten: " << user_data[k].getUser_name() << endl;
							cout << "CMND: " << user_data[k].getUser_no() << endl;
							break;
						}
					break;
				}
			cout << "Trang thai tai khoan: " << account_data[i].getActive() << endl;
			kt = 1;
			break;
		}
	if (kt == 0) cout << "Khong ton tai tai khoan nay!" << endl;
}

void mokhoataikhoan() {
	Account  _x;
	cin.ignore();
	cout << "Nhap ten tai khoan : "; _x.setAccountId();
	int kt = 0;
	while (1) {
		for (int i = 0; i < account_data.size(); i++)
			if (account_data[i].getAccountId() == _x.getAccountId()) {
				if (account_data[i].getActive() == "true") {
					cout << "Tai khoan dang o trang thai kich hoat.Ban co muon khoa tai khoan nay(y/n):";
					char choice;
					cin >> choice;
					if (choice == 'y') {
						account_data[i].setActive("false");
						cout << "Tai khoan da bi khoa!" << endl;
					}
					cout << "Nhan enter de tiep tuc!";
					cin.ignore();
					_getch();
				}
				else {
					cout << "Tai khoan dang o trang thai bi khoa. Ban co muon kich hoat tai khoan nay(y/n):";
					char choice;
					cin >> choice;
					if (choice == 'y') {
						account_data[i].setActive("false");
						cout << "Tai khoan da bi khoa!" << endl;
					}
					cout << "Nhan enter de tiep tuc!";
					cin.ignore();
					_getch();
				}
				kt = 1;
				break;
			}
		if (kt == 0) {
			cout << "Khong ton tai tai khoan nay!" << endl;
			cout << "Ban co muon tim kiem lai(y/n):";
			char choice; cin >> choice;
			if (choice == 'n') break;
			cin.ignore();
		}
		else break;
	}

}

void xoataikhoan() {
	string account_name;
	cout << "Nhap vao tai khoan ban muon xoa: ";
	cin.ignore();
	getline(cin, account_name);
	int kt = 0;
	char choice;
	cout << "Xoa tai khoan se dong nghia voi viec moi thong tin ve so lan muon sach ";
	cout << "tien no, moi du lieu ve tai khoan se mat! " << endl;
	cout << "Ban co dong y xoa tai khoan nay khong(y/n)?: "; cin >> choice;
	if (choice == 'y') {
		for (int i = 0; i < account_data.size(); i++)
			if (account_data[i].getAccountId() == account_name) {
				Account tam1;
				tam1 = account_data[i];
				account_data[i] = account_data[account_data.size() - 1];
				account_data[account_data.size() - 1] = tam1;
				account_data.pop_back();
				savefileaccount_data();
				for (int j = 0; j < tienno_data.size(); j++)
					if (tienno_data[j].account.getAccountId() == account_name) {
						Tienno tam2;
						tam2 = tienno_data[j];
						tienno_data[j] = tienno_data[tienno_data.size() - 1];
						tienno_data[tienno_data.size() - 1] = tam2;
						tienno_data.pop_back();
						savefiletienno();
					}
				for (int j = 0; j < account_user_data.size(); j++)
					if (account_user_data[j].account.getAccountId() == account_name) {
						Account_User tam3;
						tam3 = account_user_data[j];
						account_user_data[j] = account_user_data[account_user_data.size() - 1];
						account_user_data[account_user_data.size() - 1] = tam3;
						account_user_data.pop_back();
						savefileaccount_user_data();
					}
				for (int j = 0; j < accountrolemap_data.size(); j++)
					if (accountrolemap_data[j].account_id == account_name) {
						AccountRoleMap tam4;
						tam4 = accountrolemap_data[j];
						accountrolemap_data[j] = accountrolemap_data[accountrolemap_data.size() - 1];
						accountrolemap_data[accountrolemap_data.size() - 1] = tam4;
						accountrolemap_data.pop_back();
						savefileaccountrolemap_data();
					}
				for (int j = 0; j < giohang_data.size(); j++)
					if (giohang_data[j].account.getAccountId() == account_name) {
						Giohang tam5;
						tam5 = giohang_data[j];
						giohang_data[j] = giohang_data[giohang_data.size() - 1];
						giohang_data[giohang_data.size() - 1] = tam5;
						giohang_data.pop_back();
						savefilegioHang();
					}
				for (int j = 0; j < hosomuonsach_data.size(); j++)
					if (hosomuonsach_data[j].account.getAccountId() == account_name) {
						Hosomuonsach tam6;
						tam6 = hosomuonsach_data[j];
						hosomuonsach_data[j] = hosomuonsach_data[hosomuonsach_data.size() - 1];
						hosomuonsach_data[hosomuonsach_data.size() - 1] = tam6;
						hosomuonsach_data.pop_back();
						savehosomuonsach();
					}
				kt = 1;
				cout << "Da xoa tai khoan thanh cong!" << endl;
				break;
			}
	}
	else {
		cout << "Nhan enter de tiep tuc...." << endl;
		return;
	}
	if (kt == 0) cout << "Khong tim thay tai khoan nao!" << endl;
}

void themtaikhoan() {
	Account x;
	string user, role;
	cin.ignore();
	cout << "Nhap ten dang nhap : "; x.setAccountId();
	cout << "Nhap User_no : "; getline(cin, user);
	cout << "Nhap password: "; x.setPassword();
	cout << "Trang thai tai khoan: "; x.setActive();
	cout << "Tao vai tro cho tai khoan: " << endl; getline(cin, role);
	int kt = 0;
	for (int i = 0; i < user_data.size(); i++)
		if (user_data[i].getUser_no() == user) {
			kt = 1;
			break;
		}
	if (kt == 1) {
		account_data.push_back(x);
		savefileaccount_data();
		Tienno tienno;
		tienno.account = x;
		tienno.tienno = 0;
		tienno_data.push_back(tienno);
		savefiletienno();
		AccountRoleMap _x;
		_x.account_id = x.getAccountId();
		_x.role_id = role;
		accountrolemap_data.push_back(_x);
		savefileaccountrolemap_data();
		Account_User x_;
		x_.account.setAccountId(x.getAccountId());
		x_.user.setUser_no(user);
		account_user_data.push_back(x_);
		savefileaccount_user_data();
		cout << "Tao tai khoan moi thanh cong!" << endl;
	}
	if (kt == 0)
		cout << "Khong co ten nguoi dung phu hop trong du lieu! ";
}



/*Cac hoat dong lien quan den tien no*/

void xemno(string account_name) {
	load_tienno();
	savefiletienno();
	int kt = 0;
	cout << "THONG KE VE NO:" << endl;
	for (int i = 0; i<tienno_data.size(); i++)
		if (tienno_data[i].account.getAccountId() == account_name) {
			kt = 1;
			cout << setw(20) << left << "Tong no: " << setw(15) << tienno_data[i].tienno << "VND" << endl;
			cout << setw(20) << left << "Da thanh toan: " << setw(15) << tienno_data[i].tiendt << "VND" << endl;
			cout << setw(20) << left << "So con lai: " << setw(15) << tienno_data[i].tienno - tienno_data[i].tiendt << "VND" << endl;
			break;
		}
	if (kt == 0) cout << "Khong co du lieu ve so no doi voi tai khoan nay! " << endl;
}
void nhantrano() {
	load_tienno();
	string account_name;
	unsigned int tientr;
	int kt = 0;
	cin.ignore();
	cout << "Nhap tai khoan can thanh toan: "; getline(cin, account_name);
	cout << "THONG TIN SO NO: " << endl;
	for (int i = 0; i < tienno_data.size(); i++)
		if (tienno_data[i].account.getAccountId() == account_name) {
			kt = 1;
			cout << left << setw(20) << "TAI KHOAN: " << account_name << endl;
			cout << setw(20) << left << "Tong no: " << setw(15) << tienno_data[i].tienno << "VND" << endl;
			cout << setw(20) << left << "Da thanh toan: " << setw(15) << tienno_data[i].tiendt << "VND" << endl;
			cout << setw(20) << left << "So con lai: " << setw(15) << tienno_data[i].tienno - tienno_data[i].tiendt << "VND" << endl;
			cout << "Nhap so tien nguoi dung thanh toan: "; cin >> tientr;
			if (tientr >(tienno_data[i].tienno - tienno_data[i].tiendt)) {
				cout << "Da thanh toan thanh cong tat ca cac khoan no!" << endl;
				cout << "So tien thua tra lai cho nguoi dung: ";
				cout << tientr - (tienno_data[i].tienno - tienno_data[i].tiendt) << " VND" << endl;
				tienno_data[i].tiendt = tienno_data[i].tienno;
				savefiletienno();
			}
			else {
				cout << "Da thanh toan thanh cong!" << endl;
				cout << "So no con lai can thanh toan: ";
				cout << setw(15) << (tienno_data[i].tienno - tienno_data[i].tiendt) - tientr << "VND" << endl;
				tienno_data[i].tiendt += tientr;
				savefiletienno();
			}
		}
	if (kt == 0) cout << "Khong tim thay du lieu ve tai khoan nay! " << endl;
}

/*Cac hoat dong lien quan den sach*/
void themsach() {
	Book x;
	cin.ignore();
	x.setbook_no();
	x.setbook_name();
	x.setbook_author();
	x.setnum_avai();
	book.push_back(x);
	cout << "Da them thanh cong! Nhan enter de tiep tuc!";
	savefilebook();
	cin.ignore();
}
 
void xoasach() {
	string book_no;
	cout << "Nhap ma so sach ban muon xoa: "; getline(cin, book_no);

}

/*____________________________________________________________________*/
/*MOT SO XU LI QUAN TRONG*/

//get current time 
Time time() {
	Time s;
	time_t now = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &now);
	str[strlen(str) - 1] = '\0';
	s.date = str;
	s.time = time(0);
	return s;
};

//Giai thuat KMP tim kiem chuoi//
int *return_arr(string w) {
	int *T = new int[w.length()];
	int pos = 2, cnd = 0;
	*T = -1;
	for (int i = 1; i < w.length(); i++) *(T + i) = 0;
	while (pos < w.length()) {
		if (w[pos - 1] == w[cnd]) {
			T[pos] = cnd + 1;
			pos++;
			cnd++;
		}
		else if (cnd > 1) cnd = T[cnd];
		else {
			T[pos] = 0;
			pos++;
		}
	}
	return T;
}
//giai thuat kmp
bool timkiem(string s, string w) {
	int *T = new int[w.length()];
	int kt = 0;
	T = return_arr(w);
	int m = 0, i = 0;
	while (m + i < s.length()) {
		if (w[i] == s[m + i]) {
			i++;
			if (i == w.length()) {
				kt = 1;
				break;
			}
		}
		else if (T[i] > -1) {
			i = T[i];
			m = m + i - T[i];
		}
		else {
			i = 0;
			m++;
		}
	}
	if (kt == 1) return true;
	else return false;
}

//dang nhap
string dangnhap() {
	Account  _x;
	int kt = 0;
    string account_name;
	cout << setw(50) << "HE THONG LIBPRO" << endl;
	cout << "Nhap ten dang nhap: "; getline(cin, account_name);
	cout << "Nhap mat khau: ";
	string password;
	char ch;
	string in = "";
	ch = _getch();
	while (ch != 13) {
		if (ch == 8) {
			if (password.length() == 0) {
				ch = _getch();
				continue;
			}
			else {
				password.erase(password.length() - 1, 1);
				in.erase(in.length() - 1, 1);
				system("cls");
				cout << setw(50) << "HE THONG LIBPRO" << endl;
				cout << "Nhap ten dang nhap: " << account_name << endl;
				cout << "Nhap mat khau: ";
				cout << in;
				ch = _getch();
				continue;
			}
		}
		password += ch;
		in = in + '*';
		system("cls");
		cout << setw(50) << "HE THONG LIBPRO" << endl;
		cout << "Nhap ten dang nhap: " << account_name << endl;
		cout << "Nhap mat khau: ";
		cout << in;
		ch = _getch();
	}
	_x.setAccountId(account_name);
	_x.setPassword((password));
	for (int i = 0; i < account_data.size(); i++)
		if (account_data[i].getAccountId() == _x.getAccountId())
			if (account_data[i].getPassword() == _x.getPassword()) {
				kt = 1;
				cout << "Dang nhap thanh cong" << endl;
				return _x.getAccountId();
			}
	if (kt == 0) {
		cout << endl;
		cout << "Ten dang nhap hoac mat khau sai! " << endl;
		return "false";
	}

}

void doimatkhau(string account_name) {
	system("cls");
	cout << setw(50) << "HE THONG LIBPRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "Nhap mat khau cu: ";
	string password;
	char ch;
	string in = "";
	ch = _getch();
	while (ch != 13) {
		if (ch == 8) {
			if (password.length() == 0) {
				ch = _getch();
				continue;
			}
			else {
				password.erase(password.length() - 1, 1);
				in.erase(in.length() - 1, 1);
				system("cls");
				cout << setw(50) << "HE THONG LIBPRO" << endl;
				cout << "Tai khoan: " << account_name << endl;
				cout << "Nhap mat khau cu: ";
				cout << in;
				ch = _getch();
				continue;
			}
		}
		password += ch;
		in = in + '*';
		system("cls");
		cout << setw(50) << "HE THONG LIBPRO" << endl;
		cout << "Tai khoan: " << account_name << endl;
		cout << "Nhap mat khau cu: ";
		cout << in;
		ch = _getch();
	}
	for (int i = 0; i<account_data.size(); i++)
		if (account_data[i].getAccountId() == account_name)
			if (account_data[i].getPassword() == (password)) {
				string npass1, npass2, in1, in2;
				system("cls");
				cout << setw(50) << "HE THONG LIBPRO" << endl;
				cout << "Tai khoan: " << account_name << endl;
				cout << "Nhap mat khau moi: ";
				ch = _getch();
				while (ch != 13) {
					if (ch == 8) {
						if (npass1.length() == 0) {
							ch = _getch();
							continue;
						}
						else {
							npass1.erase(password.length() - 1, 1);
							in1.erase(in1.length() - 1, 1);
							system("cls");
							cout << setw(50) << "HE THONG LIBPRO" << endl;
							cout << "Tai khoan: " << account_name << endl;
							cout << "Nhap mat khau moi: ";
							cout << in1;
							ch = _getch();
							continue;
						}
					}
					npass1 += ch;
					in1 = in1 + '*';
					system("cls");
					cout << setw(50) << "HE THONG LIBPRO" << endl;
					cout << "Tai khoan: " << account_name << endl;
					cout << "Nhap mat khau moi: ";
					cout << in1;
					ch = _getch();
				}
				cout << endl;
				cout << "Xac nhan lai mat khau: ";
				ch = _getch();
				while (ch != 13) {
					if (ch == 8) {
						if (npass2.length() == 0) {
							ch = _getch();
							continue;
						}
						else {
							npass2.erase(password.length() - 1, 1);
							in2.erase(in2.length() - 1, 1);
							system("cls");
							cout << setw(50) << "HE THONG LIBPRO" << endl;
							cout << "Tai khoan: " << account_name << endl;
							cout << "Nhap mat khau moi: " << in1 << endl;
							cout << "Xac nhan lai mat khau: ";
							cout << in2;
							ch = _getch();
							continue;
						}
					}
					npass2 += ch;
					in2 = in2 + '*';
					system("cls");
					cout << setw(50) << "HE THONG LIBPRO" << endl;
					cout << "Tai khoan: " << account_name << endl;
					cout << "Nhap mat khau moi: " << in1 << endl;
					cout << "Xac nhan lai mat khau: ";
					cout << in2;
					ch = _getch();
				}
				cout << endl;
				if (!kiemtramatkhau(npass1)) {
					cout << endl;
					cout << "Mat khau khong hop le! Mat khau chi chua so va chu cai, co phan biet chu hoa, chu thuong!" << endl;
					cout << "Doi mat khau that bai" << endl;
					return;
				}
				if (npass1 != npass2) {
					cout << endl;
					cout << "Mat khau hai lan nhap khong giong nhau! Doi mat khau that bai!" << endl;
				}
				else {
					cout << "Doi mat khau thanh cong " << endl;
					account_data[i].setPassword((npass1));
					savefileaccount_data();
				}
				break;
			}
			else {
				cout << endl;
				cout << "Mat khau cu cua ban nhap khong chinh xac! Viec doi mat khau that bai!" << endl;
				break;
			}
}
bool kiemtramatkhau(std::string pass) {
	int kt = 0;
	for (int i = 0; i < pass.length(); i++)
		if ((pass[i] > '0'&& pass[i] < '9') || (pass[i] > 'a'&& pass[i] < 'z') || (pass[i] > 'A'&& pass[i] < 'Z'))
			continue;
		else return false;
		return true;
}
bool kiemtratrangthai(std::string account_name) {
	for (int i = 0; i < account_data.size(); i++) 
		if (account_data[i].getAccountId()==account_name){
			if (account_data[i].getActive() == "true") return true;
			else return false;
			break;
		}
}





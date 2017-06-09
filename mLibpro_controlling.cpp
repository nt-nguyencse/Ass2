#include "mLibpro_controlling.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include<string>
//#include "SHA512.h"
using namespace std;

vector<AccountRoleMap> _accountrolemap_data = loadaccountrolemap();

/*______________________________________________________________________*/
//MAN HINH CHINH //

void manhinhchinh() {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Chao mung den voi he thong LIBRO!" << endl;
	cout << "1.Dang nhap" << endl;
	cout << "2.Thoat" << endl;
	cout << "HAY CHON CHUC NANG: ";
	int choice;
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1: manhinhdangnhap(); break;
	case 2:break;
	}
};
void manhinhdangnhap() {
	system("cls");
	//cout << setw(50) << right << "HE THONG LIBRO" << endl;
	Account account_pre;
	account_pre.setAccountId(dangnhap());
	if (account_pre.getAccountId() == "false") {
		cout << "Ban co muon dang nhap lai? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'y') {
			system("cls");
			cin.ignore();
			manhinhdangnhap();
		}
		else {
			cout << "Nhap enter de tiep tuc!" << endl;
			_getch();
			manhinhchinh();
		}
	}
	else {
		for (int i = 0; i < _accountrolemap_data.size(); i++)
			if (_accountrolemap_data[i].account_id == account_pre.getAccountId()) {
				if (_accountrolemap_data[i].role_id == "001") manhinhdocgia(account_pre.getAccountId());
				else if(_accountrolemap_data[i].role_id == "002")  manhinhquanli(account_pre.getAccountId());
				else if (_accountrolemap_data[i].role_id == "003") manhinhthuthu(account_pre.getAccountId());
				break;
			}
	}
}
void chucnangthoat(string account_name) {
	for (int i = 0; i < _accountrolemap_data.size(); i++)
		if (_accountrolemap_data[i].account_id == account_name) {
			ofstream f;
			f.open("phientruoc.txt");
			f << _accountrolemap_data[i].account_id << endl;
			f << _accountrolemap_data[i].role_id << endl;
			f.close();
			break;
		}
}
void dangxuat() {
	ofstream f;
	f.open("phientruoc.txt");
	f << 0 << endl;
	f << 0 << endl;
	f.close();
	manhinhchinh();
}
void khoidonghethong() {
	string account_id, role_id;
	ifstream f;
	f.open("phientruoc.txt");
	getline(f, account_id);
	getline(f, role_id);
	f.close();
	if (account_id == "0" || role_id == "0") manhinhchinh();
	else if (role_id == "001") manhinhdocgia(account_id);
	else if (role_id == "002") manhinhquanli(account_id);
	else if (role_id == "003") manhinhthuthu(account_id);
}

/*_________________________________________________________________________*/
// CHUC NANG DANH CHO DOC GIA//

void manhinhdocgia(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "Chao mung den voi he thong LIBRO!" << endl;
	cout << "1.Tim sach" << endl;
	cout << "2.Gui yeu cau muon sach" << endl;
	cout << "3.Nhac tra sach" << endl;
	cout << "4.Xem thong tin" << endl;
	cout << "5.Doi mat khau" << endl;
	cout << "6. Dang xuat" << endl;
	cout << "7.Thoat" << endl;
	cout << "HAY CHON CHUC NANG: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: manhinhtimsach(account_name); break;
	case 2: manhinhmuonsach(account_name); break;
	case 3:  manhinhnhactrasach(account_name); break;
	case 4:  manhinhxemthongtin(account_name); break;
	case 5:  manhinhdoimatkhaudocgia(account_name); break;
	case 6: dangxuat(); break;
	case 7:chucnangthoat(account_name); break;
	}
}
void manhinhtimsach(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	timsach(account_name);
	_getch();
	system("cls");
	manhinhdocgia(account_name);
}
void manhinhmuonsach(string account_name) {
	cin.ignore();
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	if (xemgiohang(account_name)) {
		cout << "Ban co muon xoa sach nao khoi gio hang khong?(y/n)";
		while (1) {
			char choice;
			cin >> choice;
			if (choice == 'y') {
				cin.ignore();
				xoakhoigiohang(account_name);
				if (!xemgiohang(account_name)) break;
				cout << "Ban co muon xoa sach nao nua khoi gio hang khong?(y/n) ";
				cin >> choice;
				if (choice == 'n') break;
			}
			else break;
		}
	}
	guiyeucaumuonsach(account_name);
	_getch();
	system("cls");
	manhinhdocgia(account_name);
}
void manhinhxemthongtin(string account_name) {
	cin.ignore();
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	xemthongtinmuontra(account_name);
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	xemno(account_name);
	_getch();
	system("cls");
	manhinhdocgia(account_name);
}
void manhinhnhactrasach(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	nhactrasach(account_name);
	_getch();
	system("cls");
	manhinhdocgia(account_name);

}
void manhinhdoimatkhaudocgia(string account_name) {
	doimatkhau(account_name);
	_getch();
	manhinhdocgia(account_name);
}


/*________________________________________________________________*/
/*CHUC NANG DANH CHO QUAN LI NGUOI DUNG*/
void manhinhquanli(string account_name) {
	system("cls");
	cout << setw(80) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "Chao mung den voi he thong LIBRO!" << endl;
	cout << "1.Them nguoi dung" << endl;
	cout << "2.Xoa nguoi dung" << endl;
	cout << "3.Tim kiem nguoi dung " << endl;
	cout << "4.Them vao tai khoan" << endl;
	cout << "5.Xoa tai khoan" << endl;
	cout << "6.Tim kiem tai khoan" << endl;
	cout << "7.Mo khoa tai khoan" << endl;
	cout << "8.Doi mat khau" << endl;
	cout << "9.Dang xuat" << endl;
	cout << "10.Thoat" << endl;
	cout << "HAY CHON CHUC NANG: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: manhinhthemnguoidung(account_name); break;
	case 2: manhinhxoanguoidung(account_name); break;
	case 3: manhinhtimkiemnguoidung(account_name); break;
	case 4: manhinhthemtaikhoan(account_name); break;
	case 5: manhinhxoataikhoan(account_name); break;
	case 6: manhinhtimkiemtaikhoan(account_name); break;
	case 7: manhinhmokhoa(account_name); break;
	case 8: manhinhdoimatkhauquanli(account_name); break;
	case 9: dangxuat(); break;
	case 10: chucnangthoat(account_name); break;
	}
}
void manhinhtimkiemtaikhoan(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	timkiemtheotaikhoan();
	_getch();
	system("cls");
	manhinhquanli(account_name);
}
void manhinhmokhoa(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	mokhoataikhoan();
	system("cls");
	manhinhquanli(account_name);
}
void manhinhthemnguoidung(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	themnguoidung();
	system("cls");
	manhinhquanli(account_name);
}
void manhinhtimkiemnguoidung(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	timkiemnguoidung();
	system("cls");
	manhinhquanli(account_name);
}
void manhinhthemtaikhoan(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	themtaikhoan();
	_getch();
	while (1) {
		cout << "Ban co muon tao nua khong?(y/n): ";
		char choice;
		cin >> choice;
		cin.ignore();
		if (choice == 'y') themtaikhoan();
		else {
			cout << "Nhan enter de tiep tuc....." << endl;
			break;
		}
	}
	system("cls");
	manhinhquanli(account_name);
}
void manhinhxoataikhoan(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	xoataikhoan();
	_getch();
	system("cls");
	manhinhquanli(account_name);

}
void manhinhxoanguoidung(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	xoanguoidung();
	_getch();
	system("cls");
	manhinhquanli(account_name);
}
void manhinhdoimatkhauquanli(string account_name) {
	doimatkhau(account_name);
	_getch();
	manhinhquanli(account_name);
}

/*________________________________________________________*/
/*CHUC NANG DANH CHO THU THU*/

void manhinhthuthu(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "Chao mung den voi he thong LIBRO!" << endl;
	cout << "1.Them sach" << endl;
	cout << "2.Xoa sach" << endl;
	cout << "3.Tra sach " << endl;
	cout << "4.Ghi nhan muon sach" << endl;
	cout << "5.Tra no" << endl;
	cout << "6.Doi mat khau" << endl;
	cout << "7.Dang xuat" << endl;
	cout << "8.Thoat" << endl;
	cout << "HAY CHON CHUC NANG: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: manhinhthemsach(account_name); break;
	case 2: break;
	case 3: manhinhtrasach(account_name); break;
	case 4: manhinhxacnhanmuonsach(account_name); break;
	case 5: manhinhnhantrano(account_name); break;
	case 6: manhinhdoimatkhauthuthu(account_name); break;
	case 7: dangxuat(); break;
	case 8: chucnangthoat(account_name); break;
	}
}
void manhinhthemsach(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	themsach();
	_getch();
	system("cls");
	manhinhthuthu(account_name);

}
void manhinhtrasach(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	trasach();
	_getch();
	system("cls");
	manhinhthuthu(account_name);
}
void manhinhnhantrano(string account_name) {
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	nhantrano();
	_getch();
	system("cls");
	manhinhthuthu(account_name);

}
void manhinhxacnhanmuonsach(string account_name) {
	string _account_name;
	cin.ignore();
	system("cls");
	cout << setw(50) << right << "HE THONG LIBRO" << endl;
	cout << "Tai khoan: " << account_name << endl;
	cout << "Nhap ten tai khoan yeu cau muon sach: "; getline(cin, _account_name);
	if (xemdonhang(_account_name)) {
		cout << "Ban co muon xoa sach nao khoi don hang khong?(y/n)";
		while (1) {
			char choice;
			cin >> choice;
			if (choice == 'y') {
				cin.ignore();
				xoakhoidonhang(_account_name);
				cout << "Ban co muon xoa sach nao nua khoi gio hang khong?(y/n) ";
				cin >> choice;
				if (choice == 'n') break;
			}
			else break;
		}
	}
	xacnhanmuonsach(_account_name);
	_getch();
	system("cls");
	manhinhthuthu(account_name);
}
void manhinhdoimatkhauthuthu(string account_name) {
	doimatkhau(account_name);
	_getch();
	manhinhthuthu(account_name);
}

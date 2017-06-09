#include "mLibpro_data.h"
#include <iostream>
#include <string>
#include "sha512.h"
using namespace std;
/*----------------------------------------------------------*/
/*--------------------ACCOUNT-------------------------------*/
void Account::setAccountId() {
	getline(cin, account_id);
}

void Account::setAccountId(string _account_id) {
	account_id = _account_id;
}

string Account::getAccountId() {
	return account_id;
}

void Account::setPassword() {
	password = new char[50];
	getline(cin, password);
}

void Account::setPassword(std::string _password) {
	password = sha512(_password);
}

string Account::getPassword() {
	return sha512(password);
}

void Account::setActive() {
	getline(cin, active);
}

void Account::setActive(std::string _acive) {
	active = _acive;
}

string Account::getActive() {
	return active;
}

/*----------------------------------------------------------*/
/*-----------------------BOOK-------------------------------*/
void Book::setbook_name() {
	cout << "Nhap ten sach: ";
	getline(cin, book_names);
}

void Book::setbook_author() {
	cout << "Nhap tac gia: ";
	getline(cin, book_author);
}

string Book::getbook_name() {
	return book_names;
}

void Book::setbook_name(string s) {
	book_names = s;
}

string Book::getbook_author() {
	return book_author;
}

void Book::setbook_author(string s) {
	book_author = s;
}

void Book::setbook_no() {
	cout << "Nhap ma so sach: ";
	getline(cin, book_no);
}

void Book::setbook_no(string _book_no) {
	book_no = _book_no;
}

string Book::getbook_no() {
	return book_no;
}

void Book::setnum_avai() {
	cout << "Nhap so luong sach co san: ";
	cin >> num_avai;
}

void Book::setnum_avai(int _num) {
	num_avai = _num;
}

int Book::getnum_avai() {
	return num_avai;
}

/*------------------------------------------------------*/
/*-----------------USER---------------------------------*/
void User::setUser_no() {
	getline(cin, user_no);
}

string User::getUser_no() {
	return user_no;
}

void User::setUser_no(string _user_no) {
	user_no = _user_no;
}

void User::setUser_name() {
	getline(cin, user_name);
}

void User::setUser_name(string _user_name) {
	user_name = _user_name;
}

string User::getUser_name() {
	return user_name;
}

void User::setdob() {
	getline(cin, dob);
}

void User::setdob(string _dob) {
	dob = _dob;
}

string User::getdob() {
	return dob;
}

void User::setemail() {
	getline(cin, email);
}

void User::setemail(string _email) {
	email = _email;
}

string User::getemail() {
	return email;
}

/*------------------------------------------------------*/

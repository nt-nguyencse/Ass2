#pragma once
#ifndef  MLIBRO_DATA
#define  MLIBRO_DATA
#include <string>
#include <vector>
class Account {
private:
	std::string account_id;
	std::string password;
	std::string active;

public:
	std::string getAccountId();
	void setAccountId();
	void setAccountId(std::string _account_id);
	std::string getPassword();
	void setPassword();
	void setPassword(std::string _password);
	void setActive();
	void setActive(std::string _acive);
	std::string getActive();
};
class User {
private:
	std::string user_no;
	std::string user_name;
	std::string dob;
	std::string email;
public:
	std::string getUser_no();
	void setdob();
	std::string getdob();
	void setdob(std::string _dob);
	void setUser_no();
	void setUser_no(std::string _user_no);
	std::string getUser_name();
	void setUser_name();
	void setUser_name(std::string _user_name);
	std::string getemail();
	void setemail();
	void setemail(std::string _email);
};
typedef struct Role {
	std::string role_id;
	std::string role_desc;
}Role;

typedef struct AccountRoleMap {
	std::string account_id;
	std::string role_id;
}AccountRoleMap;
class Book {
private:
	std::string book_no;
	std::string book_names;
	std::string book_author;
	int num_avai;

public:
	void setbook_no();
	void setbook_no(std::string _book_no);
	void setbook_name();
	void setbook_author();
	std::string getbook_no();
	std::string getbook_name();
	void setbook_name(std::string _book_name);
	std::string getbook_author();
	void setbook_author(std::string _book_author);
	void setnum_avai();
	int getnum_avai();
	void setnum_avai(int num);
};

typedef struct {
	std::string date;
	unsigned long long time;
}Time;

typedef struct {
	Account account;
	std::vector<Book> listbook;
	std::string trangthai;
	Time time;
}Giohang;



typedef struct {
	std::string book_no;
	Time tgm;
	Time tgt;
}Book_MT;

typedef struct {
	Account account;
	std::vector<Book_MT> listbook;
}Hosomuonsach;

typedef struct {
	Account account;
	unsigned int tienno;
	unsigned int tiendt;
}Tienno;

typedef struct {
	Account account;
	User user;
}Account_User;

#endif



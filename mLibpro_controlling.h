#pragma once
#ifndef  MLIBPRO_CONTROLLING
#define MLIBPRO_CONTROLLING
#include "mLibpro_data.h"
#include "mLibpro_load_save_data.h"
#include <string>

/*______________________________________________________________________*/
//MAN HINH CHINH //
void manhinhchinh();
void manhinhdangnhap();
void chucnangthoat(std::string account_name);
void dangxuat();
void khoidonghethong();


/*_________________________________________________________________________*/
// CHUC NANG DANH CHO DOC GIA//
void manhinhdocgia(std::string account_name);
void manhinhtimsach(std::string account_name);
void manhinhmuonsach(std::string account_name);
void manhinhxemthongtin(std::string account_name);
void manhinhnhactrasach(std::string account_name);
void manhinhdoimatkhaudocgia(std::string account_name);

/*________________________________________________________________*/
/*CHUC NANG DANH CHO QUAN LI NGUOI DUNG*/

void manhinhquanli(std::string account_name);
void manhinhtimkiemtaikhoan(std::string account_name);
void manhinhmokhoa(std::string account_name);
void manhinhthemnguoidung(std::string account_name);
void manhinhtimkiemnguoidung(std::string account_name);
void manhinhthemtaikhoan(std::string account_name);
void manhinhxoataikhoan(std::string account_name);
void manhinhxoanguoidung(std::string account_name);
void manhinhdoimatkhauquanli(std::string account_name);

/*________________________________________________________*/
/*CHUC NANG DANH CHO THU THU*/
void manhinhthuthu(std::string account_name);
void manhinhthemsach(std::string account_name);
void manhinhtrasach(std::string account_name);
void manhinhnhantrano(std::string account_name);
void manhinhxacnhanmuonsach(std::string account_name);
void manhinhdoimatkhauthuthu(std::string account_name);



#endif

// HuynhTrongNghia_N15DCCN120
// NguyenThanhHuy_N15DCAT017
#include <iostream>
#include "GiaoDien.h"
#include <stdlib.h>
#include<string>
#include <fstream>

using namespace std;
string a = "1. Danh Sach Khoa", b = "2. Danh Sach Khoa Hoc", c = "3. Danh Sach Sinh Vien", d = "4. Danh Sach Chuong Trinh", e = "5. Danh Sach Mon Hoc", f = "6. Ket Qua", g = "7. Danh Sach Lop Hoc", h = "8. Danh Sach Giang Day", i = "9. Gioi thieu", j = "10. Thoat";
///
struct Khoa {
	char maKhoa[15];
	char tenKhoa[50];
	int namThanhLap;
	int id;
};
struct DSKhoa
{
	Khoa data;
	struct  DSKhoa* left;
	struct  DSKhoa* right;
};

typedef struct DSKhoa* Tree_DSKhoa;
///
struct ChuongTrinh {
	char maCTr[15];
	char tenCTr[20];
};
struct NodeCTr {
	ChuongTrinh data;
	struct NodeCTr* next;
};
//
struct KetQua {
	int diem;
	int lanThi;
	char maMonHoc[15];
	char maSV[15];
};
struct NodeKQ {
	KetQua data;
	struct NodeKQ* next;
};
//
struct SinhVien {
	char maSV[15];
	char hoTen[30];
	int namSinh;
	bool gioitinh;
	char maLop[15];
};
struct NodeSV {
	SinhVien data;
	struct NodeSV* next;
};
//
struct  GiangDay
{
	char maMonHoc[15];
	char maKhoa[15];
	char maCTr[15];
	int hocKy;
	int namHoc;
	int tietLyThuyet;
	int tietThucHanh;
	int tinChi;
};
struct NodeGD {
	GiangDay data;
	struct NodeGD* next;
};

//
struct MonHoc {
	char maMonHoc[15];
	char tenMonHoc[50];
	char maKhoa[15];
	int id;
	//	int tietLyThuyet;
	//	int tietThucHanh;
	//	int tinChi;
};
struct DSMonHoc
{
	MonHoc data;
	struct  DSMonHoc* left;
	struct  DSMonHoc* right;
};
typedef struct DSMonHoc* Tree_DSMH;
void Init_monhoc(Tree_DSMH& root) {
	root = NULL;
}
struct LopHoc {
	char maLop[15];
	char maKhoa[15];
	char maKhoaHoc[15];
	char maCTr[15];
	int id;
};
struct NodeLHoc {
	LopHoc data;
	struct NodeLHoc* next;
};
//
struct SVTheoMon {
	string masinhvien[50];
};
struct MH_Nam {
	string maMonHoc[100];
}; 
struct MH_Khoa {
	string maMonHoc[50];
};
//
DSKhoa* getNodeKhoa(Khoa& khoa)
{
	DSKhoa* node = new DSKhoa;
	node->data = khoa;
	node->left = node->right = NULL;
	return node;
}
DSKhoa* TimThemKhoa(Tree_DSKhoa& root, Khoa& khoa)
{
	if (root == NULL)
	{
		return NULL;
	}
	DSKhoa* p = root;
	DSKhoa* f = p;
	while (p != NULL)
	{
		f = p;
		if (strcmp(p->data.maKhoa, khoa.maKhoa) > 0)
		{
			p = p->left;
		}
		else if (strcmp(p->data.maKhoa, khoa.maKhoa) < 0)
		{
			p = p->right;
		}
	}
	return f;
}
DSKhoa* SearchKhoa(Tree_DSKhoa& t, Khoa& khoa)
{

	if (t != NULL)
	{
		if (strcmp(t->data.maKhoa, khoa.maKhoa) == 0)
		{
			DSKhoa* p = t;
			return p;
		}
		else if (strcmp(t->data.maKhoa, khoa.maKhoa) > 0)
		{
			return SearchKhoa(t->left, khoa);
		}
		else if (strcmp(t->data.maKhoa, khoa.maKhoa) < 0)
		{
			return SearchKhoa(t->right, khoa);
		}
	}
	return NULL;
}//
DSMonHoc* SearchMonHoc(Tree_DSMH& t, MonHoc& monhoc)
{

	if (t != NULL)
	{
		if (strcmp(t->data.maMonHoc, monhoc.maMonHoc) == 0)
		{
			DSMonHoc* p = t;
			return p;
		}
		else if (strcmp(t->data.maMonHoc, monhoc.maMonHoc) > 0)
		{
			return SearchMonHoc(t->left, monhoc);
		}
		else if (strcmp(t->data.maMonHoc, monhoc.maMonHoc) < 0)
		{
			return SearchMonHoc(t->right, monhoc);
		}
	}
	return NULL;
}
//
//
DSMonHoc* getNodeMonHoc(MonHoc& monhoc)
{
	DSMonHoc* node = new DSMonHoc;
	node->data = monhoc;
	node->left = node->right = NULL;
	return node;
}
DSMonHoc* TimThemMonHoc(Tree_DSMH& root, MonHoc& monhoc)
{
	if (root == NULL)
	{
		return NULL;
	}
	DSMonHoc* p = root;
	DSMonHoc* f = p;
	while (p != NULL)
	{
		f = p;
		if (strcmp(p->data.maMonHoc, monhoc.maMonHoc) > 0)
		{
			p = p->left;
		}
		else if (strcmp(p->data.maMonHoc, monhoc.maMonHoc) < 0)
		{
			p = p->right;
		}
	}
	return f;
}
void AddNodeMonHoc(Tree_DSMH& t, MonHoc monhoc)
{
	DSMonHoc* n = getNodeMonHoc(monhoc);
	if (t == NULL)
	{
		n->data.id = 1;
		t = n;
		return;
	}
	else
	{
		DSMonHoc* k = TimThemMonHoc(t, monhoc);
		if (k != NULL)
		{

			if (strcmp(k->data.maMonHoc, monhoc.maMonHoc) > 0)
			{
				n->data.id = t->data.id++;
				k->left = n;

			}
			else if (strcmp(k->data.maMonHoc, monhoc.maMonHoc) < 0)
			{
				n->data.id = t->data.id++;
				k->right = n;

			}
		}
	}
}
///
void xoamactr(char mactr[15], NodeCTr*& DSCTR) {
	if (DSCTR == NULL) {
		return;
	}
	if (strcmp(DSCTR->data.maCTr, mactr) == 0) {
		NodeCTr* b = DSCTR;
		DSCTR = b->next;
		delete b;
		return;
	}
	NodeCTr* Temp = NULL;
	for (NodeCTr* b = DSCTR; b != NULL; b = b->next) {
		if (strcmp(DSCTR->data.maCTr, mactr) == 0) {
			Temp->next = b->next;
			delete b;
			return;
		}
		Temp = b;
	}
}
//
void DanhSachKhoa(Tree_DSKhoa& t, Khoa a[], int& n)
{

	if (t != NULL)
	{
		strcpy_s(a[n].maKhoa, t->data.maKhoa);
		strcpy_s(a[n].tenKhoa, t->data.tenKhoa);
		a[n++].namThanhLap = t->data.namThanhLap;
		DanhSachKhoa(t->left, a, n);
		DanhSachKhoa(t->right, a, n);
	}
}
void AddNodeKhoa(Tree_DSKhoa& t, Khoa khoa)
{
	DSKhoa* n = getNodeKhoa(khoa);
	if (t == NULL)
	{
		n->data.id = 1;
		t = n;
		return;
	}
	else
	{
		DSKhoa* k = TimThemKhoa(t, khoa);
		if (k != NULL)
		{

			if (strcmp(k->data.maKhoa, khoa.maKhoa) > 0)
			{
				n->data.id = t->data.id++;
				k->left = n;
			}
			else if (strcmp(k->data.maKhoa, khoa.maKhoa) < 0)
			{
				n->data.id = t->data.id++;
				k->right = n;
			}
		}
	}
}
int XoaKhoa(Tree_DSKhoa& t, Khoa& khoa)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (strcmp(t->data.maKhoa, khoa.maKhoa) > 0) {

		return XoaKhoa(t->left, khoa);

	}
	else if (strcmp(t->data.maKhoa, khoa.maKhoa) < 0)
	{
		return XoaKhoa(t->right, khoa);
	}
	else
	{
		if (t->left == NULL)
		{
			t = t->right;
		}
		else if (t->right == NULL)
		{
			t = t->left;
		}
		else
		{
			DSKhoa* x = t->left;
			while (x->right != NULL)
			{
				x = x->right;
			}
			t->data = x->data;
			XoaKhoa(t->left, x->data);

		}

	}
	return 1;

}
void Init_khoa(Tree_DSKhoa& root) {
	root = NULL;
}

struct KhoaHoc {
	char maKhoaHoc[15];
	int namBD;
	int namKT;
};
struct DSKhoaHoc
{
	KhoaHoc data;
	struct  DSKhoaHoc* left;
	struct  DSKhoaHoc* right;
};
typedef struct DSKhoaHoc* Tree_DSKhoaHoc;
void Init_khoahoc(Tree_DSKhoaHoc& root) {
	root = NULL;
}
DSKhoaHoc* getNodeKhoaHoc(KhoaHoc& khoahoc)
{
	DSKhoaHoc* node = new DSKhoaHoc;
	node->data = khoahoc;
	node->left = node->right = NULL;
	return node;
}
DSKhoaHoc* TimThemKhoaHoc(Tree_DSKhoaHoc& root, KhoaHoc& khoahoc)
{
	if (root == NULL)
	{
		return NULL;
	}
	DSKhoaHoc* p = root;
	DSKhoaHoc* f = p;
	while (p != NULL)
	{
		f = p;
		if (strcmp(p->data.maKhoaHoc, khoahoc.maKhoaHoc) > 0)
		{
			p = p->left;
		}
		else if (strcmp(p->data.maKhoaHoc, khoahoc.maKhoaHoc) < 0)
		{
			p = p->right;
		}
	}
	return f;
}
DSKhoaHoc* SearchKhoaHoc(Tree_DSKhoaHoc& t, KhoaHoc& khoahoc)
{

	if (t != NULL)
	{
		if (strcmp(t->data.maKhoaHoc, khoahoc.maKhoaHoc) == 0)
		{
			DSKhoaHoc* p = t;
			return p;
		}
		else if (strcmp(t->data.maKhoaHoc, khoahoc.maKhoaHoc) > 0)
		{
			return SearchKhoaHoc(t->left, khoahoc);
		}
		else
		{
			return SearchKhoaHoc(t->right, khoahoc);
		}
	}
	return NULL;
}
void DanhSachKhoaHoc(Tree_DSKhoaHoc& t, KhoaHoc a[], int& n)
{
	if (t != NULL)
	{
		strcpy_s(a[n].maKhoaHoc, t->data.maKhoaHoc);
		a[n].namBD = t->data.namBD;
		a[n++].namKT = t->data.namKT;
		DanhSachKhoaHoc(t->left, a, n);
		DanhSachKhoaHoc(t->right, a, n);
	}
}
void AddNodeKhoaHoc(Tree_DSKhoaHoc& t, KhoaHoc khoahoc)
{
	DSKhoaHoc* n = getNodeKhoaHoc(khoahoc);
	if (t == NULL)
	{
		t = n;
		return;
	}
	else
	{
		DSKhoaHoc* k = TimThemKhoaHoc(t, khoahoc);
		if (k != NULL)
		{

			if (strcmp(k->data.maKhoaHoc, khoahoc.maKhoaHoc) > 0)
			{
				k->left = n;
			}
			else if (strcmp(k->data.maKhoaHoc, khoahoc.maKhoaHoc) < 0)
			{
				k->right = n;
			}
		}
	}
}
int XoaKhoaHoc(Tree_DSKhoaHoc& t, KhoaHoc& khoahoc)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (strcmp(t->data.maKhoaHoc, khoahoc.maKhoaHoc) > 0) {

		return XoaKhoaHoc(t->left, khoahoc);

	}
	else if (strcmp(t->data.maKhoaHoc, khoahoc.maKhoaHoc) < 0)
	{
		return XoaKhoaHoc(t->right, khoahoc);
	}
	else
	{
		if (t->left == NULL)
		{
			t = t->right;
		}
		else if (t->right == NULL)
		{
			t = t->left;
		}
		else
		{
			DSKhoaHoc* x = t->left;
			while (x->right != NULL)
			{
				x = x->right;
			}
			t->data = x->data;
			XoaKhoaHoc(t->left, x->data);

		}

	}
	return 1;
}
//
int XoaMonHoc(Tree_DSMH& t, MonHoc& monhoc)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (strcmp(t->data.maMonHoc, monhoc.maMonHoc) > 0) {

		return XoaMonHoc(t->left, monhoc);

	}
	else if (strcmp(t->data.maMonHoc, monhoc.maMonHoc) < 0)
	{
		return XoaMonHoc(t->right, monhoc);
	}
	else
	{
		if (t->left == NULL)
		{
			t = t->right;
		}
		else if (t->right == NULL)
		{
			t = t->left;
		}
		else
		{
			DSMonHoc* x = t->left;
			while (x->right != NULL)
			{
				x = x->right;
			}
			t->data = x->data;
			XoaMonHoc(t->left, x->data);

		}

	}
	return 1;

}
//

void DelRow(int x, int y, int viTriChuot) {
	for (int i = x; i < y; i++) {
		gotoxy(i, viTriChuot);
		cout << "\b" << " " << "\b";
	}
}
void DelMenuSmall() {
	DelRow(40, 80, 4);
	DelRow(40, 80, 5);
	DelRow(40, 80, 6);
	DelRow(40, 80, 7);
	DelRow(40, 80, 8);
	DelRow(40, 80, 9);
	DelRow(40, 80, 10);
	DelRow(40, 80, 11);
}
void XoaManHinh()
{
	system("cls");
	system("color 7");
}
void Vedau(int n, int x) {
	for (int i = 0; i < n; i++) {
		cout << (char)x;
	}
}
void Vedau_doc(int n, int x, int y) {
	int z = 0;
	for (int i = 0; i < n; i++) {
		z = y + i;
		gotoxy(x, z);
		cout << (char)179;
	}
}
void VeKhung(int x, int y, int daungang, int daudoc) {
	gotoxy(x, y);
	cout << (char)218;
	Vedau(daungang, 196);
	Vedau_doc(daudoc, x, y + 1);
	gotoxy(x, y + daudoc + 1);
	cout << (char)192;
	gotoxy(x + 1, y + daudoc + 1);
	Vedau(daungang, 196);
	gotoxy(x + daungang + 1, y);
	cout << (char)191;
	Vedau_doc(daudoc, x + daungang + 1, y + 1);
	gotoxy(x + daungang + 1, y + daudoc + 1);
	cout << (char)217;
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, ESC };
TRANGTHAI keyPress(int z)
{
	if (z == 224)
	{
		char c;
		c = _getch();
		if (c == 72) return UP;
		if (c == 80) return DOWN;
		if (c == 77) return RIGHT;
		if (c == 75) return LEFT;
	}
	else if (z == 13) return ENTER;
	else if (z == 27)return ESC;
}
void veHCN(int xBD, int yBD, int chieurong, int chieucao)
{

	for (int i = 0; i < chieucao; i++)
	{
		gotoxy(xBD, i + yBD);
		cout << (char)179;
		gotoxy(xBD + chieurong, i + yBD);
		cout << (char)179;
	}
	for (int i = 0; i < chieurong + 1; i++)
	{
		gotoxy(i + xBD, yBD);
		cout << (char)196;
		gotoxy(i + xBD, chieucao + yBD);
		cout << (char)196;
	}

	gotoxy(xBD, yBD);
	cout << (char)218;

	gotoxy(xBD + chieurong, yBD);
	cout << (char)191;

	gotoxy(xBD, chieucao + yBD);
	cout << (char)192;
	gotoxy(xBD + chieurong, chieucao + yBD);
	cout << (char)217;

}
int menu_khoa(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Thong Tin Khoa";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Khoa Theo Ma";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Khoa";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Khoa";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Khoa";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Khoa Theo Ten";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Thong Ke Sinh Vien Theo Khoa";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}int menu_khoahoc(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Thong Tin Khoa Hoc";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Danh Sach Khoa Hoc";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Khoa Hoc";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Khoa Hoc";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Khoa Hoc";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Khoa Hoc Theo Ma";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "DSSV Theo Khoa Hoc";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
//sinh vien 
int menu_sinhvien(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Sinh Vien";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Sinh Vien";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Sinh Vien";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Sinh Vien";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Sinh Vien";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sap Xep Sinh Vien";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "DSSV Theo Lop";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
///chuong trinh
int menu_chuongtrinh(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Chuong Trinh";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Chuong Trinh Theo Ma";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Chuong Trinh";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Chuong Trinh";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Chuong Trinh Theo Ten";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Chuong Trinh";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
//mon hoc
int menu_monhoc(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Mon Hoc";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Theo Ma";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Mon Hoc";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Mon Hoc";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Theo Ten";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Mon Hoc";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "So Luong Sinh Vien Theo Mon";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
///ket qua
int menu_ketqua(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Ket Qua Thi";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thi Ket Qua Thi";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa,Sua,Tim Kiem Ket Qua Thi";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Thong Ke Diem Cua Sinh Vien";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "DSSV Thi Lan II Theo Mon Hoc";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "DSSV Thi Lan II Theo Khoa";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "DSSV Thi Lan II Theo Nam Hoc";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
///lop hoc
int menu_lophoc(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Lop Hoc";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Lop Hoc";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Lop Hoc";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Lop Hoc";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sap Xep Lop Hoc";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Lop Hoc";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Thong Ke SV Theo Lop";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
//
int menu_gd(int luachon) {
	gotoxy(40, 4);
	if (luachon == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Nhap Thong Tin Giang Day";
	gotoxy(40, 5);
	if (luachon == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Hien Thong Tin Giang Day";
	gotoxy(40, 6);
	if (luachon == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sua Thong Tin Giang Day";
	gotoxy(40, 7);
	if (luachon == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Xoa Thong Tin Giang Day";
	gotoxy(40, 8);
	if (luachon == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Sap Xep Danh Sach Giang Day";
	gotoxy(40, 9);
	if (luachon == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Tim Kiem Thong Tin Giang Day";
	gotoxy(40, 10);
	if (luachon == 7) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Mon Hoc Nhieu Sinh Vien Nhat Trong Nam";
	gotoxy(40, 11);
	if (luachon == 8) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	cout << "Thong Ke Sinh Vien Theo Nam Hoc";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return luachon;

}
//


int menu(int& tt) {
	//AnDauNhay();
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		VeKhung(49, 1, 40, 1);
		gotoxy(50, 2);
		cout << "DO AN MON CAU TRUC DU LIEU VA GIAI THUAT";
		gotoxy(2, 4);
		cout << a;
		gotoxy(2, 5);
		cout << b;
		gotoxy(2, 6);
		cout << c;
		gotoxy(2, 7);
		cout << d;
		gotoxy(2, 8);
		cout << e;
		gotoxy(2, 9);
		cout << f;
		gotoxy(2, 10);
		cout << g;
		gotoxy(2, 11);
		cout << h;
		gotoxy(2, 12);
		cout << i;
		gotoxy(2, 13);
		cout << j;
		if (tt == 1)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 4);
			cout << a;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 2)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 5);
			cout << b;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 3)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 6);
			cout << c;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 4)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 7);
			cout << d;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 5)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 8);
			cout << e;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 6)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 9);
			cout << f;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 7)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 10);
			cout << g;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 8)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 11);
			cout << h;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 9)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 12);
			cout << i;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		if (tt == 10)
		{
			SetConsoleTextAttribute(hConsoleColor, 240);
			gotoxy(2, 13);
			cout << j;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		int z = _getch();

		TRANGTHAI trangThai = keyPress(z);
		switch (trangThai)
		{
		case UP:
			tt--;
			if (tt < 1)tt = 10;
			break;
		case DOWN:
			tt++;
			if (tt > 10)tt = 1;
			break;
		case ENTER:
			return tt;
			break;
		}
		//XoaManHinh();
	}
}
////
string Nhapmakhoa(string& temp, string& tenkhoa, string& namTL, bool& trangthai);
string Nhaptenkhoa(string& makhoa, string& temp, string& namTL, bool& trangthai);
string NhapnamTL(string& makhoa, string& tenkhoa, string& temp, bool& trangthai);
string Nhapmakhoa(string& temp, string& tenkhoa, string& namTL, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(55 + tenkhoa.length(), 15);
					Nhaptenkhoa(temp, tenkhoa, namTL, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string Nhaptenkhoa(string& makhoa, string& temp, string& namTL, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 50)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(54 + makhoa.length(), 14);
					Nhapmakhoa(makhoa, temp, namTL, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
				else if (key == 80) {
					gotoxy(60 + namTL.length(), 16);
					NhapnamTL(makhoa, temp, namTL, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string NhapnamTL(string& makhoa, string& tenkhoa, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 47 && key < 58)) && count < 4)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(55 + tenkhoa.length(), 15);
					Nhaptenkhoa(makhoa, tenkhoa, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
////
string Nhapmamonhoc(string& temp, string& tenmonhoc, string& makhoa, bool& trangthai);
string Nhaptenmonhoc(string& mamonhoc, string& temp, string& makhoa, bool& trangthai);
string NhapmakhoaMH(string& mamonhoc, string& tenmonhoc, string& temp, bool& trangthai);
string Nhapmamonhoc(string& temp, string& tenmonhoc, string& makhoa, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(58 + tenmonhoc.length(), 15);
					Nhaptenmonhoc(temp, tenmonhoc, makhoa, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string Nhaptenmonhoc(string& mamonhoc, string& temp, string& makhoa, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || key == 32) && count < 50)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(57 + mamonhoc.length(), 14);
					Nhapmamonhoc(mamonhoc, temp, makhoa, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
				else if (key == 80) {
					gotoxy(54 + makhoa.length(), 16);
					NhapmakhoaMH(mamonhoc, temp, makhoa, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string NhapmakhoaMH(string& mamonhoc, string& tenmonhoc, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 47 && key < 58) || (key > 64 && key < 91) || (key > 96 && key < 123)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(58 + tenmonhoc.length(), 15);
					Nhaptenmonhoc(mamonhoc, tenmonhoc, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
///


string Nhapmakhoahoc(string& temp, string& namBD, string& namKT, bool& trangthai);
string NhapnamBD(string& maKhoaHoc, string& temp, string& namKT, bool& trangthai);
string NhapnamKT(string& maKhoaHoc, string& namBD, string& temp, bool& trangthai);
string Nhapmakhoahoc(string& temp, string& namBD, string& namKT, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(53 + namBD.length(), 15);
					NhapnamBD(temp, namBD, namKT, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string NhapnamBD(string& maKhoaHoc, string& temp, string& namKT, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 47 && key < 58)) && count < 4)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(58 + maKhoaHoc.length(), 14);
					Nhapmakhoahoc(maKhoaHoc, temp, namKT, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
				else if (key == 80) {
					gotoxy(53 + namKT.length(), 16);
					NhapnamKT(maKhoaHoc, temp, namKT, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string NhapnamKT(string& maKhoaHoc, string& namBD, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 47 && key < 58)) && count < 4)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(53 + namBD.length(), 15);
					NhapnamBD(maKhoaHoc, namBD, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
string Nhapmalh(string& temp, string& makhoa, string& makh, string& mactr, bool& trangthai);
string Nhapmakhoalh(string& malh, string& temp, string& makh, string& mactr, bool& trangthai);
string Nhapmakhlh(string& malh, string& makhoa, string& temp, string& mactr, bool& trangthai);
string Nhapmactrlh(string& malh, string& makhoa, string& makh, string& temp, bool& trangthai);
string Nhapmalh(string& temp, string& makhoa, string& makh, string& mactr, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(55 + makhoa.length(), 15);
					Nhapmakhoalh(temp, makhoa, makh, mactr, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string Nhapmakhoalh(string& malh, string& temp, string& makh, string& mactr, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(53 + malh.length(), 14);
					Nhapmalh(malh, temp, makh, mactr, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
				else if (key == 80) {
					gotoxy(59 + makh.length(), 16);
					Nhapmakhlh(malh, temp, makh, mactr, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string Nhapmakhlh(string& malh, string& makhoa, string& temp, string& mactr, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(55 + makhoa.length(), 15);
					Nhapmakhoalh(malh, makhoa, temp, mactr, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
				else if (key == 80) {
					gotoxy(62 + mactr.length(), 17);
					Nhapmactrlh(malh, makhoa, temp, mactr, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string Nhapmactrlh(string& malh, string& makhoa, string& makh, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || (key == 32)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(59 + makh.length(), 16);
					Nhapmakhlh(malh, makhoa, makh, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
////
string Nhap(string& temp)
{
	int count = 0;
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 47 && key < 58) || (key > 64 && key < 91) || (key > 96 && key < 123) || (key == 32)) && count < 14)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 9 || key == 13)
				{
					return temp;
				}
			}
			else
			{
				key = _getch();
			}
		}
	}
	return temp;
}
int NhapNam(int& x)
{
	int kq;
	int count = 0;
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if ((key >= 48 && key <= 57) && count < 4)
				{
					kq = key - 48;
					cout << kq;
					x = x * 10 + kq;
					count++;
				}
				else if (key == 8)
				{

					if (count > 0) {
						cout << "\b" << " " << "\b";
						x /= 10;
						count--;
					}
				}
				else if (key == 13)
				{
					if (x > 1950 && x <= 2035)
					{
						return x;
					}
				}
				else if (key == 27)
				{
					x = -1;
					return -1;
				}
			}
			else
			{
				key = _getch();
			}

		}
	}

	return x;
}
int NhapNamhoc_GD(int& x)
{
	int kq;
	int count = 0;
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if ((key >= 48 && key <= 57) && count < 4)
				{
					kq = key - 48;
					cout << kq;
					x = x * 10 + kq;
					count++;
				}
				else if (key == 8)
				{

					if (count > 0) {
						cout << "\b" << " " << "\b";
						x /= 10;
						count--;
					}
				}
				else if (key == 13)
				{
					if (x > 2000 && x <= 2070)
					{
						return x;
					}
				}
				else if (key == 27)
				{
					x = -1;
					return -1;
				}
			}
			else
			{
				key = _getch();
			}

		}
	}

	return x;
}
////
string Nhapyesno(string& temp)
{
	int count = 0;
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if ((key > 109 && key < 122) && count < 1)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					if (temp == "y" || temp == "n") {
						return temp;
					}
				}
			}
			else
			{
				key = _getch();
			}
		}
	}
	return temp;
}
///
string Suatenkhoa(string& temp, string& namTL, bool& trangthai);
string SuanamTL(string& makhoa, string& temp, bool& trangthai);

string Suatenkhoa(string& temp, string& namTL, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58)) && count < 48)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(60 + namTL.length(), 18);
					SuanamTL(temp, namTL, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string SuanamTL(string& tenkhoa, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if ((key > 47 && key < 58) && count < 4)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(55 + tenkhoa.length(), 17);
					Suatenkhoa(tenkhoa, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
//
string Suatenmonhoc(string& temp, string& makhoa, bool& trangthai);
string SuamakhoaMh(string& makhoa, string& temp, bool& trangthai);

string Suatenmonhoc(string& temp, string& makhoa, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58) || key == 32) && count < 48)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(54 + makhoa.length(), 18);
					SuamakhoaMh(temp, makhoa, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string SuamakhoaMh(string& tenmonhoc, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 47 && key < 58) || (key > 64 && key < 91) || (key > 96 && key < 123)) && count < 15)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(58 + tenmonhoc.length(), 17);
					Suatenmonhoc(tenmonhoc, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
//

string Suanambd(string& temp, string& namkt, bool& trangthai);
string Suanamkt(string& nambd, string& temp, bool& trangthai);

string Suanambd(string& temp, string& namkt, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if ((key > 47 && key < 58) && count < 4)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(60 + namkt.length(), 18);
					Suanamkt(temp, namkt, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string Suanamkt(string& nambd, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if ((key > 47 && key < 58) && count < 4)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(55 + nambd.length(), 17);
					Suanambd(nambd, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}
string NhapMaCT(string& temp, string& tenct, bool& trangthai);
string NhapTenCT(string& mact, string& temp, bool& trangthai);

string NhapMaCT(string& temp, string& tenct, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58)) && count < 16)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
			}
			else
			{
				key = _getch();
				if (key == 80) {
					gotoxy(63 + tenct.length(), 15);
					NhapTenCT(temp, tenct, trangthai);
					if (trangthai == true) {
						return "";
					}
				}
			}
		}
	}
	return temp;
}
string NhapTenCT(string& mact, string& temp, bool& trangthai) {
	int count = temp.length();
	int key;
	while (true)
	{
		while (_kbhit())
		{
			key = _getch();
			if (key != 224)
			{
				if (((key > 64 && key < 91) || (key > 96 && key < 123) || (key > 47 && key < 58)) && count < 21)
				{
					cout << (char)key;
					temp += (char)key;
					count++;

				}
				else if (key == 8)
				{
					if (temp.length() > 0 && count > 0) {
						cout << "\b" << " " << "\b";
						temp.erase(temp.length() - 1, 1);
						count--;
					}
				}
				else if (key == 13)
				{
					trangthai = true;
					return temp;
				}
			}
			else
			{
				key = _getch();
				if (key == 72) {
					gotoxy(62 + mact.length(), 14);
					NhapMaCT(mact, temp, trangthai);
					if (trangthai == true) {
						return "";

					}
				}
			}
		}
	}
	return temp;
}

///
string convertCharToString(char chuoi2[]) {
	string chuoi = "";
	int i = 0;
	while (chuoi2[i] != '\0') {
		chuoi = chuoi + chuoi2[i];
		i++;
	}
	return chuoi;
}
///
int CountNodeKhoa(Tree_DSKhoa treekhoa) {
	if (treekhoa == NULL)
		return 0;
	else
		return 1 + CountNodeKhoa(treekhoa->left) + CountNodeKhoa(treekhoa->right);
}
int CountNodeKhoaHoc(Tree_DSKhoaHoc treekhoahoc) {
	if (treekhoahoc == NULL)
		return 0;
	else
		return 1 + CountNodeKhoaHoc(treekhoahoc->left) + CountNodeKhoaHoc(treekhoahoc->right);
}
int CountNodeCT(NodeCTr* ctr) {
	int n = 0;
	if (ctr == NULL)
		return n;
	else {
		for (NodeCTr* b = ctr; b != NULL; b = b->next)
		{
			n++;
		}
		return n;
	}
}
int CountNodeLH(NodeLHoc* l) {
	int n = 0;
	if (l == NULL)
		return n;
	else {
		for (NodeLHoc* b = l; b != NULL; b = b->next)
		{
			n++;
		}
		return n;
	}
}
int CountNodeSV(NodeSV* l) {
	int n = 0;
	if (l == NULL)
		return n;
	else {
		for (NodeSV* b = l; b != NULL; b = b->next)
		{
			n++;
		}
		return n;
	}
}
int CountNodeKQ(NodeKQ* l) {
	int n = 0;
	if (l == NULL)
		return n;
	else {
		for (NodeKQ* b = l; b != NULL; b = b->next)
		{
			n++;
		}
		return n;
	}
}
int CountNodeKQ_Mon(NodeKQ* l, string& mamh) {
	int n = 0;
	if (l == NULL)
		return n;
	else {
		for (NodeKQ* b = l; b != NULL; b = b->next)
		{
			if (b->data.lanThi == 2 && strcmp(b->data.maMonHoc, mamh.c_str()) == 0) {
				n++;
			}
		}
		return n;
	}
}
int CountNodeGD(NodeGD* l) {
	int n = 0;
	if (l == NULL)
		return n;
	else {
		for (NodeGD* b = l; b != NULL; b = b->next)
		{
			n++;
		}
		return n;
	}
}

int CountNodeMonHoc(Tree_DSMH treemonhoc) {
	if (treemonhoc == NULL)
		return 0;
	else
		return 1 + CountNodeMonHoc(treemonhoc->left) + CountNodeMonHoc(treemonhoc->right);
}
//void HienThiDSKhoaHoc(Tree_DSKhoaHoc treekh) {
//	KhoaHoc khoahoc[100];
//	int n = 0;
//	int y = 18;
//	gotoxy(29, 16);
//	cout << "MA KHOA HOC";
//	gotoxy(51, 16);
//	cout << "NAM BAT DAU";
//	gotoxy(82, 16);
//	cout << "NAM TKET THUC";
//	gotoxy(28, 14);
//	cout << (char)218;
//	Vedau(21, 196);
//	cout << (char)194;
//	Vedau(30, 196);
//	cout << (char)194;
//	Vedau(19, 196);
//	cout << (char)191;
//	Vedau_doc(2, 28, 15);
//	Vedau_doc(2, 50, 15);
//	Vedau_doc(2, 81, 15);
//	Vedau_doc(2, 101, 15);
//	gotoxy(28, 17);
//	cout << (char)195;
//	Vedau(21, 196);
//	cout << (char)197;
//	Vedau(30, 196);
//	cout << (char)197;
//	Vedau(19, 196);
//	cout << (char)180;
//	DanhSachKhoaHoc(treekh, khoahoc, n);
//	for (int i = 0; i < n; i++)
//	{
//		Vedau_doc(3, 28, y);
//		gotoxy(28, y + 2);
//		cout << (char)195;
//		Vedau(21, 196);
//		cout << (char)197;
//		Vedau(30, 196);
//		cout << (char)197;
//		Vedau(19, 196);
//		Vedau_doc(2, 50, y);
//		Vedau_doc(2, 81, y);
//		Vedau_doc(2, 101, y);
//		gotoxy(101, y + 2);
//		cout << (char)180;
//
//		gotoxy(29, y + 1);
//		cout << khoahoc[i].maKhoaHoc;
//		gotoxy(51, y + 1);
//		cout << khoahoc[i].namBD;
//		gotoxy(82, y + 1);
//		cout << khoahoc[i].namKT;
//		y = y + 3;
//	}
//
//}///
int SVTheoLop(NodeSV*& l, char malop[15])
{
	int a = 0;
	if (l == NULL) {
		return a;
	}
	else {
		for (NodeSV* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maLop, malop) == 0)
			{
				a++;
			}

		}
	}
	return a;
}
int SVTheoKhoa(NodeSV*& b, NodeLHoc*& l, char makhoa[15])
{
	int a = 0;
	if (l == NULL) {
		return a;
	}
	else {
		for (NodeLHoc* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maKhoa, makhoa) == 0)
			{
				a += SVTheoLop(b, i->data.maLop);
			}

		}
	}
	return a;
}
//
int SVTheoNamHoc(NodeGD*& b, NodeSV*& c, NodeLHoc*& l, int& namhoc)
{
	int a = 0;
	if (l == NULL) {
		return a;
	}
	else {
		for (NodeGD* i = b; i != NULL; i = i->next)
		{
			if (i->data.namHoc == namhoc)
			{
				a += SVTheoKhoa(c, l, i->data.maKhoa);
			}

		}
	}
	return a;
}
//
void GiaoDienKhung() {
	gotoxy(28, 14);
	cout << (char)218;
	Vedau(21, 196);
	cout << (char)194;
	Vedau(30, 196);
	cout << (char)194;
	Vedau(19, 196);
	cout << (char)191;
	Vedau_doc(2, 28, 15);
	Vedau_doc(2, 50, 15);
	Vedau_doc(2, 81, 15);
	Vedau_doc(2, 101, 15);
	gotoxy(28, 17);
	cout << (char)195;
	Vedau(21, 196);
	cout << (char)197;
	Vedau(30, 196);
	cout << (char)197;
	Vedau(19, 196);
	cout << (char)180;
}
void GiaoDienKhung1() {
	gotoxy(28, 14);
	cout << (char)218;
	Vedau(21, 196);
	cout << (char)194;
	Vedau(30, 196);
	cout << (char)191;
	Vedau_doc(2, 28, 15);
	Vedau_doc(2, 50, 15);
	Vedau_doc(2, 81, 15);
	gotoxy(28, 17);
	cout << (char)195;
	Vedau(21, 196);
	cout << (char)197;
	Vedau(30, 196);
	cout << (char)180;
}


void LNRKhoaHoc(Tree_DSKhoaHoc& l, int& y)
{
	if (l != NULL) {


		LNRKhoaHoc(l->left, y);
		Vedau_doc(3, 28, y);
		gotoxy(28, y + 2);
		cout << (char)195;
		Vedau(21, 196);
		cout << (char)197;
		Vedau(30, 196);
		cout << (char)197;
		Vedau(19, 196);
		Vedau_doc(2, 50, y);
		Vedau_doc(2, 81, y);
		Vedau_doc(2, 101, y);
		gotoxy(101, y + 2);
		cout << (char)180;
		//
		gotoxy(29, 1 + y);
		cout << l->data.maKhoaHoc;
		gotoxy(51, 1 + y);
		cout << l->data.namBD;
		gotoxy(82, 1 + y);
		cout << l->data.namKT;
		y = y + 3;
		LNRKhoaHoc(l->right, y);
	}
}
void HienThiDSKhoaHoc(Tree_DSKhoaHoc& treekh, int luachon) {
	KhoaHoc khoahoc[100];
	int n = 0;
	int y = 18;
	gotoxy(29, 16);
	cout << "MA KHOA HOC";
	gotoxy(51, 16);
	cout << "NAM BAT DAU";
	gotoxy(82, 16);
	cout << "NAM TKET THUC";
	GiaoDienKhung();
	DanhSachKhoaHoc(treekh, khoahoc, n);
	if (luachon == 1) {
		for (int i = 0; i < n; i++)
		{
			Vedau_doc(3, 28, y);
			gotoxy(28, y + 2);
			cout << (char)195;
			Vedau(21, 196);
			cout << (char)197;
			Vedau(30, 196);
			cout << (char)197;
			Vedau(19, 196);
			Vedau_doc(2, 50, y);
			Vedau_doc(2, 81, y);
			Vedau_doc(2, 101, y);
			gotoxy(101, y + 2);
			cout << (char)180;
			gotoxy(29, y + 1);
			cout << khoahoc[i].maKhoaHoc;
			gotoxy(51, y + 1);
			cout << khoahoc[i].namBD;
			gotoxy(82, y + 1);
			cout << khoahoc[i].namKT;
			y = y + 3;
		}
	}
	else if (luachon == 2)
	{
		LNRKhoaHoc(treekh, y);
	}

}

////

void LNRKhoa(Tree_DSKhoa& l, int& y)
{
	if (l != NULL) {


		LNRKhoa(l->left, y);
		Vedau_doc(3, 28, y);
		gotoxy(28, y + 2);
		cout << (char)195;
		Vedau(21, 196);
		cout << (char)197;
		Vedau(30, 196);
		cout << (char)197;
		Vedau(19, 196);
		Vedau_doc(2, 50, y);
		Vedau_doc(2, 81, y);
		Vedau_doc(2, 101, y);
		gotoxy(101, y + 2);
		cout << (char)180;
		//
		gotoxy(29, 1 + y);
		cout << l->data.maKhoa;
		gotoxy(51, 1 + y);
		cout << l->data.tenKhoa;
		gotoxy(82, 1 + y);
		cout << l->data.namThanhLap;
		y = y + 3;
		LNRKhoa(l->right, y);
	}
}//

 //
void SapXepTheoTenKhoa(Khoa khoa[], int& n)
{
	Khoa x;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (convertCharToString(khoa[i].tenKhoa) > convertCharToString(khoa[j].tenKhoa))
			{
				x = khoa[i];
				khoa[i] = khoa[j];
				khoa[j] = x;
			}
		}
	}

}
void SapXepTheoTenMH(MonHoc monhoc[], int& n)
{
	MonHoc x;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (convertCharToString(monhoc[i].tenMonHoc) > convertCharToString(monhoc[j].tenMonHoc))
			{
				x = monhoc[i];
				monhoc[i] = monhoc[j];
				monhoc[j] = x;
			}
		}
	}

}

void HienThiDSKhoa(Tree_DSKhoa& treekhoa, int luachon) {
	Khoa khoa[100];
	int n = 0;
	int y = 18;
	gotoxy(29, 16);
	cout << "MA KHOA";
	gotoxy(51, 16);
	cout << "TEN KHOA";
	gotoxy(82, 16);
	cout << "NAM THANH LAP";
	GiaoDienKhung();
	DanhSachKhoa(treekhoa, khoa, n);

	if (luachon == 2) {
		SapXepTheoTenKhoa(khoa, n);
		for (int i = 0; i < n; i++)
		{

			Vedau_doc(3, 28, y);
			gotoxy(28, y + 2);
			cout << (char)195;
			Vedau(21, 196);
			cout << (char)197;
			Vedau(30, 196);
			cout << (char)197;
			Vedau(19, 196);
			Vedau_doc(2, 50, y);
			Vedau_doc(2, 81, y);
			Vedau_doc(2, 101, y);
			gotoxy(101, y + 2);
			cout << (char)180;

			gotoxy(29, y + 1);
			cout << khoa[i].maKhoa;
			gotoxy(51, y + 1);
			cout << khoa[i].tenKhoa;
			gotoxy(82, y + 1);
			cout << khoa[i].namThanhLap;
			y = y + 3;
		}
	}
	if (luachon == 3)
	{
		LNRKhoa(treekhoa, y);
	}

}
///
void DanhSachMonHoc(Tree_DSMH& t, MonHoc a[], int& n)
{
	if (t != NULL)
	{
		strcpy_s(a[n].maMonHoc, t->data.maMonHoc);
		strcpy_s(a[n].tenMonHoc, t->data.tenMonHoc);
		strcpy_s(a[n++].maKhoa, t->data.maKhoa);
		DanhSachMonHoc(t->left, a, n);
		DanhSachMonHoc(t->right, a, n);
	}
}
void LNRMonHoc(Tree_DSMH& l, int& y)
{
	if (l != NULL) {


		LNRMonHoc(l->left, y);
		Vedau_doc(3, 28, y);
		gotoxy(28, y + 2);
		cout << (char)195;
		Vedau(21, 196);
		cout << (char)197;
		Vedau(30, 196);
		cout << (char)197;
		Vedau(19, 196);
		Vedau_doc(2, 50, y);
		Vedau_doc(2, 81, y);
		Vedau_doc(2, 101, y);
		gotoxy(101, y + 2);
		cout << (char)180;
		//
		gotoxy(29, 1 + y);
		cout << l->data.maMonHoc;
		gotoxy(51, 1 + y);
		cout << l->data.tenMonHoc;
		gotoxy(82, 1 + y);
		cout << l->data.maKhoa;
		//
		/*gotoxy(104, 1 + y);
		cout << l->data.id;*/
		//
		y = y + 3;
		LNRMonHoc(l->right, y);
	}
}
//
int LNR_MH_Khoa(Tree_DSMH& l,Tree_DSKhoa& b,string& makhoa, MH_Khoa mhkhoa[],int& a )
{
	if (l != NULL) {
		Khoa khoa;
		strcpy_s(khoa.maKhoa, makhoa.c_str());
		LNR_MH_Khoa(l->left,b, makhoa,mhkhoa,a);
		if (strcmp(l->data.maKhoa, khoa.maKhoa) == 0) {
			mhkhoa[SearchKhoa(b, khoa)->data.id].maMonHoc[a] = convertCharToString(l->data.maMonHoc);
			a++;
		}
		LNR_MH_Khoa(l->right, b, makhoa,mhkhoa,a);
	}
	return a;
}
////
void HienThiDSMonHoc(Tree_DSMH& treemonhoc, int luachon) {
	MonHoc monhoc[100];
	int n = 0;
	int y = 18;
	gotoxy(29, 16);
	cout << "MA MON HOC";
	gotoxy(51, 16);
	cout << "TEN MON HOC";
	gotoxy(82, 16);
	cout << "MA KHOA";
	GiaoDienKhung();
	DanhSachMonHoc(treemonhoc, monhoc, n);
	if (luachon == 1) {
		SapXepTheoTenMH(monhoc, n);
		for (int i = 0; i < n; i++)
		{
			Vedau_doc(3, 28, y);
			gotoxy(28, y + 2);
			cout << (char)195;
			Vedau(21, 196);
			cout << (char)197;
			Vedau(30, 196);
			cout << (char)197;
			Vedau(19, 196);
			Vedau_doc(2, 50, y);
			Vedau_doc(2, 81, y);
			Vedau_doc(2, 101, y);
			gotoxy(101, y + 2);
			cout << (char)180;
			gotoxy(29, y + 1);
			cout << monhoc[i].maMonHoc;
			gotoxy(51, y + 1);
			cout << monhoc[i].tenMonHoc;
			gotoxy(82, y + 1);
			cout << monhoc[i].maKhoa;
			y = y + 3;
		}
	}
	else if (luachon == 2)
	{
		LNRMonHoc(treemonhoc, y);
	}

}

///

void Delxy(int x, int y, int end) {
	for (int i = y; i < end; i++) {
		DelRow(x, 150, i);
	}
}
/// 
NodeSV* getNodeSV(SinhVien info)
{
	NodeSV* p = new NodeSV;
	p->data = info;
	p->next = NULL;
	return p;
}
///
NodeCTr* getNode(ChuongTrinh info)
{
	NodeCTr* p = new NodeCTr;
	p->data = info;
	p->next = NULL;
	return p;
}
NodeLHoc* getNodeLH(LopHoc info)
{
	NodeLHoc* p = new NodeLHoc;
	p->data = info;
	p->next = NULL;
	return p;
}

NodeKQ* getNodeKQ(KetQua info)
{
	NodeKQ* p = new NodeKQ;
	p->data = info;
	p->next = NULL;
	return p;
}
//
NodeGD* getNodeGD(GiangDay info)
{
	NodeGD* p = new NodeGD;
	p->data = info;
	p->next = NULL;
	return p;
}
//
boolean CheckMaCtr(NodeCTr*& l, ChuongTrinh x)
{
	if (l == NULL) {
		return true;
	}
	else {
		for (NodeCTr* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maCTr, x.maCTr) == 0)
			{
				return false;
			}
		}
	}
	return true;
}
NodeCTr* InfoMaCtr(NodeCTr*& l, ChuongTrinh x)
{
	if (l == NULL) {
		return NULL;
	}
	else {
		for (NodeCTr* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maCTr, x.maCTr) == 0)
			{
				return i;
			}
		}
	}
	return NULL;
}

//
int count(string masinhvien[], int n)
{
	int result = 0; //kết quả (số lượng các phần tử khác nhau)
	for (int i = 0; i < n; i++)
	{
		// kiểm tra xem từ 0->i-1 phần tử a[i] đã xuất hiện chưa, nếu chưa thì tăng kết quả lên 1
		bool isOccur = false;  // giả sử là chưa xuất hiện
		for (int j = 0; j < i; j++)
			if (masinhvien[i] == masinhvien[j])
			{
				isOccur = true; // đã xuất hiện rồi
				break;
			}
		if (!isOccur) result++; // tăng kết quả lên 1
	}
	return result;
}
//

int SVtheoMH(NodeKQ*& l, Tree_DSMH& b, string& mamh, SVTheoMon svtheomon[])
{
	MonHoc monhoc;
	int SLSV = 0;
	if (l == NULL) {
		return SLSV;
	}
	else {
		int a = 0;
		strcpy_s(monhoc.maMonHoc, mamh.c_str());
		DSMonHoc* d = SearchMonHoc(b, monhoc);
		int c = d->data.id;
		for (NodeKQ* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maMonHoc, monhoc.maMonHoc) == 0)
			{
				svtheomon[c].masinhvien[a] = convertCharToString(i->data.maSV);
				a++;
			}
		}
		SLSV = count(svtheomon[c].masinhvien, a);
	}
	return SLSV;
}
//
boolean CheckMasv(NodeSV*& l, SinhVien x)
{
	if (l == NULL) {
		return true;
	}
	else {
		for (NodeSV* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maSV, x.maSV) == 0)
			{
				return false;
			}
		}
	}
	return true;
}
boolean CheckMaLH(NodeLHoc*& l, LopHoc x)
{
	if (l == NULL) {
		return true;
	}
	else {
		for (NodeLHoc* i = l; i != NULL; i = i->next)
		{
			if (strcmp(i->data.maLop, x.maLop) == 0)
			{
				return false;
			}

		}
	}
	return true;
}
//
boolean CheckNamHoc(NodeGD*& l, GiangDay x)
{
	if (l == NULL) {
		return true;
	}
	else {
		for (NodeGD* i = l; i != NULL; i = i->next)
		{
			if (i->data.namHoc == x.namHoc)
			{
				return false;
			}

		}
	}
	return true;
}
int index_MHMax(MH_Nam mh[], int& n, NodeKQ*& l, Tree_DSMH& b, int& x, SVTheoMon svtheomon[]) {
	int a = 0;
	int max = SVtheoMH(l, b, mh[x].maMonHoc[0], svtheomon);
	for (int i = 0; i < n; i++) {
		if (max < SVtheoMH(l, b, mh[x].maMonHoc[i], svtheomon)) {
			max = SVtheoMH(l, b, mh[x].maMonHoc[i], svtheomon);
			a = i;
		}
		return a;
	}

}
//
int DSMH_Nam(NodeGD*& l, GiangDay& x, MH_Nam mhh[])
{

	int a = 0;
	if (l == NULL) {
		return a;
	}
	else {
		for (NodeGD* i = l; i != NULL; i = i->next)
		{
			if (i->data.namHoc == x.namHoc)
			{
				mhh[x.namHoc - 2020].maMonHoc[a] = convertCharToString(i->data.maMonHoc);
				a++;
			}
		}

	}
	return a;
}

void Xoa(string a[], int& n, int vitrixoa)
{
	for (int i = vitrixoa + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	n--; // số lượng phần tử mảng giảm
}

int DSMH_N_RG(MH_Nam mhh[],int& a, int& namhoc) {
	for (int i = 0; i < a-1; i++) {
		for (int j = i + 1; j < a; j++) {
			if (mhh[namhoc-2020].maMonHoc[i] == mhh[namhoc - 2020].maMonHoc[j]) {
				Xoa(mhh[namhoc - 2020].maMonHoc, a, j);
				i--;
			}
			a--;
		}
	}
	return a;
}
//

//
boolean Checklanthi(NodeKQ*& l, KetQua x)
{
	if (l == NULL) {
		return true;
	}
	else {
		for (NodeKQ* i = l; i != NULL; i = i->next)
		{
			if (i->data.lanThi == x.lanThi && strcmp(i->data.maMonHoc, x.maMonHoc) == 0 && strcmp(i->data.maSV, x.maSV) == 0)
			{
				return false;
			}

		}
	}
	return true;
}
//

boolean checkgioitinh(string& gioitinh) {
	if (gioitinh == "nam" || gioitinh == "Nam" || gioitinh == "NAM") {
		return true;
	}
	else if (gioitinh == "nu" || gioitinh == "NU" || gioitinh == "Nu") {
		return false;
	}
}
//
void GhiFile_LNRKhoa(ofstream& file, Tree_DSKhoa& root) {
	if (root != NULL) {
		GhiFile_LNRKhoa(file, root->left);
		file << root->data.maKhoa << endl
			<< root->data.tenKhoa << endl
			<< root->data.namThanhLap << endl;
		GhiFile_LNRKhoa(file, root->right);
	}
}
void GhiFileKhoa(Tree_DSKhoa& root) {
	ofstream outfile;
	outfile.open("DSKhoa.txt", ios::out);
	GhiFile_LNRKhoa(outfile, root);
	outfile.close();
}
void GhiFile_LNRKh(ofstream& file, Tree_DSKhoaHoc& root) {
	if (root != NULL) {
		GhiFile_LNRKh(file, root->left);
		file << root->data.maKhoaHoc << endl
			<< root->data.namBD << endl
			<< root->data.namKT << endl;
		GhiFile_LNRKh(file, root->right);
	}
}
void GhiFileKh(Tree_DSKhoaHoc& root) {
	ofstream outfile;
	outfile.open("DSKhoaHoc.txt", ios::out);
	GhiFile_LNRKh(outfile, root);
	outfile.close();
}
void GhiFile_LNRMH(ofstream& file, Tree_DSMH& root) {
	if (root != NULL) {
		GhiFile_LNRMH(file, root->left);
		file << root->data.maMonHoc << endl
			<< root->data.tenMonHoc << endl
			<< root->data.maKhoa << endl;
		GhiFile_LNRMH(file, root->right);
	}
}
void GhiFileMH(Tree_DSMH& root) {
	ofstream outfile;
	outfile.open("DSMonHoc.txt", ios::out);
	GhiFile_LNRMH(outfile, root);
	outfile.close();
}
//
void DocFilekhoa(Tree_DSKhoa& root) {
	ifstream infile;
	string data;
	infile.open("DSKhoa.txt", ios::in);
	if (!infile) {
		return;
	}
	while (infile.good()) {
		Khoa khoa;
		getline(infile, data);
		if (data.size() == 0) {
			break;//co file nhung ko co du lieu
		}
		strcpy_s(khoa.maKhoa, data.c_str());
		getline(infile, data);
		strcpy_s(khoa.tenKhoa, data.c_str());
		getline(infile, data);
		khoa.namThanhLap = atoi(data.c_str());


		AddNodeKhoa(root, khoa);
	}
}
void DocFilekh(Tree_DSKhoaHoc& root) {
	ifstream infile;
	string data;
	infile.open("DSKhoaHoc.txt", ios::in);
	if (!infile) {
		return;
	}
	while (infile.good()) {
		KhoaHoc khoa;
		getline(infile, data);
		if (data.size() == 0) {
			break;//co file nhung ko co du lieu
		}
		strcpy_s(khoa.maKhoaHoc, data.c_str());
		getline(infile, data);
		khoa.namBD = atoi(data.c_str());
		getline(infile, data);
		khoa.namKT = atoi(data.c_str());
		AddNodeKhoaHoc(root, khoa);
	}
}
void DocFileMH(Tree_DSMH& root) {
	ifstream infile;
	string data;
	infile.open("DSMonHoc.txt", ios::in);
	if (!infile) {
		return;
	}
	while (infile.good()) {
		MonHoc mh;
		getline(infile, data);
		if (data.size() == 0) {
			break;//co file nhung ko co du lieu
		}
		strcpy_s(mh.maMonHoc, data.c_str());
		getline(infile, data);
		strcpy_s(mh.tenMonHoc, data.c_str());
		getline(infile, data);
		strcpy_s(mh.maKhoa, data.c_str());
		AddNodeMonHoc(root, mh);
	}
}
//
int idlh(NodeLHoc*& l, LopHoc& x)
{
	int a = 1;
	if (l == NULL) {
		return a;
	}
	else {
		for (NodeLHoc* i = l; i != NULL; i = i->next)
		{
			if (strcmp(l->data.maKhoaHoc, x.maKhoaHoc) == 0 && strcmp(l->data.maKhoa, x.maKhoa) == 0 && strcmp(l->data.maCTr, x.maCTr) == 0)
			{
				a++;
			}
		}
		return a;
	}
}
void SuaCtr(NodeCTr*& l, ChuongTrinh x)
{

	for (NodeCTr* i = l; i != NULL; i = i->next)
	{
		if (strcmp(l->data.maCTr, x.maCTr) == 0)
		{
			strcpy_s(i->data.maCTr, x.maCTr);
			strcpy_s(i->data.tenCTr, x.tenCTr);
		}

	}
}

NodeCTr* SearchNodeCT(NodeCTr*& list, ChuongTrinh d)
{
	NodeCTr* pTmp = new NodeCTr;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->data.maCTr, d.maCTr) == 0)
			break;
		pTmp = pTmp->next;
	}
	return pTmp;
}
void SapXepTheoMa(NodeCTr*& list)
{
	NodeCTr* tmp = new NodeCTr;
	for (NodeCTr* pTmp = list; pTmp != NULL; pTmp = pTmp->next)
	{
		for (NodeCTr* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (strcmp(pTmp->data.maCTr, pTmp2->data.maCTr) > 0)
			{
				tmp->data = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp->data;
			}
		}
	}
}
void SapXepTheoTen(NodeCTr*& list)
{
	NodeCTr* tmp = new NodeCTr;
	for (NodeCTr* pTmp = list; pTmp != NULL; pTmp = pTmp->next)
	{
		for (NodeCTr* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (strcmp(pTmp->data.tenCTr, pTmp2->data.tenCTr) > 0)
			{
				tmp->data = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp->data;
			}
		}
	}
}
void SapXepTheoMaLH(NodeLHoc*& list)
{
	NodeLHoc* tmp = new NodeLHoc;
	for (NodeLHoc* pTmp = list; pTmp != NULL; pTmp = pTmp->next)
	{
		for (NodeLHoc* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (strcmp(pTmp->data.maLop, pTmp2->data.maLop) > 0)
			{
				tmp->data = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp->data;
			}
		}
	}
}
void SapXepTheoMaSV(NodeSV*& list)
{
	NodeSV* tmp = new NodeSV;
	for (NodeSV* pTmp = list; pTmp != NULL; pTmp = pTmp->next)
	{
		for (NodeSV* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (strcmp(pTmp->data.maSV, pTmp2->data.maSV) > 0)
			{
				tmp->data = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp->data;
			}
		}
	}
}
void AddCTR(NodeCTr*& l, NodeCTr* p)
{
	if (l == NULL) {
		l = p;
	}
	else {
		for (NodeCTr* b = l; b != NULL; b = b->next) {
			if (b->next == NULL) {
				b->next = p;
				break;
			}
		}
	}
}
void AddSV(NodeSV*& l, NodeSV* p)
{
	if (l == NULL) {
		l = p;
	}
	else {
		for (NodeSV* b = l; b != NULL; b = b->next) {
			if (b->next == NULL) {
				b->next = p;
				break;
			}
		}
	}
}
void AddLH(NodeLHoc*& l, NodeLHoc* p)
{
	if (l == NULL) {
		l = p;
	}
	else {
		for (NodeLHoc* b = l; b != NULL; b = b->next) {
			if (b->next == NULL) {
				b->next = p;
				break;
			}
		}
	}
}
//
void AddKQ(NodeKQ*& l, NodeKQ* p)
{
	if (l == NULL) {
		l = p;
	}
	else {
		for (NodeKQ* b = l; b != NULL; b = b->next) {
			if (b->next == NULL) {
				b->next = p;
				break;
			}
		}
	}
}
//
void AddGD(NodeGD*& l, NodeGD* p)
{
	if (l == NULL) {
		l = p;
	}
	else {
		for (NodeGD* b = l; b != NULL; b = b->next) {
			if (b->next == NULL) {
				b->next = p;
				break;
			}
		}
	}
}
//
void HienThiDSCT(NodeCTr*& l, int luachon) {

	int n = 0;
	int y = 18;
	gotoxy(29, 16);
	cout << "Ma Chuong Trinh";
	gotoxy(51, 16);
	cout << "Ten Chuong Trinh";

	GiaoDienKhung1();

	if (luachon == 1) {
		SapXepTheoMa(l);
		for (NodeCTr* b = l; b != NULL; b = b->next)
		{
			Vedau_doc(3, 28, y);
			gotoxy(28, y + 2);
			cout << (char)195;
			Vedau(21, 196);
			cout << (char)197;
			Vedau(30, 196);
			cout << (char)180;
			Vedau_doc(2, 50, y);
			Vedau_doc(2, 81, y);

			gotoxy(29, y + 1);
			cout << b->data.maCTr;
			gotoxy(51, y + 1);
			cout << b->data.tenCTr;
			y = y + 3;
		}
	}
	if (luachon == 2) {
		SapXepTheoTen(l);
		for (NodeCTr* b = l; b != NULL; b = b->next)
		{
			Vedau_doc(3, 28, y);
			gotoxy(28, y + 2);
			cout << (char)195;
			Vedau(21, 196);
			cout << (char)197;
			Vedau(30, 196);
			cout << (char)180;
			Vedau_doc(2, 50, y);
			Vedau_doc(2, 81, y);

			gotoxy(29, y + 1);
			cout << b->data.maCTr;
			gotoxy(51, y + 1);
			cout << b->data.tenCTr;
			y = y + 3;
		}
	}
}
void GiaoDienKhung2() {
	gotoxy(28, 14);
	cout << (char)218;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)191;
	Vedau_doc(2, 28, 15);
	Vedau_doc(2, 47, 15);
	Vedau_doc(2, 66, 15);
	Vedau_doc(2, 85, 15);
	Vedau_doc(2, 104, 15);
	Vedau_doc(2, 123, 15);
	gotoxy(28, 17);
	cout << (char)195;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)180;
}
////
void HienThiDSSV(NodeSV*& l) {

	int n = 0;
	int y = 18;
	gotoxy(29, 16);
	cout << "Ma Sinh Vien";
	gotoxy(48, 16);
	cout << "Ho Va Ten";
	gotoxy(67, 16);
	cout << "Nam Sinh";
	gotoxy(86, 16);
	cout << "Gioi Tinh";
	gotoxy(106, 16);
	cout << "Ma Lop";

	//
	GiaoDienKhung2();
	//

	SapXepTheoMaSV(l);
	for (NodeSV* b = l; b != NULL; b = b->next)
	{
		string a = "";
		Vedau_doc(3, 28, y);
		gotoxy(28, y + 2);
		cout << (char)195;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)180;
		Vedau_doc(2, 47, y);
		Vedau_doc(2, 66, y);
		Vedau_doc(2, 85, y);
		Vedau_doc(2, 104, y);
		Vedau_doc(2, 123, y);
		gotoxy(29, y + 1);
		cout << b->data.maSV;
		gotoxy(48, y + 1);
		cout << b->data.hoTen;
		gotoxy(67, y + 1);
		cout << b->data.namSinh;
		if (b->data.gioitinh == TRUE) {
			a = "Nam";
		}
		else a = "Nu";
		gotoxy(86, y + 1);
		cout << a;
		gotoxy(106, y + 1);
		cout << b->data.maLop;
		y = y + 3;
	}

}
////
void HienThiDSLH(NodeLHoc*& l) {

	int n = 0;
	int y = 18;
	gotoxy(29, 16);
	cout << "Ma Lop";
	gotoxy(48, 16);
	cout << "Ma Khoa Hoc";
	gotoxy(67, 16);
	cout << "Ma Chuong Trinh";
	gotoxy(86, 16);
	cout << "Ma Khoa";
	gotoxy(106, 16);
	cout << "STT";

	//
	GiaoDienKhung2();
	//

	SapXepTheoMaLH(l);
	for (NodeLHoc* b = l; b != NULL; b = b->next)
	{
		Vedau_doc(3, 28, y);
		gotoxy(28, y + 2);
		cout << (char)195;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)180;
		Vedau_doc(2, 47, y);
		Vedau_doc(2, 66, y);
		Vedau_doc(2, 85, y);
		Vedau_doc(2, 104, y);
		Vedau_doc(2, 123, y);
		gotoxy(29, y + 1);
		cout << b->data.maLop;
		gotoxy(48, y + 1);
		cout << b->data.maKhoaHoc;
		gotoxy(67, y + 1);
		cout << b->data.maCTr;
		gotoxy(86, y + 1);
		cout << b->data.maKhoa;
		gotoxy(106, y + 1);
		cout << b->data.id;
		y = y + 3;
	}

}
//
void HienThiDSKQ(NodeKQ*& l) {
	int y = 18;
	gotoxy(29, 16);
	cout << "Ma Sinh Vien";
	gotoxy(48, 16);
	cout << "Ma Mon Hoc";
	gotoxy(67, 16);
	cout << "So Lan Thi";
	gotoxy(86, 16);
	cout << "Diem";

	//
	gotoxy(28, 14);
	cout << (char)218;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)191;
	Vedau_doc(2, 28, 15);
	Vedau_doc(2, 47, 15);
	Vedau_doc(2, 66, 15);
	Vedau_doc(2, 85, 15);
	Vedau_doc(2, 104, 15);

	gotoxy(28, 17);
	cout << (char)195;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)180;
	//
	for (NodeKQ* b = l; b != NULL; b = b->next)
	{
		Vedau_doc(3, 28, y);
		gotoxy(28, y + 2);
		cout << (char)195;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)180;
		Vedau_doc(2, 47, y);
		Vedau_doc(2, 66, y);
		Vedau_doc(2, 85, y);
		Vedau_doc(2, 104, y);
		gotoxy(29, y + 1);
		cout << b->data.maSV;
		gotoxy(48, y + 1);
		cout << b->data.maMonHoc;
		gotoxy(67, y + 1);
		cout << b->data.lanThi;
		gotoxy(86, y + 1);
		cout << b->data.diem;
		y = y + 3;
	}

}
//
void HienThiDSKQ_Mon(NodeKQ*& l, string& mamh,int& y) {
	//
	char Mamh[15];
	strcpy_s(Mamh,mamh.c_str());
	for (NodeKQ* b = l; b != NULL; b = b->next)
	{
		if (b->data.lanThi == 2 && strcmp(b->data.maMonHoc, Mamh) == 0) {
			Vedau_doc(3, 28, y);
			gotoxy(28, y + 2);
			cout << (char)195;
			Vedau(18, 196);
			cout << (char)197;
			Vedau(18, 196);
			cout << (char)197;
			Vedau(18, 196);
			cout << (char)197;
			Vedau(18, 196);
			cout << (char)180;
			Vedau_doc(2, 47, y);
			Vedau_doc(2, 66, y);
			Vedau_doc(2, 85, y);
			Vedau_doc(2, 104, y);
			gotoxy(29, y + 1);
			cout << b->data.maSV;
			gotoxy(48, y + 1);
			cout << b->data.maMonHoc;
			gotoxy(67, y + 1);
			cout << b->data.lanThi;
			gotoxy(86, y + 1);
			cout << b->data.diem;
			y = y + 3;
		}
	}

}
//
void HienThiDSGD(NodeGD*& l) {

	int n = 0;
	int y = 18;
	gotoxy(19, 16);
	cout << "Ma Mon Hoc";
	gotoxy(38, 16);
	cout << "Ma Khoa";
	gotoxy(57, 16);
	cout << "Ma Chuong Trinh";
	gotoxy(76, 16);
	cout << "Nam Hoc";
	gotoxy(95, 16);
	cout << "Hoc Ky";
	gotoxy(106, 16);
	cout << "Tin Chi";
	gotoxy(117, 16);
	cout << "Tiet TH";
	gotoxy(128, 16);
	cout << "Tiet LT";

	//
	gotoxy(18, 14);
	cout << (char)218;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(18, 196);
	cout << (char)194;
	Vedau(10, 196);
	cout << (char)194;
	Vedau(10, 196);
	cout << (char)194;
	Vedau(10, 196);
	cout << (char)194;
	Vedau(10, 196);
	cout << (char)191;
	Vedau_doc(2, 18, 15);
	Vedau_doc(2, 37, 15);
	Vedau_doc(2, 56, 15);
	Vedau_doc(2, 75, 15);
	Vedau_doc(2, 94, 15);
	Vedau_doc(2, 105, 15);
	Vedau_doc(2, 116, 15);
	Vedau_doc(2, 127, 15);
	Vedau_doc(2, 138, 15);

	gotoxy(18, 17);
	cout << (char)195;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(18, 196);
	cout << (char)197;
	Vedau(10, 196);
	cout << (char)197;
	Vedau(10, 196);
	cout << (char)197;
	Vedau(10, 196);
	cout << (char)197;
	Vedau(10, 196);
	cout << (char)180;
	//
	for (NodeGD* b = l; b != NULL; b = b->next)
	{
		Vedau_doc(3, 18, y);
		gotoxy(18, y + 2);
		cout << (char)195;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(18, 196);
		cout << (char)197;
		Vedau(10, 196);
		cout << (char)197;
		Vedau(10, 196);
		cout << (char)197;
		Vedau(10, 196);
		cout << (char)197;
		Vedau(10, 196);
		cout << (char)180;
		Vedau_doc(2, 37, y);
		Vedau_doc(2, 56, y);
		Vedau_doc(2, 75, y);
		Vedau_doc(2, 94, y);
		Vedau_doc(2, 105, y);
		Vedau_doc(2, 116, y);
		Vedau_doc(2, 127, y);
		Vedau_doc(2, 138, y);
		gotoxy(19, y + 1);
		cout << b->data.maMonHoc;
		gotoxy(38, y + 1);
		cout << b->data.maKhoa;
		gotoxy(57, y + 1);
		cout << b->data.maCTr;
		gotoxy(76, y + 1);
		cout << b->data.namHoc;
		gotoxy(95, y + 1);
		cout << b->data.hocKy;
		gotoxy(106, y + 1);
		cout << b->data.tinChi;
		gotoxy(117, y + 1);
		cout << b->data.tietThucHanh;
		gotoxy(128, y + 1);
		cout << b->data.tietLyThuyet;
		y = y + 3;
	}

}


///
void GhiFileCTR(NodeCTr*& ctr) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSChuongTrinh.txt", "wb")) == NULL)
	{

	}
	for (NodeCTr* p = ctr; p != NULL; p = p->next)
	{
		ChuongTrinh ct;
		strcpy_s(ct.maCTr, p->data.maCTr);
		strcpy_s(ct.tenCTr, p->data.tenCTr);
		fwrite(&ct, sizeof(ChuongTrinh), 1, f);
	}
	fclose(f);
}
void DocFileCTR(NodeCTr*& ctr) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSChuongTrinh.txt", "rb")) == NULL)
	{

	}
	ChuongTrinh ctgf;
	while (fread(&ctgf, sizeof(ChuongTrinh), 1, f) != 0)
	{
		ChuongTrinh ct;
		strcpy_s(ct.maCTr, ctgf.maCTr);
		strcpy_s(ct.tenCTr, ctgf.tenCTr);
		AddCTR(ctr, getNode(ct));
	}
	fclose(f);
}
void GhiFileSV(NodeSV*& node) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSSinhVien.txt", "wb")) == NULL)
	{

	}
	for (NodeSV* p = node; p != NULL; p = p->next)
	{
		SinhVien sv;
		strcpy_s(sv.maSV, p->data.maSV);
		strcpy_s(sv.hoTen, p->data.hoTen);
		sv.namSinh = p->data.namSinh;
		sv.gioitinh = p->data.gioitinh;
		strcpy_s(sv.maLop, p->data.maLop);
		fwrite(&sv, sizeof(SinhVien), 1, f);
	}
	fclose(f);
}
void DocFileSV(NodeSV*& node) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSSinhVien.txt", "rb")) == NULL)
	{

	}
	SinhVien svgf;
	while (fread(&svgf, sizeof(SinhVien), 1, f) != 0)
	{

		SinhVien sv;
		strcpy_s(sv.maSV, svgf.maSV);
		strcpy_s(sv.hoTen, svgf.hoTen);
		sv.namSinh = svgf.namSinh;
		sv.gioitinh = svgf.gioitinh;
		strcpy_s(sv.maLop, svgf.maLop);
		AddSV(node, getNodeSV(sv));
	}
	fclose(f);
}
void GhiFileLH(NodeLHoc*& lhoc) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSLopHoc.txt", "wb")) == NULL)
	{

	}
	for (NodeLHoc* p = lhoc; p != NULL; p = p->next)
	{
		LopHoc lh;
		strcpy_s(lh.maLop, p->data.maLop);
		strcpy_s(lh.maKhoa, p->data.maKhoa);
		strcpy_s(lh.maKhoaHoc, p->data.maKhoaHoc);
		strcpy_s(lh.maCTr, p->data.maCTr);
		lh.id = p->data.id;
		fwrite(&lh, sizeof(LopHoc), 1, f);
	}
	fclose(f);
}
void DocFileLH(NodeLHoc*& lhoc) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSLopHoc.txt", "rb")) == NULL)
	{

	}
	LopHoc lhgf;
	while (fread(&lhgf, sizeof(LopHoc), 1, f) != 0)
	{
		LopHoc lh;
		strcpy_s(lh.maLop, lhgf.maLop);
		strcpy_s(lh.maKhoa, lhgf.maKhoa);
		strcpy_s(lh.maKhoaHoc, lhgf.maKhoaHoc);
		strcpy_s(lh.maCTr, lhgf.maCTr);
		lh.id = lhgf.id;
		AddLH(lhoc, getNodeLH(lh));
	}
	fclose(f);
}
void GhiFileKQ(NodeKQ*& kqua) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSKetQua.txt", "wb")) == NULL)
	{

	}
	for (NodeKQ* p = kqua; p != NULL; p = p->next)
	{
		KetQua kq;
		kq.diem = p->data.diem;
		kq.lanThi = p->data.lanThi;
		strcpy_s(kq.maMonHoc, p->data.maMonHoc);
		strcpy_s(kq.maSV, p->data.maSV);
		fwrite(&kq, sizeof(KetQua), 1, f);
	}
	fclose(f);
}
void DocFileKQ(NodeKQ*& kqua) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSKetQua.txt", "rb")) == NULL)
	{

	}
	KetQua kqgf;
	while (fread(&kqgf, sizeof(KetQua), 1, f) != 0)
	{
		KetQua kq;
		kq.diem = kqgf.diem;
		kq.lanThi = kqgf.lanThi;
		strcpy_s(kq.maMonHoc, kqgf.maMonHoc);
		strcpy_s(kq.maSV, kqgf.maSV);
		AddKQ(kqua, getNodeKQ(kq));
	}
	fclose(f);
}
void GhiFileGD(NodeGD*& gday) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSGiangDay.txt", "wb")) == NULL)
	{

	}
	for (NodeGD* p = gday; p != NULL; p = p->next)
	{
		GiangDay gd;
		strcpy_s(gd.maMonHoc, p->data.maMonHoc);
		strcpy_s(gd.maKhoa, p->data.maKhoa);
		strcpy_s(gd.maCTr, p->data.maCTr);
		gd.hocKy = p->data.hocKy;
		gd.namHoc = p->data.namHoc;
		gd.tietLyThuyet = p->data.tietLyThuyet;
		gd.tietThucHanh = p->data.tietThucHanh;
		gd.tinChi = p->data.tinChi;
		fwrite(&gd, sizeof(GiangDay), 1, f);
	}
	fclose(f);
}
void DocFileGD(NodeGD*& gday) {
	errno_t err;
	FILE* f;
	if ((err = fopen_s(&f, "DSGiangDay.txt", "rb")) == NULL)
	{

	}
	GiangDay gdgf;
	while (fread(&gdgf, sizeof(GiangDay), 1, f) != 0)
	{
		GiangDay gd;
		strcpy_s(gd.maMonHoc, gdgf.maMonHoc);
		strcpy_s(gd.maKhoa, gdgf.maKhoa);
		strcpy_s(gd.maCTr, gdgf.maCTr);
		gd.hocKy = gdgf.hocKy;
		gd.namHoc = gdgf.namHoc;
		gd.tietLyThuyet = gdgf.tietLyThuyet;
		gd.tietThucHanh = gdgf.tietThucHanh;
		gd.tinChi = gdgf.tinChi;
		AddGD(gday, getNodeGD(gd));
	}
	fclose(f);
}
int main()
{
	int toado_y = 0;
	resizeConsole(1200, 800);
	Tree_DSKhoaHoc treekh;
	NodeSV* sv;
	sv = NULL;
	NodeKQ* kq;
	kq = NULL;
	NodeGD* gd;
	gd = NULL;
	NodeCTr* ctr;
	ctr = NULL;
	NodeLHoc* nodelh;
	nodelh = NULL;
	Init_khoahoc(treekh);
	Tree_DSKhoa treekhoa;
	Tree_DSMH treemonhoc;
	Init_monhoc(treemonhoc);
	Init_khoa(treekhoa);
	int vt = 1;
	DocFilekhoa(treekhoa);
	DocFilekh(treekh);
	DocFileMH(treemonhoc);
	DocFileCTR(ctr);
	DocFileSV(sv);
	DocFileLH(nodelh);
	DocFileKQ(kq);
	DocFileGD(gd);
	MH_Nam mhh[100];
	SVTheoMon svtheomon[100];
	MH_Khoa mhkhoa[100];

	while (true)
	{
		menu(vt);
		if (vt == 1) {
			int luachon;
			int vitri_menu1 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_khoa(vitri_menu1);

				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu1 == 1) {
						vitri_menu1 = 7;
					}
					else {
						vitri_menu1--;
						menu_khoa(vitri_menu1);
					}
					break;
				case DOWN:
					if (vitri_menu1 == 7) {
						vitri_menu1 = 1;
						menu_khoa(vitri_menu1);
					}
					else {
						vitri_menu1++;
					}
					break;
				case ENTER:
					if (vitri_menu1 == 1) {
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 3);
						Khoa khoa;
						gotoxy(41, 14);
						cout << "Nhap Ma Khoa:";
						gotoxy(41, 15);
						cout << "Nhap Ten Khoa:";
						gotoxy(41, 16);
						cout << "Nhap Nam Thanh Lap:";

						string makhoa = "";
						string tenkhoa = "";
						string namTl = "";
						bool trangthai = false;
						gotoxy(54, 14);
						Nhapmakhoa(makhoa, tenkhoa, namTl, trangthai);
						if (makhoa.length() == 0 || tenkhoa.length() == 0 || namTl.length() == 0) {
							gotoxy(41, 18);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(khoa.maKhoa, makhoa.c_str());
							strcpy_s(khoa.tenKhoa, tenkhoa.c_str());
							khoa.namThanhLap = atoi(namTl.c_str());
							if (SearchKhoa(treekhoa, khoa) == NULL) {
								AddNodeKhoa(treekhoa, khoa);
								gotoxy(48, 18);
								cout << "Nhap Thong Tin Thanh Cong";

							}
							else {
								DelRow(41, 18, 50);
								gotoxy(41, 18);
								cout << "Ma Khoa Da Ton Tai";
							}
						}
						toado_y = 19;

					}
					else if (vitri_menu1 == 2) {
						Delxy(17, 13, toado_y);
						HienThiDSKhoa(treekhoa, 3);
						toado_y = 18 + (CountNodeKhoa(treekhoa) * 3);
					}
					else if (vitri_menu1 == 3) {
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						Khoa khoa;
						//VeKhung(40, 16, 50, 2);
						gotoxy(41, 14);
						cout << "Nhap Ma Khoa:";
						string makhoa = "";
						gotoxy(54, 14);
						Nhap(makhoa);
						strcpy_s(khoa.maKhoa, makhoa.c_str());
						DSKhoa* b = SearchKhoa(treekhoa, khoa);
						if (b == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa khong ton tai";
						}
						else
						{
							VeKhung(40, 16, 50, 2);
							gotoxy(41, 17);
							cout << "Nhap Ten Khoa:";
							gotoxy(41, 18);
							cout << "Nhap Nam Thanh Lap:";
							string Tenkhoa = convertCharToString(b->data.tenKhoa);
							string NamTL;
							NamTL = to_string(b->data.namThanhLap);
							bool trangthai = false;
							gotoxy(55, 17);
							cout << Tenkhoa;
							gotoxy(60, 18);;
							cout << NamTL;
							gotoxy(55 + Tenkhoa.length(), 17);
							Suatenkhoa(Tenkhoa, NamTL, trangthai);
							gotoxy(41, 20);
							cout << "Ban co chac muon sua ma khoa " << makhoa << " khong?[y/n]:";
							gotoxy(83 + makhoa.length(), 20);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								b->data.namThanhLap = atoi(NamTL.c_str());
								strcpy_s(b->data.tenKhoa, Tenkhoa.c_str());
							}
						}
						toado_y = 21;
					}
					else if (vitri_menu1 == 4) {
						Delxy(17, 13, toado_y);
						Khoa khoa;
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap ma khoa can xoa:";
						string makhoa = "";
						gotoxy(62, 14);
						Nhap(makhoa);
						strcpy_s(khoa.maKhoa, makhoa.c_str());
						if (SearchKhoa(treekhoa, khoa) == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa khong ton tai";
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ban co chac muon xoa ma khoa " << makhoa << " khong?[y/n]:";
							gotoxy(83 + makhoa.length(), 16);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								XoaKhoa(treekhoa, khoa);
								gotoxy(41, 17);
								cout << "Da xoa khoa co ma khoa " << makhoa << " thanh cong!";
							}

						}
						toado_y = 18;
					}
					else if (vitri_menu1 == 5) {
						Delxy(17, 13, toado_y);
						Khoa khoa;
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap ma khoa can tim:";
						string makhoa = "";
						gotoxy(62, 14);
						Nhap(makhoa);
						strcpy_s(khoa.maKhoa, makhoa.c_str());
						DSKhoa* b = SearchKhoa(treekhoa, khoa);
						if (b == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa khong ton tai";
						}
						else {
							gotoxy(29, 18);
							cout << "MA KHOA";
							gotoxy(51, 18);
							cout << "TEN KHOA";
							gotoxy(82, 18);
							cout << "NAM THANH LAP";
							gotoxy(28, 16);
							cout << (char)218;
							Vedau(21, 196);
							cout << (char)194;
							Vedau(30, 196);
							cout << (char)194;
							Vedau(19, 196);
							cout << (char)191;
							Vedau_doc(2, 28, 17);
							Vedau_doc(2, 50, 17);
							Vedau_doc(2, 81, 17);
							Vedau_doc(2, 101, 17);
							gotoxy(28, 19);
							cout << (char)195;
							Vedau(21, 196);
							cout << (char)197;
							Vedau(30, 196);
							cout << (char)197;
							Vedau(19, 196);
							cout << (char)180;
							Vedau_doc(3, 28, 20);
							gotoxy(28, 22);
							cout << (char)192;
							Vedau(21, 196);
							cout << (char)193;
							Vedau(30, 196);
							cout << (char)193;
							Vedau(19, 196);
							Vedau_doc(2, 50, 20);
							Vedau_doc(2, 81, 20);
							Vedau_doc(2, 101, 20);
							gotoxy(101, 22);
							cout << (char)217;
							////
							gotoxy(29, 21);
							cout << b->data.maKhoa;
							gotoxy(51, 21);
							cout << b->data.tenKhoa;
							gotoxy(82, 21);
							cout << b->data.namThanhLap;
						}
						toado_y = 23;
					}
					else if (vitri_menu1 == 6) {
						Delxy(17, 13, toado_y);
						HienThiDSKhoa(treekhoa, 2);
						toado_y = 18 + (CountNodeKhoa(treekhoa) * 3);
					}
					else if (vitri_menu1 == 7) {
						Khoa khoa;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Ma Khoa:";
						string makhoa = "";
						gotoxy(54, 14);
						Nhap(makhoa);
						strcpy_s(khoa.maKhoa, makhoa.c_str());
						if (SearchKhoa(treekhoa, khoa)) {
							gotoxy(41, 16);
							cout << "So sinh vien cua khoa " << makhoa << " la: " << SVTheoKhoa(sv, nodelh, khoa.maKhoa);

						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ma Khoa khong Ton Tai";
						}
						toado_y = 17;
					}
					break;
				}
				if (trangthai == ESC) {
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					GhiFileKhoa(treekhoa);
					break;
				}
			}
		}
		if (vt == 2) {
			int luachon;
			int vitri_menu2 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_khoahoc(vitri_menu2);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu2 == 1) {
						vitri_menu2 = 7;
					}
					else {
						vitri_menu2--;
						menu_khoahoc(vitri_menu2);
					}
					break;
				case DOWN:
					if (vitri_menu2 == 7) {
						vitri_menu2 = 1;
						menu_khoahoc(vitri_menu2);
					}
					else {
						vitri_menu2++;
					}
					break;
				case ENTER:
					if (vitri_menu2 == 1) {
						KhoaHoc kh;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 3);
						gotoxy(41, 14);
						cout << "Nhap Ma Khoa Hoc:";
						gotoxy(41, 15);
						cout << "Nhap Nam BD:";
						gotoxy(41, 16);
						cout << "Nhap Nam KT:";

						string makhoaHoc = "";
						string namBD = "";
						string namKT = "";
						bool trangthai = false;
						gotoxy(58, 14);
						Nhapmakhoahoc(makhoaHoc, namBD, namKT, trangthai);

						if (makhoaHoc.length() == 0 || namBD.length() == 0 || namKT.length() == 0) {
							gotoxy(41, 18);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(kh.maKhoaHoc, makhoaHoc.c_str());
							kh.namBD = atoi(namBD.c_str());
							kh.namKT = atoi(namKT.c_str());
							if (SearchKhoaHoc(treekh, kh) == NULL) {
								AddNodeKhoaHoc(treekh, kh);
								gotoxy(41, 18);
								cout << "Nhap Thong Tin Thanh Cong ";
							}
							else {
								DelRow(41, 18, 50);
								gotoxy(41, 18);
								cout << "Ma Khoa Da Ton Tai";
							}
						}
						toado_y = 19;
					}
					else if (vitri_menu2 == 2)
					{
						Delxy(17, 13, toado_y);
						HienThiDSKhoaHoc(treekh, 1);
						toado_y = 18 + (CountNodeKhoaHoc(treekh) * 3);
					}
					else if (vitri_menu2 == 3) {
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						KhoaHoc kh;
						//VeKhung(40, 16, 50, 2);
						gotoxy(41, 14);
						cout << "Nhap Ma Khoa Hoc:";
						string makh = "";
						gotoxy(58, 14);
						Nhap(makh);
						strcpy_s(kh.maKhoaHoc, makh.c_str());
						DSKhoaHoc* b = SearchKhoaHoc(treekh, kh);
						if (b == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa hoc khong ton tai";
						}
						else
						{
							VeKhung(40, 16, 50, 2);
							gotoxy(41, 17);
							cout << "Nhap Nam Bat Dau:";
							gotoxy(41, 18);
							cout << "Nhap Nam Ket Thuc:";
							string NamBD;
							NamBD = to_string(b->data.namKT);
							string NamKT;
							NamKT = to_string(b->data.namKT);
							bool trangthai = false;
							gotoxy(60, 17);
							cout << NamBD;
							gotoxy(60, 18);;
							cout << NamKT;
							gotoxy(60 + NamBD.length(), 17);
							Suanambd(NamBD, NamKT, trangthai);
							gotoxy(41, 20);
							cout << "Ban co chac muon sua ma khoa " << makh << " khong?[y/n]:";
							gotoxy(83 + makh.length(), 20);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								b->data.namBD = atoi(NamBD.c_str());
								b->data.namKT = atoi(NamKT.c_str());
							}
						}
						toado_y = 21;
					}
					else if (vitri_menu2 == 4) {
						Delxy(17, 13, toado_y);
						KhoaHoc kh;
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap ma khoa can xoa:";
						string makh = "";
						gotoxy(62, 14);
						Nhap(makh);
						strcpy_s(kh.maKhoaHoc, makh.c_str());
						if (SearchKhoaHoc(treekh, kh) == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa khong ton tai";
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ban co chac muon xoa ma khoa " << makh << " khong?[y/n]:";
							gotoxy(83 + makh.length(), 16);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								XoaKhoaHoc(treekh, kh);
								gotoxy(41, 17);
								cout << "Da xoa khoa hoc co ma " << makh << " thanh cong!";
							}

						}
						toado_y = 17;
					}
					else if (vitri_menu2 == 5) {
						Delxy(17, 13, toado_y);
						KhoaHoc kh;
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap ma khoa hoc can tim:";
						string makh = "";
						gotoxy(66, 14);
						Nhap(makh);
						strcpy_s(kh.maKhoaHoc, makh.c_str());
						DSKhoaHoc* b = SearchKhoaHoc(treekh, kh);
						if (b == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa hoc khong ton tai";
						}
						else {
							gotoxy(29, 18);
							cout << "MA KHOA HOC";
							gotoxy(51, 18);
							cout << "NAM BAT DAU";
							gotoxy(82, 18);
							cout << "NAM KET THUC";
							gotoxy(28, 16);
							cout << (char)218;
							Vedau(21, 196);
							cout << (char)194;
							Vedau(30, 196);
							cout << (char)194;
							Vedau(19, 196);
							cout << (char)191;
							Vedau_doc(2, 28, 17);
							Vedau_doc(2, 50, 17);
							Vedau_doc(2, 81, 17);
							Vedau_doc(2, 101, 17);
							gotoxy(28, 19);
							cout << (char)195;
							Vedau(21, 196);
							cout << (char)197;
							Vedau(30, 196);
							cout << (char)197;
							Vedau(19, 196);
							cout << (char)180;
							Vedau_doc(3, 28, 20);
							gotoxy(28, 22);
							cout << (char)192;
							Vedau(21, 196);
							cout << (char)193;
							Vedau(30, 196);
							cout << (char)193;
							Vedau(19, 196);
							Vedau_doc(2, 50, 20);
							Vedau_doc(2, 81, 20);
							Vedau_doc(2, 101, 20);
							gotoxy(101, 22);
							cout << (char)217;
							////
							gotoxy(29, 21);
							cout << b->data.maKhoaHoc;
							gotoxy(51, 21);
							cout << b->data.namBD;
							gotoxy(82, 21);
							cout << b->data.namKT;
						}
						toado_y = 23;
					}
					else if (vitri_menu2 == 6) {
						Delxy(17, 13, toado_y);
						HienThiDSKhoaHoc(treekh, 2);
						toado_y = 18 + (CountNodeKhoaHoc(treekh) * 3);
					}

					break;
				}
				if (trangthai == ESC) {
					GhiFileKh(treekh);
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					break;
				}
			}
		}
		if (vt == 3) {

			int luachon;
			int vitri_menu3 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_sinhvien(vitri_menu3);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu3 == 1) {
						vitri_menu3 = 7;
					}
					else {
						vitri_menu3--;
						menu_sinhvien(vitri_menu3);
					}
					break;
				case DOWN:
					if (vitri_menu3 == 7) {
						vitri_menu3 = 1;
						menu_sinhvien(vitri_menu3);
					}
					else {
						vitri_menu3++;
					}
					break;
				case ENTER:
					if (vitri_menu3 == 1) {

						SinhVien sinhvien;
						LopHoc lophoc;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 5);
						gotoxy(41, 14);
						cout << "Nhap Ma Sinh Vien:";
						gotoxy(41, 15);
						cout << "Nhap Ho Ten:";;
						gotoxy(41, 16);
						cout << "Nhap Nam Sinh:";
						gotoxy(41, 17);
						cout << "Nhap Gioi Tinh:";
						gotoxy(41, 18);
						cout << "Nhap Ma Lop:";
						toado_y = 20;
						string mssv = "";
						string hoten = "";
						int namsinh = 0;
						string gioitinh = "";
						string malop = "";
						gotoxy(59, 14);
						Nhap(mssv);
						gotoxy(53, 15);
						Nhap(hoten);
						gotoxy(55, 16);
						NhapNam(namsinh);
						gotoxy(56, 17);
						Nhap(gioitinh);
						gotoxy(53, 18);
						Nhap(malop);
						if (mssv.length() == 0 || hoten.length() == 0 || hoten.length() == 0 || gioitinh.length() == 0 || malop.length() == 0) {
							gotoxy(41, 20);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(sinhvien.maSV, mssv.c_str());
							strcpy_s(sinhvien.hoTen, hoten.c_str());
							strcpy_s(sinhvien.maLop, malop.c_str());
							strcpy_s(lophoc.maLop, malop.c_str());
							sinhvien.namSinh = namsinh;
							sinhvien.gioitinh = checkgioitinh(gioitinh);
							//if (gioitinh == "nam" || gioitinh == "nu") {
							if (CheckMasv(sv, sinhvien) == true && CheckMaLH(nodelh, lophoc) == false) {
								AddSV(sv, getNodeSV(sinhvien));
								gotoxy(41, 20);
								cout << "ban da them sinh vien thanh cong";
							}
							else {
								DelRow(41, 20, 50);
								gotoxy(41, 20);
								cout << "Ma Sinh Vien Da Ton Tai Hoac Ma Lop Khong Dung";
							}
							/*}
							else {
								DelRow(41, 20, 50);
								gotoxy(41, 20);
								cout << "Gioi Tinh Nhap (nam/nu)";
							}*/
						}
						toado_y = 22;

					}
					else if (vitri_menu3 == 2) {
						Delxy(17, 13, toado_y);
						HienThiDSSV(sv);
						toado_y = 18 + (CountNodeSV(sv) * 3);
					}
					break;
				}
				if (trangthai == ESC) {
					GhiFileSV(sv);
					Delxy(17, 13, toado_y);
					DelMenuSmall();
					break;
				}
			}
		}
		if (vt == 4) {
			int luachon;
			int vitri_menu4 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_chuongtrinh(vitri_menu4);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu4 == 1) {
						vitri_menu4 = 6;
					}
					else {
						vitri_menu4--;
						menu_chuongtrinh(vitri_menu4);
					}
					break;
				case DOWN:
					if (vitri_menu4 == 6) {
						vitri_menu4 = 1;
						menu_chuongtrinh(vitri_menu4);
					}
					else {
						vitri_menu4++;
					}
					break;
				case ENTER:
					if (vitri_menu4 == 1) {
						ChuongTrinh ct;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 2);
						gotoxy(41, 14);
						cout << "Nhap Ma Chuong Trinh:";
						gotoxy(41, 15);
						cout << "Nhap Ten Chuong Trinh:";;

						string mact = "";
						string tenct = "";
						bool trangthai = false;
						gotoxy(62, 14);
						NhapMaCT(mact, tenct, trangthai);

						if (mact.length() == 0 || tenct.length() == 0) {
							gotoxy(41, 18);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(ct.maCTr, mact.c_str());
							strcpy_s(ct.tenCTr, tenct.c_str());
							if (CheckMaCtr(ctr, ct) == TRUE) {
								AddCTR(ctr, getNode(ct));
								gotoxy(41, 17);
								cout << "Nhap Thong Tin Thanh Cong ";
							}
							else {
								DelRow(41, 18, 50);
								gotoxy(41, 18);
								cout << "Ma Chuong Trinh Da Ton Tai";
							}
						}
						toado_y = 19;
					}
					else if (vitri_menu4 == 2)
					{
						Delxy(17, 13, toado_y);
						HienThiDSCT(ctr, 1);
						toado_y = 18 + (CountNodeCT(ctr) * 3);
					}
					else if (vitri_menu4 == 3)
					{
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						ChuongTrinh ct;
						//VeKhung(40, 16, 50, 2);
						gotoxy(41, 14);
						cout << "Nhap Ma Chuong Trinh:";
						string mact = "";
						gotoxy(62, 14);
						Nhap(mact);
						strcpy_s(ct.maCTr, mact.c_str());

						if (CheckMaCtr(ctr, ct) == FALSE) {
							VeKhung(40, 16, 50, 1);
							gotoxy(41, 17);
							cout << "Nhap Ten Chuong Trinh:";
							string TenCT;
							bool trangthai = false;
							cout << TenCT;
							gotoxy(63 + TenCT.length(), 17);
							Nhap(TenCT);
							strcpy_s(ct.tenCTr, TenCT.c_str());
							gotoxy(41, 20);
							cout << "Ban co chac muon sua ma chuong trinh " << mact << " khong?[y/n]:";
							gotoxy(91 + mact.length(), 20);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								SuaCtr(ctr, ct);
							}
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ma Chuong Trinh Khong Ton Tai";
						}
						toado_y = 21;
					}
					else if (vitri_menu4 == 4)
					{
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						ChuongTrinh ct;
						gotoxy(41, 14);
						cout << "Nhap Ma Chuong Trinh:";
						string mact = "";
						gotoxy(62, 14);
						Nhap(mact);
						strcpy_s(ct.maCTr, mact.c_str());
						if (CheckMaCtr(ctr, ct) == FALSE) {
							gotoxy(41, 17);
							cout << "Ban co chac muon xoa ma chuong trinh " << mact << " khong?[y/n]:";
							gotoxy(91 + mact.length(), 17);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								xoamactr(ct.maCTr, ctr);
							}
						}
						else {
							DelRow(41, 18, 50);
							gotoxy(41, 18);
							cout << "Ma Chuong Trinh Khong Ton Tai";
						}
						toado_y = 21;
					}
					else if (vitri_menu4 == 5)
					{
						Delxy(17, 13, toado_y);
						HienThiDSCT(ctr, 2);
						toado_y = 18 + (CountNodeCT(ctr) * 3);
					}
					else if (vitri_menu4 == 6) {
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						ChuongTrinh ct;
						gotoxy(41, 14);
						cout << "Nhap Ma Chuong Trinh:";
						string mact = "";
						gotoxy(62, 14);
						Nhap(mact);
						strcpy_s(ct.maCTr, mact.c_str());
						if (CheckMaCtr(ctr, ct) == FALSE) {
							Delxy(17, 13, 16);
							gotoxy(29, 16);
							cout << "Ma Chuong Trinh";
							gotoxy(51, 16);
							cout << "Ten Chuong Trinh";
							GiaoDienKhung1();
							NodeCTr* b = InfoMaCtr(ctr, ct);
							Vedau_doc(3, 28, 18);
							gotoxy(28, 20);
							cout << (char)195;
							Vedau(21, 196);
							cout << (char)197;
							Vedau(30, 196);
							cout << (char)180;
							Vedau_doc(2, 50, 18);
							Vedau_doc(2, 81, 18);
							gotoxy(29, 19);
							cout << b->data.maCTr;
							gotoxy(51, 19);
							cout << b->data.tenCTr;

						}
						else {
							DelRow(41, 18, 50);
							gotoxy(41, 18);
							cout << "Ma Chuong Trinh Khong Ton Tai";
						}
						toado_y = 21;
					}

					break;
				}

				if (trangthai == ESC) {
					GhiFileCTR(ctr);
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					break;
				}

			}
		}
		if (vt == 5) {
			int luachon;
			int vitri_menu5 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_monhoc(vitri_menu5);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu5 == 1) {
						vitri_menu5 = 7;
					}
					else {
						vitri_menu5--;
						menu_monhoc(vitri_menu5);
					}
					break;
				case DOWN:
					if (vitri_menu5 == 7) {
						vitri_menu5 = 1;
						menu_monhoc(vitri_menu5);
					}
					else {
						vitri_menu5++;
					}
					break;
				case ENTER:
					if (vitri_menu5 == 1) {
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 3);
						MonHoc monhoc;
						Khoa khoa;
						gotoxy(41, 14);
						cout << "Nhap Ma Mon Hoc:";
						gotoxy(41, 15);
						cout << "Nhap Ten Mon Hoc:";
						gotoxy(41, 16);
						cout << "Nhap Ma Khoa:";

						string mamonhoc = "";
						string tenmonhoc = "";
						string makhoa = "";
						bool trangthai = false;
						gotoxy(57, 14);
						Nhapmamonhoc(mamonhoc, tenmonhoc, makhoa, trangthai);
						if (mamonhoc.length() == 0 || tenmonhoc.length() == 0 || makhoa.length() == 0) {
							gotoxy(41, 18);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(monhoc.maMonHoc, mamonhoc.c_str());
							strcpy_s(monhoc.tenMonHoc, tenmonhoc.c_str());
							strcpy_s(monhoc.maKhoa, makhoa.c_str());
							strcpy_s(khoa.maKhoa, makhoa.c_str());
							if (SearchMonHoc(treemonhoc, monhoc) == NULL && SearchKhoa(treekhoa, khoa) != NULL) {
								AddNodeMonHoc(treemonhoc, monhoc);
								gotoxy(41, 18);
								cout << "Ban da nhap mon hoc thong tin";
							}
							else {
								DelRow(41, 18, 50);
								gotoxy(41, 18);
								cout << "Ma Mon Hoc Da Ton Tai Hoac Ma Khoa Khong Dung";
							}
						}
						toado_y = 19;

					}
					else if (vitri_menu5 == 2) {
						Delxy(17, 13, toado_y);
						HienThiDSMonHoc(treemonhoc, 2);
						toado_y = 18 + (CountNodeMonHoc(treemonhoc) * 3);
					}
					else if (vitri_menu5 == 3) {
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						MonHoc monhoc;
						//VeKhung(40, 16, 50, 2);
						gotoxy(41, 14);
						cout << "Nhap Ma Mon hoc:";
						string mamonhoc = "";
						gotoxy(57, 14);
						Nhap(mamonhoc);
						strcpy_s(monhoc.maMonHoc, mamonhoc.c_str());
						DSMonHoc* b = SearchMonHoc(treemonhoc, monhoc);
						if (b == NULL) {
							gotoxy(41, 16);
							cout << "Ma mon hoc khong ton tai";
						}
						else
						{
							VeKhung(40, 16, 50, 2);
							gotoxy(41, 17);
							cout << "Nhap Ten Mon Hoc:";
							gotoxy(41, 18);
							cout << "Nhap Ma Khoa:";
							string Tenmonhoc = convertCharToString(b->data.tenMonHoc);
							string makhoa = convertCharToString(b->data.maKhoa);
							bool trangthai = false;
							gotoxy(58, 17);
							cout << Tenmonhoc;
							gotoxy(54, 18);;
							cout << makhoa;
							gotoxy(58 + Tenmonhoc.length(), 17);
							Suatenmonhoc(Tenmonhoc, makhoa, trangthai);
							gotoxy(41, 20);
							cout << "Ban co chac muon sua ma mon hoc " << mamonhoc << " khong?[y/n]:";
							gotoxy(86 + mamonhoc.length(), 20);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								strcpy_s(b->data.tenMonHoc, Tenmonhoc.c_str());
								strcpy_s(b->data.maKhoa, makhoa.c_str());
							}
						}
						toado_y = 21;
					}
					else if (vitri_menu5 == 4) {
						Delxy(17, 13, toado_y);
						MonHoc monhoc;
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap ma mon hoc can xoa:";
						string mamonhoc = "";
						gotoxy(65, 14);
						Nhap(mamonhoc);
						strcpy_s(monhoc.maMonHoc, mamonhoc.c_str());
						if (SearchMonHoc(treemonhoc, monhoc) == NULL) {
							gotoxy(41, 16);
							cout << "Ma khoa khong ton tai";
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ban co chac muon xoa ma mon hoc " << mamonhoc << " khong?[y/n]:";
							gotoxy(86 + mamonhoc.length(), 16);
							string yesno = "";
							Nhapyesno(yesno);
							if (yesno == "y") {
								XoaMonHoc(treemonhoc, monhoc);
								gotoxy(41, 17);
								cout << "Da xoa khoa co ma mon hoc " << mamonhoc << " thanh cong!";
							}

						}
						toado_y = 17;
					}
					else if (vitri_menu5 == 5) {
						Delxy(17, 13, toado_y);
						HienThiDSMonHoc(treemonhoc, 1);
						toado_y = 18 + (CountNodeMonHoc(treemonhoc) * 3);
					}
					else if (vitri_menu5 == 6) {
						Delxy(17, 13, toado_y);
						MonHoc monhoc;
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap ma mon hoc can tim:";
						string mamonhoc = "";
						gotoxy(65, 14);
						Nhap(mamonhoc);
						strcpy_s(monhoc.maMonHoc, mamonhoc.c_str());
						DSMonHoc* b = SearchMonHoc(treemonhoc, monhoc);
						if (b == NULL) {
							gotoxy(41, 16);
							cout << "Ma mon hoc khong ton tai";
						}
						else {
							gotoxy(29, 18);
							cout << "MA MON HOC";
							gotoxy(51, 18);
							cout << "TEN MON HOC";
							gotoxy(82, 18);
							cout << "MA KHOA";
							gotoxy(28, 16);
							cout << (char)218;
							Vedau(21, 196);
							cout << (char)194;
							Vedau(30, 196);
							cout << (char)194;
							Vedau(19, 196);
							cout << (char)191;
							Vedau_doc(2, 28, 17);
							Vedau_doc(2, 50, 17);
							Vedau_doc(2, 81, 17);
							Vedau_doc(2, 101, 17);
							gotoxy(28, 19);
							cout << (char)195;
							Vedau(21, 196);
							cout << (char)197;
							Vedau(30, 196);
							cout << (char)197;
							Vedau(19, 196);
							cout << (char)180;
							Vedau_doc(3, 28, 20);
							gotoxy(28, 22);
							cout << (char)192;
							Vedau(21, 196);
							cout << (char)193;
							Vedau(30, 196);
							cout << (char)193;
							Vedau(19, 196);
							Vedau_doc(2, 50, 20);
							Vedau_doc(2, 81, 20);
							Vedau_doc(2, 101, 20);
							gotoxy(101, 22);
							cout << (char)217;
							////
							gotoxy(29, 21);
							cout << b->data.maMonHoc;
							gotoxy(51, 21);
							cout << b->data.tenMonHoc;
							gotoxy(82, 21);
							cout << b->data.maKhoa;
						}
						toado_y = 23;
					}
					else if (vitri_menu5 == 7) {
						MonHoc monhoc;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Ma Mon Hoc:";
						string mamh = "";
						gotoxy(57, 14);
						Nhap(mamh);
						strcpy_s(monhoc.maMonHoc, mamh.c_str());
						if (SearchMonHoc(treemonhoc, monhoc) != NULL) {
							gotoxy(41, 16);
							cout << "So sinh vien cua mon hoc " << mamh << " la: " << SVtheoMH(kq, treemonhoc, mamh, svtheomon);

						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ma Mon Hoc khong Ton Tai";
						}
						toado_y = 17;

					}
					break;
				}
				if (trangthai == ESC) {
					GhiFileMH(treemonhoc);
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					break;
				}
			}
		}
		if (vt == 6) {
			int luachon;
			int vitri_menu6 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_ketqua(vitri_menu6);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu6 == 1) {
						vitri_menu6 = 7;
					}
					else {
						vitri_menu6--;
						menu_ketqua(vitri_menu6);
					}
					break;
				case DOWN:
					if (vitri_menu6 == 7) {
						vitri_menu6 = 1;
						menu_ketqua(vitri_menu6);
					}
					else {
						vitri_menu6++;
					}
					break;
				case ENTER:
					if (vitri_menu6 == 1) {
						KetQua ketqua;
						SinhVien sinhvien;
						MonHoc monhoc;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 4);
						gotoxy(41, 14);
						cout << "Nhap Ma Sinh Vien:";
						gotoxy(41, 15);
						cout << "Nhap Ma Mon Hoc:";;
						gotoxy(41, 16);
						cout << "Nhap Diem:";
						gotoxy(41, 17);
						cout << "Nhap Lan Thi:";
						string mssv = "";
						string mamh = "";
						string diem = "";
						string lanthi = "";
						gotoxy(59, 14);
						Nhap(mssv);
						gotoxy(57, 15);
						Nhap(mamh);
						gotoxy(51, 16);
						Nhap(diem);
						gotoxy(54, 17);
						Nhap(lanthi);

						if (mssv.length() == 0 || mamh.length() == 0 || lanthi.length() == 0 || diem.length() == 0) {
							gotoxy(41, 19);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(ketqua.maSV, mssv.c_str());
							strcpy_s(sinhvien.maSV, mssv.c_str());
							strcpy_s(ketqua.maMonHoc, mamh.c_str());
							strcpy_s(monhoc.maMonHoc, mamh.c_str());

							ketqua.lanThi = atoi(lanthi.c_str());
							ketqua.diem = atoi(diem.c_str());
							if (CheckMasv(sv, sinhvien) == false && SearchMonHoc(treemonhoc, monhoc) != NULL) {
								if (Checklanthi(kq, ketqua) == true) {
									AddKQ(kq, getNodeKQ(ketqua));
									gotoxy(41, 20);
									cout << "Ban da them ket qua thanh cong";
								}
								else {
									gotoxy(41, 19);
									cout << "Ban da nhap trung so lan thi";
								}

							}
							else {
								DelRow(41, 19, 50);
								gotoxy(41, 19);
								cout << "Ban nhap thong tin chua chinh xac";
							}
						}
						toado_y = 21;
					}
					else if (vitri_menu6 == 2) {
						Delxy(17, 13, toado_y);
						HienThiDSKQ(kq);
						toado_y = 18 + (CountNodeKQ(kq) * 3);
					}
					else if (vitri_menu6 == 5) {
						MonHoc monhoc;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Ma Mon Hoc:";
						string mamh = "";
						gotoxy(57, 14);
						Nhap(mamh);
						strcpy_s(monhoc.maMonHoc, mamh.c_str());
						if (SearchMonHoc(treemonhoc, monhoc) != NULL) {
							int y = 18;
							Delxy(17, 13, 16);
							gotoxy(29, 16);
							cout << "Ma Sinh Vien";
							gotoxy(48, 16);
							cout << "Ma Mon Hoc";
							gotoxy(67, 16);
							cout << "So Lan Thi";
							gotoxy(86, 16);
							cout << "Diem";
							//
							gotoxy(28, 14);
							cout << (char)218;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)191;
							Vedau_doc(2, 28, 15);
							Vedau_doc(2, 47, 15);
							Vedau_doc(2, 66, 15);
							Vedau_doc(2, 85, 15);
							Vedau_doc(2, 104, 15);
							gotoxy(28, 17);
							cout << (char)195;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)180;
							HienThiDSKQ_Mon(kq, mamh,y);
							toado_y = y + (CountNodeKQ_Mon(kq, mamh) * 3);

						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ma Mon Hoc khong Ton Tai";
							toado_y = 17;
						}

					}
					else if (vitri_menu6 == 6) {
						Khoa khoa;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Ma Khoa:";
						string makhoa = "";
						gotoxy(54, 14);
						Nhap(makhoa);
						strcpy_s(khoa.maKhoa, makhoa.c_str());
						DSKhoa* b = SearchKhoa(treekhoa, khoa);
						if (SearchKhoa(treekhoa,khoa)!= NULL) {
							int a = 0;
							int c = LNR_MH_Khoa(treemonhoc, treekhoa, makhoa, mhkhoa,a);
							int y = 18;
							Delxy(17, 13, 16);
							gotoxy(29, 16);
							cout << "Ma Sinh Vien";
							gotoxy(48, 16);
							cout << "Ma Mon Hoc";
							gotoxy(67, 16);
							cout << "So Lan Thi";
							gotoxy(86, 16);
							cout << "Diem";
							//
							gotoxy(28, 14);
							cout << (char)218;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)191;
							Vedau_doc(2, 28, 15);
							Vedau_doc(2, 47, 15);
							Vedau_doc(2, 66, 15);
							Vedau_doc(2, 85, 15);
							Vedau_doc(2, 104, 15);
							gotoxy(28, 17);
							cout << (char)195;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)180;
							for (int i = 0; i < c;i++) {
								HienThiDSKQ_Mon(kq, mhkhoa[b->data.id].maMonHoc[i], y);
								y += (CountNodeKQ_Mon(kq, mhkhoa[b->data.id].maMonHoc[i]) * 3 -3);
							}
							toado_y = y;
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ma Khoa khong Ton Tai";
							toado_y = 17;
						}
					}
					else if (vitri_menu6 == 7) {
						GiangDay giangday;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Nam Hoc:";
						int Namhoc = 0;
						gotoxy(54, 14);
						NhapNamhoc_GD(Namhoc);
						giangday.namHoc = Namhoc;
						int x = Namhoc - 2020;
						if (CheckNamHoc(gd, giangday) == false) {
							int n = DSMH_Nam(gd, giangday, mhh);
							int m = DSMH_N_RG(mhh, n, Namhoc)+1;
							Delxy(17, 13, 16);
							int y = 18;
							Delxy(17, 13, 16);
							gotoxy(29, 16);
							cout << "Ma Sinh Vien";
							gotoxy(48, 16);
							cout << "Ma Mon Hoc";
							gotoxy(67, 16);
							cout << "So Lan Thi";
							gotoxy(86, 16);
							cout << "Diem";
							//
							gotoxy(28, 14);
							cout << (char)218;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)194;
							Vedau(18, 196);
							cout << (char)191;
							Vedau_doc(2, 28, 15);
							Vedau_doc(2, 47, 15);
							Vedau_doc(2, 66, 15);
							Vedau_doc(2, 85, 15);
							Vedau_doc(2, 104, 15);
							gotoxy(28, 17);
							cout << (char)195;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)197;
							Vedau(18, 196);
							cout << (char)180;
							for (int i = 0; i < m; i++) {
								HienThiDSKQ_Mon(kq, mhh[x].maMonHoc[i], y);
								y += (CountNodeKQ_Mon(kq, mhh[x].maMonHoc[i]) * 3 - 3);
							}
							toado_y = y;

						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Nam hoc khong co trong du lieu";
							toado_y = 17;
						}
					}
					break;
				}
				if (trangthai == ESC) {
					GhiFileKQ(kq);
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					break;
				}
			}
		}
		if (vt == 7) {
			int luachon;
			int vitri_menu7 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_lophoc(vitri_menu7);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu7 == 1) {
						vitri_menu7 = 7;
					}
					else {
						vitri_menu7--;
						menu_lophoc(vitri_menu7);
					}
					break;
				case DOWN:
					if (vitri_menu7 == 7) {
						vitri_menu7 = 1;
						menu_lophoc(vitri_menu7);
					}
					else {
						vitri_menu7++;
					}
					break;
				case ENTER:
					if (vitri_menu7 == 1) {
						LopHoc lh;
						ChuongTrinh chuongtrinh;
						KhoaHoc khoahoc;
						Khoa khoa;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 4);
						gotoxy(41, 14);
						cout << "Nhap Ma Lop:";
						gotoxy(41, 15);
						cout << "Nhap Ma Khoa:";;
						gotoxy(41, 16);
						cout << "Nhap Ma Khoa Hoc:";
						gotoxy(41, 17);
						cout << "Nhap Ma Chuong Trinh:";

						string malh = "";
						string mak = "";
						string makh = "";
						string mactr = "";
						bool trangthai = false;
						gotoxy(53, 14);
						Nhapmalh(malh, mak, makh, mactr, trangthai);

						if (malh.length() == 0 || mak.length() == 0 || makh.length() == 0 || mactr.length() == 0) {
							gotoxy(41, 19);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(lh.maLop, malh.c_str());
							strcpy_s(lh.maKhoa, mak.c_str());
							strcpy_s(khoa.maKhoa, mak.c_str());
							strcpy_s(lh.maKhoaHoc, makh.c_str());
							strcpy_s(khoahoc.maKhoaHoc, makh.c_str());
							strcpy_s(lh.maCTr, mactr.c_str());
							strcpy_s(chuongtrinh.maCTr, mactr.c_str());
							lh.id = idlh(nodelh, lh);

							if (CheckMaLH(nodelh, lh) == true && CheckMaCtr(ctr, chuongtrinh) == false && SearchKhoa(treekhoa, khoa) != NULL && SearchKhoaHoc(treekh, khoahoc)) {
								AddLH(nodelh, getNodeLH(lh));
								gotoxy(41, 19);
								cout << "Nhap Thong Tin Lop Hoc Thanh Cong";
							}
							else {
								DelRow(41, 19, 50);
								gotoxy(41, 19);
								cout << "Thong Tin Ban Nhap Chua Dung";
							}
						}
						toado_y = 20;
					}
					else if (vitri_menu7 == 2)
					{
						Delxy(17, 13, toado_y);
						HienThiDSLH(nodelh);
						toado_y = 18 + (CountNodeLH(nodelh) * 3);
					}
					else if (vitri_menu7 == 7) {
						LopHoc lh;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Ma Lop:";
						string malh = "";
						gotoxy(53, 14);
						Nhap(malh);
						strcpy_s(lh.maLop, malh.c_str());
						if (CheckMaLH(nodelh, lh) == false) {
							gotoxy(41, 16);
							cout << "So sinh vien cua lop " << malh << " la: " << SVTheoLop(sv, lh.maLop);
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Ma Lop khong Ton Tai";
						}
						toado_y = 17;

					}

					break;

				}
				if (trangthai == ESC) {
					GhiFileLH(nodelh);
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					break;
				}
			}
		}
		//
		if (vt == 8) {
			int luachon;
			int vitri_menu8 = 1;
			//toado_y = 10;
			//int toado = 19;
			while (true) {
				/*DelMenuSmall();*/
				gotoxy(40, 4);
				menu_gd(vitri_menu8);
				int luachon = _getch();
				TRANGTHAI trangthai = keyPress(luachon);
				switch (trangthai)
				{
				case UP:
					if (vitri_menu8 == 1) {
						vitri_menu8 = 8;
					}
					else {
						vitri_menu8--;
						menu_gd(vitri_menu8);
					}
					break;
				case DOWN:
					if (vitri_menu8 == 8) {
						vitri_menu8 = 1;
						menu_gd(vitri_menu8);
					}
					else {
						vitri_menu8++;
					}
					break;
				case ENTER:
					if (vitri_menu8 == 1) {
						GiangDay giangday;
						MonHoc monhoc;
						ChuongTrinh ct;
						Khoa khoa;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 8);
						gotoxy(41, 14);
						cout << "Nhap Ma Mon Hoc:";
						gotoxy(41, 15);
						cout << "Nhap Ma Khoa:";;
						gotoxy(41, 16);
						cout << "Nhap Ma Chuong Trinh:";
						gotoxy(41, 17);
						cout << "Nhap Hoc Ky:";
						gotoxy(41, 18);
						cout << "Nhap Nam Hoc:";
						gotoxy(41, 19);
						cout << "Nhap Tiet Thuc Hanh:";
						gotoxy(41, 20);
						cout << "Nhap Tiet Ly Thuyet:";
						gotoxy(41, 21);
						cout << "Nhap So Tin Chi:";
						string mamh = "";
						string makhoa = "";
						string mactr = "";
						string hocky = "";
						int namhoc = 0;
						string tietth = "";
						string tietlt = "";
						string sotinchi = "";
						gotoxy(57, 14);
						Nhap(mamh);
						gotoxy(54, 15);
						Nhap(makhoa);
						gotoxy(62, 16);
						Nhap(mactr);
						gotoxy(53, 17);
						Nhap(hocky);
						gotoxy(54, 18);
						NhapNamhoc_GD(namhoc);
						gotoxy(61, 19);
						Nhap(tietth);
						gotoxy(61, 20);
						Nhap(tietlt);
						gotoxy(57, 21);
						Nhap(sotinchi);
						if (mamh.length() == 0 || makhoa.length() == 0 || hocky.length() == 0 || mactr.length() == 0 || tietth.length() == 0 || tietlt.length() == 0 || sotinchi.length() == 0) {
							gotoxy(41, 23);
							cout << "Ban da nhap thieu thong tin";
						}
						else {
							strcpy_s(giangday.maMonHoc, mamh.c_str());
							strcpy_s(monhoc.maMonHoc, mamh.c_str());
							strcpy_s(giangday.maKhoa, makhoa.c_str());
							strcpy_s(khoa.maKhoa, makhoa.c_str());
							strcpy_s(giangday.maCTr, mactr.c_str());
							strcpy_s(ct.maCTr, mactr.c_str());
							giangday.namHoc = namhoc;
							giangday.hocKy = atoi(hocky.c_str());
							giangday.tietThucHanh = atoi(tietth.c_str());
							giangday.tietLyThuyet = atoi(tietlt.c_str());
							giangday.tinChi = atoi(sotinchi.c_str());
							if (SearchMonHoc(treemonhoc, monhoc) != NULL && SearchKhoa(treekhoa, khoa) != NULL && CheckMaCtr(ctr, ct) == false) {
								AddGD(gd, getNodeGD(giangday));
								gotoxy(41, 23);
								cout << "Ban Da Nhap Thong TIn Giang Day Thanh Cong";
							}
							else {
								DelRow(41, 23, 50);
								gotoxy(41, 23);
								cout << "Thong Tin ban Nhap Chua Chinh Xac";
							}
						}
						toado_y = 25;
					}
					else if (vitri_menu8 == 2) {
						Delxy(17, 13, toado_y);
						HienThiDSGD(gd);
						toado_y = 18 + (CountNodeGD(gd) * 3);
					}
					else if (vitri_menu8 == 7) {
						GiangDay giangday;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Nam Hoc:";
						int Namhoc = 0;
						gotoxy(54, 14);
						NhapNamhoc_GD(Namhoc);
						giangday.namHoc = Namhoc;
						int x = Namhoc - 2020;
						if (CheckNamHoc(gd, giangday) == false) {
							int n = DSMH_Nam(gd, giangday, mhh);
							int a = index_MHMax(mhh, n, kq, treemonhoc, x, svtheomon);
							gotoxy(41, 16);
							cout << "Mon hoc co sinh vien nhieu nhat trong nam " << Namhoc << " la mon: " << mhh[x].maMonHoc[a] << " co so sv la " << SVtheoMH(kq, treemonhoc, mhh[x].maMonHoc[a], svtheomon);

						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Nam hoc khong co trong du lieu";
						}
						toado_y = 17;

					}
					else if (vitri_menu8 == 8) {
						GiangDay giangday;
						Delxy(17, 13, toado_y);
						VeKhung(40, 13, 50, 1);
						gotoxy(41, 14);
						cout << "Nhap Nam Hoc:";
						int Namhoc = 0;
						gotoxy(54, 14);
						NhapNamhoc_GD(Namhoc);
						giangday.namHoc = Namhoc;
						if (CheckNamHoc(gd, giangday) == false) {
							gotoxy(41, 16);
							cout << "So sinh vien cua nam hoc " << Namhoc << " la: " << SVTheoNamHoc(gd, sv, nodelh, Namhoc);
						}
						else {
							DelRow(41, 16, 50);
							gotoxy(41, 16);
							cout << "Nam hoc khong Ton Tai";
						}
						toado_y = 17;
					}
					break;
				}
				if (trangthai == ESC) {
					GhiFileGD(gd);
					DelMenuSmall();
					Delxy(17, 13, toado_y);
					break;
				}
			}
		}
		//
		if (vt == 9) {
			int luachon = _getch();
			TRANGTHAI trangthai = keyPress(luachon);
			gotoxy(28, 14);
			cout << (char)218;
			Vedau(21, 196);
			cout << (char)194;
			Vedau(30, 196);
			cout << (char)194;
			Vedau(19, 196);
			cout << (char)191;
			Vedau_doc(2, 28, 15);
			Vedau_doc(2, 50, 15);
			Vedau_doc(2, 81, 15);
			Vedau_doc(2, 101, 15);
			gotoxy(28, 17);
			cout << (char)195;
			Vedau(21, 196);
			cout << (char)197;
			Vedau(30, 196);
			cout << (char)197;
			Vedau(19, 196);
			cout << (char)180;
			/////////

			gotoxy(29, 16);
			cout << "Ma Sinh Vien";
			gotoxy(51, 16);
			cout << "Ten Sinh Vien ";
			gotoxy(82, 16);
			cout << "Lop";
			//

			int y = 18;
			while (y < 23) {
				Vedau_doc(3, 28, y);
				gotoxy(28, y + 3);
				cout << (char)195;
				Vedau(21, 196);
				cout << (char)197;
				Vedau(30, 196);
				cout << (char)197;
				Vedau(19, 196);
				Vedau_doc(3, 50, y);
				Vedau_doc(3, 81, y);
				Vedau_doc(3, 101, y);
				gotoxy(101, y + 3);
				cout << (char)180;
				y += 4;
			}
			gotoxy(29, 19);
			cout << "N15DCCN120";
			gotoxy(51, 19);
			cout << "Huynh Trong Nghia";
			gotoxy(82, 19);
			cout << "D15CQMT01-N";
			gotoxy(29, 23);
			cout << "N15DCAT017";
			gotoxy(51, 23);
			cout << "Nguyen Thanh Huy";
			gotoxy(82, 23);
			cout << "D15CQAT01-N";
			toado_y = 27;
			if (trangthai == ESC) {
				Delxy(17, 13, toado_y);
				break;
			}

			//
			/*gotoxy(60, 15);
			cout << "N15DCCN120 Huynh Trong Nghia D15CQMT01-N";
			gotoxy(60, 17);
			cout << "N15DCAT017 Nguyen Thanh Huy D15CQAT01-N";*/
		}
		if (vt == 10) {
			return 0;
		}
	}
}
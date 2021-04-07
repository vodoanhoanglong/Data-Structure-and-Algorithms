#include<iostream>
#include<string>
using namespace std;
class SINHVIEN
{
	private:
		string HoTen;
		string MSSV;
		SINHVIEN *pNext;
	public:
		friend class LIST;				
};		
class LIST
{
	private:
		SINHVIEN *pHead;
		SINHVIEN *pTail;
	public:		
		void KhoiTaoDanhSach(LIST &l);
		SINHVIEN *KhoiTaoSinhVien(string HoTen, string MSSV); 
		void ThemDau(LIST &l, SINHVIEN *p);  
		void ThemCuoi(LIST &l, SINHVIEN *p);
		void ThemNode_p_VaoViTriBatKi(LIST &l, SINHVIEN *p, int vt);
		void XoaDau(LIST &l); 
		void XoaCuoi(LIST &l); 
		void XoaVSBatKy(LIST &l, string HoTen);
		void OutPut(LIST l); 
		void InPut_List(LIST &l);		
};
void LIST::KhoiTaoDanhSach(LIST &l){ 
	l.pHead = NULL;
	l.pTail = NULL; 
}
SINHVIEN* LIST::KhoiTaoSinhVien(string HoTen, string MSSV){ 
	SINHVIEN *p = new SINHVIEN;
	if (p == NULL){
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->HoTen = HoTen; 
	p->MSSV = MSSV;;
	p->pNext = NULL; 
	return p;
}
void LIST::ThemDau(LIST &l, SINHVIEN *p){ 	
	if (l.pHead == NULL){ 
	        l.pHead = l.pTail = p;
	}
	else{
		p->pNext = l.pHead; 
		l.pHead = p; 
	}
} 
void LIST::ThemCuoi(LIST &l, SINHVIEN *p){ 

	if (l.pHead == NULL){
		l.pHead = l.pTail = p; 
	}
	else{
		l.pTail->pNext = p;
		l.pTail = p; 
	}
} 
void LIST::ThemNode_p_VaoViTriBatKi(LIST &l, SINHVIEN *p, int vt)
{
    int n = 0;

	if (l.pHead == NULL || vt == 1)
	{
	
		ThemDau(l, p);
	}
	else if (vt == n + 1)
	{
		
		ThemCuoi(l, p);
	}
	else 
	{
		int dem = 0; 
		SINHVIEN *g = new SINHVIEN; 
		
		for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext)
		{
			dem++;
		
			if (dem == vt)
			{
				SINHVIEN *h = KhoiTaoSinhVien(p->HoTen, p->MSSV); 
				
				h->pNext = k; 
				g->pNext = h; 
				break;
			}
			g = k; 
		}
	}
}
void LIST::XoaDau(LIST &l){ 

	if (l.pHead == NULL) 
		return;
	SINHVIEN *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void LIST::XoaCuoi(LIST &l){ 

	if (l.pHead == NULL)
		return;
	if (l.pHead->pNext == NULL){ 
		XoaDau(l);
		return;
	}
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){ 
		if (k->pNext == l.pTail){ 
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k; 
			return;
		}
	}
}
void LIST::XoaVSBatKy(LIST &l, string HoTen){
	
	if (l.pHead == NULL) 	
		return;	
	if (l.pHead->HoTen == HoTen) 
	{
		XoaDau(l);
		return;
	}
	if (l.pTail->HoTen == HoTen) 
	{
		XoaCuoi(l);
		return;
	}
	SINHVIEN *g = new SINHVIEN; 
	
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){ 
		if (k->HoTen == HoTen){ 

			g->pNext = k->pNext; 
			delete k; 
			return;
		}
		g = k; 
	}
}
void LIST::OutPut(LIST l){ 
	for (SINHVIEN *k = l.pHead; k != NULL; k = k->pNext){ 
		cout<<"\nHo ten: "<<k->HoTen<<endl;
		cout<<"\nMSSS: "<<k->MSSV<<endl;
	}		

}

void LIST::InPut_List(LIST &l){ 
	int luachon;
	while (true){
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n\t\t1. Them vao dau danh sach";
		cout << "\n\t\t2. Them vao cuoi danh sach";
		cout << "\n\t\t3. Them vao vi tri bat ki";
		cout << "\n\t\t4. Xoa vi tri bat ki";
		cout << "\n\t\t5. Xuat danh sach";
		cout << "\n\t\t0. Ket thuc";
		cout << "\n\n\t\t =========== END ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1){
			string HoTen;
			string MSSV;
			fflush(stdin);
			cout<<"Nhap ho ten sinh vien: ";
			getline(cin, HoTen);
			cout<<"Nhap MSSV: ";
			getline(cin, MSSV);
			SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);
			ThemDau(l, p);
		}
		else if (luachon == 2){
			string HoTen;
			string MSSV;
			fflush(stdin);
			cout<<"Nhap ho ten sinh vien: ";
			getline(cin, HoTen);
			cout<<"Nhap MSSV: ";
		    getline(cin, MSSV);
			SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);
			ThemCuoi(l, p);
		}
		else if (luachon == 3){
			
            int vt;
			int n = 1;
			do
			{
				cout << "\nNhap vi tri can them: ";
				cin >> vt;
				if (vt < 1 || vt > n + 1)
				{
					cout << "\nVi tri can them phai nam trong doan[1; " << n + 1 << "]";
					system("pause");
				}
			} while (vt < 1 || vt > n + 1);
			string HoTen;
			string MSSV;
			
			fflush(stdin);
			cout<<"Nhap ho ten sinh vien: ";
			getline(cin, HoTen);
			cout<<"Nhap MSSV: ";
		    getline(cin, MSSV);
			SINHVIEN *p = KhoiTaoSinhVien(HoTen, MSSV);

			ThemNode_p_VaoViTriBatKi(l, p, vt); // CÃCH 2
			n++;
		}
		else if (luachon == 4)
		{
			string HoTen;	
			fflush(stdin);
			cout<<"Nhap ho ten sinh vien can xoa: ";
			getline(cin, HoTen);
			XoaVSBatKy(l, HoTen);	
		}

		else if (luachon == 5){
			cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
			OutPut(l);
			system("pause");
		}
		else 
		{
			break;
		}
	}
}           											     		   
int main(){
	LIST l;
	l.KhoiTaoDanhSach(l);
	l.InPut_List(l);

	system("pause");		
	return 0;
} 
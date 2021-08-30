#include <iostream>
using namespace std;
struct node
{
	int stt;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
struct queue
{
	node* pHead;
	node* pTail;
};
struct data
{
	int SoGhe;
	string name;
};
typedef struct data data;
struct node_C
{
	struct data C;
	node* pNext;
};
struct listC
{
	node_C* pHead;
	node_C* pTail;
};
node_C* KhoiTaoNODE_C(data X)
{

}
node* KhoiTaoNode(int x)
{
	node* p = new node();
	if (p == NULL)
		return NULL;
	else
	{
		p->stt = x;
		p->pNext = NULL;
		return p;
	}
}
void KhoiTaoList(list& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void Xuat(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->stt << " ";
		p = p->pNext;
	}
}
void AddTail(list& l, node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void NhapList(list& l)
{
	int n;
	cout << "\n Nhap n = : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x=i;
		node* p = KhoiTaoNode(x);
		AddTail(l, p);
	}
}
void KhoiTaoQueue(queue& B)
{
	B.pHead = B.pTail = NULL;
}
int IsEmpty(queue B)
{
	if (B.pHead == NULL)
		return 1;
	return 0;
}
void EnQueue(queue& B, node* p)
{
	if (IsEmpty(B))
	{
		B.pHead = B.pTail = p;
	}
	else
	{
		B.pTail->pNext = p;
		B.pTail = p;
	}
}
void XepHang(queue& B)
{
	int stt;
	if (IsEmpty(B))
	{
		stt = 1;
		node* p = KhoiTaoNode(stt);
		EnQueue(B, p);
	}
	else
	{
		stt = B.pTail->stt + 1;
		node* p = KhoiTaoNode(stt);
		EnQueue(B, p);
	}

}
//void MuaVe(list &l,queue &B,)
void menu(list& l, queue& B)
{
	int luachon;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t============MENU============";
		cout << "\n\t1.Lay so xep hang .";
		cout << "\n\n\t\t============END============";
		cout << "\nNhap lua chon.";
		cin >> luachon;
		if (luachon == 1)
		{
			XepHang(B);
			cout << B.pTail->stt << endl;
			system("pause");
		}
		else
			break;



	}
}

int main()
{
	list l;
	queue B;
	KhoiTaoList(l);
	NhapList(l);
	KhoiTaoQueue(B);
	menu(l, B);
}


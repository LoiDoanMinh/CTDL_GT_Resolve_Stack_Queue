#include <iostream>
using namespace std;
struct stack
{
	int A[100];
	int t;
};
void KhoiTaoStack(stack& s)
{
	s.t = -1;
}
int IsEmpty(stack s)
{
	if (s.t == -1)
		return 1;
	else
		return 0;
}
int IsFull(stack s)
{
	if (s.t >= 100)
		return 1;
	return 0;
}
int Push(stack& s, int x)
{
	if (IsFull(s))
		return 0;
	else
	{
		s.t++;
		s.A[s.t] = x;
		return 1;
	}
}
int Pop(stack& s, int& x)
{
	if (IsEmpty(s) == 1)
		return 0;
	else
	{
		x = s.A[s.t];
		s.t--;
	}
	return 1;
}
void ChuyenDoiCoSo(stack& s, int &n)
{
	while (n != 0)
	{
		Push(s,n%2);
		n = n / 2;
	}
}
void Xuat(stack& s, int& tv)
{
	while (IsEmpty(s) != 1)
	{
		Pop(s, tv);
		cout << tv;
	}
}
int main()
{
	int n, tv;
	stack s;
	KhoiTaoStack(s);
	cout << "\n\n\t\t CHUONG TRINH CHUYEN HE CO SO SO 10 SANG HE CO SO 2 !";	
	cout << "\n\tNhap so nguyen n : ";
	cin >> n;
	cout << "\nHe co so 2 cua : " << n << " la : ";
	ChuyenDoiCoSo(s, n);
	Xuat(s, tv);

}
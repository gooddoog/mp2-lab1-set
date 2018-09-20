// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_prime_numbers.cpp - Copyright (c) ������� �.�. 20.08.2000
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (19.04.2015)
//
// ������������ �������� ���� � ���������

#include <iomanip>

// #define USE_SET // ������������ ����� TSet,
                // ���������������, ����� ������������ ������� ����

#ifndef USE_SET // ������������ ����� TBitField

#include "tbitfield.h"

int main()
{
  int n, m, k, count;
    cout << endl;
  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� �������� ����" << endl;
  cout << "             ������ ����������" << endl;
  cout << "������� ������� ������� ����� �������� - ";
  cin  >> n;
  TBitField s(n + 1);
  // ���������� ���������
  for (m = 2; m <= n; m++)
    s.SetBit(m);
  // �������� �� sqrt(n) � �������� �������
  for (m = 2; m * m <= n; m++)
    // ���� m � s, �������� �������
    if (s.GetBit(m))
      for (k = 2 * m; k <= n; k += m)
        if (s.GetBit(k))
          s.ClrBit(k);
  // ���������� � s �������� - ������� �����
  cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
  cout << endl << "������ ������� �����" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.GetBit(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "� ������ " << n << " ������ " << count << " �������" << endl;
}
#else

#include "tset.h"

int main()
{
  int n, m, k, count;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ���������" << endl;
  cout << "              ������ ����������" << endl;
  cout << "������� ������� ������� ����� �������� - ";
  cin  >> n;
  TSet s(n + 1);
  // ���������� ���������
  for (m = 2; m <= n; m++)
    s.InsElem(m);
  // �������� �� sqrt(n) � �������� �������
  for (m = 2; m * m <= n; m++)
    // ���� � � s, �������� �������
    if (s.IsMember(m))
      for (k = 2 * m; k <= n; k += m)
       if (s.IsMember(k))
         s.DelElem(k);
  // ���������� � s �������� - ������� �����
  cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
  cout << endl << "������ ������� �����" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.IsMember(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "� ������ " << n << " ������ " << count << " �������" << endl;
}

#endif
//
//#include <iostream>
//#include "tset.h"
//#include <vector>
//using namespace std;
//
//int main() {
//const int size = 4;
//  TSet set(size), set1(size), expSet(size);
//  // set1 = {1, 3}
//  set.InsElem(1);
//  set.InsElem(3);
//  set1 = ~set;
//  // expSet = {0, 2}
//  expSet.InsElem(0);
//  expSet.InsElem(2);
//cout << expSet << endl << set1 << endl;
//
////  cout << expNegBf << " " << negBf << endl;
//}

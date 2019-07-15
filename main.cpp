#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;
map<int, int> m;
map<int, int>::iterator it;
vector<int> v;
vector<int> v1;

void FCFS()
{
    int n; // số tiến trình;
    cout << "Nhap so tien trinh: ";
    cin >> n;
    int a[n + 1]; // mảng lưu thời gian xuất hiện
    int b[n + 1]; // mảng lưu thời gian thực đang chạy cho đến khi chạy hết tiến trình
    int c[n + 1]; // mảng lưu thời gian tồn tại
    int element_a = 0, element_b = 0;
    int time = 0;
    int sum = 0;
    int thuchien, xuathien;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cout << "Process P" << i + 1 << ":" << endl;
        cout << "Thoi gian thuc hien: ";
        cin >> thuchien;
        cout << "Thoi gian xuat hien: ";
        cin >> xuathien;
        a[element_a] = xuathien;
        element_a++;
        p = make_pair(xuathien, thuchien);
        m.insert(p);
    }
    cout << endl;
    cout << setw(10) << "Process" << setw(20) << "Time t/hien" << setw(20) << "Time x/hien" << endl;
    for (int i = 0; i < element_a; i++)
    {
        for (it = m.begin(); it != m.end(); it++)
        {
            if (a[i] == (*it).first)
            {
                cout << setw(9) << "P" << i + 1;
                cout << setw(20) << (*it).second << setw(20) << (*it).first;
                cout << endl;
                break;
            }
        }
    }
    cout << "_________________________________________________________________________________________________" << endl;

    cout << endl;
    cout << "SO DO Grantt: " << endl;
    cout << "(0) ";

    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < element_a; i++)
        {
            if ((*it).first == a[i])
            {

                time += (*it).second;
                b[i] = time;
                cout << "|P" << i + 1 << "| (" << b[i] << ") ";
                c[i] = (*it).second + (*it).first;
                break;
            }
        }
    }

    cout << endl
         << endl
         << "Thoi gian cho cua cac tien trinh: " << endl;
    for (int i = 0; i < element_a; i++)
    {
        cout << "Thoi gian cho P" << i + 1 << ": " << b[i] - c[i] << endl;
        sum += b[i] - c[i];
    }
    cout << "Thoi gian cho trung binh: " << ((float)sum / (float)n) << endl;
}

int main()
{
    int ch;
    while (ch != 5 )
    {
        cout << endl
             << "_____________________________________________Menu_______________________________________________" << endl;
        cout << endl
             << "1.First Come First Served(FCFS)" << endl;
        cout << endl
             << "5.EXIT" << endl;
        cout << "Nhap lua chon: " << endl;
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                cout << endl
                    << "Thuc hien FCFS:" << endl;
                FCFS();
                break;
            }

            case 5:
            {
                cout << "BYE!";
                break;
            }
                default : cout << "Lua chon khong ton tai!\n";
        }
    }

    return 0;
}
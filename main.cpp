#include<iostream>
#include<map>
#include<iomanip>
#include<vector>
using namespace std;
map<int,int> m;
map<int,int> ::iterator it;
vector<int> v;
vector<int> v1;

void FCFS(){
    int n; // số tiến trình;
    cout<<"Nhap so tien trinh: "; cin>>n;
    int a[n+1]; // mảng lưu thời gian xuất hiện
    int b[n+1]; // mảng lưu thời gian thực đang chạy cho đến khi chạy hết tiến trình
    int c[n+1]; // mảng lưu thời gian tồn tại
    int element_a = 0 , element_b = 0;
    int time = 0;
    int sum = 0;
    int thuchien,xuathien;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        cout<<"Process P"<<i+1<<":"<<endl;
        cout<<"Thoi gian thuc hien: "; cin>>thuchien;
        cout<<"Thoi gian xuat hien: ";cin>>xuathien;
        a[element_a] = xuathien;
        element_a++;
        p = make_pair(xuathien,thuchien);
        m.insert(p);
    }
    cout<<endl;
    cout<<setw(10)<<"Process"<<setw(20)<<"Time t/hien"<<setw(20)<<"Time x/hien"<<endl;
    for(int i=0;i<element_a;i++){
        for(it=m.begin();it!=m.end();it++){
            if(a[i] == (*it).first){
                cout<<setw(9)<<"P"<<i+1;
                cout<<setw(20)<<(*it).second<<setw(20)<<(*it).first;
                cout<<endl;
                break;
            }
        }
    }
    cout<<"_________________________________________________________________________________________________"<<endl;
    
    cout<<endl;
    cout<<"SO DO Grantt: "<<endl;
    cout<<"(0) ";

    for(it = m.begin(); it!= m.end();it++){
        for(int i=0;i<element_a;i++){
            if((*it).first == a[i]){
               
                time += (*it).second;
                b[i] = time;
                cout<<"|P"<<i+1<<"| (" <<b[i]<<") ";
                c[i] = (*it).second + (*it).first;
                break;
            }
        }    
    }
    
    cout<<endl<<endl<<"Thoi gian cho cua cac tien trinh: "<<endl;
    for(int i=0;i<element_a;i++){
        cout<<"Thoi gian cho P"<<i+1<<": "<<b[i]-c[i]<<endl;
        sum+= b[i] - c[i];
    }
    cout<<"Thoi gian cho trung binh: "<<((float)sum/(float)n)<<endl;
}


void SJF(){
    int n; // số tiến trình;
    cout<<"Nhap so tien trinh: "; cin>>n;
    int a[n+1]; // mảng lưu thời gian xuất hiện
    int b[n+1]; // mảng lưu thời gian thực đang chạy cho đến khi chạy hết tiến trình
    int c[n+1]; // mảng lưu thời gian tồn tại
    int element_a = 0 , element_b = 0;
    int time = 0;
    int sum = 0;
    int thuchien,xuathien;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        cout<<"Process P"<<i+1<<":"<<endl;
        cout<<"Thoi gian thuc hien: "; cin>>thuchien;
        cout<<"Thoi gian xuat hien: ";cin>>xuathien;
        a[element_a] = xuathien;
        element_a++;
        p = make_pair(xuathien,thuchien);
        m.insert(p);
    }
    cout<<endl;
    cout<<setw(10)<<"Process"<<setw(20)<<"Time t/hien"<<setw(20)<<"Time x/hien"<<endl;
    for(int i=0;i<element_a;i++){
        for(it=m.begin();it!=m.end();it++){
            if(a[i] == (*it).first){
                cout<<setw(9)<<"P"<<i+1;
                cout<<setw(20)<<(*it).second<<setw(20)<<(*it).first;
                cout<<endl;
                break;
            }
        }
    }
    cout<<"_________________________________________________________________________________________________"<<endl;
    
    cout<<endl;
    cout<<"SO DO Grantt: "<<endl;
    cout<<"(0) ";

    while(!m.empty()){
        int min1=0;
        int min2=9999999;
        for( it=m.begin(); it!=m.end();it++ ){
            if((*it).first <= time && (*it).second <= min2){
                min1 = (*it).first;
                min2 = m[min1];
            }
        }

        for(int i=0;i<element_a;i++){
            if(a[i] == min1){
                time += min2;
                b[i] = time;
                cout<<"|P"<<i+1<<"| (" <<b[i]<<") ";
                c[i] = min1 + min2;
                break;
            }
        }
        
        m.erase(min1);
    
    }    
    
    cout<<endl<<endl<<"Thoi gian cho cua cac tien trinh: "<<endl;
    for(int i=0;i<element_a;i++){
        cout<<"Thoi gian cho P"<<i+1<<": "<<b[i]-c[i]<<endl;
        sum+= b[i] - c[i];
    }
    cout<<"Thoi gian cho trung binh: "<<((float)sum/(float)n)<<endl;
}

void SRT(){
    int n; // số tiến trình;
    cout<<"Nhap so tien trinh: "; cin>>n;
    int a[n+1]; // mảng lưu thời gian xuất hiện
    int b[n+1]; // mảng lưu thời gian thực đang chạy cho đến khi chạy hết tiến trình
    int c[n+1]; // mảng lưu thời gian tồn tại
    int element_a = 0 , element_b = 0;
    int time = 0;
    int sum = 0;
    int thuchien,xuathien;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        cout<<"Process P"<<i+1<<":"<<endl;
        cout<<"Thoi gian thuc hien: "; cin>>thuchien;
        cout<<"Thoi gian xuat hien: ";cin>>xuathien;
        a[element_a] = xuathien;
        b[element_a] = thuchien;
        element_a++;
        p = make_pair(xuathien,thuchien);
        m.insert(p);
    }
    cout<<endl;
    cout<<setw(10)<<"Process"<<setw(20)<<"Time t/hien"<<setw(20)<<"Time x/hien"<<endl;
    for(int i=0;i<element_a;i++){
        for(it=m.begin();it!=m.end();it++){
            if(a[i] == (*it).first){
                cout<<setw(9)<<"P"<<i+1;
                cout<<setw(20)<<(*it).second<<setw(20)<<(*it).first;
                cout<<endl;
                break;
            }
        }
    }
    cout<<"_________________________________________________________________________________________________"<<endl;
    
    cout<<endl;
    cout<<"SO DO Grantt: "<<endl<<"(";
    int total = 0,next = 0, old;
    int finish[n+1],rt[n+1],wt[n+1]; 
    for(int i=0;i<element_a;i++){
        total += b[i];
        rt[i]=b[i];
        finish[i] = 0;
        wt[i] = 0;
    }
    for(time =0 ;time < total ; time++){
        old = next;
        for(int i=0;i<n;i++){
            if(finish[i] == 0 ){
                next = i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(finish[i]!=1){
                if(rt[i] < rt[next] && a[i] <= time ){
                    next = i;
                }
            }
        }
        if(old!=next || time==0) cout<<time<<") |P"<<next+1<<"| (";
        rt[next]=rt[next]-1;
        if(rt[next]==0) finish[next]=1;
        for(int i=0;i<n;i++){
            if(i!=next && finish[i]==0 && a[i]<=time)
            wt[i]++;
        }

    }
    cout<<total<<")";
    
     
    
   // }    
    
    cout<<endl<<endl<<"Thoi gian cho cua cac tien trinh: "<<endl;
    for(int i=0;i<element_a;i++){
        cout<<"Thoi gian cho P"<<i+1<<": "<<wt[i]<<endl;
        sum+= wt[i];
    }
    cout<<"Thoi gian cho trung binh: "<<((float)sum/(float)n)<<endl;
    
}
void RR(){
        int n; // số tiến trình;
    cout<<"Nhap so tien trinh: "; cin>>n;
    int a[n+1]; // mảng lưu thời gian xuất hiện
    int b[n+1]; // mảng lưu thời gian thực đang chạy cho đến khi chạy hết tiến trình
    int c[n+1]; // mảng lưu thời gian tồn tại
    int d[n+1];
    int e[n+1];
    int element_a = 0 , element_b = 0, element_d =0;
    int time = 0;
    int sum = 0;
    int thuchien,xuathien;
    int R;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        cout<<"Process P"<<i+1<<":"<<endl;
        cout<<"Thoi gian thuc hien: "; cin>>thuchien;
        cout<<"Thoi gian xuat hien: ";cin>>xuathien;
        a[element_a] = xuathien;
        d[element_a] = thuchien;
        element_a++;
        p = make_pair(xuathien,thuchien);
        m.insert(p);
    }
    cout<<"Nhap R: "; cin>>R;
    cout<<endl;
    cout<<setw(10)<<"Process"<<setw(20)<<"Time t/hien"<<setw(20)<<"Time x/hien"<<endl;
    for(int i=0;i<element_a;i++){
        for(it=m.begin();it!=m.end();it++){
            if(a[i] == (*it).first){
                cout<<setw(9)<<"P"<<i+1;
                cout<<setw(20)<<(*it).second<<setw(20)<<(*it).first;
                cout<<endl;
                break;
            }
        }
    }
    cout<<"_________________________________________________________________________________________________"<<endl;
    cout<<"SO DO Grantt: "<<endl;
    cout<<"(0) ";
    int z = 0 ;
    while(1){
        int min1=0;
        int min2=9999999;
        int dal=0;
        for( it=m.begin(); it!=m.end();it++ ){
            if((*it).first <= time){
                v.push_back((*it).second);
                v1.push_back((*it).first);
                min1 = (*it).first;
                break;
                
            }
        }
        m.erase(min1);
        
        for(int i=0;i<element_a;i++){
            if(a[i] == v1[0]){
                if(v[0] <= R ){
                    time += v[0];
                    b[i] = time;
                    c[i] = d[i] + v1[0];
                    for( it=m.begin(); it!=m.end();it++ ){
                        if((*it).first < time){
                            v.push_back((*it).second);
                            v1.push_back((*it).first);
                            min1 = (*it).first;
                             break;
                
                        }
                    }
                    m.erase(min1);
                    v.erase(v.begin());
                    v1.erase(v1.begin());
                    
                }
                else {
                    time += R;
                    v[0] -= R;
                    for( it=m.begin(); it!=m.end();it++ ){
                        if((*it).first < time){
                            v.push_back((*it).second);
                            v1.push_back((*it).first);
                            min1 = (*it).first;
                             break;
                
                        }
                    }
                    m.erase(min1);                    
                    v.push_back(v[0]);
                    v.erase(v.begin());
                    v1.push_back(v1[0]);
                    v1.erase(v1.begin());
        
                }
                   
                
                cout<<"|P"<<i+1<<"| (" <<time<<") ";
                
                break;
            }
            
        }
        if(v.empty()) break;
        
        //m.erase(min1);
    
    } 
    cout<<endl<<endl<<"Thoi gian cho cua cac tien trinh: "<<endl;
    for(int i=0;i<element_a;i++){
        cout<<"Thoi gian cho P"<<i+1<<": "<<b[i]-c[i]<<endl;
        sum+= b[i] - c[i];
    }
    cout<<"Thoi gian cho trung binh: "<<((float)sum/(float)n)<<endl;   

}
int main(){
    int ch;
    while(ch!=5)
    {
        cout<<endl<<"_____________________________________________Menu_______________________________________________"<<endl;
        cout<<endl<<"1.First Come First Served(FCFS)\n2.Shortest Job First(SJF)\n3.Shortest Remain Time(SRT)\n4.Round Robun(RR)\n5.Thoat\n\nNhap lua chon: ";
        cin>>ch;
        switch(ch)
        {
            case 1:  cout<<endl<<"Thuc hien FCFS:"<<endl; FCFS(); break;
            case 2:  cout<<endl<<"Thuc hien SJF:"<<endl;  SJF(); break;
            case 3:  cout<<endl<<"Thuc hien SRT:"<<endl; SRT(); break;
            case 4:  cout<<endl<<"Thuc hien RR:"<<endl; RR(); break;
            case 5: cout<<"BYE!"; break;
            default: cout<<"Lua chon khong ton tai!\n";
 
        }
    }

return 0;
}
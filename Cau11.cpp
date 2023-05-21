#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
class maytinh{
private:
    float tocdo;
    int dungluongram;
    int hhd;
    public:
    void nhapmaytinh()
    {
        cout<<"Nhap vao toc do may tinh : ";cin>>tocdo;
         cout<<"Nhap vao dung luong ram may tinh : ";cin>>dungluongram;
         cout<<"Nhap vao hhd cua may tinh : ";cin>>hhd;
    }
    void xuatmaytinh()
    {
        cout<<""<<tocdo<<" "<<"          "<<dungluongram<<"         "<<hhd<<"  ";
    }
    void xoamaytinh()
    {
        tocdo=0;
        dungluongram=0;
        hhd=0;
    }
    };
class sanxuat{
private:
    string tenNSX;
    char diachi[20];
    friend class may;
    friend main();
};
class may:public maytinh{
    public:
    char nhanhieu[20];
    sanxuat NSX;
    float giathanh;
    maytinh b;
    void nhapmay()
    {
        cout<<"Nhap vao nhan hieu may : ";
        fflush(stdin);
        cin.getline(nhanhieu,20);
        cout<<"Nhap vao nha san xuat : ";getline(cin,NSX.tenNSX);
        cout<<"Nhap vao gia thanh : ";cin>>giathanh;
        b.nhapmaytinh();
        fflush(stdin);
        cout<<"Dia chi : ";cin.getline(NSX.diachi,20);
    }
    void xuatmay()
    {
        cout<<"  "<<nhanhieu<<"        "<<NSX.tenNSX<<"       "<<giathanh<<"      ";
        b.xuatmaytinh();
        cout<<"      "<<NSX.diachi<<endl;
    }
    void xuatmayintel(may a[],int n)
    {
        for(int i=0;i<n;i++)
        {
           if(a[i].NSX.tenNSX=="Intel")
           {
               a[i].xuatmay();
           }
        }
    }
};
int main()
{
    may a[100];
    cout<<"Nhap vao so may muon nhap :";
    int n;
    cin>>n;
    float tonggia;
    float giatb;
    for(int i=0;i<n;i++)
    {
        a[i].nhapmay();
    }
    cout<<"danh sach cac may tinh :"<<endl;
    cout<<"  Nhan hieu "<<" Nha san xuat  "<<"Gia thanh  "<<"toc do "<<" dung luong ram  "<<"  hhd  "<<" Dia chi "<<endl;
    for(int i=0;i<n;i++)
    {
        a[i].xuatmay();
        tonggia+=a[i].giathanh;
    }
    giatb=tonggia/n;
    cout<<"danh sach may tinh theo chieu giam dan cua gia "<<endl;
    //a[100].sapxeptheogia(a,n);
      cout<<"  Nhan hieu "<<" Nha san xuat  "<<"Gia thanh  "<<"toc do "<<" dung luong ram  "<<"  hhd  "<<" Dia chi "<<endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].giathanh<a[j].giathanh)
            {
                may tg=a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i].xuatmay();
    }
    cout<<endl<<"in ra may co nhan hieu inter :"<<endl;
    a[100].xuatmayintel(a,n);
    cout<<"gia trung binh cua moi chiec may tinh la :"<<giatb<<endl;
    //a[100].xoamayintel(a,n);
    cout<<"day da xoa cac may nhan hieu intel :"<<endl;
     for(int i=0;i<n;i++)
        {
            if(a[i].NSX.tenNSX=="Intel")
            {
                for(int j=i;j<n-1;j++)
                {
                    a[j]=a[j+1];
                }
                n--;//giam so luong phan tu
                i--;//quay lai phan tu truoc do vi da xoa phan tu i hien tai
            }
        }
    for(int i=0;i<n;i++)
    {
        a[i].xuatmay();
    }

}


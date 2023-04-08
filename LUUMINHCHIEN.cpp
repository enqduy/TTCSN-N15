#include <bits/stdc++.h>

using namespace std;
class PHIEU;
class NCC
{
    char MaNCC[50];
    char TenNCC[30];
    char DC[50];
    char SDT[13];
public:
    void nhap();
    void xuat();
};
void NCC::nhap()
{
    cout<<"Nhap ma nha cung cap : "     ;   fflush(stdin)   ;gets(MaNCC);
    cout<<"Nhap ten NCC : "             ;   fflush(stdin)   ;gets(TenNCC);
    cout<<"Nhap DC NCC : "              ;   fflush(stdin)   ;gets(DC);
    cout<<"Nhap SDT NCC : "             ;   fflush(stdin)   ;gets(SDT);
}
void NCC::xuat()
{
    cout<<"Ma nha cung cap : "<<MaNCC<<"\t"   ;   cout<<"Ten nha cung cap : "<<TenNCC<<endl;
    cout<<"Dia chi :"<<DC<<"\t"               ;   cout<<"SDT : "<<SDT<<endl;
}
class SP
{
    char MaSP[50];
    char TenSP[50];
    int SL;
    float DG;
public:
    void nhap();
    void xuat();
    friend float tong(PHIEU x);
    friend PHIEU ;
    friend void checksl(PHIEU x);
    friend void sapxep(PHIEU x);
};
void SP::nhap()
{
    cout<<"Nhap ma SP: "        ;       fflush(stdin)       ;   gets(MaSP);
    cout<<"Nhap ten SP: "       ;       fflush(stdin)       ;   gets(TenSP);
    cout<<"Nhap So Luong : "    ;       cin>>SL;
    cout<<"Nhap don gia : "     ;       cin>>DG;
}
void SP::xuat()
{
    cout<<setw(10)<<left<<MaSP<<setw(15)<<TenSP<<setw(15)<<SL<<setw(15)<<DG<<setw(15)<<SL*DG<<endl;
}
class PHIEU
{
    char MaP[30];
    int D,M,Y;
    NCC x;
    SP *y;
    int n;
public:
    void nhap();
    void xuat();
    friend float tong(PHIEU x);
    friend void checksl(PHIEU x);
    friend void sapxep(PHIEU x);
};
void PHIEU::nhap()
{
    cout<<"Nhap ma phieu : "        ;       fflush(stdin)   ;   gets(MaP);
    cout<<"Nhap ngay :" ;   cin>>D  ;   cout<<"Nhap thang : ";  cin>>M  ;   cout<<"Nhap nam : " ;  cin>>Y;
    x.nhap();
    cout<<"Nhap so luong SP n = "   ;   cin>>n;
    y = new SP[n];
    for(int i=0;i<n;i++)
        y[i].nhap();
}
void PHIEU::xuat()
{
    cout<<"Ma phieu : "<<MaP<<"\t"  ;   cout<<"Ngay lap: "<<D<<" / "<<M<<" / "<<Y<<endl;
    x.xuat();
    cout<<setw(10)<<left<<"Ma SP"<<setw(15)<<"Ten san pham"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
    for(int i=0;i<n;i++)
        y[i].xuat();
}
float tong(PHIEU x)
{
    float sum=0;
    for(int i=0;i<x.n;i++)
    {
        sum+=x.y[i].DG*x.y[i].SL;
    }
    return sum;
}
void checksl(PHIEU x)
{
    int dem=0;
    for(int i=0;i<x.n;i++)
    {
        if(x.y[i].SL<80)
            dem++;
    }
    cout<<"\nSo SP co so luong < 80 = "<<dem;
}
void sapxep(PHIEU x)
{
    for(int i=0;i<x.n;i++)
    {
        for(int j=i+1;j<x.n;j++)
        {
            if(x.y[i].DG>x.y[j].DG)
                swap(x.y[i],x.y[j]);
        }
    }
}
int main()
{
    PHIEU x;
    x.nhap();
    sapxep(x);
    cout<<"\n";
    cout<<"Dai hoc Victory"<<endl;
    cout<<setw(30)<<left<<"PHIEU NHAP VAN PHONG PHAM"<<endl;
    x.xuat();
    cout<<" TONG                    "<<tong(x)<<endl;
    cout<<setw(20)<<left<<"Hieu truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap"<<endl;
    checksl(x);
}

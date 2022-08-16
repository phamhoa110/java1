#include <iostream>
#define MAX 10
using namespace std;

int a[MAX],dd[MAX] = {0};
int n = 7;
struct Sinhvien{
    char ten[10];
    float diem;
    float tien;
};

struct List{
    int Count;
    Sinhvien e[MAX];
};
typedef struct List L;

void Hienthi(List L, int n)
{
    if(n == -1) return;
    cout<<L.e[n].ten<<"\t"<<L.e[n].diem<<"\t"<<L.e[n].tien<<endl;
    Hienthi(L,n-1);
}
void Layhs(List L, float p)
{
    int dem = 0;
    for(int i=0;i<L.Count;i++)
    {
        for(int j = i + 1; j<L.Count;j++)
        if(L.e[i].tien>L.e[j].tien) swap(L.e[i],L.e[j]);
    }
    int i = 0;
    while(p > L.e[i].tien)
    {
        dem++;
        p = p - L.e[i].tien;
    }
    cout<<"So hoc sinh nhieu nhat : "<<dem;
}
void view_config (List L, int n)
{
    for(int i=1;i<=n;i++)
        cout<<L.e[a[i]-1].ten<<" ";
    cout<<endl;
}
void next_config (int n, int i)
{
    int k = n;
    while(a[k] < a[i]) k--;
    swap(a[i],a[k]);
    int j = n;
    i++;
    while(i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
}
void config(int n, List L)
{
    for(int i=0;i<=n;i++)
        a[i] = i;
    int i;
    do{
        view_config(L,n);
        i = n-1;
        while(i>0 && a[i] > a[i+1]) i--;
        if(i>0) next_config(n,i);
    }
    while(i>0);
}
void Try(int k,List L,int n){
    for(int i=1; i <= n; i++)
        if(dd[i] == 0){
            a[k] = i;
            if(k == n)
                view_config(L,n);
            else{
                dd[i] = 1;
                Try(k+1,L,n);
                dd[i] = 0;
            }
        }
}

int main()
{
    List L;
    L.Count = 7;
    fflush(stdin);
    L.e[0].ten[0] = 'A';
    L.e[0].ten[1] = '\0';
    L.e[0].diem = 10;
    L.e[0].tien = 200000;
    fflush(stdin);
    L.e[1].ten[0] = 'B';
    L.e[1].ten[1] = '\0';
    L.e[1].diem = 9;
    L.e[1].tien = 200001;
    fflush(stdin);
    L.e[2].ten[0] = 'C';
    L.e[2].ten[1] = '\0';
    L.e[2].diem = 8;
    L.e[2].tien = 200002;
    fflush(stdin);
    L.e[3].ten[0] = 'D';
    L.e[3].ten[1] = '\0';
    L.e[3].diem = 7;
    L.e[3].tien = 200003;
    fflush(stdin);
    L.e[4].ten[0] = 'E';
    L.e[4].ten[1] = '\0';
    L.e[4].diem = 6;
    L.e[4].tien = 200004;
    fflush(stdin);
    L.e[5].ten[0] = 'F';
    L.e[5].ten[1] = '\0';
    L.e[5].diem = 5;
    L.e[5].tien = 200005;
    fflush(stdin);
    L.e[6].ten[0] = 'G';
    L.e[6].ten[1] = '\0';
    L.e[6].diem = 4;
    L.e[6].tien = 200006;
    cout<<"Ten"<<"\t"<<"Diem"<<"\t"<<"Tien"<<endl;
    Hienthi(L,L.Count-1);
    float p = 1000000;
    Layhs(L,p);
    //config(L.Count,L);
    Try(1,L,L.Count);
}

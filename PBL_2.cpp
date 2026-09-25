#include <iostream>
#include <string>

using namespace std;

struct NodeInfo;

typedef struct NodeInfo *Node;
typedef struct NodeInfo *Position;

class Shoe{
    protected:
        string Id;
        string Name;
        string Brand;
        string Target;
        int Size;
        string Color;
        string Material;
        long long Price;
        int Count;

    public:
        Shoe();
        Shoe(string id, string name, string brand, string target, int size, string color, string material, long long price, int count);
        Shoe(const Shoe &s);

        ~Shoe();

        void Add();
        void Out() const;

        friend Position FindById(Node pl, string searchId);

};

Shoe::Shoe()
    : Id(""), Name(""), Brand(""), Target(""), Size(0), Color(""), Material(""), Price(0), Count(0)
{ }

Shoe::Shoe(string id, string name, string brand, string target, int size, string color, string material, long long price, int count)
    : Id(id), Name(name), Brand(brand), Target(target), Size(size), Color(color), Material(material), Price(price), Count(count)
{ }

Shoe::Shoe(const Shoe &s)
    : Id(s.Id), Name(s.Name), Brand(s.Brand), Target(s.Target), Size(s.Size), Color(s.Color), Material(s.Material), Price(s.Price), Count(s.Count)
{ }

Shoe::~Shoe()
{ }

void Shoe::Add(){
    cout << "Nhap ma giay: ";
    getline(cin, Id);
    cout << "Nhap ten giay: ";
    getline(cin, Name);
    cout << "Nhap ten hang san xuat: ";
    getline(cin, Brand);
    cout << "Nhap doi tuong nguoi dung: ";
    getline(cin, Target);
    cout << "Nhap kich co giay: ";
    cin >> Size;
    cin.ignore();
    cout << "Nhap mau sac: ";
    getline(cin, Color);
    cout << "Nhap chat lieu giay: ";
    getline(cin, Material);
    cout << "Nhap gia ban: ";
    cin >> Price;
    cout << "Nhap so luong giay: ";
    cin >> Count;
    cin.ignore();
}

void Shoe::Out() const {
    cout << "Ma giay: " << Id << endl;
    cout << "Ten giay: " << Name << endl;
    cout << "Hang san xuat: " << Brand << endl;
    cout << "Doi tuong: " << Target << endl;
    cout << "Kich co: " << Size << endl;
    cout << "Mau sac: " << Color << endl;
    cout << "Chat lieu: " << Material << endl;
    cout << "Gia ban: " << Price << "VND" << endl;
    cout << "So luong hien tai: " << Count << endl;
}

class SportShoe : public Shoe{
    private:
        string Sport;
        string Cushion;

    public:
        SportShoe();
        SportShoe(string id, string name, string brand, string target, int size, string color, string material, long long price, int count, string sport, string cushion);
        SportShoe(const SportShoe &s);

        ~SportShoe();

        void Add();
        void Out() const;
};

SportShoe::SportShoe() 
    : Shoe(), Sport(""), Cushion("")
{ }

SportShoe::SportShoe(string id, string name, string brand, string target, int size, string color, string material, long long price, int count, string sport, string cushion) 
    : Shoe(id, name, brand, target, size, color, material, price, count), Sport(sport), Cushion(cushion)
{ }

SportShoe::SportShoe(const SportShoe &s) 
    : Shoe(s), Sport(s.Sport), Cushion(s.Cushion)
{ }

SportShoe::~SportShoe()
{ }

void SportShoe::Add(){
    Shoe::Add();

    cout << "Nhap mon the thao: ";
    getline(cin, Sport);
    cout << "Nhap loai dem: ";
    getline(cin, Cushion);
}

void SportShoe::Out() const {
    Shoe::Out();

    cout << "Mon the thao:" << Sport << endl;
    cout << "Loai dem:" << Cushion << endl;
}

class DressShoe : public Shoe{
    private:
        string Leather;
        string Style;

    public:
        DressShoe();
        DressShoe(string id, string name, string brand, string target, int size, string color, string material, long long price, int count, string leather, string style);
        DressShoe(const DressShoe &s);
        ~DressShoe();

        void Add();
        void Out() const;
};

DressShoe::DressShoe() 
    : Shoe(), Leather(""), Style("") 
{ }

DressShoe::DressShoe(string id, string name, string brand, string target, int size, string color, string material, long long price, int count, string leather, string style) 
    : Shoe(id, name, brand, target, size, color, material, price, count), Leather(leather), Style(style) 
{ }

DressShoe::DressShoe(const DressShoe &s) 
    : Shoe(s), Leather(s.Leather), Style(s.Style) 
{ }

DressShoe::~DressShoe() 
{ }

void DressShoe::Add(){
    Shoe::Add();

    cout << "Nhap loai da: ";
    getline(cin, Leather);
    cout << "Nhap kieu dang: ";
    getline(cin, Style);
}

void DressShoe::Out() const {
    Shoe::Out();

    cout << "Loai da:" << Leather << endl;
    cout << "Kieu dang:" << Style << endl;
}

struct NodeInfo{
    Shoe *Info;
    NodeInfo *Next;
    NodeInfo *Prev;
};

typedef struct NodeInfo *Node;
typedef struct NodeInfo *Position;

Node Create(){
    Node pl = new NodeInfo;

    pl->Next = NULL;
    pl->Prev = NULL;

    return pl;
}

bool Insert(Node pl, Shoe *info, Position p){
    Node newNode = new NodeInfo;

    if(newNode == NULL) return false;
    if(p == NULL)   p = pl;

    newNode->Info = info;
    newNode->Next = p->Next;
    newNode->Prev = p;
    
    if(p->Next != NULL) p->Next->Prev = newNode;
    p->Next = newNode;
    
    return true;
}

void ShowList(Node pl){
    pl = pl->Next;

    if(pl == NULL){
        cout << "Danh sach dang trong, vui long them thong tin san pham!" << endl;
        return;
    }

    int i = 1;
    while(pl != NULL){
        cout << i << ". ";
        pl->Info->Out();
        pl = pl->Next;
        i++;
    }
}

Position FindById(Node pl, string id){
    pl = pl->Next;

    if(pl == NULL)  return NULL;
    while(pl != NULL && pl->Info->Id != id) pl = pl->Next;

    return pl;
}

bool Remove(Node pl, Position p){
    if (p == NULL || p == pl)   return false;

    p->Prev->Next = p->Next;
    if (p->Next != NULL)    p->Next->Prev = p->Prev;

    delete p->Info;
    delete p;

    return true;
}

bool Update(Node pl, Shoe *info, Position p){
    if(p == NULL || p == pl) return false;
    p->Info = info;

    return true;
}

bool ClearList(Node pl){
    if (pl == NULL || pl->Next == NULL) return false;

    Position p = pl->Next;

    while (p != NULL){
        Position t = p;
        p = p->Next;
        delete t->Info;
        delete t;
    }
    pl->Next = NULL;

    return true;
}

int main(){
    cout << "====================================================================================================" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                           TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG                           ||" << endl;
    cout << "||                                    KHOA CONG NGHE THONG TIN                                    ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||------------------------------------------------------------------------------------------------||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                  PBL 2: DU AN CO SO LAP TRINH                                  ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                DE TAI: UNG DUNG QUAN LY BAN GIAY                               ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||------------------------------------------------------------------------------------------------||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                      GIANG VIEN HUONG DAN:                                     ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                     ThS. Nguyen Van Nguyen                                     ||" << endl;
    cout << "||                                      TS. Nguyen Van Hieu                                       ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                      SINH VIEN THUC HIEN:                                      ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                 Le Nguyen Hoang Viet       Lop: 25T_DT2         MSSV: 102250102                ||" << endl;
    cout << "||                 Nguyen Minh Tri            Lop: 25T_KHDL        MSSV: 102250375                ||" << endl;
    cout << "====================================================================================================" << endl;

    system("pause");
    return 0;
}
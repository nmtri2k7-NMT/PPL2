#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct NodeShoe;

typedef struct NodeShoe *Node;
typedef struct NodeShoe *Position;

class Shoe{
    protected:
        string Id;
        string Name;
        string Brand;
        int Size;
        string Color;
        long long Price;
        int Count;

    public:
        Shoe();
        Shoe(string id, string name, string brand, int size, string color, long long price, int count);
        Shoe(const Shoe &s);

        virtual ~Shoe();

        virtual void Add();
        virtual void Out() const;

        string GetId() const;
        string GetName() const;
        long long GetPrice() const;
        int virtual GetType();
        int GetCount() const;

        void SetPrice(long long price);
        void SetCount(int count);

        bool operator <= (const Shoe &s);
        bool operator >= (const Shoe &s);
};

Shoe::Shoe()
    : Id(""), Name(""), Brand(""), Size(0), Color(""), Price(0), Count(0)
{ }

Shoe::Shoe(string id, string name, string brand, int size, string color, long long price, int count)
    : Id(id), Name(name), Brand(brand), Size(size), Color(color), Price(price), Count(count)
{ }

Shoe::Shoe(const Shoe &s)
    : Id(s.Id), Name(s.Name), Brand(s.Brand), Size(s.Size), Color(s.Color), Price(s.Price), Count(s.Count)
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
    cout << "Nhap kich co giay: ";
    cin >> Size;
    cin.ignore();
    cout << "Nhap mau sac: ";
    getline(cin, Color);
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
    cout << "Kich co: " << Size << endl;
    cout << "Mau sac: " << Color << endl;
    cout << "Gia ban: " << Price << "VND" << endl;
    cout << "So luong hien tai: " << Count << endl;
    cout << "--------------------------------------------------" << endl;
}

string Shoe::GetId() const {
    return Id;
}

string Shoe::GetName() const {
    return Name;
}

long long Shoe::GetPrice() const {
    return Price;
}

void Shoe::SetPrice(long long price){
    Price = price;
}

void Shoe::SetCount(int count){
    Count = count;
}

int Shoe::GetType(){
    return 0;
}

int Shoe::GetCount() const {
    return Count;
}

bool Shoe::operator <= (const Shoe &s){
    return this->Price <= s.Price;
}

bool Shoe::operator >= (const Shoe &s){
    return this->Price >= s.Price;
}

class SportShoe : public Shoe{
    private:
        string Sport;
        string Cushion;

    public:
        SportShoe();
        SportShoe(string id, string name, string brand, int size, string color, long long price, int count, string sport, string cushion);
        SportShoe(const SportShoe &s);

        ~SportShoe();

        void Add();
        void Out() const;

        int GetType();
};

SportShoe::SportShoe() 
    : Shoe(), Sport(""), Cushion("")
{ }

SportShoe::SportShoe(string id, string name, string brand, int size, string color, long long price, int count, string sport, string cushion) 
    : Shoe(id, name, brand, size, color, price, count), Sport(sport), Cushion(cushion)
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

    cout << "Mon the thao: " << Sport << endl;
    cout << "Loai dem: " << Cushion << endl;
}

int SportShoe::GetType(){
    return 1;
}

class DressShoe : public Shoe{
    private:
        string Leather;
        string Style;

    public:
        DressShoe();
        DressShoe(string id, string name, string brand, int size, string color, long long price, int count, string leather, string style);
        DressShoe(const DressShoe &s);
        ~DressShoe();

        void Add();
        void Out() const;
        int GetType();
};

DressShoe::DressShoe() 
    : Shoe(), Leather(""), Style("") 
{ }

DressShoe::DressShoe(string id, string name, string brand, int size, string color, long long price, int count, string leather, string style) 
    : Shoe(id, name, brand, size, color, price, count), Leather(leather), Style(style) 
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

    cout << "Loai da: " << Leather << endl;
    cout << "Kieu dang: " << Style << endl;
}

int DressShoe::GetType(){
    return 2;
}

struct NodeShoe{
    Shoe *Info;
    NodeShoe *Next;
    NodeShoe *Prev;
};

Node Create(){
    Node pl = new NodeShoe;

    pl->Info = NULL;
    pl->Next = NULL;
    pl->Prev = NULL;

    return pl;
}

bool Insert(Node pl, Shoe *info, Position p){
    Node newNode = new NodeShoe;

    if(newNode == NULL)    return false;
    if(p == NULL)    p = pl;

    newNode->Info = info;
    newNode->Next = p->Next;
    newNode->Prev = p;
    
    if(p->Next != NULL)    p->Next->Prev = newNode;
    p->Next = newNode;
    
    return true;
}

Position FindById(Node pl, string id){
    pl = pl->Next;

    if(pl == NULL)    return NULL;
    while(pl != NULL && pl->Info->GetId() != id)    pl = pl->Next;

    return pl;
}

void FindByName(Node pl, string name){
    pl = pl->Next;

    if(pl == NULL){
        cout << "Danh sach dang trong, vui long them thong tin san pham!" << endl;
        return;
    }

    int count = 0;
    while(pl != NULL){
        if(pl->Info->GetName() == name){
            pl->Info->Out();
            count++;
        }

        pl = pl->Next;
    }

    if(count == 0){
        cout << "Khong tim thay san pham co ten " << name << "!" << endl;
    }
}

bool Remove(Node pl, Position p){
    if(p == NULL || p == pl)    return false;

    p->Prev->Next = p->Next;
    if(p->Next != NULL)    p->Next->Prev = p->Prev;

    delete p->Info;
    delete p;

    return true;
}

bool Update(Position p, int c){
    if(p == NULL)    return false;
    
    if(c == 1){
        long long price;

        cout << "Nhap gia san pham moi: ";
        cin >> price;
        cin.ignore();

        p->Info->SetPrice(price);
    }

    else if(c == 2){
        int count;

        cout << "Nhap so luong san pham moi: ";
        cin >> count;
        cin.ignore();

        p->Info->SetCount(count);
    }

    else{
        cout << "Lua chon khong hop le!" << endl;
        return false;
    }

    return true;
}

bool ClearList(Node pl){
    if(pl == NULL || pl->Next == NULL)    return false;

    Position p = pl->Next;
    while(p != NULL){
        Position t = p;
        p = p->Next;
        delete t->Info;
        delete t;
    }

    pl->Next = NULL;

    return true;
}

void ChiaDoi(Node pl, Node &Left, Node &Right){
    int count = 0;
    Position p = pl;
    while (p != NULL){
        count++;
        p = p->Next;
    }

    int mid = count/2;
    Position Mid = pl;
    for (int i = 1; i < mid; i++){
        Mid = Mid->Next;
    }

    Left = pl;
    Right = Mid->Next;
    Mid->Next = NULL;
    Right->Prev = NULL;
}

bool Tang(Node Left, Node Right){
    return *(Left->Info) <= *(Right->Info);
}

bool Giam(Node Left, Node Right){
    return *(Left->Info) >= *(Right->Info);
}

Node MergeSort(Node pl, bool(*Compare)(Node , Node)){
    if(pl == NULL || pl->Next == NULL)    return pl;

    Node Left = NULL;
    Node Right = NULL;

    ChiaDoi(pl, Left, Right);
    Left = MergeSort(Left, Compare);
    Right = MergeSort(Right, Compare);

    if(Compare(Left, Right)){
        pl = Left;
        Left = Left->Next;
    }

    else{
        pl = Right;
        Right = Right->Next;
    }

    pl->Prev = NULL;
    Position p = pl;
    while(Left != NULL  && Right != NULL){
        if(Compare(Left, Right)){
            p->Next = Left;
            Left->Prev = p;
            p = Left;
            Left = Left->Next;
        }

        else{
            p->Next = Right;
            Right->Prev = p;
            p = Right;
            Right = Right->Next;
        }
    }

    if(Left != NULL){
        p->Next = Left;
        Left->Prev = p;
    }

    else if(Right != NULL){
        p->Next = Right;
        Right->Prev = p;
    }

    return pl;
}

void ShowList(Node pl, int c){
    if(pl->Next == NULL){
        cout << "Danh sach dang trong, vui long them thong tin san pham!" << endl;
        return;
    }

    if(c == 1){
        pl = pl->Next;
        int i = 1;

        while(pl != NULL){
            cout << i << ". ";
            pl->Info->Out();
            pl = pl->Next;
            i++;
        }
    }

    else if(c == 2){
        pl->Next = MergeSort(pl->Next, Giam);
        pl->Next->Prev = pl;
        Position p = pl->Next;

        int i = 1;
        while(p != NULL){
            cout << i << ". ";
            p->Info->Out();
            p = p->Next;
            i++;
        }
    }

    else if(c == 3){
        pl->Next = MergeSort(pl->Next, Tang);
        pl->Next->Prev = pl;
        Position p = pl->Next;

        int i = 1;
        while(p != NULL){
            cout << i << ". ";
            p->Info->Out();
            p = p->Next;
            i++;
        }
    }

    else if(c == 4){
        pl = pl->Next;
        int i = 1;

        while(pl != NULL){
            if(pl->Info->GetType() == 1){
                cout << i << ". ";
                pl->Info->Out();
                i++;
            }

            pl = pl->Next;
        }
    }

    else if(c == 5){
        pl = pl->Next;
        int i = 1;

        while(pl != NULL){
            if(pl->Info->GetType() == 2){
                cout << i << ". ";
                pl->Info->Out();
                i++;
            }

            pl = pl->Next;
        }
    }

    else{
        cout << "Lua chon khong hop le!" << endl;
    }
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
    cout << "====================================================================================================" << endl << endl;

    Node ShoeList = Create();
        
    while(1){
        cout << "===== Ung dung quan ly ban giay =====" << endl << endl;
        cout << "1. Them san pham moi." << endl;
        cout << "2. Hien thi toan bo san pham." << endl;
        cout << "3. Tim kiem san pham." << endl;
        cout << "4. Cap nhat thong tin san pham." << endl;
        cout << "5. Xoa san pham." << endl;
        cout << "6. Xoa toan bo san pham." << endl;
        cout << "0. Thoat chuong trinh." << endl << endl;
        cout << ">> ";
        
        int c;
        cin >> c;
        cin.ignore();

        switch (c){
            case 1:{
                cout << "\nChon loai san pham muon them vao ung dung:" << endl;
                cout << "1. Giay the thao." << endl;
                cout << "2. Giay tay." << endl;
                cout << "0. Quay lai." << endl;
                cout << ">> ";

                int type;
                cin >> type;
                cin.ignore();

                if(type == 0){
                    break;
                }

                Shoe *s = NULL;

                if(type == 1){
                    s = new SportShoe();
                }

                else if(type == 2){
                    s = new DressShoe();
                }

                else{
                    cout << "Lua chon khong hop le!" << endl;
                    break;
                }

                s->Add();
                Position p = FindById(ShoeList, s->GetId());

                if(p != NULL){
                    p->Info->SetCount(p->Info->GetCount() + s->GetCount());
                    p->Info->SetPrice(s->GetPrice());

                    delete s;
                }

                else{
                    Insert(ShoeList, s, NULL);
                    cout << ">> Them san pham moi thanh cong!" << endl;
                }

                break;
            }

            case 2:{
                cout << "1. Hien thi tat ca san pham." << endl;
                cout << "2. Hien thi theo gia giam dan." << endl;
                cout << "3. Hien thi theo gia tang dan." << endl;
                cout << "4. Chi hien thi giay theo thao." << endl;
                cout << "5. Chi hien thi giay tay." << endl;
                cout << "0. Quay lai." << endl;
                cout << ">> ";

                int c;
                cin >> c;
                cin.ignore();

                if(c == 0){
                    break;
                }

                ShowList(ShoeList, c);

                break;
            }

            case 3:{
                cout << "1. Tim kiem theo ma giay." << endl;
                cout << "2. Tim kiem theo ten giay." << endl;
                cout << "0. Quay lai." << endl;

                int c;
                cout << ">> ";
                cin >> c;
                cin.ignore();

                if(c == 0){
                    break;
                }

                if(c == 1){
                    string id;
                    cout << "Nhap ma giay can tim: ";
                    getline(cin, id);

                    Position p = FindById(ShoeList, id);
                    if(p != NULL){
                        cout << "Thong tin san pham tim thay:" << endl;
                        p->Info->Out();
                    }

                    else{
                        cout << "Khong tim thay san pham co ma giay " << id << "!" << endl;
                    }
                }

                else if(c == 2){
                    string name;
                    cout << "Nhap ten giay can tim: ";
                    getline(cin, name);

                    FindByName(ShoeList, name);
                }

                else{
                    cout << "Lua chon khong hop le!" << endl;
                }

                break;
            }

            case 4:{
                    cout << "Thong tin can cap nhat: " << endl;
                    cout << "1. Cap nhat gia san pham." << endl;
                    cout << "2. Cap nhat so luong san pham." << endl;
                    cout << "0. Quay lai." << endl << endl;
                    cout << ">> ";

                    int c;
                    cin >> c;
                    cin.ignore();

                    if(c == 0){
                        break;
                    }

                    cout << "Nhap ma giay cua san pham can cap nhat thong tin: ";
                    string id;
                    getline(cin, id);

                    Position p = FindById(ShoeList, id);
                    if(p != NULL){
                        if(Update(p, c)){

                            cout << "Thong tin san pham hien tai: " << endl;
                            p->Info->Out();
                        }
                    }

                else{
                    cout << "Khong tim thay san pham co ma giay " << id << "!" << endl;
                }

                break;
            }

            case 5:{
                cout << "Nhap ma giay cua san pham can xoa: ";
                string id;
                getline(cin, id);

                Position p = FindById(ShoeList, id);
                if(p != NULL){
                    Remove(ShoeList, p);
                    cout << "Da xoa san pham thanh cong!" << endl;
                }

                else{
                cout << "Khong tim thay san pham co ma " << id << "!" << endl;
                }

                break;
            }

            case 6:{
                ClearList(ShoeList);
                cout << "Da xoa toan bo san pham!" << endl;
                break;
            }

            case 0:{
                cout << "Cam on ban da su dung ung dung!" << endl;
                return 0;
            }

            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    }

    system("pause");
    return 0;
}
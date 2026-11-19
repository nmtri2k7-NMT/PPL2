#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void TextColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

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

        virtual ~Shoe();

        virtual void Add();
        virtual void Out() const;

        string GetId() const;
        string GetName() const;
        int virtual GetType() = 0;

        void SetId(string id);
        void SetName(string name);
        void SetBrand(string brand);
        void SetSize(int size);
        void SetColor(string color);
        void SetPrice(long long price);
        void SetCount(int count);

        bool operator <= (const Shoe &s);
        bool operator >= (const Shoe &s);

        virtual void Write(ofstream &f) const;
};

Shoe::Shoe()
    : Id(""), Name(""), Brand(""), Size(0), Color(""), Price(0), Count(0)
{ }

Shoe::Shoe(string id, string name, string brand, int size, string color, long long price, int count)
    : Id(id), Name(name), Brand(brand), Size(size), Color(color), Price(price), Count(count)
{ }

Shoe::~Shoe()
{ }

void Shoe::Add(){
    TextColor(15);
    cout << "\nNhap ma san pham: ";
    TextColor(14);
    getline(cin, Id);

    TextColor(15);
    cout << "Nhap ten san pham: ";
    TextColor(14);
    getline(cin, Name);

    TextColor(15);
    cout << "Nhap ten hang san xuat: ";
    TextColor(14);
    getline(cin, Brand);

    TextColor(15);
    cout << "Nhap kich co giay: ";
    TextColor(14);
    cin >> Size;
    cin.ignore(100, '\n');

    TextColor(15);
    cout << "Nhap mau sac: ";
    TextColor(14);
    getline(cin, Color);
}

void Shoe::Out() const {
    TextColor(15);
    cout << "\nMa san pham: ";
    TextColor(14);
    cout << Id << endl;

    TextColor(15);
    cout << "Ten san pham: ";
    TextColor(14);
    cout << Name << endl;

    TextColor(15);
    cout << "Hang san xuat: ";
    TextColor(14);
    cout << Brand << endl;

    TextColor(15);
    cout << "Kich co: ";
    TextColor(14);
    cout << Size << endl;

    TextColor(15);
    cout << "Mau sac: ";
    TextColor(14);
    cout << Color << endl;
}

string Shoe::GetId() const {
    return Id;
}

string Shoe::GetName() const {
    return Name;
}

void Shoe::SetId(string id){
    Id = id;
}

void Shoe::SetName(string name){
    Name = name;
}

void Shoe::SetBrand(string brand){
    Brand = brand;
}

void Shoe::SetSize(int size){
    Size = size;
}

void Shoe::SetColor(string color){
    Color = color;
}

void Shoe::SetPrice(long long price){
    Price = price;
}

void Shoe::SetCount(int count){
    Count = count;
}

bool Shoe::operator <= (const Shoe &s){
    return this->Price <= s.Price;
}

bool Shoe::operator >= (const Shoe &s){
    return this->Price >= s.Price;
}

void Shoe::Write(ofstream &f) const {
    f << "Ma san pham: ";
    f << Id << endl;

    f << "Ten san pham: ";
    f << Name << endl;

    f << "Hang san xuat: ";
    f << Brand << endl;

    f << "Kich co: ";
    f << Size << endl;

    f << "Mau sac: ";
    f << Color << endl;
}

class SportShoe : public Shoe{
    private:
        string Sport;
        string Cushion;

    public:
        SportShoe();
        SportShoe(string id, string name, string brand, int size, string color, long long price, int count, 
            string sport, string cushion);

        ~SportShoe();

        void Add();
        void Out() const;

        int GetType();

        void SetSport(string sport);
        void SetCushion(string cushion);

        void Write(ofstream &f) const;
};

SportShoe::SportShoe() 
    : Shoe(), Sport(""), Cushion("")
{ }

SportShoe::SportShoe(string id, string name, string brand, int size, string color, long long price, int count, string sport, string cushion) 
    : Shoe(id, name, brand, size, color, price, count), Sport(sport), Cushion(cushion)
{ }

SportShoe::~SportShoe()
{ }

void SportShoe::Add(){
    Shoe::Add();

    TextColor(15);
    cout << "Nhap mon the thao: ";
    TextColor(14);
    getline(cin, Sport);

    TextColor(15);
    cout << "Nhap cong nghe dem: ";
    TextColor(14);
    getline(cin, Cushion);

    TextColor(15);
    cout << "Nhap don gia: ";
    TextColor(14);
    cin >> Price;

    TextColor(15);
    cout << "Nhap so luong giay: ";
    TextColor(14);
    cin >> Count;
    cin.ignore(100, '\n');
}

void SportShoe::Out() const {
    Shoe::Out();

    TextColor(15);
    cout << "Mon the thao: ";
    TextColor(14);
    cout << Sport << endl;

    TextColor(15);
    cout << "Cong nghe dem: ";
    TextColor(14);
    cout << Cushion << endl;

    TextColor(15);
    cout << "Don gia: ";
    TextColor(14);
    cout << Price << " VND" << endl;

    TextColor(15);
    cout << "So luong hien tai: ";
    TextColor(14);
    cout << Count << endl;

    TextColor(15);
    cout << "--------------------------------------------------" << endl;
}

int SportShoe::GetType(){
    return 1;
}

void SportShoe::SetSport(string sport){
    Sport = sport;
}

void SportShoe::SetCushion(string cushion){
    Cushion = cushion;
}

void SportShoe::Write(ofstream &f) const {
    f << "#SPORTSHOE" << endl;

    Shoe::Write(f);
    f << "Mon the thao: ";
    f << Sport << endl;

    f << "Cong nghe dem: ";
    f << Cushion << endl;

    f << "Don gia: ";
    f << Price << endl;

    f << "So luong: ";
    f << Count << endl;

    f << "--------------------------------------------------" << endl;
}

class DressShoe : public Shoe{
    private:
        string Leather;
        string Style;

    public:
        DressShoe();
        DressShoe(string id, string name, string brand, int size, string color, long long price, int count,
             string leather, string style);

        ~DressShoe();

        void Add();
        void Out() const;

        int GetType();

        void SetLeather(string leather);
        void SetStyle(string style);

        void Write(ofstream &f) const;
};

DressShoe::DressShoe() 
    : Shoe(), Leather(""), Style("") 
{ }

DressShoe::DressShoe(string id, string name, string brand, int size, string color, long long price, int count, string leather, string style) 
    : Shoe(id, name, brand, size, color, price, count), Leather(leather), Style(style) 
{ }

DressShoe::~DressShoe() 
{ }

void DressShoe::Add(){
    Shoe::Add();

    TextColor(15);
    cout << "Nhap chat lieu da: ";
    TextColor(14);
    getline(cin, Leather);

    TextColor(15);
    cout << "Nhap kieu dang: ";
    TextColor(14);
    getline(cin, Style);

    TextColor(15);
    cout << "Nhap don gia: ";
    TextColor(14);
    cin >> Price;

    TextColor(15);
    cout << "Nhap so luong giay: ";
    TextColor(14);
    cin >> Count;
    cin.ignore(100, '\n');
}

void DressShoe::Out() const {
    Shoe::Out();

    TextColor(15);
    cout << "Chat lieu da: ";
    TextColor(14);
    cout << Leather << endl;

    TextColor(15);
    cout << "Kieu dang: ";
    TextColor(14);
    cout << Style << endl;

    TextColor(15);
    cout << "Don gia: ";
    TextColor(14);
    cout << Price << " VND" << endl;

    TextColor(15);
    cout << "So luong hien tai: ";
    TextColor(14);
    cout << Count << endl;

    TextColor(15);
    cout << "--------------------------------------------------" << endl;
}

int DressShoe::GetType(){
    return 2;
}

void DressShoe::SetLeather(string leather){
    Leather = leather;
}

void DressShoe::SetStyle(string style){
    Style = style;
}

void DressShoe::Write(ofstream &f) const {
    f << "#DRESSSHOE" << endl;

    Shoe::Write(f);
    f << "Chat lieu da: ";
    f << Leather << endl;

    f << "Kieu dang: ";
    f << Style << endl;

    f << "Don gia: ";
    f << Price << endl;

    f << "So luong: ";
    f << Count << endl;

    f << "--------------------------------------------------" << endl;
}

struct NodeShoe{
    Shoe *Info;
    NodeShoe *Next;
    NodeShoe *Prev;
};

Node Create(){
    Node pl = new NodeShoe;

    pl->Info = nullptr;
    pl->Next = nullptr;
    pl->Prev = nullptr;

    return pl;
}

bool Insert(Node pl, Shoe *info, Position p){
    Node newNode = new NodeShoe;

    if(newNode == nullptr)    return false;
    if(p == nullptr)    p = pl;

    newNode->Info = info;
    newNode->Next = p->Next;
    newNode->Prev = p;
    
    if(p->Next != nullptr)    p->Next->Prev = newNode;
    p->Next = newNode;
    
    return true;
}

Position FindById(Node pl, string id){
    pl = pl->Next;

    if(pl == nullptr)    return nullptr;
    while(pl != nullptr && pl->Info->GetId() != id)    pl = pl->Next;

    return pl;
}

bool FindByName(Node pl, string name){
    pl = pl->Next;

    bool check = 0;
    while(pl != nullptr){
        if(pl->Info->GetName() == name){
            if(check == 0){
                TextColor(15);
                cout << ">> Thong tin san pham tim thay:" << endl;
            }

            pl->Info->Out();
            check = 1;
        }

        pl = pl->Next;
    }

    return check;
}

bool Remove(Node pl, Position p){
    if(p == nullptr || p == pl)    return false;

    p->Prev->Next = p->Next;
    if(p->Next != nullptr)    p->Next->Prev = p->Prev;

    delete p->Info;
    delete p;

    return true;
}

bool Update(Node pl, Position p, char c){
    if(p == nullptr)    return false;

    if(c == '1'){
        string id;
        TextColor(15);
        cout << "\n>> Nhap ma san pham moi: ";
        TextColor(14);
        getline(cin, id);

        if(id != p->Info->GetId() && FindById(pl, id) != nullptr){
            TextColor(12);
            cout << "\n>> Loi: Ma giay ";
            TextColor(14);
            cout << id;
            TextColor(12);
            cout << " da ton tai!" << endl;
            
            return false;
        }

        p->Info->SetId(id);
    }

    else if(c == '2'){
        string name;
        TextColor(15);
        cout << "\n>> Nhap ten san pham moi: ";
        TextColor(14);
        getline(cin, name);

        p->Info->SetName(name);
    }

    else if(c == '3'){
        string brand;
        TextColor(15);
        cout << "\n>> Nhap ten hang san xuat moi: ";
        TextColor(14);
        getline(cin, brand);

        p->Info->SetBrand(brand);
    }

    else if(c == '4'){
        int size;
        TextColor(15);
        cout << "\n>> Nhap kich co giay moi: ";
        TextColor(14);
        cin >> size;
        cin.ignore(100, '\n');

        p->Info->SetSize(size);
    }

    else if(c == '5'){
        string color;
        TextColor(15);
        cout << "\n>> Nhap mau sac moi: ";
        TextColor(14);
        getline(cin, color);

        p->Info->SetColor(color);
    }

    else if(c == '6'){
        long long price;
        TextColor(15);
        cout << "\n>> Nhap gia san pham moi: ";
        TextColor(14);
        cin >> price;
        cin.ignore(100, '\n');

        p->Info->SetPrice(price);
    }

    else if(c == '7'){
        int count;
        TextColor(15);
        cout << "\n>> Nhap so luong san pham moi: ";
        TextColor(14);
        cin >> count;
        cin.ignore(100, '\n');

        p->Info->SetCount(count);
    }

    else if(c == '8'){
        if(p->Info->GetType() == 1){
            string sport;
            TextColor(15);
            cout << "\n>> Nhap mon the thao moi: ";
            TextColor(14);
            getline(cin, sport);

            ((SportShoe*)p->Info)->SetSport(sport);
        }

        else if(p->Info->GetType() == 2){
            string leather;
            TextColor(15);
            cout << "\n>> Nhap chat lieu da moi: ";
            TextColor(14);
            getline(cin, leather);

            ((DressShoe*)p->Info)->SetLeather(leather);
        }
    }

    else if(c == '9'){
        if(p->Info->GetType() == 1){
            string cushion;
            TextColor(15);
            cout << "\n>> Nhap cong nghe dem moi: ";
            TextColor(14);
            getline(cin, cushion);

            ((SportShoe*)p->Info)->SetCushion(cushion);
        }

        else if(p->Info->GetType() == 2){
            string style;
            TextColor(15);
            cout << "\n>> Nhap kieu dang moi: ";
            TextColor(14);
            getline(cin, style);

            ((DressShoe*)p->Info)->SetStyle(style);
        }
    }

    else{
        TextColor(12);
        cout << "\n>> Lua chon khong hop le! Vui long nhap lai.";
        cin.get();

        return false;
    }

    TextColor(10);
    cout << ">> Cap nhat thong tin thanh cong!";
    cin.get();
    
    return true;
}

bool ClearList(Node pl){
    if(pl == nullptr || pl->Next == nullptr)    return false;

    Position p = pl->Next;
    while(p != nullptr){
        Position t = p;
        p = p->Next;
        delete t->Info;
        delete t;
    }

    pl->Next = nullptr;

    return true;
}

void ChiaDoi(Node pl, Node &Left, Node &Right){
    int count = 0;
    Position p = pl;
    while (p != nullptr){
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
    Mid->Next = nullptr;
    Right->Prev = nullptr;
}

bool Tang(Node Left, Node Right){
    return *(Left->Info) <= *(Right->Info);
}

bool Giam(Node Left, Node Right){
    return *(Left->Info) >= *(Right->Info);
}

Node Merge(Node Left, Node Right, bool(*Compare)(Node, Node)){
    Node pl = nullptr;

    if(Compare(Left, Right)){
        pl = Left;
        Left = Left->Next;
    }

    else{
        pl = Right;
        Right = Right->Next;
    }

    pl->Prev = nullptr;
    Position p = pl;
    while(Left != nullptr && Right != nullptr){
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

    if(Left != nullptr){
        p->Next = Left;
        Left->Prev = p;
    }

    else if(Right != nullptr){
        p->Next = Right;
        Right->Prev = p;
    }

    return pl;
}

Node MergeSort(Node pl, bool(*Compare)(Node , Node)){
    if(pl == nullptr || pl->Next == nullptr)    return pl;

    Node Left = nullptr;
    Node Right = nullptr;

    ChiaDoi(pl, Left, Right);
    Left = MergeSort(Left, Compare);
    Right = MergeSort(Right, Compare);

    pl = Merge(Left, Right, Compare);

    return pl;
}

void ShowList(Node pl, char c = '1'){
        pl = pl->Next;
        int i = 1;

        while(pl != nullptr){
            if((c != '4' && c != '5') || (c == '4' && pl->Info->GetType() == 1) || (c == '5' && pl->Info->GetType() == 2)){
                TextColor(15);
                cout << i << ". ";

                pl->Info->Out();
                i++;
            }

            pl = pl->Next;
        }

       if(i == 1){
            TextColor(12);
            cout << "\n>> Khong tim thay san pham!" << endl;
        }
}

bool DocFile(Node pl, string filename){
    ifstream f(filename);
    if(!f.is_open()){
        TextColor(12);
        cout << ">> Loi: Khong tim thay file ";
        TextColor(14);
        cout << filename;
        TextColor(12);
        cout << "!";

        return false;
    }

    string line;
    while(getline(f, line)){
        if(line == "" || line[0] == '-' || line[0] == '=')   continue;

        if(line == "#SPORTSHOE" || line == "#DRESSSHOE"){
            bool isSportShoe = (line == "#SPORTSHOE");

            string id, name, brand;
            int size;
            string color;
            long long price;
            int count;

            string remove;

            getline(f, remove, ':');
            f >> ws;
            getline(f, id);

            getline(f, remove, ':');
            f >> ws;
            getline(f, name);

            getline(f, remove, ':');
            f >> ws;
            getline(f, brand);

            getline(f, remove, ':');
            f >> size;

            getline(f, remove, ':');
            f >> ws;
            getline(f, color);

            Shoe* s = nullptr;

            if(isSportShoe){
                string sport, cushion;

                getline(f, remove, ':');
                f >> ws;
                getline(f, sport);

                getline(f, remove, ':');
                f >> ws;
                getline(f, cushion);

                getline(f, remove, ':');
                f >> price;

                getline(f, remove, ':');
                f >> count;

                s = new SportShoe(id, name, brand, size, color, price, count, sport, cushion);
            }

            else{
                string leather, style;
                getline(f, remove, ':');
                f >> ws;
                getline(f, leather);

                getline(f, remove, ':');
                f >> ws;
                getline(f, style);

                getline(f, remove, ':');
                f >> price;

                getline(f, remove, ':');
                f >> count;

                s = new DressShoe(id, name, brand, size, color, price, count, leather, style);
            }

            Position p = FindById(pl, s->GetId());
            if(p != nullptr){
                TextColor(12);
                cout << ">> Loi: Ma san pham ";
                TextColor(14);
                cout << s->GetId();
                TextColor(12);
                cout  << " da ton tai!" << endl;
                
                delete s;
            }

            else{
                Insert(pl, s, nullptr);
            }
        }
    }

    f.close();
    TextColor(10);
    cout << ">> Doc du lieu tu file ";
    TextColor(14);
    cout << filename;
    TextColor(10);
    cout << " thanh cong!";

    return true;
}

void SaveFile(Node pl, string filename = "DataShoe.txt"){
    ofstream f(filename);
    if(!f.is_open()){
        return;
    }

    Position p = pl->Next;
    while(p != nullptr){
        p->Info->Write(f);
        p = p->Next;
    }

    f.close();
}

int main(){
    TextColor(15);
    cout << "====================================================================================================" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                           TRUONG DAI HOC BACH KHOA - DAI HOC DA NANG                           ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                    KHOA CONG NGHE THONG TIN                                    ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||------------------------------------------------------------------------------------------------||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                  PBL 2: DU AN CO SO LAP TRINH                                  ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                DE TAI: UNG DUNG QUAN LY BAN GIAY                               ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||------------------------------------------------------------------------------------------------||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                      GIANG VIEN HUONG DAN:                                     ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                     ThS. Nguyen Van Nguyen                                     ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                      TS. Nguyen Van Hieu                                       ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                                      SINH VIEN THUC HIEN:                                      ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||                                                                                                ||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                 Le Nguyen Hoang Viet       Lop: 25T_DT2         MSSV: 102250102                ";
    TextColor(15);
    cout << "||" << endl;
    cout << "||";
    TextColor(11);
    cout << "                 Nguyen Minh Tri            Lop: 25T_KHDL        MSSV: 102250375                ";
    TextColor(15);
    cout << "||" << endl;
    cout << "====================================================================================================" << endl << endl;

    Node ShoeList = Create();
        
    while(1){
        TextColor(11);
        cout << "\n===================== UNG DUNG QUAN LY BAN GIAY =====================" << endl << endl;

        TextColor(15);
        cout << "1. Them san pham moi." << endl;
        cout << "2. Hien thi toan bo san pham." << endl;
        cout << "3. Tim kiem san pham." << endl;
        cout << "4. Cap nhat thong tin san pham." << endl;
        cout << "5. Xoa san pham." << endl;
        cout << "6. Lam moi he thong." << endl;
        cout << "0. Thoat chuong trinh." << endl << endl;

        TextColor(15);
        cout << ">> ";
        
        char C;
        TextColor(14);
        cin >> C;
        cin.ignore(100, '\n');

        switch (C){
            case '1':{
                while(1){
                    TextColor(11);
                    cout << "\n------------------ THEM SAN PHAM ------------------" << endl << endl;

                    TextColor(15);
                    cout << "1. Them san pham tu file." << endl;
                    cout << "2. Them san pham tu ban phim." << endl;
                    cout << "0. Quay lai." << endl << endl;
                    cout << ">> ";

                    char c;
                    TextColor(14);
                    cin >> c;
                    cin.ignore(100, '\n');

                    if(c != '0' && c != '1' && c != '2'){
                        TextColor(12);
                        cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                        cin.get();

                        continue;
                    }

                    else if(c == '0'){
                        break;
                    }

                    else if(c == '1'){
                        string f;
                        TextColor(15);
                        cout << "\n>> Nhap ten file can doc: ";

                        TextColor(14);
                        getline(cin, f);
                        f += ".txt";

                        DocFile(ShoeList, f);
                        SaveFile(ShoeList);

                        cin.get();

                        continue;
                    }

                    else if(c == '2'){
                        while(1){
                            TextColor(11);
                            cout << "\n------------------------- THEM SAN PHAM -------------------------" << endl << endl;

                            TextColor(15);
                            cout << "Chon loai san pham muon them vao ung dung:" << endl;
                            cout << "1. Giay the thao." << endl;
                            cout << "2. Giay tay." << endl;
                            cout << "0. Quay lai." << endl << endl;
                            cout << ">> ";

                            char type;
                            TextColor(14);
                            cin >> type;
                            cin.ignore(100, '\n');

                            if(type != '0' && type != '1' && type != '2'){
                                TextColor(12);
                                cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                                cin.get();

                                continue;
                            }

                            if(type == '0'){
                                break;
                            }

                            Shoe *s = nullptr;

                            if(type == '1'){
                                s = new SportShoe();
                            }

                            else if(type == '2'){
                                s = new DressShoe();
                            }

                            s->Add();
                            Position p = FindById(ShoeList, s->GetId());
                    
                            if(p != nullptr){
                                TextColor(12);
                                cout << "\n>> Loi: Ma san pham ";
                                TextColor(14);
                                cout << s->GetId();
                                TextColor(12);
                                cout << " da ton tai!";
                                delete s;

                                cin.get();
                            }

                            else{
                                Insert(ShoeList, s, nullptr);
                                SaveFile(ShoeList);

                                TextColor(10);
                                cout << "\n>> Them san pham moi thanh cong!";
                                cin.get();

                                continue ;
                            }
                        }
                    }
                }

                break;
            }

            case '2':{
                while(1){
                    TextColor(11);
                    cout << "\n------------------------ HIEN THI SAN PHAM ------------------------" << endl << endl;

                    TextColor(15);
                    cout << "1. Hien thi tat ca san pham." << endl;
                    cout << "2. Hien thi theo gia giam dan." << endl;
                    cout << "3. Hien thi theo gia tang dan." << endl;
                    cout << "4. Chi hien thi giay theo thao." << endl;
                    cout << "5. Chi hien thi giay tay." << endl;
                    cout << "0. Quay lai." << endl << endl;
                    cout << ">> ";

                    char c;
                    TextColor(14);
                    cin >> c;
                    cin.ignore(100, '\n');

                    if(c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5'){
                        TextColor(12);
                        cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                        cin.get();

                        continue;
                    }

                    if(c == '0'){
                        break;
                    }

                    if(ShoeList->Next == nullptr){
                            TextColor(12);
                            cout << "\n>> Danh sach dang trong, vui long them thong tin san pham!";
                            cin.get();

                            continue;
                        }
                    
                    else if(c == '1'){
                        ShowList(ShoeList);

                        TextColor(15);
                        cout << ">> Nhan Enter de tiep tuc...";
                        cin.get();
                    }

                    else if(c == '2'){
                        ShoeList->Next = MergeSort(ShoeList->Next, Giam);
                        ShoeList->Next->Prev = ShoeList;

                        ShowList(ShoeList);

                        TextColor(15);
                        cout << ">> Nhan Enter de tiep tuc...";
                        cin.get();
                    }

                    else if(c == '3'){
                        ShoeList->Next = MergeSort(ShoeList->Next, Tang);
                        ShoeList->Next->Prev = ShoeList;

                        ShowList(ShoeList);

                        TextColor(15);
                        cout << ">> Nhan Enter de tiep tuc...";
                        cin.get();
                    }

                    else if(c == '4'){
                        ShowList(ShoeList, c);

                        TextColor(15);
                        cout << ">> Nhan Enter de tiep tuc...";
                        cin.get();
                    }

                    else if(c == '5'){
                        ShowList(ShoeList, c);

                        TextColor(15);
                        cout << ">> Nhan Enter de tiep tuc...";
                        cin.get();
                    }
                }

                break;
            }

            case '3':{
                while(1){
                    TextColor(11);
                    cout << "\n-------------------- TIM KIEM SAN PHAM --------------------" << endl << endl;

                    TextColor(15);
                    cout << "1. Tim kiem theo ma giay." << endl;
                    cout << "2. Tim kiem theo ten giay." << endl;
                    cout << "0. Quay lai." << endl << endl;
                    cout << ">> ";

                    char c;
                    TextColor(14);
                    cin >> c;
                    cin.ignore(100, '\n');

                    if(c != '0' && c != '1' && c != '2'){
                        TextColor(12);
                        cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                        cin.get();

                        continue;
                    }

                    if(c == '0'){
                        break;
                    }

                    if(ShoeList->Next == nullptr){
                        TextColor(12);
                        cout << "\n>> Danh sach dang trong, vui long them thong tin san pham!";
                        cin.get();

                        continue;
                    }

                    if(c == '1'){
                        string id;
                        TextColor(15);
                        cout << "\n>> Nhap ma giay can tim: ";
                        TextColor(14);
                        getline(cin, id);

                        Position p = FindById(ShoeList, id);
                    
                        if(p != nullptr){
                            TextColor(15);
                            cout << ">> Thong tin san pham tim thay:" << endl;
                            p->Info->Out();
                            
                            TextColor(15);
                            cout << ">> Nhan Enter de tiep tuc...";
                            cin.get();

                            continue;
                        }

                        else{
                            TextColor(12);
                            cout << ">> Khong tim thay san pham co ma giay ";
                            TextColor(14);
                            cout << id;
                            TextColor(12);
                            cout << "!";

                            cin.get();

                            continue;
                        }
                    }

                    else if(c == '2'){
                        string name;
                        TextColor(15);
                        cout << "\n>> Nhap ten giay can tim: ";
                        TextColor(14);
                        getline(cin, name);

                        if(FindByName(ShoeList, name)){
                            TextColor(15);
                            cout << ">> Nhan Enter de tiep tuc...";
                            cin.get();

                            continue;
                        }

                        else{
                            TextColor(12);
                            cout << ">> Khong tim thay san pham co ten ";
                            TextColor(14);
                            cout << name;
                            TextColor(12);
                            cout << "!";

                            cin.get();

                            continue;
                        }
                    }
                }

                break;
            }

            case '4':{
                while(1){
                    TextColor(11);
                    cout << "\n------------------------------ CAP NHAT THONG TIN ------------------------------" << endl << endl;

                    TextColor(15);
                    cout << ">> Nhap ma cua san pham can cap nhat thong tin (hoac nhap '0' de quay lai): ";
                    
                    string id;
                    TextColor(14);
                    getline(cin, id);

                    if(id == "0"){
                        break;
                    }

                    Position p = FindById(ShoeList, id);

                    if(p != nullptr){
                        while(1){
                            TextColor(11);
                            cout << "\n-------------------- CAP NHAT THONG TIN --------------------" << endl << endl;
                            
                            TextColor(15);
                            cout << "Thong tin can cap nhat:" << endl;
                            cout << "1. Cap nhat ma san pham." << endl;
                            cout << "2. Cap nhat ten san pham." << endl;
                            cout << "3. Cap nhat hang san xuat." << endl;
                            cout << "4. Cap nhat kich co giay." << endl;
                            cout << "5. Cap nhat mau sac." << endl;
                            cout << "6. Cap nhat gia san pham." << endl;
                            cout << "7. Cap nhat so luong san pham." << endl;

                            if(p->Info->GetType() == 1){
                                TextColor(15);
                                cout << "8. Cap nhat mon the thao." << endl;
                                cout << "9. Cap nhat cong nghe dem." << endl;
                            }

                            else if(p->Info->GetType() == 2){
                                TextColor(15);
                                cout << "8. Cap nhat chat lieu da." << endl;
                                cout << "9. Cap nhat kieu dang." << endl;
                            }

                            cout << "0. Hoan tat cap nhat." << endl << endl;
                            cout << ">> ";

                            char c;
                            TextColor(14);
                            cin >> c;
                            cin.ignore(100, '\n');

                            if(c == '0'){
                                TextColor(15);
                                cout << "\n>> Thong tin san pham hien tai:" << endl;
                                p->Info->Out();

                                cout << ">> Nhan Enter de tiep tuc...";
                                cin.get();

                                break;
                            }

                            Update(ShoeList, p, c);
                            SaveFile(ShoeList);

                            continue;
                        }

                        break;
                    }

                    else{
                        TextColor(12);
                        cout << ">> Khong tim thay san pham co ma giay ";
                        TextColor(14);
                        cout << id;
                        TextColor(12);
                        cout << "!";
                        cin.get();

                        continue;
                    }
                }

                break;
            }

            case '5':{
                while(1){
                    TextColor(11);
                    cout << "\n---------------- XOA SAN PHAM ----------------" << endl << endl;

                    TextColor(15);
                    cout << "1. Xoa nhieu san pham." << endl;
                    cout << "2. Xoa mot san pham." << endl;
                    cout << "0. Quay lai." << endl << endl;
                    cout << ">> ";

                    char c;
                    TextColor(14);
                    cin >> c;
                    cin.ignore(100, '\n');

                    if(c != '0' && c != '1' && c != '2'){
                        TextColor(12);
                        cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                        cin.get();

                        continue;
                    }

                    if(c == '0'){
                        break;
                    }
                
                    if(c == '1'){
                        string FileName;
                        TextColor(15);
                        cout << "\n>> Nhap ten file chua danh sach ma giay can xoa: ";
                        TextColor(14);
                        getline(cin, FileName);
                        FileName += ".txt";
                    
                        ifstream f(FileName);
                    
                        if(!f.is_open()){
                            TextColor(12);
                            cout << ">> Loi: Khong mo duoc file ";
                            TextColor(14);
                            cout << FileName;
                            TextColor(12);
                            cout << "!";
                            cin.get();

                            continue;
                        }
                    
                        else{
                            string id;
                            int count = 0;

                            while(getline(f, id)){
                                Position p = FindById(ShoeList, id);

                                if(p != nullptr){
                                    Remove(ShoeList, p);
                                    count++;
                                }

                                else{
                                    TextColor(12);
                                    cout << "\n>> Khong tim thay san pham co ma giay ";
                                    TextColor(14);
                                    cout << id;
                                    TextColor(12);
                                    cout << "!" << endl;
                                }
                            }

                            f.close();
                            SaveFile(ShoeList);

                            TextColor(10);
                            cout << "\n>> Da xoa thanh cong ";
                            TextColor(14);
                            cout << count;
                            TextColor(10);
                            cout << " san pham!";
                            cin.get();

                            continue;
                        }
                    }
                
                    else if(c == '2'){
                        TextColor(15);
                        cout << "\n>> Nhap ma giay cua san pham can xoa: ";
                        string id;
                        TextColor(14);
                        getline(cin, id);

                        Position p = FindById(ShoeList, id);
                        if(p != nullptr){
                            Remove(ShoeList, p);
                            SaveFile(ShoeList);

                            TextColor(10);
                            cout << ">> Da xoa san pham thanh cong!";
                            cin.get();

                            continue;
                        }

                        else{
                            TextColor(12);
                            cout << ">> Khong tim thay san pham co ma ";
                            TextColor(14);
                            cout << id;
                            TextColor(12);
                            cout << "!";
                            cin.get();

                            continue;
                        }
                    }
                }

                break;
            }

            case '6':{
                while(1){
                    TextColor(11);
                    cout << "\n------------------------------ LAM MOI HE THONG ------------------------------" << endl << endl;

                    TextColor(15);
                    cout << ">> Xac nhan ban muon xoa toan bo san pham (Y/N): ";
                    
                    char c;
                    TextColor(14);
                    cin >> c;
                    cin.ignore(100, '\n');

                    if(c == 'n' || c == 'N'){
                        TextColor(10);
                        cout << ">> Da huy thao tac xoa toan bo san pham!";
                        cin.get();

                        break;
                    }

                    else if(c == 'y' || c == 'Y'){
                        ClearList(ShoeList);
                        SaveFile(ShoeList);

                        TextColor(10);
                        cout << ">> Da xoa thanh cong toan bo san pham!";
                        cin.get();

                        break;                    
                    }

                    else{
                        TextColor(12);
                        cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                        cin.get();

                        continue;
                    }
                }

                break;
            }

            case '0':{
                TextColor(10);
                cout << "\n>> Cam on ban da dung ung dung!";
                system("pause");

                return 0;
            }

            default:
                TextColor(12);
                cout << ">> Lua chon khong hop le! Vui long nhap lai.";
                cin.get();

                continue;
        }
    }

    return 0;
}
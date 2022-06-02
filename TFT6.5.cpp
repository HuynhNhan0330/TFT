#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
* 
* Toc:
* 1 - Cong nghe
* 2 - Tien cong
*
* He:
* -1 - khong he
* 1 - Dau si
*
*/

class CTuong {
protected:
    int attack;
    int defend;
    string name;
    int giatri;
    string skill;
    double satthuongS;
    string toc;
    int pToc;
    string he;
    int pHe;
public:
    CTuong();
    virtual void init();
    void out() const;
    int getToc() const;
    int getHe() const;
    int getGiaTri() const;
    void tangAttack(int value);
    void tangDefend(int value);
    virtual void setSTS(int sll) = 0;
};

class CTuongType1 : public CTuong {
public:
    CTuongType1();
    void init();
    void out() const;
    void setSTS(int sll);
};

class CTuongType2 : public CTuong {
public:
    CTuongType2();
    void init();
    void out() const;
    void setSTS(int sll);
};

class CTuongType3 : public CTuong {
public:
    CTuongType3();
    void init();
    void out() const;
    void setSTS(int sll);
};

class CTuongType4 : public CTuong {
public:
    CTuongType4();
    void init();
    void out() const;
    void setSTS(int sll);
};

class CBangTocHe {
private:
    set <string> TCongNghe;
    set <string> TTienCong;
    set <string> HDauSi;
public:
    CBangTocHe();
    ~CBangTocHe();
    void addTH(string name, int pT, int pH);
    int getSLCN() const;
    int getSLTC() const;
    int getSLDS() const;
} BGameX;

class CGame {
private:
    int sltuong;
    int slluot;
    CTuong** dst;
public:
    CGame();
    ~CGame();
    friend istream& operator >> (istream& is, CGame& g);
    friend ostream& operator << (ostream& os, const CGame& g);
    void update();
    int getTongGiaTri() const;
};

int main() {
    CGame GameX;
    cin >> GameX;
    GameX.update();
    cout << GameX;
    cout << "Tong gia tri: " << GameX.getTongGiaTri();
}

CTuongType1::CTuongType1():
    CTuong()
{
    this->name = "Jarvan";
    this->giatri = 1;
    this->skill = "Thuong Thuat";
    this->toc = "Cong nghe";
    this->pToc = 1;
    this->he = "Dau si";
    this->pHe = 1;

    BGameX.addTH(this->name, this->pToc, this->pHe);
}

void CTuongType1::init()
{
    CTuong::init();
}

void CTuongType1::out() const
{
    CTuong::out();
}

void CTuongType1::setSTS(int sll)
{
    this->satthuongS = this->defend * 2 * sll;
}

CTuong::CTuong():
    defend(0), attack(0), giatri(0), name(""), skill(""), satthuongS(0), toc(""), pToc(0), he(""), pHe(0)
{
}

void CTuong::init()
{
    cin >> this->attack >> this->defend;
}

void CTuong::out() const
{
    cout << this->name << " - sat thuong gay ra: " << this->satthuongS << '\n';
}

int CTuong::getToc() const
{
    return this->pToc;
}

int CTuong::getHe() const
{
    return this->pHe;
}

int CTuong::getGiaTri() const
{
    return this->giatri;
}

void CTuong::tangAttack(int value)
{
    this->attack += value;
}

void CTuong::tangDefend(int value)
{
    this->defend += value;
}

CTuongType2::CTuongType2():
    CTuong()
{
    this->name = "Reksai";
    this->giatri = 2;
    this->skill = "Nu hoang phan no";
    this->toc = "Tien cong";
    this->pToc = 2;
    this->he = "Dau si";
    this->pHe = 1;

    BGameX.addTH(this->name, this->pToc, this->pHe);
}

void CTuongType2::init()
{
    CTuong::init();
}

void CTuongType2::out() const
{
    CTuong::out();
}

void CTuongType2::setSTS(int sll)
{
    this->satthuongS = this->attack * sll + this->attack * (sll / 4);
}

CTuongType3::CTuongType3():
    CTuong()
{
    this->name = "Sivir";
    this->giatri = 4;
    this->skill = "Guom Boomerang";
    this->toc = "Cong nghe";
    this->pToc = 1;
    this->pHe = -1;

    BGameX.addTH(this->name, this->pToc, this->pHe);
}

void CTuongType3::init()
{
    CTuong::init();
}

void CTuongType3::out() const
{
    CTuong::out();
}

void CTuongType3::setSTS(int sll)
{
    this->satthuongS = this->attack * 2 * sll;
}

CTuongType4::CTuongType4():
    CTuong()
{
    this->name = "Illaoi";
    this->giatri = 1;
    this->skill = "Loi ran khac nghiet";
    this->toc = "Tien cong";
    this->pToc = 2;
    this->he = "Dau si";
    this->pHe = 1;

    BGameX.addTH(this->name, this->pToc, this->pHe);
}

void CTuongType4::init()
{
    CTuong::init();
}

void CTuongType4::out() const
{
    CTuong::out();
}

void CTuongType4::setSTS(int sll)
{
    this->satthuongS = (this->attack + this->defend) * sll / 2.0;
}

istream& operator>>(istream& is, CGame& g)
{
    cin >> g.sltuong >> g.slluot;
    
    g.dst = new CTuong * [g.sltuong];

    for (int i = 0; i < g.sltuong; ++i) {
        int luachon;
        cin >> luachon;
        
        switch (luachon)
        {
        case 1:
            g.dst[i] = new CTuongType1;
            break;

        case 2:
            g.dst[i] = new CTuongType2;
            break;

        case 3:
            g.dst[i] = new CTuongType3;
            break;

        case 4:
            g.dst[i] = new CTuongType4;
            break;

        default:
            break;
        }

        g.dst[i]->init();

    }

    return is;
}

ostream& operator<<(ostream& os, const CGame& g)
{
    for (int i = 0; i < g.sltuong; ++i) {
        g.dst[i]->setSTS(g.slluot);
        g.dst[i]->out();
    }

    return os;
}

CGame::CGame():
    sltuong(0), slluot(0), dst(NULL)
{
}

CGame::~CGame()
{
    if (this->dst != NULL) {
        for (int i = 0; i < this->sltuong; ++i) {
            delete this->dst[i];
        }

        delete this->dst;
    }
}

void CGame::update()
{
    int slTCN = BGameX.getSLCN();
    int slTTC = BGameX.getSLTC();
    int slHDS = BGameX.getSLDS();

    for (int i = 0; i < this->sltuong; ++i) {
        if (this->dst[i]->getToc() == 1) {
            if (slTCN == 2) {
                this->dst[i]->tangAttack(15);
                this->dst[i]->tangDefend(15);
            }
        }
        else {
            if (this->dst[i]->getToc() == 2) {
                if (slTTC == 2) {
                    this->dst[i]->tangAttack(30);
                }
            }
        }

        if (this->dst[i]->getHe() == 1) {
            if (slHDS == 3) {
                this->dst[i]->tangDefend(30);
            }
            else {
                if (slHDS == 2) {
                    this->dst[i]->tangDefend(15);
                }
            }
        }
    }
}

int CGame::getTongGiaTri() const
{
    int Sgiatri = 0;

    for (int i = 0; i < this->sltuong; ++i) {
        Sgiatri += this->dst[i]->getGiaTri();
    }

    return Sgiatri;
}

CBangTocHe::CBangTocHe()
{
    TCongNghe.clear();
    TTienCong.clear();
    HDauSi.clear();
}

CBangTocHe::~CBangTocHe()
{
    if (this->TCongNghe.size()) {
        this->TCongNghe.clear();
    }

    if (this->TTienCong.size()) {
        this->TTienCong.clear();
    }

    if (this->HDauSi.size()) {
        this->HDauSi.clear();
    }
}

void CBangTocHe::addTH(string name, int pT, int pH)
{
    switch (pT)
    {
    case 1:
        TCongNghe.insert(name);
        break;

    case 2:
        TTienCong.insert(name);
        break;

    default:
        break;
    }

    switch (pH)
    {
    case 1:
        HDauSi.insert(name);
        break;

    default:
        break;
    }
}

int CBangTocHe::getSLCN() const
{
    return TCongNghe.size();
}

int CBangTocHe::getSLTC() const
{
    return TTienCong.size();
}

int CBangTocHe::getSLDS() const
{
    return HDauSi.size();
}

//Mateusz Mokot IBM 3B 203713
#include <iostream>
#include <time.h>
using namespace std;

const int WX = 4;
const int WY = 4;
const int pionkiB = 0;
const int pionkiC = 1;
const int puste = -1;
const char pusteP = ' ';
const char IkonkaB = 'b';
const char IkonkaC = 'c';
const char Separator = char(186);
const int A = 'A';

int DcU(int liczba)
{
    if (liczba > 0)
    {
        return 1;
    }
    else if (liczba < 0)
    {

        return -1;
    }
    return 0;
}

struct plansza
{
    int plansza[WY][WX];
    bool CzyjRuch = 0;
    char nazwa1[10];
    char nazwa2[10];
    int ile;
    time_t czas1, czas2;
    pair <int, int> ruch{0,0};
    pair <int, int> ruchprim{0,0};
    pair <pair<int, int>, pair<int, int>> ruchPC;
    
    void STANP() {
        for (int i = 0; i < WY; i++) {
            for (int g = 0; g < WX; g++) {
                plansza[i][g] = puste;
            }
        }
        for (int i = 0; i < WX; i++) {
            plansza[0][i] = pionkiC;
            plansza[3][i] = pionkiB;
        }
    }
    void wczytajnazwy() {

        cout << "podaj nazwy graczy:";
        cin >> nazwa1;
        cin >> nazwa2;
    }
    void wczytajczas()
    {
        float czas;
        cout << " podaj czas";
        cin >> czas;
        czas1 = czas;
        czas2 = czas;
    }
    void rysuj() {
        system("cls");
        int wiersz = 4;
        cout << " " << char(201) << char(205) << char(203) << char(205) << char(203) << char(205) << char(203) << char(205) << char(187) << endl;
        int tab2 = 0;
        for (int i = 0; i < 2 * WY - 1; i++)
        {
            
            if (i%2==0)
            {
                cout << wiersz--;
                int tab1 = 0;
                for (int i = 0; i < 2 * WX + 1; i++)
                {
                    
                    if (i % 2 == 0)
                    {
                        cout << char(186);
                    }
                    else if (plansza[tab2][tab1] == 0)
                    {
                        cout << IkonkaB;
                        tab1++;
                    }
                    else if (plansza[tab2][tab1] == 1)
                    {
                        cout << IkonkaC;
                        tab1++;
                    }
                    else if (plansza[tab2][tab1] == -1)
                    {
                        cout << pusteP;
                        tab1++;
                    }
                }
                cout  << endl;
                tab2++;
            }
            if (i%2==1)
            {
                cout << " " << char(204) << char(205) << char(206) << char(205) << char(206) << char(205) << char(206) << char(205) << char(185) << endl;

            }

        }
        cout <<" " << char(200) << char(205) << char(202) << char(205) << char(202) << char(205) << char(202) << char(205) << char(188) << endl;
        cout << "  A B C D ";
        cout << endl << endl;
        cout << "-----------------------------" << endl;
        cout << "biale-" << nazwa1 << " czas-" << czas1<<endl;
        cout << "czarne-" << nazwa2 << " czas-" << czas2<<endl;
        cout << "----------------------------- " << endl;
    }
    void rysujkoniec() 
    {
        int wiersz = 4;
        cout << " " << char(201) << char(205) << char(203) << char(205) << char(203) << char(205) << char(203) << char(205) << char(187) << endl;
        int tab2 = 0;
        for (int i = 0; i < 2 * WY - 1; i++)
        {

            if (i % 2 == 0)
            {
                cout << wiersz--;
                int tab1 = 0;
                for (int i = 0; i < 2 * WX + 1; i++)
                {

                    if (i % 2 == 0)
                    {
                        cout << char(186);
                    }
                    else if (plansza[tab2][tab1] == 0)
                    {
                        cout << IkonkaB;
                        tab1++;
                    }
                    else if (plansza[tab2][tab1] == 1)
                    {
                        cout << IkonkaC;
                        tab1++;
                    }
                    else if (plansza[tab2][tab1] == -1)
                    {
                        cout << pusteP;
                        tab1++;
                    }

                }
                cout << endl;
                tab2++;
            }
            if (i % 2 == 1)
            {

                cout << " " << char(204) << char(205) << char(206) << char(205) << char(206) << char(205) << char(206) << char(205) << char(185) << endl;

            }

        }
        cout << " " << char(200) << char(205) << char(202) << char(205) << char(202) << char(205) << char(202) << char(205) << char(188) << endl;
        cout << "  A B C D ";
        char znak1 = ruchPC.first.second + 'A';
        char znak2 = ruchPC.second.second + 'A';
        char znak3 = ruch.second + 'A';
        char znak4 = ruchprim.second + 'A';
        cout << endl << endl;
        cout << "-----------------------------" << endl;
        if(CzyjRuch==1)cout << "biale-" << nazwa1 << " " << WX-ruchPC.first.first << znak1 << "-->" << WX-ruchPC.second.first << znak2 << endl;
        if(CzyjRuch == 0)cout << "czarne-" << nazwa2 << "  " << WX-ruch.first << znak3 << "-->" << WX-ruchprim.first << znak4 <<endl;
        cout << "----------------------------- " << endl;
    }

    void CzyjR() {
        if (CzyjRuch == 0) {
            cout << "bialych gracza: " << nazwa1 << " ";
        }
        else {
            cout << "czarnych gracza: " << nazwa2 << " ";
        }
    }
    bool KolorRuchu(int wiersz, int kolumna) {

        return plansza[wiersz][kolumna] == CzyjRuch;
    }
    pair<int, int> wszytajR() {
        int wiersz = -1;
        char kolumna = -1;
        pair <int, int> UNDO = { 10,10 };
        cout << "Ruch ";
        CzyjR();
        cout << "Wybierz pionka (wiersz 1-4, kolumna A-D): ";
        char input[5];
        while (true)
        {

            cin  >> input;

            if (input[0] == 'U' && input[1] == 'N' && input[2] == 'D' && input[3] == 'O' && input[4] == '\0') {
                
                return UNDO;
            }
            if (input[0] >= '1' && input[0] <= '4' && input[1] >= 'A' && input[1] <= 'D' && input[2] == '\0') {
                wiersz = input[0] - '1';
                kolumna = input[1] - 'A';
                wiersz = WX - wiersz - 1;
                if (plansza[wiersz][kolumna]==CzyjRuch)
                {
                    pair <int, int> kordy = { wiersz,kolumna };
                    return kordy;
                }
                cout << " brak pionka";
                continue;

            }

            cout << "zly format danych";
        
        }

    }
    bool CzyWolne(int wiersz, int kolumna, pair<int, int> kordy)
    {
        int docWiersz = wiersz;
        int docKolumna = kolumna;

        if ((abs(kordy.first - docWiersz) == 1 && kordy.second == docKolumna) ||
            (abs(kordy.second - docKolumna) == 1 && kordy.first == docWiersz)) {

            if (plansza[docWiersz][docKolumna] == puste) {
                return true;
            }
            else
            {
                return false;
            }

        }

        return false;
    }
    bool CzyMoznaBic(int wiersz, int kolumna, pair<int, int> kordy) {
        int docWiersz = wiersz;
        int docKolumna = kolumna;
        int vecotrRuchW = DcU(docWiersz - kordy.first);
        int vecotrRuchK = DcU(docKolumna - kordy.second);


        int sasiadW = kordy.first + vecotrRuchW;
        int sasiadK = kordy.second + vecotrRuchK;

        int sasiad2W = kordy.first + 2*vecotrRuchW;
        int sasiad2K = kordy.second + 2*vecotrRuchK;
        if ((wiersz==kordy.first && kolumna != kordy.second) || wiersz != kordy.first && kolumna == kordy.second)
        {

            if (plansza[sasiadW][sasiadK] == CzyjRuch && plansza[docWiersz][docKolumna] == !CzyjRuch && plansza[sasiad2W][sasiad2K] == puste)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    bool SPRAWDZRUCHY(pair<int, int> kordy, pair <int, int> docelowe) {

        int wiersz = docelowe.first;
        char kolumna = docelowe.second;

        if (CzyMoznaBic(wiersz, kolumna, kordy))
        {

            return 1;
        }
        if (CzyWolne(wiersz, kolumna, kordy))
        {
            return 1;
        }

        return 0;

    }
    pair<int,int> Ruch(pair<int, int> kordy) {
        int wiersz = 0;
        char kolumna = 0;
        cout << "Wybierz pole (wiersz 1 - 4, kolumna A - D): ";

        while (true) {
            cin >> wiersz >> kolumna;
            if (cin.fail() || wiersz < 1 || wiersz > 4 || kolumna < A || kolumna > A + 3) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Nieprawidlowe dane Sprobuj ponownie (wiersz 1-4, kolumna A-D): ";
                continue;
            }

            wiersz -= 1;
            kolumna -= 'A';
            wiersz = WX - wiersz - 1;
            if (CzyMoznaBic(wiersz, kolumna, kordy))
            {
                plansza[kordy.first][kordy.second] = -1;
                plansza[wiersz][kolumna] = CzyjRuch;
                CzyjRuch = !CzyjRuch;
                rysuj();
                pair <int, int> kordyP{wiersz, kolumna} ;
                return kordyP;

            }

            if (CzyWolne(wiersz, kolumna, kordy)) {
                plansza[kordy.first][kordy.second] = -1;
                plansza[wiersz][kolumna] = CzyjRuch;
                CzyjRuch = !CzyjRuch;
                rysuj();
                pair <int, int> kordyP{ wiersz, kolumna };
                return kordyP;
            }
            else {
                cout << "Zly ruch, podaj inny: ";
            }

        }
    }
    bool Czywygrana()
    {
        int B = 0;
        int C = 0;

        for (int i = 0; i < 4; i++)
        {

            for (int g = 0; g < 4; g++)
            {
                if (plansza[i][g] == 0)
                {
                    B++;
                }
                if (plansza[i][g] == 1)
                {
                    C++;
                }
            }
        }

        if (B == 0)
        {
            cout << "wygraly czarne";
            return true;
        }
        if (C == 0)
        {
            cout << "wygraly biala";
            return true;
        }
        return false;

    }
    bool Czywygrana2()
    {

        for (int i = 0; i < 4; i++)
        {
            for (int g = 0; g < 4; g++)
            {

                for (int c = 0; c < 4; c++)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        if (plansza[i][g] == CzyjRuch)
                        {
                            pair <int, int> kordy = { i,g };
                            pair <int, int> kordyD = { c,d };
                            if (SPRAWDZRUCHY(kordy, kordyD))
                            {

                                return false;
                            }

                        }
                    }
                }

            }
        }
        if (CzyjRuch == 1)
        {
            return true;
            cout << " wygrały białe";
        }
        if (CzyjRuch == 0)
        {
            return true;
            cout << " wygrały czarne";
        }

    }

    bool czywygrana3()
    {
        if (czas1<0)
        {
            cout << "koniec czasu, wygrana czarnych" << endl;
           return true;
        }
        if (czas2<0)
        {
            cout << "koniec czasu, wygrana białych" << endl;
                return true;
        }
        return false;

    }

    pair <pair <int,int> ,pair <int,int>> RuchKom()
    {
        time_t start, koniec;
        time(&start);
        for (int i = 0; i < 4; i++)
        {
            for (int g = 0; g < 4; g++)
            {
                for (int c = 0; c < 4; c++)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        pair<int, int> L1{ i,g };
 
                            if (CzyMoznaBic(d, c, L1) && plansza[i][g] == CzyjRuch)
                            {
                                plansza[L1.first][L1.second] = -1;
                                plansza[d][c] = CzyjRuch;
                                CzyjRuch = !CzyjRuch;
                                rysuj();
                                pair <pair <int, int>, pair<int, int>> kordy;
                                kordy.first.first = i;
                                kordy.first.second = g;
                                kordy.second.first = d;
                                kordy.second.second = c;
                                time(&koniec);

                                czas1 = czas1-difftime(koniec, start)-0.1;
                                return kordy;
                            }
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int g = 0; g < 4; g++)
            {
                for (int c = 0; c < 4; c++)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        pair<int, int> L1{ i,g };
                        if (CzyWolne(d, c, L1) && plansza[i][g] == CzyjRuch && plansza[d][c]!=CzyjRuch) {
                            plansza[L1.first][L1.second] = -1;
                            plansza[d][c] = CzyjRuch;
                            CzyjRuch = !CzyjRuch;
                            rysuj();
                            pair <pair <int, int>, pair<int, int>> kordy;
                            kordy.first.first = i;
                            kordy.first.second = g;
                            kordy.second.first = d;
                            kordy.second.second = c;
                            time(&koniec);
                            czas1 = czas1- difftime(koniec, start)-0.1;
                            return kordy;

                        }

                    }
                }
            }
        }
    }

    
            
    

};




int main()
{
    plansza glowna;
    glowna.STANP();
    glowna.wczytajnazwy();
    glowna.wczytajczas();
    plansza RUCHY[1000];
    int tura=1;
    RUCHY[0] = glowna;
    int LICZU=0;
    while (true) {
        

        if (glowna.Czywygrana() || glowna.Czywygrana2() || glowna.czywygrana3())
        {

            system("cls");
            glowna.czywygrana3();
            for (int i = 0; i < tura; i++)
            {
                RUCHY[i].rysujkoniec();
            }

            break;
        }
        
        glowna.rysuj();
        pair<int, int> UNDO{ 10,10 };
        glowna.ruchPC = glowna.RuchKom();
        RUCHY[tura] = glowna;
        tura++;

        time_t koniec, start;
        time(&start);
        glowna.ruch = glowna.wszytajR();
        if (glowna.ruch==UNDO)
        {
            
            if (tura-3>=0 && LICZU<4)
            {
                LICZU++;
                
                glowna = RUCHY[tura - 4];
                tura-=3;
                continue;
            }
            else
            {
                cout << "juz nie cofniesz";
            }
            if (LICZU==4)
            {
                cout << "juz nie cofniesz";
                while (glowna.ruch==UNDO)
                {
                    glowna.ruch=glowna.wszytajR();
                }
            }

       
        }
        glowna.ruchprim = glowna.Ruch(glowna.ruch);
        time(&koniec);
        glowna.czas2 = glowna.czas2 - difftime(koniec, start);
        RUCHY[tura] = glowna;
        tura++;


        if (LICZU!=0)
        {
            LICZU--;
        }
        
    }

    

    return 0;
}
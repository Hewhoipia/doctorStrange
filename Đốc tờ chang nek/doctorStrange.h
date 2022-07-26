//The library here is concretely set, students are not allowed to include any other libraries.
// array, link list (important), nullptr, dynamic array, xem lai li thuyet nha brooo
#ifndef doctorStrange_h
#define doctorStrange_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void upLevelsAndHP(int& hp, int& lv, int& exp, int& maxHP) {
    while (exp >= 100) {
        exp = exp - 100;
        lv++;
        maxHP += 50;
        hp += 10;
    }
    if (hp >= maxHP) {
        hp = maxHP;
    }
    if (maxHP >= 999) {
        maxHP = 999;
        if (hp >= 999) {
            hp = 999;
        }
    }
}

void event1To5(int& hp, int& lv, int& exp, int& ts, int& n, int& maxHP, int& numOfn, bool& livitation, float& Gy, int& liviTimes, bool& wong, bool& fakeWong,bool& wongHelp,bool& wongHarm) {
    int b = numOfn % 10;
    int lvo = numOfn > 6 ? (b > 5 ? b : 5) : b;
    if (lv > lvo && fakeWong==0) {
        if (n == 1) {
            exp += 10;
        }
        if (n == 2) {
            exp += 20;
        }
        if (n == 3) {
            exp += 40;
        }
        if (n == 4) {
            exp += 50;
        }
        if (n == 5) {
            exp += 70;
        }
    }
    else if (wong == 1) {
        wongHelp = 1;
        if (n == 1) {
            exp += 10;
        }
        if (n == 2) {
            exp += 20;
        }
        if (n == 3) {
            exp += 40;
        }
        if (n == 4) {
            exp += 50;
        }
        if (n == 5) {
            exp += 70;
        }
    }
    if (lv == lvo && wong==0 && fakeWong==0) {
        if (n == 1) {
            exp += 5;
        }
        if (n == 2) {
            exp += 10;
        }
        if (n == 3) {
            exp += 20;
        }
        if (n == 4) {
            exp += 25;
        }
        if (n == 5) {
            exp += 35;
        }
    }
    if (lv < lvo && wong==0) {
        if (n == 1) {
            if (livitation || liviTimes>0) {
                hp -= (1.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 1.5 * lvo * 10;
        }
        if (n == 2) {
            if (livitation || liviTimes > 0) {
                hp -= (2.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 2.5 * lvo * 10;
        }
        if (n == 3) {
            if (livitation || liviTimes > 0) {
                hp -= (4.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 4.5 * lvo * 10;
        }
        if (n == 4) {
            if (livitation || liviTimes > 0) {
                hp -= (7.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 7.5 * lvo * 10;
        }
        if (n == 5) {
            if (livitation || liviTimes > 0) {
                hp -= (9.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 9.5 * lvo * 10;
        }
    }
    else if (fakeWong == 1) {
        wongHarm = 1;
        if (n == 1) {
            if (livitation || liviTimes > 0) {
                hp -= (1.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 1.5 * lvo * 10;
        }
        if (n == 2) {
            if (livitation || liviTimes > 0) {
                hp -= (2.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 2.5 * lvo * 10;
        }
        if (n == 3) {
            if (livitation || liviTimes > 0) {
                hp -= (4.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 4.5 * lvo * 10;
        }
        if (n == 4) {
            if (livitation || liviTimes > 0) {
                hp -= (7.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 7.5 * lvo * 10;
        }
        if (n == 5) {
            if (livitation || liviTimes > 0) {
                hp -= (9.5 * lvo * 10) * (100 - Gy) / 100;
                liviTimes--;
            }
            else hp -= 9.5 * lvo * 10;
        }
    }
}

void event6(int& hp, int& lv, int& exp, int& ts, int& maxHP, int& numOfn, int& atk, int& def, string& thanchu, bool& livitation, float& Gy, int& liviTimes) {
    int Fx, x = thanchu.size()-1, winRate, bloodLoss;
    Fx = (numOfn + x) % 100;
    if (!livitation) {
        winRate = atk * 10;
        bloodLoss = def * 10;
    }
    else {
        winRate = atk * 10+Gy;
        bloodLoss = def * 10+Gy;
        liviTimes -- ;
    }
    if (winRate > Fx) {
        exp += 200;
        ts++;
        upLevelsAndHP(hp, lv, exp, maxHP);
    }
    else {
        if (hp < 100) {
            hp = 0;
        }
        else hp = hp - hp * (100 - bloodLoss) / 100;
    }
}

void readFileEvent6 (string& thanchu, int& atk, int& def) {
    //attack
    for (int a = 0; a < thanchu.size(); a++) { //a and A
        if (thanchu[a] == 'a' || thanchu[a] == 'A') {
            for (int b = a + 1; b < thanchu.size(); b++) { //t and T
                if (thanchu[b] == 't' || thanchu[b] == 'T') {
                    for (int c = b + 1; c < thanchu.size(); c++) { //t and T
                        if (thanchu[c] == 't' || thanchu[c] == 'T') {
                            for (int d = c + 1; d < thanchu.size(); d++) { //a and A
                                if (thanchu[d] == 'a' || thanchu[c] == 'A') {
                                    for (int e = d + 1; e < thanchu.size(); e++) { //c and C
                                        if (thanchu[e] == 'c' || thanchu[e] == 'C') {
                                            for (int f = e + 1; f < thanchu.size(); f++) { //k and K
                                                if (thanchu[f] == 'k' || thanchu[f] == 'K') {
                                                    atk++;
                                                }
                                                else if (thanchu[f] == '#' || thanchu[f] == '!') {
                                                    break;
                                                }
                                            }
                                        }
                                        else if (thanchu[e] == '#' || thanchu[e] == '!') {
                                            break;
                                        }
                                    }
                                }
                                else if (thanchu[d] == '#' || thanchu[d] == '!') {
                                    break;
                                }
                            }
                        }
                        else if (thanchu[c] == '#' || thanchu[c] == '!') {
                            break;
                        }
                    }
                }
                else if (thanchu[b] == '#' || thanchu[b] == '!') {
                    break;
                }
            }
        }
        else if (thanchu[a] == '#' || thanchu[a] == '!') {
            break;
        }
    }
    //defense
    for (int a = 0; a < thanchu.size(); a++) { //d and D
        if (thanchu[a] == 'd' || thanchu[a] == 'D') {
            for (int b = a + 1; b < thanchu.size(); b++) { //e and E
                if (thanchu[b] == 'e' || thanchu[b] == 'E') {
                    for (int c = b + 1; c < thanchu.size(); c++) { //f and F
                        if (thanchu[c] == 'f' || thanchu[c] == 'F') {
                            for (int d = c + 1; d < thanchu.size(); d++) { //e and E
                                if (thanchu[d] == 'e' || thanchu[c] == 'E') {
                                    for (int e = d + 1; e < thanchu.size(); e++) { //n and N
                                        if (thanchu[e] == 'n' || thanchu[e] == 'N') {
                                            for (int f = e + 1; f < thanchu.size(); f++) { //s and S
                                                if (thanchu[f] == 's' || thanchu[f] == 'S') {
                                                    for (int g = f + 1; g < thanchu.size(); g++) { //e and E
                                                        if (thanchu[g] == 'e' || thanchu[g] == 'E') {
                                                            def++;
                                                        }
                                                        else if (thanchu[g] == '#' || thanchu[g] == '!') {
                                                            break;
                                                        }
                                                    }
                                                }
                                                else if (thanchu[f] == '#' || thanchu[f] == '!') {
                                                    break;
                                                }
                                            }
                                        }
                                        else if (thanchu[e] == '#' || thanchu[e] == '!') {
                                            break;
                                        }
                                    }
                                }
                                else if (thanchu[d] == '#' || thanchu[d] == '!') {
                                    break;
                                }
                            }
                        }
                        else if (thanchu[c] == '#' || thanchu[c] == '!') {
                            break;
                        }
                    }
                }
                else if (thanchu[b] == '#' || thanchu[b] == '!') {
                    break;
                }
            }
        }
        else if (thanchu[a] == '#' || thanchu[a] == '!') {
            break;
        }
    }
}

void event7(int& hp,int& numOfn, float& Gy) {
    int y;
    int a = 2;
    for (y=hp; y < 999; y++) {
        a = 2;
        while (y % a != 0) {
            a++;
        }
        if (a > sqrt(y)) {
            break;
        }
    }
    Gy = (numOfn + y) % 100;

}

void livitationCheck(int& lv,bool& livitation, int& liviTimes) {
    if (livitation) {
        if (liviTimes == 0 && lv > 2) {
            lv -= 2;
            livitation = 0;
        }
        else if (liviTimes == 0 && lv < 3) {
            lv = 1;
            livitation = 0;
        }
    }
}

void event8(int& n,int& lv, bool& wong, bool& fakeWong, int& wongTimes, int& fakeWongTimes, bool& KT) {
    if (wong == 1) {
        fakeWong = 0;
        wongTimes--;
    }
    else if (wong == 0 && KT == 0) {
        wong = 1;
    }
    else if (wong == 0 && KT == 1) {
        if (fakeWong) {
            fakeWongTimes--;
        }
        fakeWong = 1;
        if (fakeWong == 1 && lv >= 7) {
            fakeWong = 0;
            fakeWongTimes = 3;
        }
    }
    // if event 13 and event 14 then {fakeWong=0; fakeWongTimes=3;
}

void event8Check(int& n,int& lv, bool& wong,bool& fakeWong,bool& wongHelp, bool& wongHarm,int& wongTimes,int& fakeWongTimes, bool& KT, bool& livitation,bool& fakeLivi, bool& poison, bool& poisonWong) {
    if (wong) {
        if (poison && poisonWong) {
            poison = 0;
            wongTimes--;
        }
        if (wongHelp) {
            wongTimes--;
            wongHelp = 0;
        }
    }
    if (fakeWong) {
        if (poison && poisonWong) {
            fakeWongTimes--;
        }
        if (wongHarm) {
            fakeWongTimes--;
            wongHarm = 0;
        }
        if (livitation) {
            if (lv > 2) {
                lv -= 2;
                livitation = 0;
            }
            else if (lv < 3) {
                lv = 1;
                livitation = 0;
            }
            fakeLivi = 1;
            livitation = 0;
            fakeWongTimes--;
        }
    }
    if (wongTimes == 0) {
        KT = 1;
        wong = 0;
    }
    if (fakeWongTimes == 0) {
        fakeWong = 0;
        fakeWongTimes = 3;
    }
}

void event9(bool& poison, int& lv, int& inilv, bool& CPpoison,bool& fakeWong, int& fakeWongTimes, bool& fakeLivi, bool& livitation) {
        if (poison) {
            CPpoison = 1;
            lv += inilv;
            poison = 0;
            inilv = 0;
        }
        if (fakeWong) {
            fakeWong = 0;
            fakeWongTimes = 3;
        }
        if (fakeLivi) {
            fakeLivi = 0;
            livitation = 1;
            if (lv <= 10) {
                lv = lv + 2;
            }
        }
}

void event10(int& hp, int& maxHP) {
    int x1 = 0, x2 = 1, fibo = 0;
    while (fibo < hp) {
        x1 = x2;
        x2 = fibo;
        fibo = x1 + x2;
    }
    hp += x2;
    if (hp > maxHP) {
        hp = maxHP;
    }
}

void event11(int& hp, int& lv,bool& poison, int &poisonTimes,int& inilv, bool& CPpoison) {
    if (poisonTimes > 0 && poison) {
        hp -= 50;
        if (poisonTimes==3 || CPpoison) {
            if (lv == 2) {
                lv = 1;
                inilv = 1;
            }
            else if (lv == 1) {
                lv = 1;
                inilv = 0;
            }
            else if (lv > 2) {
                lv -= 2;
                inilv = 2;
            }
            CPpoison = 0;
        }
    }
}

void event11Check(bool& poison, int& poisonTimes, int& lv, int& inilv) {
    if (poison) {
        if (poisonTimes == 0) {
            lv += inilv;
            poison = 0;
            poisonTimes--;
        }
    }
}

void dead(int& n, int& lv, int& inilv, bool& poison, bool& poisonWong, bool& fakeWong, int& fakeWongTimes, bool& livitation) {
    if (((n >= 1 && n <= 5) || poisonWong == 1) && fakeWong == 1) {
        fakeWong = 0;
        fakeWongTimes = 3;
    }
    if (poison) {
        lv += inilv;
        poison = 0;
    }
    if (livitation && lv > 2) {
        lv -= 2;
        livitation = 0;
    }
    else if (livitation && lv < 3) {
        lv = 1;
        livitation = 0;
    }
}

void event12(string& DM1, string& DM2, bool& wandaKill, int& hp, int& maxHP, int& exp,int& ts, bool& blockLivi) {
    string codingString = DM1;
    string leftStr, rightStr;
    int a, ith;
    if (DM1.size() % 2 == 0) {
        a = (DM1.size() / 2) - 1;
        leftStr = DM1.substr(0, a+1);
        rightStr = DM1.substr(a + 1, a + 1);
    }
    else {
        a = (DM1.size() / 2);
        leftStr = DM1.substr(0, a);
        rightStr = DM1.substr(a + 1, a);
    }
    int x = leftStr.size() - 1;
    int y = rightStr.size() - 1;
    for (int i = 0; i < leftStr.size() / 2; i++) {
        int contain = 0;
        contain = leftStr[i];
        leftStr[i] = leftStr[x- i];
        leftStr[x-i] = contain;
    }
    for (int i = 0; i < rightStr.size() / 2; i++) {
        int contain = 0;
        contain = rightStr[i];
        rightStr[i] = rightStr[y - i];
        rightStr[y-i] = contain;
    }
    //chuỗi mã hoá
    if (codingString.size() % 2 == 0) {
        int j = 0;
        for (int i = 0; i <= a; i++) {
            codingString[i] = leftStr[i];
        }
        for (int i = a + 1; i < codingString.size(); i++) {
            codingString[i] = rightStr[j];
            j++;
        }
    }
    else {
        int j = 0;
        for (int i = 0; i < a; i++) {
            codingString[i] = leftStr[i];
        }
        for (int i = a + 1; i < codingString.size(); i++) {
            codingString[i] = rightStr[j];
            j++;
        }
    }
    ith = DM2.size() % 10;
    for (int i = 0; i < codingString.size(); i++) {
        codingString[i] +=ith;
        if (codingString[i] > 122 && codingString[i]<126) {
            codingString[i] = codingString[i] - 122 + 96;
        }
        else if (codingString[i] > 90 && codingString[i]<94) {
            codingString[i] = codingString[i] - 90 + 64;
        }
    }
    for (int i = 0; i <= codingString.size()-DM2.size(); i++) {
        for (int j = 0; j < DM2.size(); j++) {
            if (DM2[j] == codingString[i+j]) {
                wandaKill = 1;
            }
            else {
                wandaKill = 0;
                break;
            }
        }
        if (wandaKill) {
            break;
        }
    }
    if (wandaKill) {
        hp -=hp*0.1;
        maxHP -=maxHP*0.1;
        exp += 30;
    }
    else {
        blockLivi = 1;
        ts = 0;
        exp += 15;
    }
}

bool timeStone=0; //=1 when meet event 15
int numOfnTravel=0; // number of event T travels to
int maxhp=0; //max hp through events until meet event 15

int handleEvents(string & HP, string & LV, string & EXP, string & TS, string & events) {
    ///Students have to complete this function and DO NOT modify any parameters in this function.
    int result = 0;
    int n, m; //n is a event (1-9), m is number after n (0-5)
    int numOfn = 0; //số lượng của sự kiện, sự kiện thứ numOfn
    int hp = stoi(HP);
    int lv = stoi(LV);
    int exp = stoi(EXP);
    int ts = stoi(TS); //0-5 stone
    int maxHP = hp;
    //event7:
    int liviTimes;
    bool livitation=false;
    float Gy = 0;
    //event8:
    bool wong = 0, fakeWong = 0, wongHelp = 0, wongHarm = 0, KT = 0, fakeLivi=0; //KT=1 when Wong return to Kamar-Taj
    int wongTimes = 3,fakeWongTimes=3;
    //event9:
    bool CPpoison = 0; // CPpoison mean that after get poison and meet CP, Strange may get poison again but poisonTimes can not be 3 at this time
    //event11:
    int poisonTimes=3;
    bool poison = 0, poisonWong = 0; //poisonWong = 1 when event8 affect after get poison
    int inilv=0; //lv is decresed when get poison
    //event12:
    string DM1, DM2;
    bool wandaKill = 0;
    bool blockLivi = 0;
    //event15
    for (int i = 0; i < events.size(); i++) {
        if (events[i] == '#' || events[i] == '!') {
            continue;
        }
        else {
            n = (int)events[i] - 48;
            m = (int)events[i + 1] - 48;
            numOfn++;
            //events 1 to 5 and 10 to 15
            if (n >= 1 && n <= 5) {
                if (n == 1 && m <= 5 && m >= 0) {
                    //event 10
                    if (m == 0) {
                        n += 9;
                        event10(hp, maxHP);
                        i++;
                    }

                    //event11
                    if (m == 1) {
                        n += 10;
                        poison = 1;
                        poisonWong = 1;
                        event8Check(n, lv, wong, fakeWong, wongHelp, wongHarm, wongTimes, fakeWongTimes, KT, livitation, fakeLivi, poison, poisonWong);
                        event11(hp, lv,poison, poisonTimes, inilv,CPpoison);
                        i++;
                    }

                    //event12
                    if (m == 2) {
                        n += 11;
                        int endDM1 = 0, endDM2=0;
                        for (int j = i + 3; j < events.size(); j++) {
                            endDM1 += 1;
                            if (events[j] == ' ') {
                                DM1 = events.substr(i + 3, endDM1 - 1);
                                for (int k = j + 1; k < events.size(); k++) {
                                    endDM2 += 1;
                                    if (events[k] == '#' || events[k] == '!') {
                                        DM2 = events.substr(j+1, endDM2 - 1);
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        event12(DM1, DM2, wandaKill, hp, maxHP, exp, ts, blockLivi);
                        i = i + 2 + endDM1 + endDM2;
                    }

                    //event13
                    if (m == 3) {
                        n += 12;

                        i++;
                    }

                    //event14
                    if (m == 4) {
                        n += 13;
                        i++;
                    }

                    //event15
                    if (m == 5 && timeStone==0) {
                        n += 14;
                        timeStone=1;
                        cout << "time travel!!"<endl; //add
                        return int handleEvents(HP,LV, EXP, TS, events);
                    }
                    else {
                        n += 14;
                        i++1;
                    }
                }
                else {
                    event11Check(poison, poisonTimes, lv, inilv);
                    event7(hp, numOfn, Gy);
                    event1To5(hp, lv, exp, ts, n, maxHP, numOfn, livitation, Gy, liviTimes, wong, fakeWong, wongHelp,wongHarm);
                    livitationCheck(lv, livitation, liviTimes);
                    event8Check(n, lv, wong, fakeWong, wongHelp, wongHarm, wongTimes, fakeWongTimes, KT, livitation, fakeLivi, poison, poisonWong);
                }
            }
            //event 6
            if (n == 6) {
                int atk=0, def=0;
                int endTC=0;
                for (int j = i + 2; j < events.size(); j++) {
                    endTC += 1;
                    if (events[j] == '#' || events[j] == '!') {
                        break;
                    }
                }
                string thanchu=events.substr(i+2,endTC-1); //Thần chú
                i = i + 1 + endTC;
                event11Check(poison, poisonTimes, lv, inilv);
                event7(hp, numOfn, Gy);
                readFileEvent6(thanchu, atk, def);
                event6(hp, lv, exp, ts, maxHP, numOfn, atk, def, thanchu, livitation, Gy, liviTimes);
                livitationCheck(lv, livitation, liviTimes);
            }

            //event 7
            if (n == 7 && blockLivi==0) {
                livitation = true;
                if (lv <= 10) {
                    lv = lv + 2;
                }
                if (fakeLivi) {
                    fakeLivi = 0;
                    fakeWong = 0;
                    fakeWongTimes = 3;
                }
                event8Check(n, lv, wong, fakeWong, wongHelp, wongHarm, wongTimes, fakeWongTimes, KT, livitation, fakeLivi, poison, poisonWong);
            }

            //event 8
            if (n == 8) {
                event8(n, lv, wong, fakeWong, wongTimes, fakeWongTimes, KT);
                event8Check(n, lv, wong, fakeWong, wongHelp, wongHarm, wongTimes, fakeWongTimes, KT, livitation, fakeLivi, poison, poisonWong);
            }

            //event 9
            if (n == 9) {
                hp = maxHP;
                event9(poison, lv, inilv, CPpoison, fakeWong, fakeWongTimes, fakeLivi, livitation);
            }
            //dead
            if (hp <= 0) {
                if (ts > 0) {
                    ts--;
                    hp = maxHP;
                }
                else {
                    result = -1;
                    break;
                }
                dead(n, lv, inilv, poison, poisonWong, fakeWong, fakeWongTimes, livitation);
            }
            else result = hp + lv + exp + ts;
            poisonWong = 0;
            upLevelsAndHP(hp, lv, exp, maxHP);
        }
        cout <<"event:" << n << " " << "numOfn:" << numOfn << endl; // add
        cout << hp << " " << lv << " " << exp << " " << ts << endl; //add
    }
    result = hp + lv + exp + ts;
    cout << endl << "result nek" << endl; // add
    cout << hp << " " << lv << " " << exp << " " << ts << endl;
    cout << events << endl;
    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */

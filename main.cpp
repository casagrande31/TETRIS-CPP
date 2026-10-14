#include <iostream>
#include <vector>
#include <conio.h>
#include <chrono>
#include <windows.h>
using namespace std;

const int LARGURA = 10;
const int ALTURA = 20;

int campo[ALTURA][LARGURA] = {0};

vector<vector<vector<int>>> pecas = {
    {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
    {{1,1},{1,1}},
    {{0,1,0},{1,1,1},{0,0,0}},
    {{1,0,0},{1,1,1},{0,0,0}},
    {{0,0,1},{1,1,1},{0,0,0}},
    {{1,1,0},{0,1,1},{0,0,0}},
    {{0,1,1},{1,1,0},{0,0,0}}
};

int p, px, py, rot;

vector<vector<int>> getRotacao(int id, int r) {
    vector<vector<int>> m = pecas[id];
    for(int k=0;k<r;k++){
        vector<vector<int>> t(m[0].size(), vector<int>(m.size()));
        for(unsigned i=0;i<m.size();i++)
            for(unsigned j=0;j<m[0].size();j++)
                t[j][m.size()-1-i] = m[i][j];
        m = t;
    }
    return m;
}

bool colide(int nx, int ny, int r) {
    auto m = getRotacao(p, r);
    for(unsigned i=0;i<m.size();i++){
        for(unsigned j=0;j<m[0].size();j++){
            if(m[i][j]){
                if(nx+j < 0 || nx+j >= LARGURA) return true;
                if(ny+i >= ALTURA) return true;
                if(ny+i >= 0 && campo[ny+i][nx+j]) return true;
            }
        }
    }
    return false;
}

void fixar() {
    auto m = getRotacao(p, rot);
    for(unsigned i=0;i<m.size();i++)
        for(unsigned j=0;j<m[0].size();j++)
            if(m[i][j])
                campo[py+i][px+j] = 1;
}

void removeLinhas() {
    for(int i = ALTURA-1; i >= 0; i--) {
        bool ok = true;
        for(int j=0;j<LARGURA;j++)
            if(campo[i][j] == 0) ok = false;

        if(ok) {
            for(int k=i; k>0; k--)
                for(int j=0;j<LARGURA;j++)
                    campo[k][j] = campo[k-1][j];

            for(int j=0;j<LARGURA;j++)
                campo[0][j] = 0;

            i++;
        }
    }
}

void novaPeca() {
    p = rand() % pecas.size();
    px = 3;
    py = 0;
    rot = 0;
}

int main() {
    srand(time(NULL));
    novaPeca();
    auto ultimo = chrono::steady_clock::now();

    while(true) {
        if(_kbhit()) {
            char c = _getch();
            if(c=='q') break;
            if(c=='a') if(!colide(px-1, py, rot)) px--;
            if(c=='d') if(!colide(px+1, py, rot)) px++;
            if(c=='s') if(!colide(px, py+1, rot)) py++;
            if(c=='w'){ int nr=(rot+1)%4; if(!colide(px, py, nr)) rot=nr; }
            if(c==32) while(!colide(px, py+1, rot)) py++;
        }

        auto agora = chrono::steady_clock::now();
        if(chrono::duration_cast<chrono::milliseconds>(agora - ultimo).count() > 300) {
            if(!colide(px, py+1, rot)) py++;
            else {
                fixar();
                removeLinhas();
                novaPeca();
                if(colide(px, py, rot)) {
                    cout << "GAME OVER\n";
                    break;
                }
            }
            ultimo = agora;
        }

        int temp[ALTURA][LARGURA];
        for(int i=0;i<ALTURA;i++)
            for(int j=0;j<LARGURA;j++)
                temp[i][j] = campo[i][j];

        auto m = getRotacao(p, rot);
        for(unsigned i=0;i<m.size();i++)
            for(unsigned j=0;j<m[0].size();j++)
                if(m[i][j] && py+i>=0 && py+i<ALTURA)
                    temp[py+i][px+j] = 1;

        system("cls");
        for(int i=0;i<ALTURA;i++){
            for(int j=0;j<LARGURA;j++)
                cout << (temp[i][j] ? "#" : ".");
            cout << "\n";
        }
        cout << "A/D mover | W girar | S descer | ESPACO drop | Q sair\n";

        Sleep(30);
    }
}

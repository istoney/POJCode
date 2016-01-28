/*
*     File Namw: 2632 - Crashing Robots.cpp
*/

#include<cstdio>
#include<iostream>
using namespace std;

#define MAX_N 100

int warehouse[MAX_N][MAX_N];
struct robot{
    robot(){}
    robot(int x, int y, int d):x(x),y(y),drc(d){}
    int x, y, drc;
} Robots[MAX_N];

int getDrc(char d){
    switch (d) {
        case 'N': return 0;break;
        case 'E': return 1;break;
        case 'S': return 2;break;
        case 'W': return 3;break;
    }
}

bool move(int r, char m, int re){
    switch (m) {
    case 'L':
        re = re%4;
        Robots[r].drc -= re;
        break;
    case 'R':
        re = re%4;
        Robots[r].drc += re;
        break;
    case 'F':
        robot tmp = Robots[r];
        switch (tmp.drc) {
            case 0: tmp.y += re;break;
            case 1: tmp.x += re;break;
            case 2: tmp.y -= re;break;
            case 3: tmp.x -= re;break;
        }
        if(tmp.x)
    }
}

int main(){
    int K, A, B, N, M;
    scanf("%d", &K);
    while(K--){
        scanf("%d %d\n%d %d", &A, &B, &N, &M);
        int x, y;
        char d;
        for(int i=0;i<N;i++){
            scanf("%d %d %c", &x, &y, &d);
            Robots[i] = robot(--x, --y, getDrc(d));
            warehouse[x][y] = i;
        }

        for(int i=0;i<M;i++){
            scanf("%d %c %d\n", &x, &d, &y);

        }
    }
    return 0;
}

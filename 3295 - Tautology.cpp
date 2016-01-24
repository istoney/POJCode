/*
 ======================================================================================
 *      File Name: 3295 - RoadBlocks.cpp
 *    Description: http://poj.org/problem?id=3295
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-24 21:36:44
 *       Compiler: c++
 *       Run Time: 16MS
 *         Memory: 188K
 *      Solutions: 1.采用构造真值表的方式判断WWF是否为重言式（永真式）[1]
 *                 2.WWF字符串呈现树形结构，因此采用倒序将变量压栈的方式进行运算
 *                 参考：[1]https://raw.githubusercontent.com/istoney/poj_code/master/res/3295.png
 ======================================================================================
 */
#include<cstdio>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

#define N 5
#define P 32
#define M 200

//数组声明中只能用常数，或常数变量
//真值表，对每个出现的WFF构建真值表
bool table[32][M];    //p, q, r, s, t

void init(){
    for(int c=0;c<N;c++){
        int p = pow(2.0,N-c-1);   //pow用于求方
        bool v = 1;

        for(int r=0;r<pow(2.0,N);r++){
            if(r%p==0) v = !v;
            table[r][c] = v;
        }
    }
}

int main(){
    init();
    char str_[200];
    //scanf不能将读入的字符串放入string
    while(scanf("%s", str_)!=EOF && strcmp(str_, "0")!=0){
        string str = str_;
        stack<int> S;
        int l = N;
        for(int i=str.length();i>=0;i--){
            char tmp = str[i];
            if('p'<=tmp && tmp<='t'){
                S.push(tmp - 'p');
            }
            else {
                int ch1, ch2;
                switch (tmp) {
                case 'K': //and
                    ch1 = S.top();S.pop();
                    ch2 = S.top();S.pop();
                    for(int j=0;j<pow(2.0,N);j++){
                        table[j][l] = table[j][ch1] && table[j][ch2];
                    }
                    S.push(l++);
                    break;
                case 'A': //or
                    ch1 = S.top();S.pop();
                    ch2 = S.top();S.pop();
                    for(int j=0;j<pow(2.0,N);j++){
                        table[j][l] = table[j][ch1] || table[j][ch2];
                    }
                    S.push(l++);
                    break;
                case 'N': //not
                    ch1 =  S.top();S.pop();
                    for(int j=0;j<pow(2.0,N);j++){
                        table[j][l] = !table[j][ch1];
                    }
                    S.push(l++);
                    break;
                case 'C': //implies
                    ch1 = S.top();S.pop();
                    ch2 = S.top();S.pop();
                    for(int j=0;j<pow(2.0,N);j++){
                        table[j][l] = !table[j][ch1] || table[j][ch2];
                    }
                    S.push(l++);
                    break;
                case 'E': //equal
                    ch1 = S.top();S.pop();
                    ch2 = S.top();S.pop();
                    for(int j=0;j<pow(2.0,N);j++){
                        table[j][l] = table[j][ch1] == table[j][ch2];
                    }
                    S.push(l++);
                    break;
                default: break;
                }
            }
        }

        int ch = S.top();S.pop();
        bool f = true;
        for(int j=0;f && j<pow(2.0,N);j++){
            if(!table[j][ch]) f = false;
        }
        if(f) puts("tautology");
        else puts("not");
    }
    return 0;
}

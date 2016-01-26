/*
 ======================================================================================
 *      File Name: 1086 - RoadBlocks.cpp
 *    Description: http://poj.org/problem?id=1086
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-26 16:48:54
 *       Compiler: c++
 *       Run Time: 16MS
 *         Memory: 168K
 *      Solutions: 1.通过stack还原构造parentheses字符串
 *                 2.采用两个栈构造W串：parS，存储parentheses字符串，最后的字符在顶部
 *                   countS，计数器栈，对每一个')'push一个计数器，记录其wi值，每次pop时，将计数器值加在栈顶的计数器上
 ======================================================================================
 */

#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

#define MAX_N 20

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        //get in and construct parenthesis string
        scanf("%d", &n);
        stack<char> parS;
        int l1=0, l2=0;
        while(n--){
            scanf("%d", &l2);
            for(int i=0;i<l2-l1;i++) parS.push('(');
            parS.push(')');
            l1 = l2;
        }

        //re-encoding
        stack<pair<int, int> > countS;  //count & index, index用于记录')'的位置
        int list[MAX_N];
        int index = 0;
        while(!parS.empty()){
            char ch = parS.top();parS.pop();
            if(ch==')'){
                countS.push(make_pair(1, index++));
            }
            else {
                pair<int, int> p = countS.top();countS.pop();
                list[p.second] = p.first;
                if(!countS.empty()){    //如果栈内还有')'，将计数器值加在栈顶计数器上
                    pair<int, int> p2 = countS.top();countS.pop();
                    p2.first += p.first;
                    countS.push(p2);
                }
            }
        }
        while(index) printf("%d ", list[--index]);
        puts("");
    }
}

/*
 ===============================================================================================
 *      File Name: 2856 - Conscription.cpp
 *    Description: http://poj.org/problem?id=2856
 *         Author: Stoney
 *
 *        Version: 1.0
 *    Submit Time: 2016-01-23 11:21:22
 *       Compiler: c++
 *       Run Time: 329MS
 *         Memory: 156K
 *      Solutions: 1.12个月，每个月有盈、亏两种可能，共2^12种情况，采用枚举
 *                 2.递归遍历
 *                 3.采用FIFO队列存储5个连续月的sum,判断是否所有连续5个月的和是deficit
 *
 *        Version: 2.0
 *    Submit Time: 2016-01-23 14:33:59
 *       Compiler: c++
 *       Run Time: 0MS
 *         Memory: 156K
 *      Solutions: 为了尽量使Deficit的月份减少，应该将亏损的月份放在边界上（5月）
 *                 若d>5s，只要5月、10月为d，其他月份为s；否则向前增加为d的月份
 *                      d>4s        ssssd ssssd ss
 *                      2d>3s       sssdd sssdd ss
 *                      3d>2s       ssddd ssddd ss
 *                      4d>s        sdddd sdddd sd
 *                      d<(s/4)     ddddd ddddd dd
 *                 可能情况很少，采用枚举
 ===============================================================================================
 */

/*************************** Version 1.0 ******************************************************/
// #include<cstdio>
// #include<iostream>
// #include<stack>
// using namespace std;
//
// #define N 12
// #define L 5
//
// int A[N];
// int s, d;
//
// //采用FIFO队列存储sum
// bool all_deficit(int k){
//     int sum = 0;
//     for(int i=0;i<=k;i++){
//         sum += A[i];                //入队
//         if(i>L-1) sum-=A[i-L];      //出队
//         if(i>=L-1 && sum>0) return false;
//     }
//     return true;
// }
//
// int sum_(){
//     int res = 0;
//     for(int i=0;i<N;i++) res += A[i];
//     return res;
// }
//
// //递归遍历
// int is_surplus(int k){
//     if(k==N) return sum_();
//
//     int res = 0;
//     if(k<L-1){
//         A[k] = s;
//         res = is_surplus(k+1);
//         A[k] = -d;
//         return max(res, is_surplus(k+1));
//     }
//     else {
//         A[k] = s;
//         if(all_deficit(k)) res = is_surplus(k+1);
//         A[k] = -d;
//         if(all_deficit(k)) res = max(res, is_surplus(k+1));
//
//         return res;
//     }
// }
//
// int main(){
//     while (scanf("%d %d", &s, &d) != EOF) {
//         int res = is_surplus(0);
//         if(res) printf("%d\n", res);
//         else puts("Deficit");
//     }
//     return 0;
// }

// //非递归遍历
// int is_surplus2(){
//     stack<pair<int, int> > S;
//     S.push(make_pair(0, -d));
//     S.push(make_pair(0, s));
//
//     int res = 0;
//     while(!S.empty()){
//         pair<int, int> p = S.top();
//         S.pop();
//         int k = p.first; int t = p.second;
//         A[k] = t;
//
//         if(k==N){
//             res = max(res, sum_());
//         }
//         else if(k<L-1){
//             S.push(make_pair(k+1, -d));
//             S.push(make_pair(k+1, s));
//         }
//         else if(all_deficit(k)){
//             S.push(make_pair(k+1, -d));
//             S.push(make_pair(k+1, s));
//         }
//     }
//
//     return res;
// }

/*************************** Version 2.0 ******************************************************/
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int s, d;
    while(scanf("%d %d", &s, &d) != EOF){
        int res = 0;
        if(d > 4*s){        //ssssd ssssd ss
            res = 10*s - 2*d;
        }
        else if(2*d > 3*s){ //sssdd sssdd ss
            res = 8*s - 4*d;
        }
        else if(3*d > 2*s){  //ssddd ssddd ss
            res = 6*s - 6*d;
        }
        else if(4*d > s){   //sdddd sdddd sd
            res = 3*s - 9*d;
        }
        else{               //ddddd ddddd dd
            res = 0;
        }

        if(res > 0) printf("%d\n", res);
        else puts("Deficit");
    }
}

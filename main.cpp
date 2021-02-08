/**
 * @mainpage 随机黑线生成器
 * @section 用法
 * 输入四个参数。参数分别为:
 * - start: 开始时间戳
 * - len: 每条黑线长度
 * - dis: 每两条黑线的开始时间戳之间的距离 (不是每两条黑线之间的距离)
 * - cnt: 生成黑线条数
 * @section 注意
 * - 设A(0,1),B(1,1),C(1.5,0),D(-0.5,0),则坐标在梯形ABCD范围内随机生成。
 * - 坐标生成有可能出现分布不均(这边一大坨那边空荡荡)的情况,那就多生成几次选择自己满意的一组吧(跑)
*/

#include<iostream>
#include<cstdio>
#include<time.h>
#include"arc.cpp"

using namespace std;

/**
 * @brief 初始化
 */
int init() {
    srand((unsigned)time(NULL));
    return 0;
}

/**
 * @brief 主函数
 */
int main() {
    //初始化
    init();

    //输入参数
    int start,cnt;
    float len,dis;
    cin >> start >> len >> dis >> cnt;

    //生成并打印
    for(int i=0;i<cnt;i++) {
        Arc a;
        a.randomStraight();
        a.t1 = start + dis*i;
        a.t2 = a.t1 + len;
        a.print();
    }

    //结束
    system("pause");
    return 0;
}
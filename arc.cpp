#include<stdlib.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

// 一些杂函数

float getMinXByY(float y) {
    float x = (y-1)*0.5;
    return x;
}
float getMaxXByY(float y) {
    float x = (y-3)*-0.5;
    return x;
}
int randInt(int min,int max) {
    int delta = max - min;
    return (rand()%(delta+1))+min;
}

/**
 * 音弧(蛇) 对象
 */
struct Arc {
    int t1,t2; ///开始/结束时间戳
    float x1,x2; ///开始/结束时的横坐标
    string slideasing = "s"; ///滑动方式
    float y1,y2; ///开始/结束时的纵坐标
    int color = 0; ///颜色
    string fx = "none"; ///无意义,凑数的
    bool skylineBoolean = true; ///是否为黑线

    /** 
     * @brief 置梯形范围内随机坐标
     */
    void randomStraight() {
        y1 = randInt(0,100)*0.01;
        y2 = y1;

        int minX,maxX;
        minX = getMinXByY(y1)*100;
        maxX = getMaxXByY(y2)*100;
        x1 = randInt(minX,maxX)*0.01;

        x2 = x1;
        
    }

    /**
     * @brief 打印该Arc对象
     */
    void print() {
        cout << "arc(";
        cout << t1 << ",";
        cout << t2 << ",";
        printf("%.2f,",x1);
        printf("%.2f,",x2);
        cout << slideasing << ",";
        printf("%.2f,",y1);
        printf("%.2f,",y2);
        cout << color << ",";
        cout << fx << ",";
        cout << boolalpha << skylineBoolean;
        cout << ");\n";
        cout << noboolalpha;
    }
};

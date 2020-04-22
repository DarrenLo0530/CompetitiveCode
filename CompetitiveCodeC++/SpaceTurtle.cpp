#include <bits/stdc++.h>
using namespace std;
struct coord{
    int x, y, z;
};

double getDist(int x, int y, int z){
    return (pow(x, 2) + pow(y, 2) + pow(z, 2));
}
int main(){
    int x, y, z, d;
    char c;

    cin>>x>>y>>z;
    coord turtle = {x, y, z};
    cin>>x>>y>>z;
    coord shell = {x, y, z};
    turtle.x = turtle.x - shell.x;
    turtle.y = turtle.y - shell.y;
    turtle.z = turtle.z - shell.z;

    //Turtle pos is relative position to shell(aka shell is at 0,0,0)??

    int f = 1;
    int l = 2;
    int t = 3;

    double ans = getDist(turtle.x, turtle.y, turtle.z);

    while(true){
        cin>>d>>c;
        int dir = (f > 0) ? 1 : -1;

        if(abs(f) == 1){
            int newX = turtle.x + d*dir;
            if(newX * turtle.x > 0){
                ans = min(ans, getDist(newX, turtle.y, turtle.z));
            } else {
                ans = min(ans, getDist(0, turtle.y, turtle.z));
            }
            turtle.x = newX;
        } else if(abs(f) == 2){
            int newY = turtle.y + d*dir;
            if(newY * turtle.y > 0){
                ans = min(ans, getDist(turtle.x, newY, turtle.z));
            } else {
                ans = min(ans, getDist(turtle.x, 0, turtle.z));
            }
            turtle.y = newY;
        } else {
            int newZ = turtle.z + d*dir;
            if(newZ * turtle.z > 0){
                ans = min(ans, getDist(turtle.x, turtle.y, newZ));
            } else {
                ans = min(ans, getDist(turtle.x, turtle.y, 0));
            }
            turtle.z = newZ;
        }

        if(c == 'E'){
            break;
        } else if(c == 'D'){
            swap(f, t);
            f*=-1;
        } else if (c == 'U'){
            swap(f, t);
            t*=-1;
        } else if(c == 'R'){
            swap(f, l);
            f*=-1;
        } else {
            swap(f, l);
            l*=-1;
        }
    }

    printf("%.2f", sqrt(ans));
}

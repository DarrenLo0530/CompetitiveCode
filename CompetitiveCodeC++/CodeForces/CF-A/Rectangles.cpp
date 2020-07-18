    #include <bits/stdc++.h>
    using namespace std;

    struct Rectangle {
        double x1, y1, x2, y2;

        bool isIn(double x, double y){
            if(x > min(x1, x2) && x < max(x1, x2) && y > min(y1, y2) && y < max(y1, y2)){
                return true;
            }
            return false;
        }
    };

    vector<Rectangle> rectangles;

    int main(){
        while(true){
            char s;
            scanf(" %c", &s);
            if(s == '*'){
                break;
            }

            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

            rectangles.push_back(Rectangle{x1, y1, x2, y2});
        }

        for(int i = 1; ; i++){
            bool isContained = false;
            double x, y;
            scanf("%lf%lf", &x, &y);

            if(x == 9999.9 && y == 9999.9){
                break;
            }

            for(int r = 0; r<rectangles.size(); r++){
                if(rectangles[r].isIn(x, y)){
                    isContained = true;
                    printf("Point %d is contained in figure %d\n", i, r+1);
                }
            }

            if(!isContained){
                printf("Point %d is not contained in any figure\n", i);
            }
        }
    }

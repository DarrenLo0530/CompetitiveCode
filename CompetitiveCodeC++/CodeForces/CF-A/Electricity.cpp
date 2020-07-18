#include <bits/stdc++.h>
using namespace std;

struct Date{
    int day, month, year;

    bool operator== (const Date &d2){
        return day == d2.day && month == d2.month && year == d2.year;
    }
};

int getMaxDays(Date d){
    int maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0){
        maxDays[1] = 29;
    }

    return maxDays[d.month-1];
}

Date getNextDate(Date d){
    int maxDays = getMaxDays(d);
    int nextDay = d.day;
    int nextMonth = d.month;
    int nextYear = d.year;
    
    nextDay = nextDay % maxDays + 1;
    nextMonth = (nextMonth + d.day/maxDays - 1) % 12 + 1;
    nextYear = nextYear + (d.month + d.day/maxDays)/13;

    return Date{nextDay, nextMonth, nextYear};
}

int main(){
    while(true){
        int n;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        int numConsecutive = 0;
        int electricityUsed = 0;

        int pd, pm, py, pc;
        scanf("%d%d%d%d", &pd, &pm, &py, &pc);
        Date prev = Date{pd, pm, py};
        --n;

        while(n--){
            int d, p, y, c;
            scanf("%d%d%d%d", &d, &p, &y, &c);
            Date curr = Date{d, p, y};
            //cout << getNextDate(prev).day << " " << getNextDate(prev).month << " " << getNextDate(prev).year<<"\n";
            if(getNextDate(prev) == curr){
                electricityUsed += c - pc;
                ++numConsecutive;
            }

            prev = curr;
            pc = c;
        }

        printf("%d %d\n", numConsecutive, electricityUsed);
    }   
}
#include <bits/stdc++.h>
using namespace std;
int n, t1, t2;
double k;
struct Person{
    int number;
    double size;

    bool operator < (const Person &p2) const {
        if(size == p2.size) {
            return number < p2.number;
        }

        return size > p2.size;
    }
};

double mushroomGrowth(double g1, double g2){
    double amount1 = t1 * g1 * k + t2 * g2;
    double amount2 = t1 * g2 * k + t2 * g1 ;
    return max(amount1, amount2);
}

int main(){
    scanf("%d%d%d%lf", &n, &t1, &t2, &k);
    k = 1-(k/100);

    vector<Person> people;
    for(int i = 1; i<=n; i++){
        double g1, g2;
        scanf("%lf%lf", &g1, &g2);
        people.push_back(Person{i, mushroomGrowth(g1, g2)});
    }

    sort(people.begin(), people.end());
    for(auto p: people){
        printf("%d %.2f\n", p.number, p.size);
    }

}
#include <iostream>
#include <map>

double sum(double a, double b){
    return a+b;
}

double sub(double a, double b){
    return a-b;
}

double mul(double a, double b){
    return a*b;
}

double dive(double a, double b){
    return a/b;
}
int main(){

    double a,b;
    char ch;
    std::cin >> a >> ch >> b;
    std::map<char,double (*)(double, double)> op;
    op['+']= sum;
    op['-']= sub;
    op['*']= mul;
    op['/']= dive;

    std::cout << op[ch](a,b) <<std::endl;
}
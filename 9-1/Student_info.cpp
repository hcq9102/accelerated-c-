#include "Student_info.h"
#include "grade.h"

using namespace std;

double Student_info::grade() const{
    return g;
}

bool compare(const Student_info& x, const Student_info& y){
    return x.name() < y.name();
}

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(istream& is) {read(is);}

istream& read_hw(istream& in, vector<double>& hw){
    if (in){
        hw.clear();

        int x;
        while(in >> x)
            hw.push_back(x);

        in.clear();
    }
    return in;
}

istream& Student_info::read(istream& in){
    in >> n >> midterm >> final;
    read_hw(in, homework);
    g = ::grade(midterm, final, homework);
    return in;
}

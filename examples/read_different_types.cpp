#include <cstdio>

#include "simple_csv.hpp"

int main()
{
    const char csv[] = "1,2.3,a\n2,3.4,b\n3,4.5,c";

    simple_csv::reader<> reader(csv);

    for (auto row: reader) {
        auto col = row.begin();

        char s[10];

        int i;
        col->get(i);
        printf("Integer: %d\n", i);
        ++col;

        double d;
        col->get(d);
        printf("Double: %g\n", d);

        col->get(s, sizeof(s));
        printf("String: %s\n", s);
        ++col;
    }
}

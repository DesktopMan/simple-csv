#include <cstdio>

#include "simple_csv.hpp"

int main()
{
    const char csv[] = "1,2,3\n4,5,6\n7,8,9";

    simple_csv::reader<> reader(csv);

    for (auto row: reader) {
        auto col = row.begin() + 2;

        int value;

        col->get(value);
        printf("Value: %d\n", value);
    }
}

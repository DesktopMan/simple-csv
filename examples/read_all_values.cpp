#include <cstdio>

#include "simple_csv.hpp"

int main()
{
    const char csv[] = "1,2,3\n4,5,6\n7,8,9";

    simple_csv::reader<> reader(csv);

    for (auto row: reader) {
        for (auto col: row) {
            int value;

            if (col.get(value) == simple_csv::result::OK)
                printf("Value: %d\n", value);
            else
                printf("Failed to read value!\n");
        }
    }
}

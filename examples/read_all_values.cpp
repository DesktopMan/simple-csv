#include <cstdio>

#include "scsv.hpp"

int main()
{
    const char csv[] = "1,2,3\n4,5,6\n7,8,9";

    scsv::reader<> reader(csv);

    for (auto row: reader) {
        for (auto col: row) {
            int value;

            if (col.get(value) == scsv::result::OK)
                printf("Value: %d\n", value);
            else
                printf("Failed to read value!\n");
        }
    }
}

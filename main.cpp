#include "simple_csv.hpp"

#include <cstdio>

int main() {
    const char car[] = "Year,Make,Model,Description,Price\n"
                       "1997.8,Ford,E350,\"ac, abs, moon\",3000.00\n"
                       "1999,Chevy,\"Venture \"\"Extended Edition\"\"\",\"\",4900.49\n"
                       "1999,Chevy,\"Venture \"\"Extended Edition, Very Large\"\"\",,5000.99\n";

    simple_csv::reader<> csv(car);

    printf("===========================================\n");
    printf("Reading all rows and columns with iterators\n");
    printf("===========================================\n\n");

    for (auto row = csv.begin(); row != csv.end(); ++row) {
        printf("---\n");
        printf("Row\n");
        printf("---\n");

        for (auto column = row->begin(); column != row->end(); ++column) {
            int int_value;
            double double_value;
            char string_value[40] = {0};

            if (column->get(int_value))
                printf("Value as int: %i\n", int_value);
            else if (column->get(double_value))
                printf("Value as double: %g\n", double_value);
            else if (column->get(string_value, sizeof(string_value)))
                printf("Value as string: %s\n", string_value);
        }

        printf("\n");
    }

    printf("=======================================================\n");
    printf("Reading all rows and columns with range based for loops\n");
    printf("=======================================================\n\n");

    for (auto row: csv)
    {
        printf("---\n");
        printf("Row\n");
        printf("---\n");

        for (auto column: row)
        {
            int int_value;
            double double_value;
            char string_value[40] = {0};

            if (column.get(int_value))
                printf("Value as int: %i\n", int_value);
            else if (column.get(double_value))
                printf("Value as double: %g\n", double_value);
            else if (column.get(string_value, sizeof(string_value)))
                printf("Value as string: %s\n", string_value);
        }

        printf("\n");
    }

    return 0;
}

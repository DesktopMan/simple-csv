#ifndef SIMPLE_CSV_UTIL
#define SIMPLE_CSV_UTIL

namespace simple_csv
{
    static bool is_end_of_line(const char *csv)
    {
        return *csv == '\r' || *csv == '\n';
    }

    static bool is_end_of_row(const char *csv)
    {
        return is_end_of_line(csv) || *csv == 0;
    }

    static const char *find_next_line(const char *csv)
    {
        while (!is_end_of_row(++csv));
        while (is_end_of_line(++csv));

        if (*csv == 0)
            return nullptr;

        return csv;
    }

    static const char *find_next_value(const char *csv, char delimiter)
    {
        if (csv == nullptr)
            return nullptr;

        if (*csv == delimiter) { // Empty value
            csv++;

            if (is_end_of_row(csv))
                return nullptr;

            return csv;
        }

        bool quoted = false;

        if (*csv == '"') { // Quoted value
            quoted = true;
            csv++;
        }

        while (!is_end_of_row(csv)) {
            if (*csv == ',' && !quoted) // End of unquoted value
                break;

            if (csv[0] == '"' && csv[1] != '"' && quoted) // End of quoted value
                break;

            if (csv[0] == '"' && csv[1] == '"' && quoted) // Skip embedded quotes
                csv++;

            csv++;
        }

        if (*csv == '"') // Skip end quote
            csv++;

        if (*csv == delimiter) // Skip delimiter
            csv++;

        if (is_end_of_row(csv))
            return nullptr;

        return csv;
    }
}

#endif

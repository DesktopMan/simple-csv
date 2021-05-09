#ifndef SIMPLE_CSV_UTIL
#define SIMPLE_CSV_UTIL

namespace simple_csv
{
    static const char *find_next_line(const char *csv)
    {
        while (*csv != '\n' && *csv != 0)
            csv++;

        while (*csv == '\n')
            csv++;

        return csv;
    }

    static const char *find_value_end(const char *csv, char delimiter)
    {
        bool waiting_on_quote = false;

        if (*csv == '"') {
            waiting_on_quote = true;
            csv++;
        }

        while ((*csv != delimiter || waiting_on_quote) && *csv != '\n' && *csv != 0) {
            if (waiting_on_quote && csv[0] == '"' && csv[1] != '"')
                waiting_on_quote = false;

            csv++;
        }

        return csv;
    }
}

#endif

#ifndef SCSV_UTIL_HPP
#define SCSV_UTIL_HPP

namespace scsv
{
    inline bool is_end_of_line(const char *csv)
    {
        return *csv == '\r' || *csv == '\n';
    }

    inline bool is_end_of_row(const char *csv)
    {
        return is_end_of_line(csv) || *csv == 0;
    }

    static const char *find_next_value(const char *csv, char delimiter, const char **next_line=nullptr)
    {
        if (csv == nullptr || *csv == 0)
            return nullptr;

        bool quoted = false;

        if (*csv == '"') { // Quoted value
            quoted = true;
            csv++;
        }

        while (*csv != 0) {
            if (csv[0] == '"' && csv[1] == '"' && quoted) // Embedded quote
                csv++;

            if (csv[0] == '"' && csv[1] != '"' && quoted) { // End of quoted value
                quoted = false;
                csv++;
            }

            if (*csv == delimiter && !quoted) // End of value
                break;

            if(is_end_of_row(csv) && !quoted) // End of row
                break;

            csv++;
        }

        if (*csv == 0)
            return nullptr;

        if (*csv == delimiter)
            return csv + 1;

        if (!is_end_of_line(csv))
            return nullptr;

        while (is_end_of_line(csv))
            csv++;

        if (*csv != 0 && next_line)
            *next_line = csv;

        return nullptr;
    }

    static const char *find_next_line(const char *csv, char delimiter)
    {
        const char *next_line = nullptr;

        while ((csv = find_next_value(csv, delimiter, &next_line)) != nullptr);

        if (next_line == nullptr)
            return nullptr;

        while (is_end_of_line(next_line))
            next_line++;

        if (*next_line == 0)
            return nullptr;

        return next_line;
    }
}

#endif

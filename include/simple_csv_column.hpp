#include <cstdlib>

#include "simple_csv_util.hpp"

namespace simple_csv {
    class column {
    public:
        explicit column(const char *csv) : _csv(csv) {}

        bool get(int &value) const {
            if (*_csv == '"' || *_csv == ',')
                return false;

            char *end;
            value = strtol(_csv, &end, 10);

            if (end == _csv)
                return false;

            if (*end != ',' && *end != '\n' && *end != 0)
                return false;

            return true;
        }

        bool get(double &value) const {
            if (*_csv == '"' || *_csv == ',')
                return false;

            char *end;
            value = strtod(_csv, &end);

            if (end == _csv)
                return false;

            if (*end != ',' && *end != '\n' && *end != 0)
                return false;

            return true;
        }

        bool get(char value[], size_t size) const {
            size_t ipos = 0;
            size_t opos = 0;

            bool waiting_on_quote = false;

            if (_csv[0] == '"') { // Start of value quote
                waiting_on_quote = true;
                ipos++;
            }

            while (opos < size - 1) {
                if ((_csv[ipos] == ',' && !waiting_on_quote) || _csv[ipos] == '\n' || _csv[ipos] == 0)
                    break;

                if (_csv[ipos] == '"' && _csv[ipos + 1] == '"') { // Embedded quote
                    value[opos++] = '"';
                    ipos++;
                } else if (_csv[ipos] == '"' && waiting_on_quote) // End of value quote
                    break;
                else if (_csv[ipos] == '"') // Unexpected quote
                    return false;
                else // Regular character
                    value[opos++] = _csv[ipos];

                ipos++;
            }

            value[opos++] = 0;
            return opos != size;
        }

    protected:
        const char *_csv;
    };
}

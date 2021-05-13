#include <cstdlib>

#include "simple_csv_result_codes.hpp"
#include "simple_csv_util.hpp"

namespace simple_csv {
    template <char delimiter>
    class column {
    public:
        explicit column(const char *csv) : _csv(csv) {}

        int get(int &value) const {
            int res = check_numeric_start();

            if (res != result::OK)
                return res;

            char *end;
            value = (int)strtol(_csv, &end, 10);

            return check_numeric_end(end);
        }

        int get(double &value) const {
            int res = check_numeric_start();

            if (res != result::OK)
                return res;

            char *end;
            value = strtod(_csv, &end);

            return check_numeric_end(end);
        }

        int get(char value[], size_t size) const {
            if (_csv == nullptr)
                return result::END_OF_INPUT;

            size_t ipos = 0;
            size_t opos = 0;

            bool quoted = false;

            if (_csv[0] == '"') { // Start of value quote
                quoted = true;
                ipos++;
            }

            while (opos < size - 1) {
                if ((_csv[ipos] == ',' && !quoted) || (_csv[ipos] == '\n' && !quoted) || _csv[ipos] == 0)
                    break;

                if (_csv[ipos] == '"' && _csv[ipos + 1] == '"') { // Embedded quote
                    value[opos++] = '"';
                    ipos++;
                } else if (_csv[ipos] == '"' && quoted) // End of value quote
                    break;
                else if (_csv[ipos] == '"')
                    return result::UNEXPECTED_QUOTE;
                else // Regular character
                    value[opos++] = _csv[ipos];

                ipos++;
            }

            value[opos++] = 0;

            if (opos == size)
                return result::INSUFFICIENT_BUFFER_SIZE;

            return result::OK;
        }

    protected:
        const char *_csv;

        int check_numeric_start() const {
            if (_csv == nullptr || *_csv == 0)
                return result::END_OF_INPUT;

            switch (*_csv) {
                case '"': return result::UNEXPECTED_QUOTE;
                case delimiter: return result::UNEXPECTED_DELIMITER;
                case '\r': case '\n': return result::UNEXPECTED_NEWLINE;
            }

            if (*_csv == '"')
                return result::UNEXPECTED_QUOTE;

            if (*_csv == ',')
                return result::UNEXPECTED_DELIMITER;

            return result::OK;
        }

        int check_numeric_end(const char *end) const {
            if (end == _csv)
                return result::UNEXPECTED_DATA;

            if (*end != ',' && *end != '\n' && *end != 0)
                return result::UNEXPECTED_DATA;

            return result::OK;
        }
    };
}

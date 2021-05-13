#ifndef SCSV_RESULT_CODES_HPP
#define SCSV_RESULT_CODES_HPP

namespace scsv {
    namespace result {
        enum {
            OK,
            END_OF_INPUT,
            UNEXPECTED_DELIMITER,
            UNEXPECTED_QUOTE,
            UNEXPECTED_NEWLINE,
            UNEXPECTED_DATA,
            INSUFFICIENT_BUFFER_SIZE
        };
    }
}

#endif

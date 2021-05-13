#ifndef SIMPLE_CSV_RESULT_CODES
#define SIMPLE_CSV_RESULT_CODES

namespace simple_csv {
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

#ifndef SIMPLE_CSV
#define SIMPLE_CSV

#include "simple_csv_row.hpp"

namespace simple_csv {
    template <char delimiter = ',', char decimal_separator = '.'>
    class reader {
    protected:
        class const_iterator;

    public:
        explicit reader(const char *csv) : _csv(csv) {}

        const_iterator begin() const {
            return const_iterator(_csv);
        }

        const_iterator end() const {
            return const_iterator(nullptr);
        }

    protected:
        const char *_csv;

        class const_iterator {
        public:
            explicit const_iterator(const char *csv) : _row(csv), _csv(csv) {}

            bool operator==(const const_iterator &row) const {
                return this->_csv == row._csv;
            }

            bool operator!=(const const_iterator &row) const {
                return this->_csv != row._csv;
            }

            const_iterator &operator++() {
                _csv = find_next_line(_csv);
                return *this;
            }

            const_iterator &operator+(size_t pos) {
                auto it = *this;

                for (size_t i = 0; i < pos; i++)
                    ++it;

                return it;
            }

            row<delimiter> &operator*() {
                _row = row<delimiter>(this->_csv);
                return _row;
            }

            row<delimiter> *operator->() {
                _row = row<delimiter>(this->_csv);
                return &_row;
            }

        protected:
            row<delimiter> _row;
            const char *_csv;
        };
    };
}

#endif

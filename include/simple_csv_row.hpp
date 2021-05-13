#include "simple_csv.hpp"
#include "simple_csv_column.hpp"
#include "simple_csv_util.hpp"

namespace simple_csv {
    template <char delimiter>
    class row {
    protected:
        class const_iterator;

    public:
        explicit row(const char *csv) : csv(csv) {}

        const_iterator begin() const {
            return const_iterator(csv);
        }

        const_iterator end() const {
            return const_iterator(nullptr);
        }

    protected:
        const char *csv;

        class const_iterator {
        public:
            explicit const_iterator(const char *csv) : _column(csv), _csv(csv) {}

            bool operator==(const const_iterator &row) const {
                return this->_csv == row._csv;
            }

            bool operator!=(const const_iterator &row) const {
                return this->_csv != row._csv;
            }

            const_iterator &operator++() {
                _csv = find_next_value(_csv, delimiter);
                return *this;
            }

            const_iterator operator+(size_t pos) {
                auto it = *this;

                for (size_t i = 0; i < pos; i++)
                    ++it;

                return it;
            }

            column<delimiter> operator*() {
                _column = column<delimiter>(_csv);
                return _column;
            }

            column<delimiter> *operator->() {
                _column = column<delimiter>(_csv);
                return &_column;
            }

        protected:
            column<delimiter> _column;
            const char *_csv;
        };
    };
}

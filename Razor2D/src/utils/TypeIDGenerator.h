#ifndef RZ_GENERATE_ID
#define RZ_GENERATE_ID

#include "../core/Types.h"

namespace RZ {
    template<typename T>
    class TypeIDGenerator {
    public:
        template <class P>
        static const RazorID Generate() {
            static const RazorID someId = m_count++;
            return someId;
        }

    private:
        static RazorID m_count;
    };

    template <typename T>
    RazorID TypeIDGenerator<T>::m_count = 0;
}

#endif
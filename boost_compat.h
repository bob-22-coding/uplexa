#ifndef BOOST_COMPAT_H
#define BOOST_COMPAT_H

#include <boost/version.hpp>

// boost/serialization/list.hpp uses library_version_type but doesn't
// include the header that defines it. Force-include it early so it's
// always available regardless of include order.
#include <boost/serialization/library_version_type.hpp>

// Boost 1.83 removed boost::archive::library_version_type (moved to
// boost::serialization). Provide a compatibility typedef on newer Boost.
#if BOOST_VERSION >= 108300
namespace boost { namespace archive {
    using library_version_type = boost::serialization::library_version_type;
}}
#endif

#endif // BOOST_COMPAT_H
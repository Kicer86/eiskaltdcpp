/*
 * Copyright (C) 2001-2012 Jacek Sieka, arnetheduck on gmail point com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <libintl.h>
#include <boost/format.hpp>

#if defined(BUILDING_DCPP)

#define PACKAGE "libeiskaltdcpp"
#define _(String) dgettext(PACKAGE, String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)
#define F_(String) dcpp::dcpp_fmt(dgettext(PACKAGE, String))
#define FN_(String1,String2, N) dcpp::dcpp_fmt(dngettext(PACKAGE, String1, String2, N))

#endif // defined(BUILDING_DCPP)

namespace dcpp {

template<typename T>
boost::basic_format<T> dcpp_fmt(const std::basic_string<T>& t) {
    boost::basic_format<T> fmt;
    fmt.exceptions(boost::io::no_error_bits);
    fmt.parse(t);
    return fmt;
}

template<typename T>
boost::basic_format<T> dcpp_fmt(const T* t) {
    return dcpp_fmt(std::basic_string<T>(t));
}

}

using boost::str;

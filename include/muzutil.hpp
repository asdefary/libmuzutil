#ifndef __MUZUTIL_HPP__
#define __MUZUTIL_HPP__

#include <string>

#include <muzdb.hpp>

#include <boost/shared_ptr.hpp>

namespace muzdb {

std::string format_track(const std::string &format,
	boost::shared_ptr<const Track> trk,
	const std::map<std::string, std::string> &extras
		= std::map<std::string, std::string>());

} // namespace muzdb

#endif /* __MUZUTIL_HPP__ */


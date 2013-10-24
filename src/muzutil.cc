#include "common.hpp"

#include <map>

namespace muzdb {

typedef std::map<std::string, std::string> map_type;

std::string format_track(const std::string &format, boost::shared_ptr<const Track> trk, const map_type &extras)
{
	std::string ret;
	std::string token;

	bool is_tag(false);

	BOOST_AUTO(fields, trk->fields());
	BOOST_AUTO(info, trk->file_info());

	BOOST_FOREACH(char s, format) {
		if (s == '%') {
			if (is_tag) {
				if (token.empty()) {
					ret += "%";
				} else if (extras.find(token) != extras.end()) {
					ret += extras.find(token)->second;
				} else if (info.find(token) != info.end()) {
					ret += info[token];
				} else if (fields.find(token) != fields.end()) {
					ret += fields[token];
				}

				is_tag = false;
				token.clear();
			} else {
				ret += token;
				token.clear();
				is_tag = true;
			}
		} else {
			token.push_back(s);
		}
	}

	ret += token;

	return ret;
}

} // namespace muzdb


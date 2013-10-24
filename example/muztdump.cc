#include "../include/muzutil.hpp"

#include <boost/typeof/typeof.hpp>
#include <boost/foreach.hpp>

int main(int argc, char **argv)
{
	BOOST_AUTO(db, muzdb::muzdb_init(argv[1]));

	db->update();

	BOOST_AUTO(tracks, db->tracks());

	BOOST_FOREACH(BOOST_TYPEOF(*tracks.begin()) trk, tracks) {
		std::cout << format_track(argv[2], trk.second) << std::endl;
	}

	return 0;
}


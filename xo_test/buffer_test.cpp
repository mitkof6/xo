#include <vector>
#include <map>
#include "xo/geometry/vec3.h"
#include "xo/system/log.h"
#include "xo/container/label_vector.h"
#include "xo/container/circular_frame_buffer.h"
#include "xo/container/circular_deque.h"
#include "xo/container/storage.h"
#include "xo/system/test_case.h"
#include "xo/string/string_tools.h"
#include "xo/container/container_algorithms.h"

namespace xo
{
	XO_TEST_CASE( xo_buffer_test )
	{
		// circular_deque test
		circular_deque< int > cd( 10 );
		for ( int i = 0; i < 30; ++i )
		{
			cd.push_back( i );
			if ( cd.size() == 10 )
			{
				XO_CHECK( cd.front() == i - 9 );
				cd.pop_front();
			}
		}

		// circular_deque test
		cd.clear();
		cd.reserve( 0 );
		for ( int i = 0; i < 30; ++i )
		{
			cd.push_front( i );
			if ( cd.size() == 20 )
			{
				XO_CHECK( cd.back() == i - 19 );
				cd.pop_back();
			}
		}

		// regular buffer test
		storage< float, string > buf( 0 );

		//regular_ring_buffer< double, 100, void > ringbuf( 20 );
		for ( int i = 0; i < 10; ++i )
			buf.add_channel( stringf( "channel%d", i ) );
	}
}

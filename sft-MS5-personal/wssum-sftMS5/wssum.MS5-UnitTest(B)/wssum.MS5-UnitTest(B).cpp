#include "pch.h"
#include "CppUnitTest.h"
#include "wssum-MS5_r.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace wssumMS5UnitTestB
{
	TEST_CLASS(wssumMS5UnitTestB)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			struct Route Map =
			{
					{
					{0,0},

					},
						1, BLUE
			};
			addPointToRoute(&Map, 0 / 2, 1);


			Assert::IsTrue((Map.points[3].row == 0) && (Map.points[3].col == 1));
			//Test to see if function can handle infinite reccursion or will it safely round down.
			//Post Results: 

		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "wssumSftMs5_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace wssumUnitTestB
{
	TEST_CLASS(wssumUnitTestB)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const struct Point testPoint = { 5,5 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2}

					},
						5, 2
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			addPointToRoute(&testRoute, 2, 1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);


			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsTrue(tester == expectedRoute.numPoints);
		}
	};
}

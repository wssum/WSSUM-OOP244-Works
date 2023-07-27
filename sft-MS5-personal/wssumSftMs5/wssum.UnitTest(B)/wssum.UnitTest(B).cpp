#include "pch.h"
#include "CppUnitTest.h"
#include "wssumSftMs5_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace wssumUnitTestB
{
	TEST_CLASS(wssumUnitTestB)
	{
	public:
		
		TEST_METHOD(TBP001)
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
			//Post Results:Passed

		}
		TEST_METHOD(TBP002)
		{
			const struct Point testPoint = { 2,2 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1}

					},
						4, 2
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
			//Post Results:Passed

		}
		TEST_METHOD(TBP003)
		{
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2},
				    {3,2},{3,3}
					},
						7, 2
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
			addPointToRoute(&testRoute, 3, 2);
			addPointToRouteIfNot(&testRoute, 3, 3, testPoint);

			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsTrue(tester == expectedRoute.numPoints);
			//Post Results:Passed
		}
		TEST_METHOD(TBP004)
		{
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2},
					{3,2},{3,3}
					},
						7, 2
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
			addPointToRoute(&testRoute, 3, 2);
			addPointToRouteIfNot(&testRoute, 3, 3, testPoint);

	
			Assert::IsTrue(testRoute.numPoints == expectedRoute.numPoints);
			//Post Results:Passed
		}
		TEST_METHOD(TBN001)
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
			addPointToRoute(&testRoute, 2, -1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);


			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsFalse(tester == expectedRoute.numPoints);
			//Post Results:Passed
		}
		TEST_METHOD(TBN002)
		{
			const struct Point testPoint = { 5,5 };
			const struct Point testPointB = { 2,-2 };
			int truth = 0;
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
			addPointToRouteIfNot(&testRoute, 2, -2, testPoint);

			truth = eqPt(testRoute.points[3], testPointB);
			Assert::IsFalse(truth == 1);
			//Expected Result: True for being false
			//Post Results:Passed
		}
		TEST_METHOD(TBN003)
		{
			const struct Point testPoint = { 5,5 };
			const struct Point testPointB = { 2,500 };
			int truth = 0;
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
			addPointToRouteIfNot(&testRoute, 2, 500, testPoint);

			truth = eqPt(testRoute.points[3], testPointB);
			Assert::IsFalse(truth == 1);
			//Expected Result: True for being false
			//Post Results:Passed
		}
		TEST_METHOD(TBN004)
		{
			const struct Point testPoint = { 5,5 };
			const struct Point testPointB = { 2,0 };
			int truth = 0;
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
			addPointToRouteIfNot(&testRoute, 2, 0, testPoint);

			truth = eqPt(testRoute.points[3], testPointB);
			Assert::IsFalse(truth  == 1);
			//Expected Result: True for being false
			//Post Results:Passed
		}
	};
}

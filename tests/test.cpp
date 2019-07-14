#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>
#include "matrix.h"

BOOST_AUTO_TEST_SUITE(matrix_test_suite)

BOOST_AUTO_TEST_CASE(test)
{
	Matrix<int, -1> matrix;
	BOOST_CHECK_EQUAL(matrix.size(), 0);

	auto a = matrix[0][0];
	BOOST_CHECK_EQUAL(a, -1);
	BOOST_CHECK_EQUAL(matrix.size(), 0);

	matrix[100][100] = 314;
	BOOST_CHECK_EQUAL(matrix[100][100], 314);
	BOOST_CHECK_EQUAL(matrix.size(), 1);

	for (auto c : matrix)
	{
		int x,y,v;
		std::tie(x, y, v) = c;

		BOOST_CHECK_EQUAL(x, 100);
		BOOST_CHECK_EQUAL(y, 100);
		BOOST_CHECK_EQUAL(v, 314);
	}	flaber::Matrix<int, 0, 3> matrix3;
	matrix3[0][0][0] = 10;
	BOOST_CHECK_EQUAL(matrix3[0][0][0], 10);
}

BOOST_AUTO_TEST_SUITE_END()
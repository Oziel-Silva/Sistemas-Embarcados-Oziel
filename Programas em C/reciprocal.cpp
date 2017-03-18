// Arquivo reciprocal.cpp
#include <cassert>
#include "reciprocal.hpp"

double reciprocal (int i )
{
	// I shoud be nonzero.
	assert (i != 0);
	return 1.0/i;
}

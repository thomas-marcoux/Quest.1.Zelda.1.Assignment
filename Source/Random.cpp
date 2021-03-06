#include <random>
#include "Random.h"

//Initializes random engine
std::default_random_engine &global_urng()
{
	static std::default_random_engine  u{};
	return u;
}

//Get random integer in range from -> thru
float random(float from, float thru)
{
	static std::uniform_real_distribution<float>  d{};
	using  parm_t = decltype(d)::param_type;
	return d(global_urng(), parm_t{ from, thru });
}

int	random(int from, int thru)
{
	static std::uniform_int_distribution<>  d{};
	using  parm_t = decltype(d)::param_type;
	return d(global_urng(), parm_t{ from, thru });
}
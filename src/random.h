#include <vector>
#include <stdlib.h>

typedef enum RANDOMLISTTYPE{
	RLTYPE_NULL = 0,//rand
	RLTYPE_A__B = 1,//(a,b)
	RLTYPE_AA_B = 2,//[a,b)
	RLTYPE_A_BB = 3,//(a,b]
	RLTYPE_AABB = 4,//[a,b]
}RANDOMLISTTYPE;
template<typename T>
__inline static T GenerateRandom(T min, T max, RANDOMLISTTYPE type = RLTYPE_AABB)
{
	T ret = T(0);
	srand(time(0));
	switch (type)
	{
	case RLTYPE_A__B:	ret = (rand() % (T(max - min))) + (min - 1);	break;
	case RLTYPE_AA_B:	ret = (rand() % (T(max - min))) + (min);	break;
	case RLTYPE_A_BB:	ret = (rand() % (T(max - min))) + (min + 1);	break;
	case RLTYPE_AABB:	ret = (rand() % (T(max - min + 1))) + (min); break;
	default:ret = rand() % (T)(RAND_MAX); break;
	}
	return ret;
}
template<typename T>
__inline static void GenerateRandom(std::vector<T> & vT, int min, int max, RANDOMLISTTYPE type = RLTYPE_AABB)
{
	srand(time(0));
	for (auto & it : vT)
	{
		switch (type)
		{
		case RLTYPE_A__B:	it = (rand() % (T(max - min))) + (min - 1);	break;
		case RLTYPE_AA_B:	it = (rand() % (T(max - min))) + (min);	break;
		case RLTYPE_A_BB:	it = (rand() % (T(max - min))) + (min + 1);	break;
		case RLTYPE_AABB:	it = (rand() % (T(max - min + 1))) + (min); break;
		default:it = rand() % (T)(RAND_MAX); break;
		}
	}
}
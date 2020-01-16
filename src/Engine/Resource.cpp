#include "Resource.h"

/**
*\brief Gets core
*\return Returns resource reference to core as a shared_ptr
*/
std::shared_ptr<Core> Resource::getCore()
{
	return core.lock();
}

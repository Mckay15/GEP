#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

/**
*\brief Represents NonCopyable class
*Stops a class from being copied
*/
class NonCopyable
{
protected:
	NonCopyable(){}
	~NonCopyable(){}
private:
	NonCopyable(const NonCopyable &) = delete;
	NonCopyable & operator = (const NonCopyable &) = delete;
};

#endif //!_NONCOPYABLE_H_
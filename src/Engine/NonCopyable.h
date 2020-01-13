#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

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
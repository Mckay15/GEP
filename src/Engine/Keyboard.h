#include "Component.h"
#include <vector>

class Keyboard : public Component
{
private:
	std::vector<int> keyCodes;
public:
	bool getKey(int _keyCode);
	bool getkeyDown(int _keyCode);
	bool getKeyUp(int _keyCode);

	Keyboard();
	~Keyboard();
};
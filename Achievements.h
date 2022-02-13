#include <iostream>
#include "Subject.h"
#include <vector>
#include <string>


class Achievements:public Subject
{
public:

	Achievements();
	~Achievements();

	void onNotify(int event);

private:
	void unlock(Achievements* achievements);
};
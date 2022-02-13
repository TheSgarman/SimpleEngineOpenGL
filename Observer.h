#pragma once

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(int event) = 0;
};


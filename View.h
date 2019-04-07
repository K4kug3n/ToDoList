#pragma once

#include "Commun.h"
#include <vector>

class View
{
public:
	View();

	void render(std::vector<Task> const& data) const;

	~View();

private:
	void printTask(Task const& task) const;
};

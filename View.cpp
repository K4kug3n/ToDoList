#include "View.h"

#include <iostream>

View::View()
{
}

void View::render(std::vector<Task> const& data) const
{
	for(auto const& task : data)
	{
		printTask(task);
	}
}

void View::printTask(Task const& task) const
{
	std::cout << "Priority " << task.priority << "\t" << task.description << std::endl;
}

View::~View()
{
}

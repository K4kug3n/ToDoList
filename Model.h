#pragma once

#include "Commun.h"
#include <vector>

class Model
{
public:
	Model();
	
	std::vector<Task> getData() const;
	void setData(std::vector<Task> const& data);

	~Model();

private:
	std::vector<Task> data;
};


#include "Model.h"

Model::Model()
{
}

std::vector<Task> Model::getData() const
{
	return data;
}

void Model::setData(std::vector<Task> const & data)
{
	this->data = data;
}


Model::~Model()
{
}

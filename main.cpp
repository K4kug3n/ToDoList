#include <iostream>

#include "Model.h"
#include "Controller.h"
#include "View.h"

int main()
{
	std::vector<Task> myTasks;
	myTasks.push_back( Task{ 1, "Do app" } );
	myTasks.push_back( Task{ 2, "Do web" } );

	Model myModel;
	myModel.setData(myTasks);

	Controller myController;
	myController.setModel(myModel);

	myController.displayData();


	return 0;
}

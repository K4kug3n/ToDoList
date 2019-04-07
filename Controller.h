#pragma once

#include "Commun.h"
#include "Model.h"
#include "View.h"

class Controller
{
public:
	Controller();
	Controller(Model const& model, View const& view);

	void setModel(Model const& model);
	void setView(View const& view);
	void addTask(Task const& task);
	void displayData() const;

	~Controller();

private:
	Model model;
	View view;
};

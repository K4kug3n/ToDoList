#include "Controller.h"


Controller::Controller()
{
}

Controller::Controller(Model const& model, View const& view):
  model(model), view(view)
{
}

void Controller::setModel(Model const& model)
{
  this->model = model;
}

void Controller::setView(View const& view)
{
  this->view = view;
}

void Controller::displayData() const
{
  view.render(model.getData());
}

Controller::~Controller()
{
}

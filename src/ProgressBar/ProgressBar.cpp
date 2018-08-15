#include <ProgressBar/ProgressBar.h>


ProgressBar::ProgressBar()
{
    SetModel(new ProgressBarModel());
    SetViewer(new ProgressBarViewer(Model()));
    SetController(new ProgressBarController(Model()));

}

ProgressBar::~ProgressBar()
{

}

pProgressBarModel ProgressBar::Model()
{
    return pProgressBarModel(__model);
}

void ProgressBar::SetModel(pProgressBarModel model)
{
    __model = model;
}

pProgressBarViewer ProgressBar::Viewer()
{
    return pProgressBarViewer(__viewer);
}

void ProgressBar::SetViewer(pProgressBarViewer viewer)
{
    __viewer = viewer;
}

pProgressBarController ProgressBar::Controller()
{
    return pProgressBarController(__controller);
}

void ProgressBar::SetController(pProgressBarController controller)
{
    __controller = controller;
}


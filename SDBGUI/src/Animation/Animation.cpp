#include <Animation/Animation.h>


Animation::Animation()
{
    SetModel(new AnimationModel());
    SetViewer(new AnimationViewer(Model()));
    SetController(new AnimationController(Model()));
}

Animation::~Animation()
{

}

pAnimationModel Animation::Model()
{
    return pAnimationModel(__model);
}

void Animation::SetModel(pAnimationModel model)
{
    __model = model;
}

pAnimationViewer Animation::Viewer()
{
    return pAnimationViewer(__viewer);
}

void Animation::SetViewer(pAnimationViewer viewer)
{
    __viewer = viewer;
}

pAnimationController Animation::Controller()
{
    return pAnimationController(__controller);
}

void Animation::SetController(pAnimationController controller)
{
    __controller = controller;
}


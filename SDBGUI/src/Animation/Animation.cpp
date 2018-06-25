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

pAnimation Animation::FastCreate(pComponent parent, std::string filename, sf::Vector2f tc, sf::Time interval, sf::Vector2f size, sf::Vector2f localcoord)
{
    pAnimation anim;
    anim = new Animation();
    anim->Model()->setTilesCount(tc);
    anim->Model()->SetSize(size);
    anim->Model()->loadFromFile(filename);
    anim->Model()->setInterval(interval);

    anim->Model()->SetLocalCoord(localcoord);
    if (parent != nullptr){
        parent->Model()->Add(anim);
    }
    return anim;
}

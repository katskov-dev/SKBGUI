#include "Animation/AnimationModel.h"

AnimationModel::AnimationModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    SetCurrentFrame(0);
    setInterval(sf::milliseconds(1000));
}

AnimationModel::~AnimationModel()
{
    //
}

    sf::Texture& AnimationModel::Texture()
    {
        return __texture;
    }
    void AnimationModel::SetTexture(sf::Texture texture)
    {
        __texture=texture;
    }
    int AnimationModel::currentFrame()
    {
        return __currentFrame;
    }
    void AnimationModel::SetCurrentFrame(int currentFrame)
    {
        __currentFrame=currentFrame;
    }
    sf::Vector2f AnimationModel::tilesCount()
    {
        return __tilesCount;
    }
    void AnimationModel::setTilesCount(sf::Vector2f tilesCount)
    {
        __tilesCount=tilesCount;
    }
    void AnimationModel::loadFromFile(std::string fileName)
    {
        __texture.loadFromFile(fileName);
        __tw = Texture().getSize().x / tilesCount().x;
        __th = Texture().getSize().y / tilesCount().y;
        __row = currentFrame() / tilesCount().x;
        __col = currentFrame() % int(tilesCount().x);
        __x1=__col*__tw;
        __y1=__row*__th;
        __x2=(__col+1)*__tw;
        __y2=(__row+1)*__th;



        sprite.setTexture(Texture());

        sf::IntRect rect;
        rect.left = __x1;
        rect.width = __x2;
        rect.top = __y1;
        rect.height = __y2;
        sprite.setTextureRect(rect);
        sf::Vector2f coord = AbsoluteCoord();
        sprite.setPosition(coord);


        double x = Size().x;
        double y = Size().y;
    //    sf::Vector2u size = texture.getSize();
        double s_x = x / __tw;
        double s_y = y / __th;


        sprite.setScale(s_x, s_y);
    }
    void AnimationModel::nextFrame()
    {
        SetCurrentFrame(currentFrame()+1);
        if ((currentFrame()) >= (tilesCount().x*tilesCount().y))
        {
            SetCurrentFrame(0);
        }
        //sf::Texture texture = pAnimationModel(Owner())->Texture();
        __tw = Texture().getSize().x / tilesCount().x;
        __th = Texture().getSize().y / tilesCount().y;
        __row = currentFrame() / tilesCount().x;
        __col = currentFrame() % int(tilesCount().x);
        __x1=__col*__tw;
        __y1=__row*__th;
        __x2=(__col+1)*__tw;
        __y2=(__row+1)*__th;



        //sprite.setTexture(Texture());

        sf::IntRect rect;
        rect.left = __x1;
        rect.width = __x2;
        rect.top = __y1;
        rect.height = __y2;
        sprite.setTextureRect(rect);



//        double x = Size().x;
//        double y = Size().y;
//    //    sf::Vector2u size = texture.getSize();
//        double s_x = x / __tw;
//        double s_y = y / __th;


//        sprite.setScale(s_x, s_y);

    }
    sf::Time AnimationModel::interval()
    {
       return __interval;
    }
    void AnimationModel::setInterval(sf::Time interval)
    {
        __interval=interval;
    }
    sf::Time AnimationModel::currentTime()
    {
        return __currentTime;
    }
    void AnimationModel::setCurrentTime(sf::Time currentTime)
    {
        __currentTime=currentTime;
    }

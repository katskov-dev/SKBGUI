#pragma once

#include <base.h>
#include <Component/ComponentModel.h>
#include <Component/ComponentViewer.h>
#include <Component/ComponentController.h>

/**
    \brief Основной класс библиотеки

    \details Представляет собой фундаментальный компонент библиотеки. Все другие компоненты должны наследоваться от данного.


*/

class Component
{
    public:
        Component();
        virtual ~Component();
        virtual pComponentModel Model();
        virtual void SetModel(pComponentModel model);
        virtual pComponentViewer Viewer();
        virtual void SetViewer(pComponentViewer viewer);
        virtual pComponentController Controller();
        virtual void SetController(pComponentController controller);
        //virtual std::string Class();
    protected:

    public:
        pComponentModel __model;
        pComponentViewer __viewer;
        pComponentController __controller;
};


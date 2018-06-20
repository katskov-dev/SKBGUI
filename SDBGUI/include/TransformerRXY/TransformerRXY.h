#pragma once
#include <base.h>
#include <TransformerRXY/TransformerRXYModel.h>
#include <TransformerRXY/TransformerRXYViewer.h>
#include <TransformerRXY/TransformerRXYController.h>
#include <Component/Component.h>
class TransformerRXY: public Component
{
    public:
        TransformerRXY();
        virtual ~TransformerRXY();
        virtual pTransformerRXYModel Model();
        virtual void SetModel(pTransformerRXYModel model);
        virtual pTransformerRXYViewer Viewer();
        virtual void SetViewer(pTransformerRXYViewer viewer);
        virtual pTransformerRXYController Controller();
        virtual void SetController(pTransformerRXYController controller);
    protected:

    private:
};

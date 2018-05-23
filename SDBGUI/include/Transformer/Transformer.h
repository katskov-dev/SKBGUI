#pragma once
#include <base.h>
#include <Transformer/TransformerModel.h>
#include <Transformer/TransformerViewer.h>
#include <Transformer/TransformerController.h>
#include <Component/Component.h>
class Transformer: public Component
{
    public:
        Transformer();
        virtual ~Transformer();
        virtual pTransformerModel Model();
        virtual void SetModel(pTransformerModel model);
        virtual pTransformerViewer Viewer();
        virtual void SetViewer(pTransformerViewer viewer);
        virtual pTransformerController Controller();
        virtual void SetController(pTransformerController controller);
    protected:

    private:
};

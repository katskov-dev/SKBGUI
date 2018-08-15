#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class ProgressBarModel: public ComponentModel
{
    public:
        ProgressBarModel();
        virtual ~ProgressBarModel();
        bool Vertical();
        void SetVertical(bool vertical);
        double Max();
        double Min();
        double Current();
        void SetMax(double max);
        void SetMin(double min);
        void SetCurrent(double current);

    protected:

    private:
        bool __vertical;
        double __min;
        double __max;
        double __current;

	friend ProgressBar;
	friend ProgressBarViewer;
	friend ProgressBarController;

};

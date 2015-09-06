#pragma once

#include <Filter.h>

class FilterLP6 : public Filter {
public:

	FilterLP6();
	~FilterLP6(){}

	void process(int64_t& sample) override;

    AudioNodeInput AudioIn;
	AudioNodeInput Cutoff;
	AudioNodeInput CutoffModAmount;
	AudioNodeInput CutoffModSource;

protected:

	int64_t _a0;
	int64_t _a1;
	int64_t _b0;
	int64_t _b1;
    int64_t _y1;
    int64_t _x1;
    int64_t _y0;
    int64_t _x0;
    int64_t _cutoffModSource;
    int64_t _cutoffModAmount;
	
};
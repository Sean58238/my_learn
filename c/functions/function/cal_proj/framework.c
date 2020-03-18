#include "cal.h"

int calculator(const struct cal_t * cal){
    return cal->p(cal->a, cal->b);
}

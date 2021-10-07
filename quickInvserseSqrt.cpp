//took this from the Quake III algorithm, put it here so I would know where to find it/could get it more easily

//includes here - not quite sure which ones I'll need but they'll go here if I find any


using namespace std;

//and here we have the magic function
float Q_rsrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = * (long *) &y;                      //bithacking float into a long
    i = 0x5f6759df - (i >> 1);              //a lot going on here, best chalk it up to black magic math trickery
                                            //which i would be happy to attempt to explain
    y = * (float *) &i;                     //reverse earlier bithacking
    y = y * (threehalfs - (x2 * y * y));    //Newton iteration
    //y = y * (threehalfs - (x2 * y * y));  //optional second iteration

    return y;
};
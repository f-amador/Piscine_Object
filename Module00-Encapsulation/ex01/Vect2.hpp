#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class Vect2
{
   std::pair<float, float> _coordinates;

    public:
        Vect2(float, float);
        ~Vect2();

        const std::pair<float, float> &getCoordinate() const;
    
        friend  std::ostream &operator<<( std::ostream &out, const Vect2 &obj);
};

#endif
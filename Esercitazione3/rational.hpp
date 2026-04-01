#include <iostream>
#include <concepts>

template<typename I> requires std::integral<I>
class rational
{
	I numerator;
	I denominator;
	public:
	
	//default constructor
	rational()
	{
		numerator = 0;
		denominator = 1;
	}
	
	//user defined constructor, pass by constant reference structure
	rational(const I& num, const I& den)
	{
		numerator = num;
		denominator = den;
		riduco();
	}
	
	I l_num() const {return numerator;};
	I l_den() const {return denominator;};
	
	rational& operator+=(const rational& other)
	{
		if (denominator == 0 || other.denominator == 0){
			if(numerator == 0 || other.numerator == 0){
				numerator = 0; //(0/0)
			}
			else{
				numerator = 1; //(n/0)
			}
			denominator = 0;
		}
		else{
			I new_denominator = mcm(denominator, other.denominator);
			numerator = (numerator*(new_denominator/denominator)) + 
			(other.numerator *(new_denominator/other.denominator));
			
			denominator = new_denominator;
			riduco();
		}
		return *this;
	}
	
	rational operator+(const rational& other) {
		rational result = *this;
		result += other;
		return result;
	}
	
	rational& operator-=(const rational& other)
	{
		if (denominator == 0 || other.denominator == 0){
			if(numerator == 0 || other.numerator == 0){
				numerator = 0; //(0/0)
			}
			else{
				numerator = 1; //(n/0)
			}
			denominator = 0;
		}
		else{
			I new_denominator = mcm(denominator, other.denominator);
			numerator = (numerator*(new_denominator/denominator)) - 
			(other.numerator *(new_denominator/other.denominator));
			
			denominator = new_denominator;
			riduco();
		}
		return *this;
	}
	
	rational operator-(const rational& other) {
		rational result = *this;
		result -= other;
		return result;
	}
	
	rational& operator*=(const rational& other){
		if (denominator == 0 || other.denominator == 0){
			if(numerator == 0 || other.numerator == 0){
				numerator = 0; //(0/0)
			}
			else{
				numerator = 1; //(n/0)
			}
			denominator = 0;
		}
		else{
			numerator *= other.numerator;
			denominator *= other.denominator;
			riduco();
		}
		return *this;
	}
	
	rational operator*(const rational& other){
		rational result = *this;
		result *= other;
		return result;
	}
	
	rational operator /= (const rational& other){
		if (denominator == 0 || other.denominator == 0){
			if(numerator == 0 || other.numerator == 0){
				numerator = 0; //(0/0)
			}
			else{
				numerator = 1; //(n/0)
			}
			denominator = 0;
		}
		else{
			numerator *= other.denominator;
			denominator *= other.numerator;
			riduco();
		}
		return *this;
	}
	
	rational operator/(const rational& other){
		rational result = *this;
		result /= other;
		return result;
	}
	
	private:
	//funzione mcd()
	I mcd(I a, I b){
		while(b !=0)
        { 
		int resto = a % b;
		a = b;
		b = resto;
        }
                
		if (a<0)
		{
			a = -a;
		}
		return a;
	}
	
	//funzione mcm()
	int mcm(I a, I b){
		int min_cm = (a*b)/mcd(a,b);
		return min_cm;
	}
	
	void riduco(){
		if (denominator!=0){
			I max_cd = mcd(numerator, denominator);
			numerator = numerator/max_cd;
			denominator = denominator/max_cd;
			
			if (denominator<0){
				numerator = -numerator;
				denominator = -denominator;
			}
		}
	}
};


template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& n_rational)
{
    if (n_rational.l_den() == 0)
    {
        if(n_rational.l_num() == 0)
        {
            os << "Nan";
        }
        else
        {
            os << "Inf";
        }
    }

    else
    {
        if(n_rational.l_num() == 0)
        {
            os << 0;
        }
        else
        {
            if(n_rational.l_den() == 1)
            {
                os << n_rational.l_num();
            }

            else 
            {
                os << n_rational.l_num() << "/" << n_rational.l_den();
            }

        }
    }

return os;

}
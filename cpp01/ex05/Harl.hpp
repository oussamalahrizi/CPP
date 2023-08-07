#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
    private:
        void debug( void )
        {
            std::cout << "DEBUG" << std::endl;
        }
        void info( void )
        {
            std::cout << "INFO" << std::endl;
        }
        void warning( void )
        {
            std::cout << "WARNING" << std::endl;
        }
        void error( void )
        {
            std::cout << "ERROR" << std::endl;
        }
    public:
        void complain( std::string level );
};


#endif
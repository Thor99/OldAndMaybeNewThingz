#ifndef TEMPCLASS_H
#define TEMPCLASS_H
template<typename T>
class X
{
    public:
        void f(T arg)
        {	
        	m_x = arg;
        }
    private:
        T m_x;
};
#endif

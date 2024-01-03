#include <iostream>

using namespace std;

class Strategy
{
public:
    virtual int doOperation() = 0;
};

class OperationAdd : public Strategy 
{
private:
    int m_a;
    int m_b;
public:
    OperationAdd(int a, int b) : m_a(a), m_b(b) {}
    int doOperation() {
        return m_a + m_b;
    }
};

class OperationSub : public Strategy 
{
private:
    int m_a;
    int m_b;
public:
    OperationSub(int a, int b) : m_a(a), m_b(b) {}
    int doOperation() {
        return m_a - m_b;
    }
};

class OperationMultiply : public Strategy 
{
private:
    int m_a;
    int m_b;
public:
    OperationMultiply(int a, int b) : m_a(a), m_b(b) {}
    int doOperation() {
        return m_a * m_b;
    }
};


class Context
{
private:
    Strategy *mStrategy;
public:
    Context(Strategy *strategy) : mStrategy(strategy) {}
    int executeStategy()
    {
        mStrategy->doOperation();
    }
};


int main()
{
    Context *context = new Context(new OperationAdd(2, 5));
    cout<<"a = " << context->executeStategy() << endl;
    context = new Context(new OperationSub(8, 5));
    cout<<"b = " << context->executeStategy() << endl;
    context = new Context(new OperationMultiply(6, 5));
    cout<<"c = " <<context->executeStategy() << endl;
    delete context;
    return 0;
}

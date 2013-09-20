#include "ConstructorTest.h"

//base::base()
//	:m_i(0),
//	m_j(0)
//{
//}


base::base(int i)
	:m_j(i),
	m_i(m_j)
{
}

base::~base()
{
}
// int main(int argc,char *argv[]){
	// base A;
	// base B(1);

// }

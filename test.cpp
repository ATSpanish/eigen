
#include <iostream>
#include "Eigen/Dense"
#include "Eigen/Cholesky"

int main()
{
   std::cout << "Hello, world" << std::endl;
   std::cout << "This is how we use eigen: " << std::endl;


   Eigen::MatrixXd A(3,3);
   //A << 4.0,-1.0,2.0, -1.0,6.0,0.0, 2.0,0.0,5.0;
   A << 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0;
   std::cout << "The matrix A is \n" << A << std::endl;
   Eigen::LLT<Eigen::MatrixXd> llt(A); // compute the cholesky decomposition of A
   Eigen::MatrixXd L(llt.matrixL()); // Get the L factor of the decomp
   
   if(!A.isApprox(A.transpose()) || llt.info() == Eigen::NumericalIssue)
   {
      throw std::runtime_error("Possible non semi-positive definite matrix");
   }

   std::cout << "The cholesky factor L is \n" << L << std::endl;
   auto Lt = L.transpose();
   std::cout << "To check this, let us compute L^T \n" << L.transpose() << std::endl;
   std::cout << L*L.transpose() << std::endl;
   std::cout << "This should equal the matrix A" << std::endl;
   return 0;
}

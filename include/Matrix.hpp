#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <climits>
#include <cmath>

#include "Vector.hpp"

namespace om
{
  // @description Classe representant une matrice que l'on peut parametrer comme 
  // on le souhaite avec une taille et un type arbitraire.
  // Cette classe utile en interne un tableau de Vector qui est la classe realiser
  // aussi dans le cadre du projet.
  // @WARNING durant les operations; aucune verification n'est faite sur le type
  // de la matrice pour des questions d'efficacite. Il est ainsi necessaire de
  // realiser ces tests si on le souhaite avant d'appeler les methodes.
  template <typename T, size_t N, size_t M>
  class Matrix
  {

  private:

    friend Matrix<T,M,N>;
    
    Vector<M,T> matrix[N];

    // @description methode privee utilise en interne pour echanger deux lignes
    // durant l'inversion de matrice
    // @arg matrix la matrice dont l'on souhaite echanger les lignes
    // @arg line1 l'indice de la premiere ligne a echanger
    // @arg line2 l'indice de la deuxieme ligne a echanger
    void SwapLines(Matrix<T,N,M>& matrix, int line1, int line2) const
    {
      for(unsigned int j = 0; j < M; j++)
	{
	  T tmp = matrix[line1][j];
	  matrix[line1][j] = matrix[line2][j];
	  matrix[line2][j] = tmp;
	}
    }

    // @description methode privee utilise en interne pour trouver le maximum sur une colonne
    // donnee dans la matrice
    // @arg matrix la matrice ou l'on veut trouver le maximum
    // @arg fromLine a partir de quelle ligne doit-on chercher
    // @arg column sur quelle colonne doit-on trouver le maximum
    // @return l'index de la ligne maximum que l'on a trouve, -1 si tous à 0
    int FindMaxLine(const Matrix<T,N,M>& matrix, unsigned int fromLine, unsigned int column) const
    {
      int max = INT_MIN;
      int maxIndex = -1;
      for(unsigned int i = fromLine; i < N; i++)
	{
	  if(fabs(matrix.At(i,column)) > max && matrix.At(i,column) != 0)
	    {
	      max = fabs(matrix.At(i,column));
	      maxIndex = i;
	    }
	}

      return maxIndex;
    }
    
  public:

    // @description Constructeur de notre matrice permettant d'initialiser notre matrice
    // Avec une diagonale de 1 et le reste à 0.
    Matrix()
    {
      if(!IsNull())
	{
	  for(unsigned int i = 0; i < N; i++)
	    {
	      for(unsigned int j = 0; j < M; j++)
		{
		  if(i == j)
		    {
		      matrix[i][j] = 1.0f;
		    }
		  else
		    {
		      matrix[i][j] = 0.0f;
		    }
		}
	    }
	}
    }

    // @description methode permettant de recuperer une copie de l'element à l'indice (i,j)
    // @arg i la position sur la ligne de la matrice
    // @arg j la position sur la colonne de la matrice
    // @return une copie de l'element à l'indice (i,j)
    T At(unsigned int i, unsigned int j) const
    {
      if(i < 0 || i >= N || j < 0 || j >= M)
	{
	  throw std::invalid_argument("Wrong index(es)");
	}
      
      return matrix[i].At(j);
    }

    // @description methode permettant de recuperer une reference le vecteur constituant la ligne i
    // @arg i la position de la ligne pour recuperer le vecteur
    // @return une reference sur le vecteur à la ligne i. On pourra ainsi
    // reappeller l'operateur[] pour obtenir l'element.
    Vector<M,T>& operator[](int i)
    {
      return matrix[i];
    }

    // @description methode permettant de savoir si deux matrices sont egales (memes elements)
    // @arg mat la deuxieme matrice avec laquelle on veut tester l'egalite
    // @return vrai si les matrices sont egales, faux sinon
    template <typename A, size_t B,size_t C>
    bool operator==(const Matrix<A,B,C>& mat) const
    {
      if(B != N || C != M)
	{
	  return false;
	}
      
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      if(At(i,j) != mat.At(i,j))
		{
		  return false;
		}
	    }
	}
      
      return true;
    }

    // @description methode permettant de savoir si notre matrice est valide (non null)
    // @return vrai si la matrice est null, faux sinon
    bool IsNull() const
    {
      if(std::is_same<T,int>::value) {
	return false;
      } else if(std::is_same<T,float>::value || std::is_same<T,double>::value) {
	return false;
      } else {
	return true;
      }
    }

    // @description methode permettant de savoir si notre matrice est orthogonale.
    // @return vrai si la matrice est une matrice orthogonale, faux sinon
    bool IsOrtho()
    {
      try
	{
	  Matrix<T,N,M> inverse = this->Reverse();
	  Matrix<T,M,N> transpose = this->Transpose();
	  return inverse == transpose;
	}
      catch(const std::invalid_argument& e)
	{
	  return false;
	}
    }

    // @description methode permettant d'obtenir la matrice transpose de notre matrice.
    // @return une nouveau matrice representant la transpose de notre matrice courante.
    Matrix<T,M,N> Transpose() const
    {
      Matrix<T,M,N> transpose;
      for(unsigned int i = 0; i < M; i++)
	{
	  for(unsigned int j = 0; j < N; j++)
	    {
	      transpose[i][j] = At(j,i);
	    }
	}

      return transpose;
    }

    // @description operateur d'affichage classique pour notre matrice.
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T,N,M>& matrix)
    {
      for(unsigned int i = 0; i < N; i++)
	{
	  std::cout << "| ";
	  for(unsigned int j = 0; j < M; j++)
	    {
	      std::cout << matrix.At(i,j) << " ";
	    }
	  std::cout << "|" << std::endl;
	}

      return os;
    }

    // @description methode permettant d'obtenir une nouvelle matrice etant l'addition de 2 matrices
    // @arg element la matrice avec laquelle on souhaite faire l'addition
    // @return une nouvelle matrice representant l'addition de nos matrices
    // @throw invalid_argument si les matrices ne sont pas de memes tailles
    template <typename A, size_t B, size_t C>
    Matrix<T,N,M> operator+(const Matrix<A,B,C>& element) const
    {
      if(B != N || C != M)
	{
	  throw std::invalid_argument("Addition of matrix should have same row and columns");
	}
      
      Matrix<T,N,M> add;
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      add[i][j] = At(i,j) + element.At(i,j);
	    }
	}

      return add;
    }

    // @description methode permettant de faire l'addition de matrice est mettre le resultat dans
    // la matrice courante
    // @arg element la matrice avec laquelle on souhaite faire l'addition
    // @return une reference sur notre matrice courante ayant obtenir l'addition en resultat
    // @throw invalid_argument si les matrices ne sont pas de memes tailles
    template<typename A, size_t B, size_t C>
    Matrix<T,N,M>& operator+=(const Matrix<A,B,C>& element)
    {
      if(B != N || C != M)
	{
	  throw std::invalid_argument("Addition of matrix should have same row and columns");
	}
      
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      matrix[i][j] += element.At(i,j);
	    }
	}

      return *this;
    }

    // @description methoder permettant de multiplier notre matrice par un scalaire entier
    // @arg scalar le scalaire entier avec lequel on veut mutliplier notre matrice.
    // @return une nouvelle matrice etant la multiplication de notre matrice par le scalaire.
    Matrix<T,N,M> operator*(int scalar) const
    {
      Matrix<T,N,M> time;
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      time[i][j] = At(i,j) * scalar;
	    }
	}

      return time;
    }

    // @description methode permettant de multiplier notre matrice par un scalaire flottant
    // @arg scalar le scalaire flottant avec lequel on veut mutliplier notre matrice.
    // @return une nouvelle matrice etant la multiplication de notre matrice par le scalaire.
    Matrix<T,N,M> operator*(float scalar) const
    {
      Matrix<T,N,M> time;
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      time[i][j] = At(i,j) * scalar;
	    }
	}

      return time;
    }

    // @description methode permettant de multiplier une matrice par un vecteur
    // @arg vector le vecteur avec lequel on souhaite multiplier notre matrice
    // @return une nouvelle matrice de taille N,1 representant la multiplication
    // @throw invalid_argument si le nombre de colonne de la matrice est different du nombre
    // d'element du vecteur.
    template <typename A, size_t B>
    Vector<N,T> operator*(const Vector<B,A>& vector) const
    {
      if(M != B)
	{
	  throw std::invalid_argument("Not available for product matrix * vector");
	}
      
      Matrix<T,B,1> vectorAsMatrix;
      for(unsigned int i = 0; i < B; i++)
	{
	  vectorAsMatrix[i][0] = vector.At(i);
	}

      auto result = *this * vectorAsMatrix;
      Vector<N,T> asVector;
      for(unsigned int i = 0; i < N; i++)
	{
	  asVector[i] = result[i][0];
	}

      return asVector;
    }

    // @description methode permettant de multiplier notre matrice par une autre matrice
    // @arg element la matrice avec laquelle on veut multiplier notre matrice
    // @return une nouvelle matrice representant la multiplication des 2 matrices
    // throw invalid_argument si les matrices n'ont pas le meme nombre de colonne et ligne.
    template <typename A, size_t B, size_t C>
    Matrix<T,N,C> operator*(const Matrix<A,B,C>& element) const
    {
      if(M != B)
	{
	  throw std::invalid_argument("Should have same column and row");
	}
      
      Matrix<T,N,C> time;
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < C; j++)
	    {
	      time[i][j] = 0;
	      for(unsigned int k = 0; k < M; k++)
		{
		  time[i][j] += At(i,k) * element.At(k,j);  
		}
	    }
	}

      return time;
    }

    // @description methode permettant de multiplier notre matrice par un scalaire entier et
    // d'affecter le resultat
    // @arg scalar le scalaire entier avec lequel on veut multiplier notre matrice
    // @return une reference sur notre objet ayant reçu le resultat de la multiplication
    Matrix<T,N,M>& operator*=(int scalar)
    {
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      matrix[i][j] *= scalar;
	    }
	}

      return *this;
    }

    // @description methode permettant de multiplier notre matrice par un scalaire flottant et
    // d'affecter le resultat
    // @arg scalar le scalaire flottant avec lequel on veut multiplier notre matrice
    // @return une reference sur notre objet ayant reçu le resultat de la multiplication
    Matrix<T,N,M>& operator*=(float scalar)
    {
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      matrix[i][j] *= scalar;
	    }
	}

      return *this;
    }

    // @description methode permettant de multiplier notre matrice par une autre et d'affecter
    // le resultat à notre objet. Attention, il faut donc necessairement que les matrices
    // soient de meme taille.
    // @arg element la matrice avec laquelle on souhaite multiplier notre matrice
    // @return une reference sur notre objet ayant resultat le resultat de la multiplication
    // @throw invalid_argument si les 2 matrices ne sont pas de meme taille
    template <typename A, size_t B, size_t C>
    Matrix<T,N,M>& operator*=(const Matrix<A,B,C>& element)
    {
      if(N != B || M != C)
	{
	  throw std::invalid_argument("Should have same column and row");
	}
      
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < C; j++)
	    {
	      matrix[i][j] = 0;
	      for(unsigned int k = 0; k < M; k++)
		{
		  matrix[i][j] += matrix[i][k] * element.At(k,j);  
		}
	    }
	}

      return *this;
    }

    // @description methode permettant de retourner une matrice representant l'inverse de
    // l'objet courant si elle existe
    // @return une nouvelle matrice representant l'inverse de la matrice
    // @throw invalid_argument si la matrice n'est pas inversible
    Matrix<T,N,M> Reverse() const
    {
      // Construction
      Matrix<T,N,M> copy = *this;
      Matrix<T,N,M> identity;
      for(unsigned int i = 0; i < N; i++)
	{
	  for(unsigned int j = 0; j < M; j++)
	    {
	      if(i == j) identity[i][j] = 1;
	      else identity[i][j] = 0;
	    }
	}

      // GO
      for(unsigned int i = 0; i < M; i++)
	{
	  int indexMaxLine = FindMaxLine(copy, i, i);
	  if(indexMaxLine == -1)
	    {
	      throw std::invalid_argument("Matrice non inversible");
	    }
	  
	  if(indexMaxLine != (int)i)
	    {
	      SwapLines(copy, i, indexMaxLine);
	      SwapLines(identity, i, indexMaxLine);
	    }
	  
	  float max = copy[i][i];
	  for(unsigned int j = 0; j < M; j++)
	    {
	      if(copy[i][j] != 0)
		{
		  copy[i][j] = copy[i][j] / max;
		}
	      if(identity[i][j] != 0)
		{
		  identity[i][j] = identity[i][j] / max;
		}
	    }

	  for(unsigned int j = 0; j < N; j++)
	    {
	      float value = copy[j][i];
	      if(j != i)
		{
		  for(unsigned int k = 0; k < M; k++)
		    {
		      copy[j][k] = copy[j][k] + copy[i][k] * (-value);
		      identity[j][k] = identity[j][k] + identity[i][k] * (-value);
		    
		    }
		}
	    }
	    
	}

      return identity;
    }

  };

  // @description methode permettant de multiplier une matrice par un scalaire flottant
  // @arg scalar scalaire flottant en position prefix pour multiplier notre matrice
  // @arg m la matrice que l'on veut multiplier
  // @return une nouvelle matrice representant la multiplication avec le scalaire
  template <typename T, size_t N, size_t M>
  Matrix<T,N,M> operator*(float scalar, Matrix<T,N,M>& m)
  {
    return (m * scalar);
  }

  // @description methode permettant de multiplier une matrice par un scalaire reel
  // @arg scalar scalaire reel en position prefix pour multiplier notre matrice
  // @arg m la matrice que l'on veut multiplier
  // @return
  template <typename T, size_t N, size_t M>
  Matrix<T,N,M> operator*(int scalar, Matrix<T,N,M>& m)
  {
    return m * scalar;
  }

  // @description methode permettant de multiplier un vecteur par une matrice (dans cet ordre)
  // @arg vector le vecteur en position prefix avec lequel on veut faire la multiplication
  // @arg matrix la matrice que l'on veut multiplier
  // @return une nouvelle matrice representant la multiplication
  // @throw invalid_argument si le nombre d'element du vecteur est different du nombre de ligne
  // de la matrice
  template <typename A, typename T, size_t N, size_t M, size_t B>
  Vector<M,A> operator*(Vector<B,A>& vector, Matrix<T,N,M>& matrix)
  {
    if(B != N)
      {
	throw std::invalid_argument("Not available for product matrix * vector");
      }
      
    Matrix<T,1,B> vectorAsMatrix;
    for(unsigned int i = 0; i < B; i++)
      {
	vectorAsMatrix[0][i] = vector.At(i);
      }

    auto resMatrix = vectorAsMatrix * matrix;
    return resMatrix[0];
  }
}
  
#endif

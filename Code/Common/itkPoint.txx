/*==========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkPoint.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.
  
==========================================================================*/
#include "itkPoint.h" 
#include <math.h>



namespace itk
{


template<class T, unsigned int TPointDimension>
Point<T, TPointDimension>&
Point<T, TPointDimension>
::operator= (const Self& r)
{
  BaseArray::operator=(r);
  return *this;
}


template<class T, unsigned int TPointDimension>
Point<T, TPointDimension>&
Point<T, TPointDimension>
::operator= (const typename BaseArray::Reference& r)
{
  BaseArray::operator=(r);
  return *this;
}


template<class T, unsigned int TPointDimension>
Point<T, TPointDimension>&
Point<T, TPointDimension>
::operator= (const typename BaseArray::ConstReference& r)
{
  BaseArray::operator=(r);
  return *this;
}


template<class T, unsigned int TPointDimension>
Point<T, TPointDimension>&
Point<T, TPointDimension>
::operator= (const ValueType r[PointDimension])
{
  BaseArray::operator=(r);
  return *this;
}


template<class T, unsigned int TPointDimension>
typename Point<T, TPointDimension>::ArrayCommaListCopier
Point<T, TPointDimension>
::operator= (const ValueType& r)
{
  return BaseArray::operator=(r);
}


/**
 *
 */
template<class T, unsigned int TPointDimension>
const Point<T, TPointDimension> &
Point<T, TPointDimension>
::operator+=( const Vector<T, TPointDimension> & vec )
{
  for( unsigned int i=0; i<TPointDimension; i++) 
  {
    (*this)[i] += vec[i];
  }
  return *this;
}

 
/**
 *
 */
template<class T, unsigned int TPointDimension>
const Point<T, TPointDimension> &
Point<T, TPointDimension>
::operator-=( const Vector<T, TPointDimension> & vec )
{
  for( unsigned int i=0; i<TPointDimension; i++) 
  {
    (*this)[i] -= vec[i];
  }
  return *this;
}

 

/**
 * Returns a temporary copy of a point
 */
template<class T, unsigned int TPointDimension>
Point<T, TPointDimension> 
Point<T, TPointDimension>
::operator+( const Vector<T, TPointDimension> & vec ) const
{
  Self result;
  for( unsigned int i=0; i<TPointDimension; i++) 
  {
    result[i] = (*this)[i] + vec[i];
  }
  return result;
}



/**
 * Returns a temporary copy of a point
 */
template<class T, unsigned int TPointDimension>
Point<T, TPointDimension> 
Point<T, TPointDimension>
::operator-( const Vector<T, TPointDimension> & vec )  const
{
  Self result;
  for( unsigned int i=0; i<TPointDimension; i++) 
  {
    result[i] = (*this)[i] - vec[i];
  }
  return result;
}



/**
 * Difference between two points
 */
template<class T, unsigned int TPointDimension>
Vector<T, TPointDimension> 
Point<T, TPointDimension>
::operator-( const Point<T, TPointDimension> & pnt )  const
{
  VectorType result;
  for( unsigned int i=0; i<TPointDimension; i++) 
  {
    result[i] = (*this)[i] - pnt[i];
  }
  return result;
}


/**
 * Return a vnl_vector_ref
 */
template<class T, unsigned int TPointDimension >
vnl_vector_ref< T >
Point<T, TPointDimension>
::Get_vnl_vector( void ) 
{
  vnl_vector_ref< T > vector_ref( TPointDimension, (T *)(*this) );
  return vector_ref;
}
 

/**
 * Returns Squared Euclidean distance between two points
 */
template<class T, unsigned int TPointDimension>
T
Point<T, TPointDimension>
::SquaredEuclideanDistanceTo( const Point<T, TPointDimension> & pnt )  const
{
  T sum = 0;  // consider to use a trait for null here...
  for( unsigned int i=0; i<TPointDimension; i++) 
  {
    const T difference = (*this)[i] - pnt[i];
    sum += difference * difference;
  }
  return sum;
}



/**
 * Returns Euclidean distance between two points
 */
template<class T, unsigned int TPointDimension>
T
Point<T, TPointDimension>
::EuclideanDistanceTo( const Point<T, TPointDimension> & pnt )  const
{
  const double distance = sqrt( 
                static_cast<double>( SquaredEuclideanDistanceTo( pnt ) ) ) ;
  return static_cast<T>( distance );
}
 




} // end namespace itk


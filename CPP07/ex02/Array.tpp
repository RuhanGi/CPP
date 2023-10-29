/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:01:15 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/23 19:46:45 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (n)
		this->arr = new T[n];
	else
		this->arr = NULL;
	this->_size = n;
}

template <typename T>
Array<T>::Array( void )
{
	this->arr = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array( const Array<T> &f )
{
	if (f.size())
		this->arr = new T[f.size()];
	else
		this->arr = NULL;
	this->_size = f.size();
	for (unsigned int i = 0; i < this->_size; i++)
		this->arr[i] = f.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=( const Array<T> &f )
{
	if (this == &f)
		return (*this);
	if (this->arr)
		delete[] arr;
	if (f.size())
		this->arr = new T[f.size()];
	else
		this->arr = NULL;
	this->_size = f.size();
	for (unsigned int i = 0; i < this->_size; i++)
		this->arr[i] = f.arr[i];
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	if (this->arr)
		delete[] arr;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
T	&Array<T>::operator[]( const unsigned int i )
{
	if (i < this->_size)
		return (this->arr[i]);
	throw (Array::OutOfBounds());
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return ("Index Out of Bounds!");
}

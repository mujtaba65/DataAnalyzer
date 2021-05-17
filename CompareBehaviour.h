#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H


template <class T>
class CompareBehaviour
{
	public:
		//shouldn't have ctor's
		virtual bool compare(T, T) = 0;	
};

template <class T>
class AscBehaviour : public CompareBehaviour<T>
{
	public:
		virtual bool compare(T, T);
};

template <class T>
bool AscBehaviour<T>::compare(T t1, T t2)
{
	if(t1 > t2)
	{
		return true;
	}
	return false;
}


template <class T>
class DescBehaviour : public CompareBehaviour<T>
{
	public: 
		virtual bool compare(T, T);
};

template <class T>
bool DescBehaviour<T>::compare(T t1, T t2)
{
	if(t1 < t2)
	{
		return true;
	}
	return false;
}





#endif

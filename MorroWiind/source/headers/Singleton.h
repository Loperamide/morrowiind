/*
 * Singleton.h
 *
 *  Created on: 24 févr. 2011
 *      Author: jpCapelle
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include "global.h"

template <typename T>
class Singleton
{
protected:
  Singleton (){};
  ~Singleton (){};

public:
  static T *getInstance ()
  {
    if (NULL == _singleton)	{
    	_singleton = new T;
	}

    return (static_cast<T*> (_singleton));
  }

  static void dropInstance ()
  {
    if (NULL != _singleton)
      {
        delete _singleton;
        _singleton = NULL;
      }
  }

private:
  static T *_singleton;
};

template <typename T>
T *Singleton<T>::_singleton = NULL;

#endif /* SINGLETON_H_ */

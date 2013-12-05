#pragma once

/*
 * SmartSharedPointer.h
 *
 * @author: Milot Shala <milot.shala@gmail.com>
 *
 * @reference: http://is.gd/ENpfvJ
 *
 * @description: This is one of the simplest shared-pointer implementation.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

class ReferenceCounter;

template<class T>
class SmartSharedPointer {
public:
  SmartSharedPointer();
  explicit SmartSharedPointer(T* Ptr);

  // copy constructor
  SmartSharedPointer(const SmartSharedPointer<T>& smartSharedPointer);

  ~SmartSharedPointer();
  T* operator->();
  T& operator*();
  SmartSharedPointer<T>& operator=(const SmartSharedPointer<T>& smartSharedPointer);
private:
  T* data;
  ReferenceCounter* refCounter;
};

#pragma once

/*
 * SmartDeleter.h
 *
 * @author: Milot Shala <milot.shala@gmail.com>
 *
 * @reference: http://is.gd/ENpfvJ
 *
 * @description: This is one of the simplest smart-pointer implementation.
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

template<class T>
class SmartDeleter
{
public:
    explicit SmartDeleter(T* Ptr);
    ~SmartDeleter();
    T* operator->();

private:
    T* m_Ptr;
};
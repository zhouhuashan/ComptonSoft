/*************************************************************************
 *                                                                       *
 * Copyright (c) 2011 Hirokazu Odaka                                     *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                       *
 *************************************************************************/

#ifndef ANLGEANT4_VANLGeometry_H
#define ANLGEANT4_VANLGeometry_H 1

#include "BasicModule.hh"

class G4VUserDetectorConstruction;

namespace anlgeant4
{

/**
 * Virtual geometry module
 * @author Hirokazu Odaka
 * @date xxxx-xx-xx
 * @date 2012-05-30
 * @date 2013-08-18 | H. Odaka | length unit, surface check
 */
class VANLGeometry : public anl::BasicModule
{
  DEFINE_ANL_MODULE(VANLGeometry, 4.1);
public:
  VANLGeometry();

  virtual G4VUserDetectorConstruction* create() = 0;

  void SetLengthUnit(double unit, const std::string& name);
  void SetLengthUnit(const std::string& name);
  double GetLengthUnit() const { return m_LengthUnit; }
  std::string GetLengthUnitName() const { return m_LengthUnitName; }

  bool SurfaceCheck() const { return m_SurfaceCheck; }

  anl::ANLStatus mod_startup();

private:
  double m_LengthUnit;
  std::string m_LengthUnitName;
  bool m_SurfaceCheck;
};

}

#endif /* ANLGEANT4_VANLGeometry_H */

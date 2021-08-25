/*
 * LSST Data Management System
 * See COPYRIGHT file at the top of the source tree.
 *
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
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
 * You should have received a copy of the LSST License Statement and
 * the GNU General Public License along with this program.  If not,
 * see <https://www.lsstcorp.org/LegalNotices/>.
 */

#include <pybind11/pybind11.h>
#include <lsst/utils/python.h>

#include "lsst/sphgeom/healpix/HEALPix.h"
namespace lsst { 
namespace sphgeom { 
namespace healpix {

namespace py = pybind11;
using PyHEALPix = py::class_<HEALPix, std::shared_ptr<HEALPix>>;

void wrapHEALPix(lsst::utils::python::WrapperCollection &wrappers) {
    wrappers.wrapType(PyHEALPix(wrappers.module, "HEALPix"), [](auto &mod, auto &cls) {
    cls.def(py::init<>());
  });
}

PYBIND11_MODULE(_HEALPIX, mod) {
 lsst::utils::python::WrapperCollection wrappers(mod, "lsst.sphgeom.healpix");
  wrapHEALPix(wrappers);
  wrappers.finish();
}
}
}
}
